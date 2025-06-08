#include "hash_table.h"
#include <stdexcept>

UniversalHashFunction::UniversalHashFunction(size_t table_size)
    : m(table_size), p(2147483647) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist_a(1, p - 1);
    std::uniform_int_distribution<size_t> dist_b(0, p - 1);

    a = dist_a(gen);
    b = dist_b(gen);
}

size_t UniversalHashFunction::operator()(int key) const {
    size_t k = static_cast<size_t>(key) % p;
    return ((a * k + b) % p) % m;
}

HashTable::HashTable(size_t size)
    : table(size), hash_func(size), collisions_count(0) {
    for (auto& entry : table) {
        entry.occupied = false;
    }
}

size_t HashTable::linear_probing(size_t hash, size_t attempt) const {
    return (hash + attempt) % table.size();
}

bool HashTable::insert(int key, int value) {
    if (table.empty()) return false;

    size_t attempt = 0;
    size_t original_hash = hash_func(key);
    size_t current_hash = original_hash;

    while (attempt < table.size()) {
        if (!table[current_hash].occupied) {
            table[current_hash] = {key, value, true, static_cast<int>(original_hash)};
            return true;
        }

        if (table[current_hash].key == key) {
            table[current_hash].value = value;
            return true;
        }

        if (attempt == 0) {
            collisions_count++;
        }

        attempt++;
        current_hash = linear_probing(original_hash, attempt);
    }

    return false;
}

std::optional<int> HashTable::search(int key, size_t& attempts) const {
    if (table.empty()) return std::nullopt;

    size_t original_hash = hash_func(key);
    size_t current_hash = original_hash;
    attempts = 0;

    while (attempts < table.size()) {
        if (!table[current_hash].occupied) {
            return std::nullopt;
        }

        if (table[current_hash].key == key) {
            return table[current_hash].value;
        }

        attempts++;
        current_hash = linear_probing(original_hash, attempts);
    }

    return std::nullopt;
}

void HashTable::clear() {
    for (auto& entry : table) {
        entry.occupied = false;
    }
    collisions_count = 0;
}

size_t HashTable::get_collisions_count() const {
    return collisions_count;
}

size_t HashTable::size() const {
    return table.size();
}

double HashTable::load_factor() const {
    size_t count = 0;
    for (const auto& entry : table) {
        if (entry.occupied) count++;
    }
    return static_cast<double>(count) / table.size();
}
