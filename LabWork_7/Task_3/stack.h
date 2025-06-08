#ifndef STACK_H
#define STACK_H

#include <QString>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int d);
    };

    Node* top;
    int size;

public:
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    bool isEmpty() const;
    int getSize() const;
    int peek() const;
    QString toString() const;
    int findMin() const;
};

#endif // STACK_H
