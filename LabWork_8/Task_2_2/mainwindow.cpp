#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
}

void MainWindow::setupUI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    display = new QTextEdit();
    display->setReadOnly(true);
    mainLayout->addWidget(display);

    input = new QSpinBox();
    input->setRange(-1000, 1000);
    mainLayout->addWidget(input);

    QHBoxLayout *btnLayout = new QHBoxLayout();

    insertBtn = new QPushButton("Insert");
    extractBtn = new QPushButton("Extract Max");
    showBtn = new QPushButton("Show Heap");

    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(extractBtn);
    btnLayout->addWidget(showBtn);

    mainLayout->addLayout(btnLayout);

    connect(insertBtn, &QPushButton::clicked, this, &MainWindow::insertValue);
    connect(extractBtn, &QPushButton::clicked, this, &MainWindow::extractMax);
    connect(showBtn, &QPushButton::clicked, this, &MainWindow::showHeap);

    setCentralWidget(centralWidget);
    resize(400, 300);
    setWindowTitle("Binary Heap Demo");
}

void MainWindow::insertValue()
{
    int value = input->value();
    heap.insert(value);
    display->append(QString("Inserted: %1").arg(value));
}

void MainWindow::extractMax()
{
    try {
        int max = heap.extractMax();
        display->append(QString("Extracted max: %1").arg(max));
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::showHeap()
{
    display->append("Current heap: " + heap.toString());
}
