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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *bitsetLabel1;
    QLabel *bitsetLabel2;
    QLabel *bitsetLabel3;
    QLineEdit *set1lineEdit;
    QLineEdit *set2lineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *someLabel;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        bitsetLabel1 = new QLabel(centralwidget);
        bitsetLabel1->setObjectName("bitsetLabel1");
        bitsetLabel1->setGeometry(QRect(110, 100, 391, 91));
        bitsetLabel1->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Futura\";"));
        bitsetLabel2 = new QLabel(centralwidget);
        bitsetLabel2->setObjectName("bitsetLabel2");
        bitsetLabel2->setGeometry(QRect(110, 210, 391, 91));
        bitsetLabel2->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Futura\";"));
        bitsetLabel3 = new QLabel(centralwidget);
        bitsetLabel3->setObjectName("bitsetLabel3");
        bitsetLabel3->setGeometry(QRect(110, 310, 391, 91));
        bitsetLabel3->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Futura\";"));
        set1lineEdit = new QLineEdit(centralwidget);
        set1lineEdit->setObjectName("set1lineEdit");
        set1lineEdit->setGeometry(QRect(620, 130, 131, 31));
        set2lineEdit = new QLineEdit(centralwidget);
        set2lineEdit->setObjectName("set2lineEdit");
        set2lineEdit->setGeometry(QRect(620, 230, 131, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 100, 91, 31));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"Papyrus\";"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(670, 200, 91, 31));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Papyrus\";"));
        someLabel = new QLabel(centralwidget);
        someLabel->setObjectName("someLabel");
        someLabel->setGeometry(QRect(110, 390, 391, 91));
        someLabel->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Futura\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 100, 91, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"Papyrus\";"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 210, 101, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"Papyrus\";"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(110, 310, 91, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"Papyrus\";"));
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
        bitsetLabel1->setText(QCoreApplication::translate("MainWindow", "bitset 1", nullptr));
        bitsetLabel2->setText(QCoreApplication::translate("MainWindow", "bitset 2", nullptr));
        bitsetLabel3->setText(QCoreApplication::translate("MainWindow", "bitset 3", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        someLabel->setText(QCoreApplication::translate("MainWindow", "Some Text", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "first bitset", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "second bitset", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "result bitset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
