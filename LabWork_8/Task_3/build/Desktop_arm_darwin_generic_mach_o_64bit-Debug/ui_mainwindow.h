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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_4;
    QPlainTextEdit *plainTextEdit_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPlainTextEdit *plainTextEdit_4;
    QPlainTextEdit *plainTextEdit_5;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(337, 780);
        label = new QLabel(mainwindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 70, 66, 17));
        label_2 = new QLabel(mainwindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 70, 66, 17));
        plainTextEdit = new QPlainTextEdit(mainwindow);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 30, 151, 31));
        plainTextEdit_2 = new QPlainTextEdit(mainwindow);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(170, 30, 151, 31));
        pushButton = new QPushButton(mainwindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 100, 151, 31));
        pushButton_3 = new QPushButton(mainwindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 180, 151, 31));
        label_3 = new QLabel(mainwindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 66, 17));
        label_4 = new QLabel(mainwindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 10, 181, 17));
        pushButton_4 = new QPushButton(mainwindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 260, 151, 31));
        plainTextEdit_3 = new QPlainTextEdit(mainwindow);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(10, 300, 311, 31));
        pushButton_5 = new QPushButton(mainwindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(170, 100, 151, 31));
        pushButton_6 = new QPushButton(mainwindow);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(170, 140, 151, 31));
        pushButton_7 = new QPushButton(mainwindow);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(170, 220, 151, 31));
        pushButton_8 = new QPushButton(mainwindow);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(170, 180, 151, 31));
        pushButton_9 = new QPushButton(mainwindow);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(170, 260, 151, 31));
        pushButton_10 = new QPushButton(mainwindow);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(10, 140, 151, 31));
        plainTextEdit_4 = new QPlainTextEdit(mainwindow);
        plainTextEdit_4->setObjectName("plainTextEdit_4");
        plainTextEdit_4->setGeometry(QRect(10, 340, 151, 431));
        plainTextEdit_5 = new QPlainTextEdit(mainwindow);
        plainTextEdit_5->setObjectName("plainTextEdit_5");
        plainTextEdit_5->setGeometry(QRect(170, 340, 151, 431));

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "mainwindow", nullptr));
        label->setText(QCoreApplication::translate("mainwindow", "map", nullptr));
        label_2->setText(QCoreApplication::translate("mainwindow", "set", nullptr));
        pushButton->setText(QCoreApplication::translate("mainwindow", "[] =", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mainwindow", "contains", nullptr));
        label_3->setText(QCoreApplication::translate("mainwindow", "key", nullptr));
        label_4->setText(QCoreApplication::translate("mainwindow", "value (not used in set)", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mainwindow", "size()", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mainwindow", "insert", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mainwindow", "erase", nullptr));
        pushButton_7->setText(QCoreApplication::translate("mainwindow", "clear", nullptr));
        pushButton_8->setText(QCoreApplication::translate("mainwindow", "find", nullptr));
        pushButton_9->setText(QCoreApplication::translate("mainwindow", "size()", nullptr));
        pushButton_10->setText(QCoreApplication::translate("mainwindow", "[]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
