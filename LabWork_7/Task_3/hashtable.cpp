#include "hashtable.h"
#include <cmath>
#include <stdexcept>

HashTable::HashTable(int size) : tableSize(size) {
    table = new Stack*[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        table[i] = new Stack();
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        delete table[i];
    }
    delete[] table;
}

int HashTable::hashFunction(int key) const {
    return abs(key) % tableSize;
}

void HashTable::insert(int key) {
    int index = hashFunction(key);
    table[index]->push(key);
}

bool HashTable::remove(int key) {
    int index = hashFunction(key);
    Stack* tempStack = new Stack();
    bool found = false;

    while (!table[index]->isEmpty()) {
        int current = table[index]->pop();
        if (current == key && !found) {
            found = true;
        } else {
            tempStack->push(current);
        }
    }

    while (!tempStack->isEmpty()) {
        table[index]->push(tempStack->pop());
    }

    delete tempStack;
    return found;
}

bool HashTable::contains(int key) const {
    int index = hashFunction(key);
    Stack* tempStack = new Stack();
    bool found = false;

    while (!table[index]->isEmpty()) {
        int current = table[index]->pop();
        tempStack->push(current);
        if (current == key) {
            found = true;
        }
    }

    while (!tempStack->isEmpty()) {
        table[index]->push(tempStack->pop());
    }

    delete tempStack;
    return found;
}

void HashTable::clear() {
    for (int i = 0; i < tableSize; ++i) {
        delete table[i];
        table[i] = new Stack();
    }
}

QString HashTable::toString() const {
    QString result;
    for (int i = 0; i < tableSize; ++i) {
        result += QString("Stack %1: ").arg(i);
        if (table[i]->isEmpty()) {
            result += "empty";
        } else {
            result += table[i]->toString();
        }
        result += "\n";
    }
    return result;
}

int HashTable::getTableSize() const {
    return tableSize;
}

Stack* HashTable::getStack(int index) const {
    if (index < 0 || index >= tableSize) {
        throw std::out_of_range("Index out of bounds");
    }
    return table[index];
}
