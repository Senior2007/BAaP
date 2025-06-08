#include "mainwindow.h"
#include <QHeaderView>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    setupConnections();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(2);
    tableWidget->setHorizontalHeaderLabels({"Key", "Data"});
    tableWidget->setRowCount(5);

    tableWidget->setItem(0, 0, new QTableWidgetItem("1000"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("Ivanov Ivan"));

    tableWidget->setItem(1, 0, new QTableWidgetItem("1005"));
    tableWidget->setItem(1, 1, new QTableWidgetItem("Lozhachnik Ivan"));

    tableWidget->setItem(2, 0, new QTableWidgetItem("1010"));
    tableWidget->setItem(2, 1, new QTableWidgetItem("Borsuk Daniil"));

    tableWidget->setItem(3, 0, new QTableWidgetItem("1015"));
    tableWidget->setItem(3, 1, new QTableWidgetItem("Smirnova Olga"));

    tableWidget->setItem(4, 0, new QTableWidgetItem("1020"));
    tableWidget->setItem(4, 1, new QTableWidgetItem("Ovechkin Alex"));

    treeWidget = new QTreeWidget(this);
    treeWidget->setHeaderLabel("Binary Search Tree");

    textOutput = new QTextEdit(this);
    textOutput->setReadOnly(true);

    QHBoxLayout *insertLayout = new QHBoxLayout();
    QLabel *lblKey = new QLabel("Key:", this);
    editKey = new QLineEdit(this);
    editKey->setPlaceholderText("Enter integer key");
    QLabel *lblData = new QLabel("Data:", this);
    editData = new QLineEdit(this);
    editData->setPlaceholderText("Enter data string");
    btnInsert = new QPushButton("Insert", this);
    insertLayout->addWidget(lblKey);
    insertLayout->addWidget(editKey);
    insertLayout->addWidget(lblData);
    insertLayout->addWidget(editData);
    insertLayout->addWidget(btnInsert);

    QHBoxLayout *searchLayout = new QHBoxLayout();
    QLabel *lblSearchKey = new QLabel("Search Key:", this);
    editSearchKey = new QLineEdit(this);
    editSearchKey->setPlaceholderText("Enter key to search");
    btnFind = new QPushButton("Find", this);
    searchLayout->addWidget(lblSearchKey);
    searchLayout->addWidget(editSearchKey);
    searchLayout->addWidget(btnFind);

    QHBoxLayout *removeLayout = new QHBoxLayout();
    QLabel *lblRemoveKey = new QLabel("Remove Key:", this);
    editRemoveKey = new QLineEdit(this);
    editRemoveKey->setPlaceholderText("Enter key to remove");
    btnRemove = new QPushButton("Remove", this);
    removeLayout->addWidget(lblRemoveKey);
    removeLayout->addWidget(editRemoveKey);
    removeLayout->addWidget(btnRemove);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    btnLoadFromTable = new QPushButton("Load from Table", this);
    btnPreOrder = new QPushButton("Pre-order", this);
    btnInOrder = new QPushButton("In-order", this);
    btnPostOrder = new QPushButton("Post-order", this);
    btnCountChars = new QPushButton("Count Characters", this);
    buttonLayout->addWidget(btnLoadFromTable);
    buttonLayout->addWidget(btnPreOrder);
    buttonLayout->addWidget(btnInOrder);
    buttonLayout->addWidget(btnPostOrder);
    buttonLayout->addWidget(btnCountChars);

    mainLayout->addWidget(new QLabel("Input Table:", this));
    mainLayout->addWidget(tableWidget);
    mainLayout->addWidget(new QLabel("Tree Visualization:", this));
    mainLayout->addWidget(treeWidget);
    mainLayout->addLayout(insertLayout);
    mainLayout->addLayout(searchLayout);
    mainLayout->addLayout(removeLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(new QLabel("Output:", this));
    mainLayout->addWidget(textOutput);

    setCentralWidget(centralWidget);

    setWindowTitle("Binary Search Tree Demo");
    resize(800, 600);
}

void MainWindow::setupConnections()
{
    connect(btnLoadFromTable, &QPushButton::clicked, this, &MainWindow::onLoadFromTableClicked);
    connect(btnInsert, &QPushButton::clicked, this, &MainWindow::onInsertClicked);
    connect(btnFind, &QPushButton::clicked, this, &MainWindow::onFindClicked);
    connect(btnRemove, &QPushButton::clicked, this, &MainWindow::onRemoveClicked);
    connect(btnPreOrder, &QPushButton::clicked, this, &MainWindow::onPreOrderClicked);
    connect(btnInOrder, &QPushButton::clicked, this, &MainWindow::onInOrderClicked);
    connect(btnPostOrder, &QPushButton::clicked, this, &MainWindow::onPostOrderClicked);
    connect(btnCountChars, &QPushButton::clicked, this, &MainWindow::onCountCharactersClicked);
}

void MainWindow::onLoadFromTableClicked()
{
    QVector<QPair<int, QString>> data = getTableData();
    tree.loadFromGrid(data);
    updateTreeView();
    logMessage("Data loaded from table to tree");
}

void MainWindow::onInsertClicked()
{
    bool ok;
    int key = editKey->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Invalid key value");
        return;
    }

    QString data = editData->text();
    if (data.isEmpty()) {
        QMessageBox::warning(this, "Error", "Data cannot be empty");
        return;
    }

    tree.insert(key, data);
    updateTreeView();
    logMessage(QString("Inserted: Key=%1, Data=%2").arg(key).arg(data));
}

