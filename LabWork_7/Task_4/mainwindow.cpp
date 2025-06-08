#include "mainwindow.h"
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QGridLayout>
#include <QMessageBox>
#include <random>
#include <chrono>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), currentTable(nullptr), animationTimer(new QTimer(this)), currentStep(0) {
    setupUI();
    createChart();

    connect(runButton, &QPushButton::clicked, this, &MainWindow::runBenchmark);
    connect(animationTimer, &QTimer::timeout, this, &MainWindow::updateChart);

    setWindowTitle("Hash Table Benchmark");
    resize(800, 600);
}

MainWindow::~MainWindow() {
    delete currentTable;
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);

    chart = new QChart();
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    runButton = new QPushButton("Run Benchmark", this);
    tableSizeCombo = new QComboBox(this);
    tableSizeCombo->addItems({"16", "64", "128", "2048"});

    statusLabel = new QLabel("Ready", this);
    statusLabel->setAlignment(Qt::AlignCenter);

    layout->addWidget(chartView, 0, 0, 1, 2);
    layout->addWidget(tableSizeCombo, 1, 0);
    layout->addWidget(runButton, 1, 1);
    layout->addWidget(statusLabel, 2, 0, 1, 2);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}

void MainWindow::createChart() {
    series = new QLineSeries();
    series->setName("Search Time (ns)");

    chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    axisX = new QValueAxis();
    axisX->setTitleText("Load Factor");
    axisX->setRange(0, 1.0);
    axisX->setLabelFormat("%.2f");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis();
    axisY->setTitleText("Time (ns)");
    axisY->setRange(0, 1000);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setTitle("Hash Table Search Performance");
}

void MainWindow::fillHashTable(HashTable& table, int elements_count) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 1000000);

    for (int i = 0; i < elements_count; ++i) {
        int key = dist(gen);
        table.insert(key, i);
    }
}

void MainWindow::runBenchmark() {
    if (currentTable) {
        delete currentTable;
    }

    int tableSize = tableSizeCombo->currentText().toInt();
    currentTable = new HashTable(tableSize);

    int elementsToInsert = static_cast<int>(tableSize * 0.9);
    fillHashTable(*currentTable, elementsToInsert);

    statusLabel->setText(QString("Testing table size: %1, Collisions: %2")
                             .arg(tableSize)
                             .arg(currentTable->get_collisions_count()));

    benchmarkResults.clear();
    std::vector<int> keysToSearch;

    for (int i = 0; i < elementsToInsert; ++i) {
        size_t attempts;
        if (currentTable->search(i, attempts)) {
            keysToSearch.push_back(i);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1000001, 2000000);
    for (int i = 0; i < 100; ++i) {
        keysToSearch.push_back(dist(gen));
    }

    for (double lf = 0.1; lf <= 0.9; lf += 0.1) {
        currentTable->clear();
        int currentElements = static_cast<int>(tableSize * lf);
        fillHashTable(*currentTable, currentElements);

        auto start = std::chrono::high_resolution_clock::now();
        size_t totalAttempts = 0;

        for (int key : keysToSearch) {
            size_t attempts;
            currentTable->search(key, attempts);
            totalAttempts += attempts;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        double avgTime = static_cast<double>(duration) / keysToSearch.size();

        benchmarkResults.emplace_back(lf * 100, avgTime);
    }

    currentStep = 0;
    series->clear();
    animationTimer->start(100);
}

void MainWindow::updateChart() {
    if (currentStep < benchmarkResults.size()) {
        auto point = benchmarkResults[currentStep];
        series->append(point.first / 100.0, point.second);

        double maxY = 0;
        for (const auto& p : benchmarkResults) {
            if (p.second > maxY) maxY = p.second;
        }
        axisY->setRange(0, maxY * 1.1);

        currentStep++;
    } else {
        animationTimer->stop();
    }
}
