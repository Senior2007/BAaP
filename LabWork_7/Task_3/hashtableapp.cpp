#include "hashtableapp.h"
#include <QRandomGenerator>
#include <QTime>

HashTableApp::HashTableApp(QWidget* parent) : QWidget(parent), hashTable(10) {
    setWindowTitle("Hash Table Application");
    resize(600, 500);
    setupUI();
    createNewTable();
}

void HashTableApp::setupUI() {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    QLabel* title = new QLabel("Hash Table with Stacks", this);
    title->setStyleSheet("font-size: 18px; font-weight: bold; margin-bottom: 10px;");
    title->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(title);

    output = new QTextEdit(this);
    output->setReadOnly(true);
    output->setStyleSheet("font-family: monospace;");
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(output);
    scrollArea->setWidgetResizable(true);
    mainLayout->addWidget(scrollArea);

    QGridLayout* buttonGrid = new QGridLayout();

    QPushButton* createTableBtn = new QPushButton("Create New Table", this);
    QPushButton* addRandomBtn = new QPushButton("Add Random Key", this);
    QPushButton* findMinStackBtn = new QPushButton("Find Stack with Min Key", this);
    QPushButton* clearTableBtn = new QPushButton("Clear Table", this);
    QPushButton* removeBtn = new QPushButton("Remove Key", this);
    QPushButton* containsBtn = new QPushButton("Check Contains Key", this);

    buttonGrid->addWidget(createTableBtn, 0, 0);
    buttonGrid->addWidget(addRandomBtn, 0, 1);
    buttonGrid->addWidget(findMinStackBtn, 1, 0);
    buttonGrid->addWidget(clearTableBtn, 1, 1);
    buttonGrid->addWidget(removeBtn, 2, 0);
    buttonGrid->addWidget(containsBtn, 2, 1);

    mainLayout->addLayout(buttonGrid);

    connect(createTableBtn, &QPushButton::clicked, this, &HashTableApp::createNewTable);
    connect(addRandomBtn, &QPushButton::clicked, this, &HashTableApp::addRandomKey);
    connect(findMinStackBtn, &QPushButton::clicked, this, &HashTableApp::findStackWithMinKey);
    connect(clearTableBtn, &QPushButton::clicked, this, &HashTableApp::clearTable);
    connect(removeBtn, &QPushButton::clicked, this, &HashTableApp::removeKey);
    connect(containsBtn, &QPushButton::clicked, this, &HashTableApp::checkContainsKey);
}

void HashTableApp::createNewTable() {
    hashTable.clear();
    for (int i = 0; i < 20; ++i) {
        hashTable.insert(QRandomGenerator::global()->bounded(-100, 100));
    }
    updateOutput();
}

void HashTableApp::addRandomKey() {
    int randomKey = QRandomGenerator::global()->bounded(-100, 100);
    hashTable.insert(randomKey);
    updateOutput();
    output->append(QString("Added random key: %1").arg(randomKey));
}

void HashTableApp::findStackWithMinKey() {
    try {
        int stackIndex = hashTable.findStackWithMinKey();
        if (stackIndex != -1) {
            output->append(QString("\nStack with minimum key is stack #%1").arg(stackIndex));
            output->append(QString("Stack contents: %1").arg(hashTable.getStack(stackIndex)->toString()));
            output->append(QString("Minimum value: %1").arg(hashTable.getStack(stackIndex)->findMin()));
        } else {
            output->append("\nAll stacks are empty!");
        }
    } catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void HashTableApp::clearTable() {
    hashTable.clear();
    updateOutput();
    output->append("Table cleared");
}

void HashTableApp::removeKey() {
    bool ok;
    int key = QInputDialog::getInt(this, "Remove Key", "Enter key to remove:", 0, -1000, 1000, 1, &ok);
    if (ok) {
        if (hashTable.remove(key)) {
            output->append(QString("Key %1 removed successfully").arg(key));
        } else {
            output->append(QString("Key %1 not found").arg(key));
        }
        updateOutput();
    }
}

void HashTableApp::checkContainsKey() {
    bool ok;
    int key = QInputDialog::getInt(this, "Check Key", "Enter key to check:", 0, -1000, 1000, 1, &ok);
    if (ok) {
        if (hashTable.contains(key)) {
            output->append(QString("Key %1 exists in the table").arg(key));
        } else {
            output->append(QString("Key %1 not found").arg(key));
        }
    }
}

void HashTableApp::updateOutput() {
    output->clear();
    output->setText(hashTable.toString());
}
