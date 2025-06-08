#include "heap.h"
#include <stdexcept>
#include <algorithm>

BinaryHeap::BinaryHeap() {}

void BinaryHeap::insert(int value) {
    auto ptr = std::make_shared<int>(value);
    data.push_back(ptr);
    weakRefs.push_back(ptr);
    heapifyUp(data.size() - 1);
}

int BinaryHeap::extractMax() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }

    int max = *data[0];
    std::swap(data[0], data.back());
    data.pop_back();

    if (!isEmpty()) {
        heapifyDown(0);
    }

    return max;
}

int BinaryHeap::getMax() const {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    return *data[0];
}

bool BinaryHeap::isEmpty() const {
    return data.empty();
}

size_t BinaryHeap::size() const {
    return data.size();
}

QString BinaryHeap::toString() const {
    QString result;
    for (const auto& ptr : data) {
        result += QString::number(*ptr) + " ";
    }
    return result.trimmed();
}

void BinaryHeap::heapifyUp(size_t index) {
    while (index > 0 && *data[parent(index)] < *data[index]) {
        std::swap(data[parent(index)], data[index]);
        index = parent(index);
    }
}

void BinaryHeap::heapifyDown(size_t index) {
    size_t maxIndex = index;
    size_t left = leftChild(index);
    size_t right = rightChild(index);

    if (left < data.size() && *data[left] > *data[maxIndex]) {
        maxIndex = left;
    }

    if (right < data.size() && *data[right] > *data[maxIndex]) {
        maxIndex = right;
    }

    if (index != maxIndex) {
        std::swap(data[index], data[maxIndex]);
        heapifyDown(maxIndex);
    }
}

size_t BinaryHeap::parent(size_t index) const {
    return (index - 1) / 2;
}

size_t BinaryHeap::leftChild(size_t index) const {
    return 2 * index + 1;
}

size_t BinaryHeap::rightChild(size_t index) const {
    return 2 * index + 2;
}
