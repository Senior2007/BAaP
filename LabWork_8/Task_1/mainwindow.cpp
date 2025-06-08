#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    updateTreeView();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    treeView = new QTextEdit();
    treeView->setReadOnly(true);
    treeView->setFont(QFont("Courier New", 10));
    mainLayout->addWidget(treeView);

    QHBoxLayout *operationsLayout = new QHBoxLayout();

    QGroupBox *basicGroup = new QGroupBox("Basic Operations");
    QVBoxLayout *basicLayout = new QVBoxLayout(basicGroup);

    QHBoxLayout *valueLayout = new QHBoxLayout();
    valueLayout->addWidget(new QLabel("Value:"));
    valueSpinBox = new QSpinBox();
    valueSpinBox->setRange(-999999, 999999);
    valueLayout->addWidget(valueSpinBox);
    basicLayout->addLayout(valueLayout);

    QHBoxLayout *basicButtonsLayout = new QHBoxLayout();
    addButton = new QPushButton("Add");
    removeButton = new QPushButton("Remove");
    findButton = new QPushButton("Find");
    traverseButton = new QPushButton("Traverse");
    basicButtonsLayout->addWidget(addButton);
    basicButtonsLayout->addWidget(removeButton);
    basicButtonsLayout->addWidget(findButton);
    basicButtonsLayout->addWidget(traverseButton);
    basicLayout->addLayout(basicButtonsLayout);

    operationsLayout->addWidget(basicGroup);

    QGroupBox *advancedGroup = new QGroupBox("Advanced Operations");
    QVBoxLayout *advancedLayout = new QVBoxLayout(advancedGroup);

    QHBoxLayout *parentValueLayout = new QHBoxLayout();
    parentValueLayout->addWidget(new QLabel("Parent Value:"));
    parentValueSpinBox = new QSpinBox();
    parentValueSpinBox->setRange(-999999, 999999);
    parentValueLayout->addWidget(parentValueSpinBox);
    advancedLayout->addLayout(parentValueLayout);

    QHBoxLayout *branchRadioLayout = new QHBoxLayout();
    leftBranchRadio = new QRadioButton("Left");
    rightBranchRadio = new QRadioButton("Right");
    leftBranchRadio->setChecked(true);
    branchRadioLayout->addWidget(leftBranchRadio);
    branchRadioLayout->addWidget(rightBranchRadio);
    advancedLayout->addLayout(branchRadioLayout);

    insertAtPositionButton = new QPushButton("Insert at Position");
    advancedLayout->addWidget(insertAtPositionButton);

    subtreeValuesEdit = new QLineEdit();
    subtreeValuesEdit->setPlaceholderText("Subtree values (comma separated)");
    advancedLayout->addWidget(subtreeValuesEdit);

    insertSubtreeButton = new QPushButton("Insert Subtree");
    advancedLayout->addWidget(insertSubtreeButton);

    branchValuesEdit = new QLineEdit();
    branchValuesEdit->setPlaceholderText("Branch values (comma separated)");
    advancedLayout->addWidget(branchValuesEdit);

    insertBranchButton = new QPushButton("Insert Branch");
    advancedLayout->addWidget(insertBranchButton);

    deleteSubtreeButton = new QPushButton("Delete Subtree");
    advancedLayout->addWidget(deleteSubtreeButton);

    deleteBranchButton = new QPushButton("Delete Branch");
    advancedLayout->addWidget(deleteBranchButton);

    operationsLayout->addWidget(advancedGroup);

    QGroupBox *lcaGroup = new QGroupBox("LCA");
    QVBoxLayout *lcaLayout = new QVBoxLayout(lcaGroup);

    QHBoxLayout *value1Layout = new QHBoxLayout();
    value1Layout->addWidget(new QLabel("Value 1:"));
    value1SpinBox = new QSpinBox();
    value1SpinBox->setRange(-999999, 999999);
    value1Layout->addWidget(value1SpinBox);
    lcaLayout->addLayout(value1Layout);

    QHBoxLayout *value2Layout = new QHBoxLayout();
    value2Layout->addWidget(new QLabel("Value 2:"));
    value2SpinBox = new QSpinBox();
    value2SpinBox->setRange(-999999, 999999);
    value2Layout->addWidget(value2SpinBox);
    lcaLayout->addLayout(value2Layout);

    lcaButton = new QPushButton("Find LCA");
    lcaLayout->addWidget(lcaButton);

    clearButton = new QPushButton("Clear Tree");
    lcaLayout->addWidget(clearButton);

    operationsLayout->addWidget(lcaGroup);

    mainLayout->addLayout(operationsLayout);

    statusBar()->showMessage("Ready");

    setCentralWidget(centralWidget);
    resize(800, 600);
    setWindowTitle("Binary Search Tree Visualizer");

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddButtonClicked);
    connect(removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveButtonClicked);
    connect(findButton, &QPushButton::clicked, this, &MainWindow::onFindButtonClicked);
    connect(traverseButton, &QPushButton::clicked, this, &MainWindow::onTraverseButtonClicked);
    connect(lcaButton, &QPushButton::clicked, this, &MainWindow::onLCAButtonClicked);
    connect(insertSubtreeButton, &QPushButton::clicked, this, &MainWindow::onInsertSubtreeButtonClicked);
    connect(insertBranchButton, &QPushButton::clicked, this, &MainWindow::onInsertBranchButtonClicked);
    connect(insertAtPositionButton, &QPushButton::clicked, this, &MainWindow::onInsertAtPositionButtonClicked);
    connect(deleteSubtreeButton, &QPushButton::clicked, this, &MainWindow::onDeleteSubtreeButtonClicked);
    connect(deleteBranchButton, &QPushButton::clicked, this, &MainWindow::onDeleteBranchButtonClicked);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::onClearButtonClicked);
}

