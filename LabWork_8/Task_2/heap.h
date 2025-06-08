#ifndef HEAP_H
#define HEAP_H

#include <memory>
#include <vector>
#include <QString>

class BinaryHeap {
public:
    BinaryHeap();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;
    size_t size() const;
    QString toString() const;

private:
    std::vector<std::shared_ptr<int>> data;
    std::vector<std::weak_ptr<int>> weakRefs;

    void heapifyUp(size_t index);
    void heapifyDown(size_t index);
    size_t parent(size_t index) const;
    size_t leftChild(size_t index) const;
    size_t rightChild(size_t index) const;
};

#endif // HEAP_H
