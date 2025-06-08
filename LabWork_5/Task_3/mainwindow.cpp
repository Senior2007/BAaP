#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bitset.h"

BitSet a(10);
BitSet b(15);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bitsetLabel1->setText(a.to_string());
    ui->bitsetLabel2->setText(b.to_string());

    BitSet c(16);
    c.set();
    ui->someLabel->setText(QString::number(c.none()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_set1lineEdit_editingFinished()
{
    a.set((ui->set1lineEdit->text()).toInt());
    ui->bitsetLabel1->setText(a.to_string());
    BitSet c = a | b;
    ui->bitsetLabel3->setText(c.to_string());
}


void MainWindow::on_set2lineEdit_editingFinished()
{
    b.set((ui->set2lineEdit->text()).toInt());
    ui->bitsetLabel2->setText(b.to_string());
    BitSet c = a | b;
    ui->bitsetLabel3->setText(c.to_string());
}

