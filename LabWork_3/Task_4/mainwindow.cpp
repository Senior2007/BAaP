#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    animation = new HanoiMover(this);
    animation->resize(800, 600);
    animation->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete animation;
}

void MainWindow::on_lineEdit_editingFinished()
{
    int n = (ui->lineEdit->text()).toInt();
    QVector<std::pair<int, int>> answer = HanoiSolver::solve(n, 1, 3);

    animation->show();
    animation->draw(n, answer);
}

