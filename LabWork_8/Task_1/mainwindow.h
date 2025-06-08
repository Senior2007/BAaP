#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QRadioButton>
#include <QLineEdit>
#include <QStatusBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "bst.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onRemoveButtonClicked();
    void onFindButtonClicked();
    void onTraverseButtonClicked();
    void onLCAButtonClicked();
    void onInsertSubtreeButtonClicked();
    void onInsertBranchButtonClicked();
    void onInsertAtPositionButtonClicked();
    void onDeleteSubtreeButtonClicked();
    void onDeleteBranchButtonClicked();
    void onClearButtonClicked();

private:
    void setupUI();
    void updateTreeView();

    BST bst;
    QTextEdit *treeView;
    QSpinBox *valueSpinBox;
    QSpinBox *parentValueSpinBox;
    QSpinBox *value1SpinBox;
    QSpinBox *value2SpinBox;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *findButton;
    QPushButton *traverseButton;
    QPushButton *lcaButton;
    QPushButton *insertSubtreeButton;
    QPushButton *insertBranchButton;
    QPushButton *insertAtPositionButton;
    QPushButton *deleteSubtreeButton;
    QPushButton *deleteBranchButton;
    QPushButton *clearButton;
    QRadioButton *leftBranchRadio;
    QRadioButton *rightBranchRadio;
    QLineEdit *subtreeValuesEdit;
    QLineEdit *branchValuesEdit;
};

#endif // MAINWINDOW_H
