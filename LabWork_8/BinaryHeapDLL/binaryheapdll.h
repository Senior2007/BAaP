#ifndef BINARYHEAPDLL_H
#define BINARYHEAPDLL_H

#include "binaryheapdll_global.h"
#include <memory>
#include <QString>

class BINARYHEAPDLL_EXPORT BinaryHeap {
public:
    BinaryHeap();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;
    size_t size() const;
    QString toString() const;

private:
    struct Node {
        std::shared_ptr<int> data;
        std::weak_ptr<Node> parent;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(int val) : data(std::make_shared<int>(val)) {}
    };

    std::shared_ptr<Node> root;
    size_t heapSize;

    void heapifyUp(std::shared_ptr<Node> node);
    void heapifyDown(std::shared_ptr<Node> node);
    std::shared_ptr<Node> getLastNode() const;
    void removeLastNode();
};

#endif // BINARYHEAPDLL_H
