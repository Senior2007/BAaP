#include "doublylinkedqueue.h"
#include <stdexcept>

DoublyLinkedQueue::DoublyLinkedQueue() : front(nullptr), rear(nullptr), size(0) {}

DoublyLinkedQueue::~DoublyLinkedQueue() { clear(); }

void DoublyLinkedQueue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (size == 0) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    size++;
}

int DoublyLinkedQueue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front) {
        front->prev = nullptr;
    } else {
        rear = nullptr;
    }

    delete temp;
    size--;
    return value;
}

bool DoublyLinkedQueue::isEmpty() const {
    return front == nullptr;
}

int DoublyLinkedQueue::getSize() const {
    return size;
}

void DoublyLinkedQueue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

int DoublyLinkedQueue::peekFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return front->data;
}

int DoublyLinkedQueue::peekRear() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    return rear->data;
}

Node* DoublyLinkedQueue::findMax() const {
    if (isEmpty()) return nullptr;

    Node* current = front;
    Node* maxNode = front;

    while (current) {
        if (current->data > maxNode->data) {
            maxNode = current;
        }
        current = current->next;
    }

    return maxNode;
}

Node* DoublyLinkedQueue::findMin() const {
    if (isEmpty()) return nullptr;

    Node* current = front;
    Node* minNode = front;

    while (current) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }

    return minNode;
}

DoublyLinkedQueue* DoublyLinkedQueue::getElementsBetween(Node* start, Node* end) const {
    DoublyLinkedQueue* result = new DoublyLinkedQueue();

    if (!start || !end) return result;

    Node* current = start;

    while (current && current != end) {
        current = current->next;
    }

    if (current == end) {
        current = start;
        while (true) {
            result->enqueue(current->data);
            if (current == end || !current) break;
            current = current->next;
        }
    } else {
        current = end;
        while (true) {
            result->enqueue(current->data);
            if (current == start || !current) break;
            current = current->next;
        }
    }

    return result;
}

DoublyLinkedQueue* DoublyLinkedQueue::getElementsOutside(Node* start, Node* end) const {
    DoublyLinkedQueue* result = new DoublyLinkedQueue();

    if (!start || !end) {
        return result;
    }

    int cnt = 0;

    Node* current = front;
    bool pr = false;

    while (current) {
        if (current == start || current == end) {
            if (cnt == 1)
                pr = true;
            cnt++;
        }

        if ((cnt == 0 || cnt == 2) && !pr) {
            result->enqueue(current->data);
        }

        pr = false;
        current = current->next;
    }

    return result;
}

void DoublyLinkedQueue::makeCircular() {
    if (size <= 1) return;

    rear->next = front;
    front->prev = rear;
}

bool DoublyLinkedQueue::isCircular() const {
    if (isEmpty()) return false;

    return rear->next != nullptr;
}

QVector<int> DoublyLinkedQueue::toVector() const {
    QVector<int> vec;

    if (isCircular()) {
        if (isEmpty()) return vec;

        Node* current = front;
        do {
            vec.append(current->data);
            current = current->next;
        } while (current != front);
    } else {
        Node* current = front;
        while (current) {
            vec.append(current->data);
            current = current->next;
        }
    }

    return vec;
}
