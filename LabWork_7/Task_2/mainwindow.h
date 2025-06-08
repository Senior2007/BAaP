#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QTreeWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "bstree.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadFromTableClicked();
    void onInsertClicked();
    void onFindClicked();
    void onRemoveClicked();
    void onPreOrderClicked();
    void onInOrderClicked();
    void onPostOrderClicked();
    void onCountCharactersClicked();

private:
    void setupUI();
    void setupConnections();
    QVector<QPair<int, QString>> getTableData() const;
    void updateTreeView();
    void logMessage(const QString& message);

    QTableWidget *tableWidget;
    QTreeWidget *treeWidget;
    QTextEdit *textOutput;

    QLineEdit *editKey;
    QLineEdit *editData;
    QLineEdit *editSearchKey;
    QLineEdit *editRemoveKey;


    QPushButton *btnLoadFromTable;
    QPushButton *btnInsert;
    QPushButton *btnFind;
    QPushButton *btnRemove;
    QPushButton *btnPreOrder;
    QPushButton *btnInOrder;
    QPushButton *btnPostOrder;
    QPushButton *btnCountChars;

    CharacterCountBSTree tree;
};

#endif // MAINWINDOW_H
