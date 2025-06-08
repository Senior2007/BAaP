#include "stack.h"

Stack::Node::Node(int d) : data(d), next(nullptr) {}

Stack::Stack() : top(nullptr), size(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    size++;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack underflow");
    }
    Node* temp = top;
    int popped = top->data;
    top = top->next;
    delete temp;
    size--;
    return popped;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

int Stack::getSize() const {
    return size;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return top->data;
}

QString Stack::toString() const {
    QString result;
    Node* current = top;
    while (current != nullptr) {
        result += QString::number(current->data);
        if (current->next != nullptr) {
            result += " -> ";
        }
        current = current->next;
    }
    return result;
}

int Stack::findMin() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    int min = top->data;
    Node* current = top->next;
    while (current != nullptr) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}
