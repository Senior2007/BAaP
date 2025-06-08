#ifndef BST_H
#define BST_H

#include <QVector>
#include <QString>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node* parent;

        Node(int val, Node* p = nullptr) : data(val), left(nullptr), right(nullptr), parent(p) {}
    };

    Node* root;

    void clear(Node* node);
    Node* find(Node* node, int value) const;
    Node* findMin(Node* node) const;
    Node* findMax(Node* node) const;
    void traverseInOrder(Node* node, QVector<int>& result) const;
    void traversePreOrder(Node* node, QVector<int>& result) const;
    void traversePostOrder(Node* node, QVector<int>& result) const;
    Node* insert(Node* node, Node* parent, int value);
    Node* remove(Node* node, int value);
    Node* findLCA(Node* node, int value1, int value2) const;
    bool insertSubtree(Node* parent, Node* subtree);
    bool insertBranch(Node* parent, Node* branch, bool asLeftChild);
    bool insertAtPosition(Node* parent, Node* newNode, bool asLeftChild);
    QString buildTreeString(Node* node, int level) const;

public:
    BST();
    ~BST();

    bool isEmpty() const;
    bool add(int value);
    bool remove(int value);
    bool find(int value) const;
    QVector<int> traverse(int order = 0) const;
    int findMin() const;
    int findMax() const;
    int findLCA(int value1, int value2) const;
    bool insertSubtree(int parentValue, BST& subtree);
    bool insertBranch(int parentValue, BST& branch, bool asLeftChild);
    bool insertAtPosition(int parentValue, int value, bool asLeftChild);
    bool deleteSubtree(int parentValue);
    bool deleteBranch(int parentValue, bool leftBranch);
    QString getTreeStructure() const;
};

#endif // BST_H
