#ifndef DOUBLYLINKEDQUEUE_H
#define DOUBLYLINKEDQUEUE_H

#include <QVector>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    DoublyLinkedQueue();
    ~DoublyLinkedQueue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    int getSize() const;
    void clear();
    int peekFront() const;
    int peekRear() const;

    Node* findMax() const;
    Node* findMin() const;
    DoublyLinkedQueue* getElementsBetween(Node* start, Node* end) const;
    DoublyLinkedQueue* getElementsOutside(Node* start, Node* end) const;
    void makeCircular();
    bool isCircular() const;
    QVector<int> toVector() const;
};

#endif // DOUBLYLINKEDQUEUE_H