void MainWindow::onFindClicked()
{
    bool ok;
    int key = editSearchKey->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Invalid key value");
        return;
    }

    QString result = tree.find(key);
    if (result.isEmpty()) {
        logMessage(QString("Key %1 not found").arg(key));
    } else {
        logMessage(QString("Found: Key=%1, Data=%2").arg(key).arg(result));
    }
}

void MainWindow::onRemoveClicked()
{
    bool ok;
    int key = editRemoveKey->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Error", "Invalid key value");
        return;
    }

    if (tree.contains(key)) {
        tree.remove(key);
        updateTreeView();
        logMessage(QString("Removed node with key %1").arg(key));
    } else {
        logMessage(QString("Key %1 not found for removal").arg(key));
    }
}

void MainWindow::onPreOrderClicked()
{
    QString traversal = tree.preOrderTraversal();
    textOutput->setPlainText("Pre-order traversal:\n" + traversal);
}

void MainWindow::onInOrderClicked()
{
    QString traversal = tree.inOrderTraversal();
    textOutput->setPlainText("In-order traversal:\n" + traversal);
}

void MainWindow::onPostOrderClicked()
{
    QString traversal = tree.postOrderTraversal();
    textOutput->setPlainText("Post-order traversal:\n" + traversal);
}

void MainWindow::onCountCharactersClicked()
{
    int total = tree.totalCharacters();
    logMessage(QString("Total characters in all nodes: %1").arg(total));
}

QVector<QPair<int, QString>> MainWindow::getTableData() const
{
    QVector<QPair<int, QString>> data;
    for (int i = 0; i < tableWidget->rowCount(); ++i) {
        QTableWidgetItem* keyItem = tableWidget->item(i, 0);
        QTableWidgetItem* dataItem = tableWidget->item(i, 1);

        if (keyItem && dataItem && !keyItem->text().isEmpty()) {
            bool ok;
            int key = keyItem->text().toInt(&ok);
            if (ok) {
                data.append(qMakePair(key, dataItem->text()));
            }
        }
    }
    return data;
}

void MainWindow::updateTreeView()
{
    tree.populateTreeView(treeWidget);
}

void MainWindow::logMessage(const QString& message)
{
    textOutput->append(message);
}
