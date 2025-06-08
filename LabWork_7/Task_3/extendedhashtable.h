#ifndef EXTENDEDHASHTABLE_H
#define EXTENDEDHASHTABLE_H

#include "hashtable.h"

class ExtendedHashTable : public HashTable {
public:
    ExtendedHashTable(int size = 10);
    int findStackWithMinKey() const;
};

#endif // EXTENDEDHASHTABLE_H
