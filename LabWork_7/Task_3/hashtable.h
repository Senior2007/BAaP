#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "stack.h"
#include <QString>

class HashTable {
protected:
    Stack** table;
    int tableSize;
    virtual int hashFunction(int key) const;

public:
    HashTable(int size = 10);
    virtual ~HashTable();

    void insert(int key);
    bool remove(int key);
    bool contains(int key) const;
    void clear();
    QString toString() const;
    int getTableSize() const;
    Stack* getStack(int index) const;
};

#endif // HASHTABLE_H
