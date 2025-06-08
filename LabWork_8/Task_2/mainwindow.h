#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include "heap.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onInsertClicked();
    void onExtractMaxClicked();

private:
    void updateHeapView();

    BinaryHeap heap;
    QTextEdit *heapView;
    QSpinBox *valueSpinBox;
    QPushButton *insertButton;
    QPushButton *extractMaxButton;
};

#endif // MAINWINDOW_H
