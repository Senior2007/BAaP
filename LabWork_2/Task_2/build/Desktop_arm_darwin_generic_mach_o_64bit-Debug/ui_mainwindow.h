/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *nameEdit;
    QLabel *label;
    QLineEdit *groupeEdit;
    QLineEdit *winterEdit;
    QLineEdit *summerEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *winterAverage;
    QLabel *summerAverage;
    QPushButton *addStudentButton;
    QListWidget *listWidget;
    QLabel *label_5;
    QPushButton *debtorsButton;
    QPushButton *showListButton;
    QLineEdit *curGrouplineEdit;
    QLabel *label_6;
    QPushButton *sortButton;
    QPushButton *ExpulsionButton;
    QPushButton *fileButton;
    QPushButton *findButton;
    QPushButton *removeButton;
    QPushButton *saveFileButton;
    QPushButton *updateButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(170, 90, 191, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 100, 101, 16));
        groupeEdit = new QLineEdit(centralwidget);
        groupeEdit->setObjectName("groupeEdit");
        groupeEdit->setGeometry(QRect(170, 140, 191, 31));
        winterEdit = new QLineEdit(centralwidget);
        winterEdit->setObjectName("winterEdit");
        winterEdit->setGeometry(QRect(170, 190, 191, 31));
        summerEdit = new QLineEdit(centralwidget);
        summerEdit->setObjectName("summerEdit");
        summerEdit->setGeometry(QRect(170, 240, 191, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 150, 101, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 200, 101, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 250, 101, 16));
        winterAverage = new QLabel(centralwidget);
        winterAverage->setObjectName("winterAverage");
        winterAverage->setGeometry(QRect(70, 300, 211, 41));
        summerAverage = new QLabel(centralwidget);
        summerAverage->setObjectName("summerAverage");
        summerAverage->setGeometry(QRect(70, 350, 241, 41));
        addStudentButton = new QPushButton(centralwidget);
        addStudentButton->setObjectName("addStudentButton");
        addStudentButton->setGeometry(QRect(40, 440, 151, 41));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(390, 30, 391, 391));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 60, 301, 16));
        debtorsButton = new QPushButton(centralwidget);
        debtorsButton->setObjectName("debtorsButton");
        debtorsButton->setGeometry(QRect(400, 440, 151, 41));
        showListButton = new QPushButton(centralwidget);
        showListButton->setObjectName("showListButton");
        showListButton->setGeometry(QRect(220, 440, 151, 41));
        curGrouplineEdit = new QLineEdit(centralwidget);
        curGrouplineEdit->setObjectName("curGrouplineEdit");
        curGrouplineEdit->setGeometry(QRect(580, 500, 171, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(620, 480, 101, 16));
        sortButton = new QPushButton(centralwidget);
        sortButton->setObjectName("sortButton");
        sortButton->setGeometry(QRect(590, 440, 151, 41));
        ExpulsionButton = new QPushButton(centralwidget);
        ExpulsionButton->setObjectName("ExpulsionButton");
        ExpulsionButton->setGeometry(QRect(400, 490, 151, 41));
        fileButton = new QPushButton(centralwidget);
        fileButton->setObjectName("fileButton");
        fileButton->setGeometry(QRect(40, 390, 151, 41));
        findButton = new QPushButton(centralwidget);
        findButton->setObjectName("findButton");
        findButton->setGeometry(QRect(220, 390, 151, 41));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(40, 490, 151, 41));
        saveFileButton = new QPushButton(centralwidget);
        saveFileButton->setObjectName("saveFileButton");
        saveFileButton->setGeometry(QRect(40, 10, 151, 41));
        updateButton = new QPushButton(centralwidget);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(220, 490, 151, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236 \320\241\321\202\321\203\320\264\320\265\320\275\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\227\320\270\320\274\320\275\321\217\321\217 \321\201\320\265\321\201\321\201\320\270\321\217", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\233\320\265\321\202\320\275\321\217\321\217 \321\201\320\265\321\201\321\201\320\270\321\217", nullptr));
        winterAverage->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200 \320\261\320\260\320\273\320\273 \320\267\320\260 \320\267\320\270\320\274\321\203", nullptr));
        summerAverage->setText(QCoreApplication::translate("MainWindow", "\320\241\321\200 \320\261\320\260\320\273\320\273 \320\267\320\260 \320\273\320\265\321\202\320\276", nullptr));
        addStudentButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\274\320\265\321\202\320\272\320\270 \320\262\320\262\320\276\320\264\320\270\321\202\321\214 \321\207\320\265\321\200\320\265\320\267 \320\267\320\260\320\277\321\217\321\202\321\203\321\216 \320\261\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273\320\276\320\262!", nullptr));
        debtorsButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\270\320\274\320\275\320\270\320\265 \320\264\320\276\320\273\320\266\320\275\320\270\320\272\320\270", nullptr));
        showListButton->setText(QCoreApplication::translate("MainWindow", "\320\222\320\265\321\201\321\214 \321\201\320\277\320\270\321\201\320\276\320\272", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        ExpulsionButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\275\320\260 \320\276\321\202\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\265", nullptr));
        fileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        findButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        saveFileButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
