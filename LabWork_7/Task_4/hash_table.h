#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <vector>
#include <optional>
#include <functional>
#include <random>
#include <chrono>

struct HashTableEntry {
    int key;
    int value;
    bool occupied;
    int original_hash;
};

class UniversalHashFunction {
private:
    size_t a;
    size_t b;
    size_t p;
    size_t m;

public:
    UniversalHashFunction(size_t table_size);
    size_t operator()(int key) const;
};

class HashTable {
private:
    std::vector<HashTableEntry> table;
    UniversalHashFunction hash_func;
    size_t collisions_count;
    size_t linear_probing(size_t hash, size_t attempt) const;

public:
    explicit HashTable(size_t size);

    bool insert(int key, int value);
    std::optional<int> search(int key, size_t& attempts) const;
    void clear();

    size_t get_collisions_count() const;
    size_t size() const;
    double load_factor() const;
};

#endif // HASH_TABLE_H
