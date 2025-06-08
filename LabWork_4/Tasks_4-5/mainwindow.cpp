#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    fillData();
    setupUi();
    displayMatrices();
    this->setMinimumSize(800, 300);
    setWindowTitle("Показ матриц");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUi()
{
    tableWidget = new QTableWidget(this);
    setCentralWidget(tableWidget);
    setWindowTitle("Matrix Viewer");
}

void MainWindow::displayMatrices()
{
    if (data.empty()) {
        return;
    }

    int rowCount = data.size();
    int colCount1 = data[0].first.size();
    int colCount2 = data[0].second.size();

    for (int i = 0; i < rowCount; i++) {
        int len = data[i].first.size();
        int len2 = data[i].second.size();
        colCount1 = std::max(colCount1, len);
        colCount2 = std::max(colCount2, len2);
    }

    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(colCount1 + colCount2);
    QStringList headers;
    for (int i = 0; i < colCount1; ++i) {
        headers << QString("Matrix 1, Col %1").arg(i + 1);
    }
    for (int i = 0; i < colCount2; ++i) {
        headers << QString("Matrix 2, Col %1").arg(i + 1);
    }
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < rowCount; ++i) {
        int len1 = data[i].first.size();
        int len2 = data[i].second.size();

        for (int j = 0; j < colCount1; ++j) {
            if (j < len1) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[i].first[j]));
                tableWidget->setItem(i, j, item);
            } else {
                QTableWidgetItem *item = new QTableWidgetItem("-");
                tableWidget->setItem(i, j, item);
            }
        }
        for (int j = 0; j < colCount2; ++j) {
            if (j < len2) {
                QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[i].second[j].first) + ", " +
                                                              QString::number(data[i].second[j].second));
                tableWidget->setItem(i, colCount1 + j, item);
            } else {
                QTableWidgetItem *item = new QTableWidgetItem("-");
                tableWidget->setItem(i, colCount1 + j, item);
            }
        }
    }
}


void MainWindow::fillData()
{
    Vector<int> vecInt1 = {1, 2, 3};
    Vector<int> vecInt2 = {4, 5, 6};
    Vector<int> vecInt3 = {7, 8, 9};
    //vecInt1.erase(vecInt1.begin() + 1);
    vecInt2.push_back(10);
    //vecInt3[0] = 11;
    //vecInt2.resize(1, 2);
    //vecInt1.insert(0, 10);
    //vecInt2.emplace(1, 88);
    //vecInt3.erase(vecInt3.begin() + 1, vecInt3.end());
    //vecInt1.at(2) = 900;

    Vector<pair<int, double>> vecPair1 = {{1, 1.1}, {2, 2.2}, {3, 3.3}};
    Vector<pair<int, double>> vecPair2 = {{4, 4.4}, {5, 5.5}, {6, 6.6}};
    Vector<pair<int, double>> vecPair3 = {{7, 7.7}, {8, 8.8}, {9, 9.9}};
    //vecPair3.pop_back();
    //vecPair2.assign(2, {10, 10.10});
    //vecPair1.insert(2, {10, 10.10});
    //vecPair3.emplace_back(100, 34.234);

    data.push_back({vecInt1, vecPair1});
    data.push_back({vecInt2, vecPair2});
    data.push_back({vecInt3, vecPair3});
}
