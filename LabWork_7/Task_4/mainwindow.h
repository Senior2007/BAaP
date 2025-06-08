#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>
#include "hash_table.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void runBenchmark();
    void updateChart();

private:
    void setupUI();
    void createChart();
    void fillHashTable(HashTable& table, int elements_count);

    QChart *chart;
    QChartView *chartView;
    QLineSeries *series;
    QValueAxis *axisX;
    QValueAxis *axisY;

    QPushButton *runButton;
    QComboBox *tableSizeCombo;
    QLabel *statusLabel;

    HashTable *currentTable;
    QTimer *animationTimer;
    int currentStep;
    std::vector<std::pair<int, double>> benchmarkResults;
};
#endif // MAINWINDOW_H
