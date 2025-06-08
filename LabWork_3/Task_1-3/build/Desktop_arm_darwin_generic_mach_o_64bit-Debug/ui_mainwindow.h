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
    QLabel *label;
    QLineEdit *task1LineEdit;
    QLineEdit *task2LineEdit;
    QLineEdit *task3LineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *answer1Label;
    QLabel *answer2Label;
    QLabel *answer3Label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 140, 121, 51));
        label->setStyleSheet(QString::fromUtf8("font: 18pt \"Academy Engraved LET\";\n"
"font: 13pt \"Monaco\";"));
        task1LineEdit = new QLineEdit(centralwidget);
        task1LineEdit->setObjectName("task1LineEdit");
        task1LineEdit->setGeometry(QRect(80, 190, 161, 31));
        task2LineEdit = new QLineEdit(centralwidget);
        task2LineEdit->setObjectName("task2LineEdit");
        task2LineEdit->setGeometry(QRect(300, 190, 161, 31));
        task3LineEdit = new QLineEdit(centralwidget);
        task3LineEdit->setObjectName("task3LineEdit");
        task3LineEdit->setGeometry(QRect(530, 190, 161, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(320, 140, 121, 51));
        label_2->setStyleSheet(QString::fromUtf8("font: 18pt \"Academy Engraved LET\";\n"
"font: 13pt \"Monaco\";"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(550, 140, 121, 51));
        label_3->setStyleSheet(QString::fromUtf8("font: 18pt \"Academy Engraved LET\";\n"
"font: 13pt \"Monaco\";"));
        answer1Label = new QLabel(centralwidget);
        answer1Label->setObjectName("answer1Label");
        answer1Label->setGeometry(QRect(70, 310, 651, 21));
        answer1Label->setStyleSheet(QString::fromUtf8("font: 14pt \"Monaco\";"));
        answer2Label = new QLabel(centralwidget);
        answer2Label->setObjectName("answer2Label");
        answer2Label->setGeometry(QRect(70, 350, 641, 21));
        answer2Label->setStyleSheet(QString::fromUtf8("font: 14pt \"Monaco\";"));
        answer3Label = new QLabel(centralwidget);
        answer3Label->setObjectName("answer3Label");
        answer3Label->setGeometry(QRect(70, 390, 651, 21));
        answer3Label->setStyleSheet(QString::fromUtf8("font: 14pt \"Monaco\";"));
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
        label->setText(QCoreApplication::translate("MainWindow", "   \320\227\320\260\320\264\320\260\320\275\320\270\320\265 1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "   \320\227\320\260\320\264\320\260\320\275\320\270\320\265 2", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "   \320\227\320\260\320\264\320\260\320\275\320\270\320\265 3", nullptr));
        answer1Label->setText(QCoreApplication::translate("MainWindow", " \320\236\321\202\320\262\320\265\321\202 1 :", nullptr));
        answer2Label->setText(QCoreApplication::translate("MainWindow", " \320\236\321\202\320\262\320\265\321\202 2 :", nullptr));
        answer3Label->setText(QCoreApplication::translate("MainWindow", " \320\236\321\202\320\262\320\265\321\202 3 :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