void MainWindow::updateTreeView()
{
    treeView->setText(bst.getTreeStructure());
    statusBar()->showMessage(QString("Elements in tree: %1").arg(bst.traverse().size()));
}

void MainWindow::onAddButtonClicked()
{
    int value = valueSpinBox->value();
    if (bst.add(value)) {
        updateTreeView();
        statusBar()->showMessage(QString("Added value: %1").arg(value), 2000);
    } else {
        QMessageBox::warning(this, "Warning", QString("Value %1 already exists").arg(value));
    }
}

void MainWindow::onRemoveButtonClicked()
{
    int value = valueSpinBox->value();
    if (bst.remove(value)) {
        updateTreeView();
        statusBar()->showMessage(QString("Removed value: %1").arg(value), 2000);
    } else {
        QMessageBox::warning(this, "Warning", QString("Value %1 not found").arg(value));
    }
}

void MainWindow::onFindButtonClicked()
{
    int value = valueSpinBox->value();
    if (bst.find(value)) {
        QMessageBox::information(this, "Found", QString("Value %1 exists").arg(value));
    } else {
        QMessageBox::information(this, "Not Found", QString("Value %1 not found").arg(value));
    }
}

void MainWindow::onTraverseButtonClicked()
{
    QVector<int> elements = bst.traverse();
    QString message = "Tree elements: ";
    for (int val : elements) {
        message += QString::number(val) + " ";
    }
    QMessageBox::information(this, "Traversal", message);
}

void MainWindow::onLCAButtonClicked()
{
    int value1 = value1SpinBox->value();
    int value2 = value2SpinBox->value();
    try {
        int lca = bst.findLCA(value1, value2);
        QMessageBox::information(this, "LCA",
                                 QString("LCA of %1 and %2 is %3").arg(value1).arg(value2).arg(lca));
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::onInsertSubtreeButtonClicked()
{
    int parentValue = parentValueSpinBox->value();
    BST subtree;

    QStringList values = subtreeValuesEdit->text().split(",", Qt::SkipEmptyParts);
    for (const QString& val : values) {
        bool ok;
        int num = val.trimmed().toInt(&ok);
        if (ok) subtree.add(num);
    }

    if (bst.insertSubtree(parentValue, subtree)) {
        updateTreeView();
        statusBar()->showMessage(QString("Inserted subtree under %1").arg(parentValue), 2000);
    } else {
        QMessageBox::warning(this, "Error", "Failed to insert subtree");
    }
}

void MainWindow::onInsertBranchButtonClicked()
{
    int parentValue = parentValueSpinBox->value();
    bool asLeftChild = leftBranchRadio->isChecked();
    BST branch;

    QStringList values = branchValuesEdit->text().split(",", Qt::SkipEmptyParts);
    for (const QString& val : values) {
        bool ok;
        int num = val.trimmed().toInt(&ok);
        if (ok) branch.add(num);
    }

    if (bst.insertBranch(parentValue, branch, asLeftChild)) {
        updateTreeView();
        statusBar()->showMessage(QString("Inserted %1 branch under %2")
                                     .arg(asLeftChild ? "left" : "right").arg(parentValue), 2000);
    } else {
        QMessageBox::warning(this, "Error", "Failed to insert branch");
    }
}

void MainWindow::onInsertAtPositionButtonClicked()
{
    int parentValue = parentValueSpinBox->value();
    int value = valueSpinBox->value();
    bool asLeftChild = leftBranchRadio->isChecked();

    if (bst.insertAtPosition(parentValue, value, asLeftChild)) {
        updateTreeView();
        statusBar()->showMessage(QString("Inserted %1 as %2 child of %3")
                                     .arg(value).arg(asLeftChild ? "left" : "right").arg(parentValue), 2000);
    } else {
        QMessageBox::warning(this, "Error", "Failed to insert at position");
    }
}

void MainWindow::onDeleteSubtreeButtonClicked()
{
    int parentValue = parentValueSpinBox->value();
    if (bst.deleteSubtree(parentValue)) {
        updateTreeView();
        statusBar()->showMessage(QString("Deleted subtree under %1").arg(parentValue), 2000);
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete subtree");
    }
}

void MainWindow::onDeleteBranchButtonClicked()
{
    int parentValue = parentValueSpinBox->value();
    bool leftBranch = leftBranchRadio->isChecked();

    if (bst.deleteBranch(parentValue, leftBranch)) {
        updateTreeView();
        statusBar()->showMessage(QString("Deleted %1 branch under %2")
                                     .arg(leftBranch ? "left" : "right").arg(parentValue), 2000);
    } else {
        QMessageBox::warning(this, "Error", "Failed to delete branch");
    }
}

void MainWindow::onClearButtonClicked()
{
    bst = BST();
    updateTreeView();
    statusBar()->showMessage("Tree cleared", 2000);
}
