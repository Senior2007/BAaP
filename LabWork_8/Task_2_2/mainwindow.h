#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binaryheapdll.h"

class QTextEdit;
class QSpinBox;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void insertValue();
    void extractMax();
    void showHeap();

private:
    BinaryHeap heap;
    QTextEdit *display;
    QSpinBox *input;
    QPushButton *insertBtn;
    QPushButton *extractBtn;
    QPushButton *showBtn;

    void setupUI();
};

#endif // MAINWINDOW_H
