#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    heapView = new QTextEdit();
    heapView->setReadOnly(true);
    heapView->setFont(QFont("Courier New", 12));
    layout->addWidget(heapView);

    valueSpinBox = new QSpinBox();
    valueSpinBox->setRange(-1000, 1000);
    layout->addWidget(valueSpinBox);

    insertButton = new QPushButton("Insert");
    extractMaxButton = new QPushButton("Extract Max");

    layout->addWidget(insertButton);
    layout->addWidget(extractMaxButton);

    connect(insertButton, &QPushButton::clicked, this, &MainWindow::onInsertClicked);
    connect(extractMaxButton, &QPushButton::clicked, this, &MainWindow::onExtractMaxClicked);

    setCentralWidget(centralWidget);
    resize(400, 300);
    setWindowTitle("Binary Heap Visualizer");
    updateHeapView();
}

void MainWindow::onInsertClicked() {
    int value = valueSpinBox->value();
    heap.insert(value);
    updateHeapView();
}

void MainWindow::onExtractMaxClicked() {
    try {
        int max = heap.extractMax();
        QMessageBox::information(this, "Extracted", QString("Max value: %1").arg(max));
        updateHeapView();
    } catch (const std::runtime_error& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::updateHeapView() {
    heapView->setText(QString("Heap (size: %1):\n").arg(heap.size()) + heap.toString());
}
