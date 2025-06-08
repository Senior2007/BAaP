#include "binaryheapdll.h"
#include <queue>
#include <stdexcept>

BinaryHeap::BinaryHeap() : root(nullptr), heapSize(0) {}

void BinaryHeap::insert(int value) {
    auto newNode = std::make_shared<Node>(value);

    if (!root) {
        root = newNode;
    } else {
        // Находим позицию для вставки (последний узел в списке)
        std::queue<std::shared_ptr<Node>> q;
        q.push(root);

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            if (!current->left) {
                current->left = newNode;
                newNode->parent = current;
                break;
            } else if (!current->right) {
                current->right = newNode;
                newNode->parent = current;
                break;
            } else {
                q.push(current->left);
                q.push(current->right);
            }
        }
    }

    heapSize++;
    heapifyUp(newNode);
}

int BinaryHeap::extractMax() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }

    int maxValue = *root->data;

    if (heapSize == 1) {
        root = nullptr;
    } else {
        auto lastNode = getLastNode();
        *root->data = *lastNode->data;
        removeLastNode();
        heapifyDown(root);
    }

    heapSize--;
    return maxValue;
}

int BinaryHeap::getMax() const {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    return *root->data;
}

bool BinaryHeap::isEmpty() const {
    return heapSize == 0;
}

size_t BinaryHeap::size() const {
    return heapSize;
}

QString BinaryHeap::toString() const {
    if (!root) return "Empty heap";

    QString result;
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        result += QString::number(*current->data) + " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    return result.trimmed();
}

void BinaryHeap::heapifyUp(std::shared_ptr<Node> node) {
    while (auto parent = node->parent.lock()) {
        if (*parent->data < *node->data) {
            std::swap(*parent->data, *node->data);
            node = parent;
        } else {
            break;
        }
    }
}

void BinaryHeap::heapifyDown(std::shared_ptr<Node> node) {
    while (node) {
        auto largest = node;

        if (node->left && *node->left->data > *largest->data) {
            largest = node->left;
        }

        if (node->right && *node->right->data > *largest->data) {
            largest = node->right;
        }

        if (largest != node) {
            std::swap(*node->data, *largest->data);
            node = largest;
        } else {
            break;
        }
    }
}

std::shared_ptr<BinaryHeap::Node> BinaryHeap::getLastNode() const {
    if (!root) return nullptr;

    std::queue<std::shared_ptr<Node>> q;
    q.push(root);
    std::shared_ptr<Node> last;

    while (!q.empty()) {
        last = q.front();
        q.pop();

        if (last->left) q.push(last->left);
        if (last->right) q.push(last->right);
    }

    return last;
}

void BinaryHeap::removeLastNode() {
    auto last = getLastNode();
    if (auto parent = last->parent.lock()) {
        if (parent->left == last) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
    }
}
