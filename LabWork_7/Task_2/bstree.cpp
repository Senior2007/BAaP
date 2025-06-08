#include "bstree.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>

BSTree::BSTree() : root(nullptr) {}

BSTree::~BSTree() {
    clear();
}

void BSTree::clear() {
    destroyTree(root);
    root = nullptr;
}

void BSTree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

bool BSTree::isEmpty() const {
    return root == nullptr;
}

void BSTree::insert(int key, const QString& data) {
    root = insertHelper(root, key, data);
}

TreeNode* BSTree::insertHelper(TreeNode* node, int key, const QString& data) {
    if (!node) {
        return new TreeNode(key, data);
    }

    if (key < node->key) {
        node->left = insertHelper(node->left, key, data);
    } else if (key > node->key) {
        node->right = insertHelper(node->right, key, data);
    } else {
        node->data = data;
        return node;
    }

    return balance(node);
}

bool BSTree::contains(int key) const {
    return findHelper(root, key) != nullptr;
}

QString BSTree::find(int key) const {
    TreeNode* node = findHelper(root, key);
    return node ? node->data : QString();
}

TreeNode* BSTree::findHelper(TreeNode* node, int key) const {
    if (!node) return nullptr;

    if (key < node->key) {
        return findHelper(node->left, key);
    } else if (key > node->key) {
        return findHelper(node->right, key);
    } else {
        return node;
    }
}

void BSTree::remove(int key) {
    root = removeHelper(root, key);
}

TreeNode* BSTree::removeHelper(TreeNode* node, int key) {
    if (!node) return nullptr;

    if (key < node->key) {
        node->left = removeHelper(node->left, key);
    } else if (key > node->key) {
        node->right = removeHelper(node->right, key);
    } else {
        if (!node->left || !node->right) {
            TreeNode* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            TreeNode* temp = minValueNode(node->right);
            node->key = temp->key;
            node->data = temp->data;
            node->right = removeHelper(node->right, temp->key);
        }
    }

    if (!node) return node;

    return balance(node);
}

TreeNode* BSTree::minValueNode(TreeNode* node) const {
    TreeNode* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

QString BSTree::preOrderTraversal() const {
    QString result;
    preOrderHelper(root, result);
    return result;
}

void BSTree::preOrderHelper(TreeNode* node, QString& result) const {
    if (node) {
        result += QString("Key: %1, Data: %2\n").arg(node->key).arg(node->data);
        preOrderHelper(node->left, result);
        preOrderHelper(node->right, result);
    }
}

QString BSTree::inOrderTraversal() const {
    QString result;
    inOrderHelper(root, result);
    return result;
}

void BSTree::inOrderHelper(TreeNode* node, QString& result) const {
    if (node) {
        inOrderHelper(node->left, result);
        result += QString("Key: %1, Data: %2\n").arg(node->key).arg(node->data);
        inOrderHelper(node->right, result);
    }
}

QString BSTree::postOrderTraversal() const {
    QString result;
    postOrderHelper(root, result);
    return result;
}

void BSTree::postOrderHelper(TreeNode* node, QString& result) const {
    if (node) {
        postOrderHelper(node->left, result);
        postOrderHelper(node->right, result);
        result += QString("Key: %1, Data: %2\n").arg(node->key).arg(node->data);
    }
}

void BSTree::loadFromGrid(const QVector<QPair<int, QString>>& data) {
    clear();
    for (const auto& pair : data) {
        insert(pair.first, pair.second);
    }
}

int BSTree::height(TreeNode* node) const {
    return node ? node->height : 0;
}

int BSTree::balanceFactor(TreeNode* node) const {
    return height(node->right) - height(node->left);
}

void BSTree::updateHeight(TreeNode* node) {
    int hl = height(node->left);
    int hr = height(node->right);
    node->height = (hl > hr ? hl : hr) + 1;
}

TreeNode* BSTree::rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    y->left = x->right;
    x->right = y;

    updateHeight(y);
    updateHeight(x);

    return x;
}

TreeNode* BSTree::rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    x->right = y->left;
    y->left = x;

    updateHeight(x);
    updateHeight(y);

    return y;
}

TreeNode* BSTree::balance(TreeNode* node) {
    updateHeight(node);

    int bf = balanceFactor(node);

    if (bf == 2) {
        if (balanceFactor(node->right) < 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    if (bf == -2) {
        if (balanceFactor(node->left) > 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }

    return node;
}

void BSTree::populateTreeView(QTreeWidget* treeWidget) const {
    treeWidget->clear();
    if (root) {
        QTreeWidgetItem* item = new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(root->key).arg(root->data));
        populateTreeViewHelper(item, root->left);
        populateTreeViewHelper(item, root->right);
        treeWidget->addTopLevelItem(item);
    }
}

void BSTree::populateTreeViewHelper(QTreeWidgetItem* parentItem, TreeNode* node) const {
    if (node) {
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->data));
        parentItem->addChild(item);

        populateTreeViewHelper(item, node->left);
        populateTreeViewHelper(item, node->right);
    }
}

int CharacterCountBSTree::totalCharacters() const {
    return totalCharactersHelper(root);
}

int CharacterCountBSTree::totalCharactersHelper(TreeNode* node) const {
    if (!node) return 0;
    return node->data.length() +
           totalCharactersHelper(node->left) +
           totalCharactersHelper(node->right);
}
