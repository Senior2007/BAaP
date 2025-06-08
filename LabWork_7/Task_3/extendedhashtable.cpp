#include "extendedhashtable.h"
#include <climits>

ExtendedHashTable::ExtendedHashTable(int size) : HashTable(size) {}

int ExtendedHashTable::findStackWithMinKey() const {
    int minStackIndex = -1;
    int minValue = INT_MAX;

    for (int i = 0; i < tableSize; ++i) {
        if (!table[i]->isEmpty()) {
            int currentMin = table[i]->findMin();
            if (currentMin < minValue) {
                minValue = currentMin;
                minStackIndex = i;
            }
        }
    }

    return minStackIndex;
}
