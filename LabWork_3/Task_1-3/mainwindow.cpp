#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_task1LineEdit_editingFinished()
{
    QString sx = ui->task1LineEdit->text();
    if (sx == "") {
        return;
    }
    double x = sx.toDouble();
    QString answer = Task_1::Task1(x);
    ui->answer1Label->setText(" Ответ 1 : " + answer);
}


void MainWindow::on_task2LineEdit_editingFinished()
{
    QString str = ui->task2LineEdit->text();
    if (str == "") {
        return;
    }
    QString m = "", n = "";

    bool pr = 0;
    for (int i = 0; i < str.size(); i++) {
        if (!pr && str[i] != ' ') {
            m += str[i];
        }

        if (pr && str[i] != ' ') {
            n += str[i];
        }

        if (str[i] == ' ') {
            pr = 1;
        }
    }

    int im = m.toInt(), in = n.toInt();

    if (im > 3 || (im == 3 && in > 15)) {
        ui->answer2Label->setText(" Ответ 2 : Слишком большой");
        return;
    }

    QString answer = QString::number(Task_2::A(im, in));
    ui->answer2Label->setText(" Ответ 2 : " + answer);
}


void MainWindow::on_task3LineEdit_editingFinished()
{
    QString sx = ui->task3LineEdit->text();
    if (sx == "") {
        return;
    }
    int x = sx.toInt();
    QString answer = QString::number(Task_3::Task3(x));
    ui->answer3Label->setText(" Ответ 3 : " + answer);
}

