#include "bst.h"
#include <stdexcept>

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear(root);
}

void BST::clear(Node* node) {
    if (node) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool BST::isEmpty() const {
    return root == nullptr;
}

BST::Node* BST::find(Node* node, int value) const {
    if (!node) return nullptr;
    if (value == node->data) return node;
    if (value < node->data) return find(node->left, value);
    return find(node->right, value);
}

bool BST::find(int value) const {
    return find(root, value) != nullptr;
}

BST::Node* BST::findMin(Node* node) const {
    if (!node) return nullptr;
    while (node->left) node = node->left;
    return node;
}

int BST::findMin() const {
    Node* minNode = findMin(root);
    if (!minNode) throw std::runtime_error("Tree is empty");
    return minNode->data;
}

BST::Node* BST::findMax(Node* node) const {
    if (!node) return nullptr;
    while (node->right) node = node->right;
    return node;
}

int BST::findMax() const {
    Node* maxNode = findMax(root);
    if (!maxNode) throw std::runtime_error("Tree is empty");
    return maxNode->data;
}

void BST::traverseInOrder(Node* node, QVector<int>& result) const {
    if (node) {
        traverseInOrder(node->left, result);
        result.append(node->data);
        traverseInOrder(node->right, result);
    }
}

void BST::traversePreOrder(Node* node, QVector<int>& result) const {
    if (node) {
        result.append(node->data);
        traversePreOrder(node->left, result);
        traversePreOrder(node->right, result);
    }
}

void BST::traversePostOrder(Node* node, QVector<int>& result) const {
    if (node) {
        traversePostOrder(node->left, result);
        traversePostOrder(node->right, result);
        result.append(node->data);
    }
}

QVector<int> BST::traverse(int order) const {
    QVector<int> result;
    switch (order) {
    case 0: traverseInOrder(root, result); break;
    case 1: traversePreOrder(root, result); break;
    case 2: traversePostOrder(root, result); break;
    }
    return result;
}

BST::Node* BST::insert(Node* node, Node* parent, int value) {
    if (!node) return new Node(value, parent);
    if (value < node->data) {
        node->left = insert(node->left, node, value);
    } else if (value > node->data) {
        node->right = insert(node->right, node, value);
    }
    return node;
}

bool BST::add(int value) {
    if (find(value)) return false;
    root = insert(root, nullptr, value);
    return true;
}

BST::Node* BST::remove(Node* node, int value) {
    if (!node) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (!node->left && !node->right) {
            delete node;
            return nullptr;
        } else if (!node->left) {
            Node* temp = node->right;
            temp->parent = node->parent;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            temp->parent = node->parent;
            delete node;
            return temp;
        } else {
            Node* successor = findMin(node->right);
            node->data = successor->data;
            node->right = remove(node->right, successor->data);
        }
    }
    return node;
}

bool BST::remove(int value) {
    if (!find(value)) return false;
    root = remove(root, value);
    return true;
}

BST::Node* BST::findLCA(Node* node, int value1, int value2) const {
    if (!node) return nullptr;

    if (node->data > value1 && node->data > value2) {
        return findLCA(node->left, value1, value2);
    }
    if (node->data < value1 && node->data < value2) {
        return findLCA(node->right, value1, value2);
    }
    return node;
}

int BST::findLCA(int value1, int value2) const {
    Node* lca = findLCA(root, value1, value2);
    if (!lca) throw std::runtime_error("LCA not found");
    return lca->data;
}

bool BST::insertSubtree(Node* parent, Node* subtree) {
    if (!parent || !subtree) return false;

    if (subtree->data < parent->data) {
        if (parent->left) return false;
        parent->left = subtree;
    } else {
        if (parent->right) return false;
        parent->right = subtree;
    }
    subtree->parent = parent;
    return true;
}

bool BST::insertSubtree(int parentValue, BST& subtree) {
    Node* parentNode = find(root, parentValue);
    if (!parentNode || !subtree.root) return false;
    return insertSubtree(parentNode, subtree.root);
}

bool BST::insertBranch(Node* parent, Node* branch, bool asLeftChild) {
    if (!parent || !branch) return false;

    if (asLeftChild) {
        if (parent->left) return false;
        parent->left = branch;
    } else {
        if (parent->right) return false;
        parent->right = branch;
    }
    branch->parent = parent;
    return true;
}

bool BST::insertBranch(int parentValue, BST& branch, bool asLeftChild) {
    Node* parentNode = find(root, parentValue);
    if (!parentNode || !branch.root) return false;
    return insertBranch(parentNode, branch.root, asLeftChild);
}

bool BST::insertAtPosition(Node* parent, Node* newNode, bool asLeftChild) {
    if (!parent || !newNode) return false;

    if (asLeftChild) {
        if (parent->left) return false;
        parent->left = newNode;
    } else {
        if (parent->right) return false;
        parent->right = newNode;
    }
    newNode->parent = parent;
    return true;
}

bool BST::insertAtPosition(int parentValue, int value, bool asLeftChild) {
    Node* parentNode = find(root, parentValue);
    if (!parentNode) return false;

    if (find(value)) return false;

    Node* newNode = new Node(value);
    return insertAtPosition(parentNode, newNode, asLeftChild);
}

bool BST::deleteSubtree(int parentValue) {
    Node* parentNode = find(root, parentValue);
    if (!parentNode) return false;

    if (parentNode == root) {
        clear(root);
        root = nullptr;
    } else {
        Node* parent = parentNode->parent;
        if (parent->left == parentNode) {
            clear(parent->left);
            parent->left = nullptr;
        } else {
            clear(parent->right);
            parent->right = nullptr;
        }
    }
    return true;
}

bool BST::deleteBranch(int parentValue, bool leftBranch) {
    Node* parentNode = find(root, parentValue);
    if (!parentNode) return false;

    if (leftBranch) {
        if (!parentNode->left) return false;
        clear(parentNode->left);
        parentNode->left = nullptr;
    } else {
        if (!parentNode->right) return false;
        clear(parentNode->right);
        parentNode->right = nullptr;
    }
    return true;
}

QString BST::getTreeStructure() const {
    if (!root) return "Tree is empty";
    return "Binary Search Tree:\n" + buildTreeString(root, 0);
}

QString BST::buildTreeString(Node* node, int level) const {
    if (!node) return "";

    QString result;
    QString indent(level * 4, ' ');

    result += indent;
    if (level > 0) result += "├── ";
    result += QString::number(node->data) + "\n";

    if (node->left || node->right) {
        result += buildTreeString(node->left, level + 1);
        result += buildTreeString(node->right, level + 1);
    }

    return result;
}
