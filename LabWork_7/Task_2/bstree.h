#ifndef BSTREE_H
#define BSTREE_H

#include <QString>
#include <QVector>
#include <QTreeWidget>

struct TreeNode {
    int key;
    QString data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int k, const QString& d) : key(k), data(d), left(nullptr), right(nullptr), height(1) {}
};

class BSTree {
protected:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, int key, const QString& data);
    TreeNode* findHelper(TreeNode* node, int key) const;
    TreeNode* removeHelper(TreeNode* node, int key);
    TreeNode* minValueNode(TreeNode* node) const;
    void destroyTree(TreeNode* node);

    void preOrderHelper(TreeNode* node, QString& result) const;
    void inOrderHelper(TreeNode* node, QString& result) const;
    void postOrderHelper(TreeNode* node, QString& result) const;

    int height(TreeNode* node) const;
    int balanceFactor(TreeNode* node) const;
    void updateHeight(TreeNode* node);
    TreeNode* rotateRight(TreeNode* y);
    TreeNode* rotateLeft(TreeNode* x);
    TreeNode* balance(TreeNode* node);

public:
    BSTree();
    virtual ~BSTree();

    void insert(int key, const QString& data);
    bool contains(int key) const;
    QString find(int key) const;
    void remove(int key);
    void clear();
    bool isEmpty() const;

    QString preOrderTraversal() const;
    QString inOrderTraversal() const;
    QString postOrderTraversal() const;

    void loadFromGrid(const QVector<QPair<int, QString>>& data);

    void populateTreeView(QTreeWidget* treeWidget) const;
    void populateTreeViewHelper(QTreeWidgetItem* parentItem, TreeNode* node) const;
};

class CharacterCountBSTree : public BSTree {
public:
    int totalCharacters() const;

private:
    int totalCharactersHelper(TreeNode* node) const;
};

#endif // BSTREE_H
