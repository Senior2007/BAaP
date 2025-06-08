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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *openFileButton;
    QLabel *currentDateLabel;
    QLineEdit *indexLineEdit;
    QPushButton *showPreviousDayButton;
    QPushButton *showWeekNumberButton;
    QPushButton *showDurationButton;
    QLineEdit *BirthdayDateLineEdit;
    QLabel *IndexOfDateLabel;
    QLabel *BirthdayDateLabel;
    QPushButton *showDaysTillBdButton;
    QPushButton *AddDateInFileButton;
    QPushButton *UpdateDateButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 80, 511, 371));
        openFileButton = new QPushButton(centralwidget);
        openFileButton->setObjectName("openFileButton");
        openFileButton->setGeometry(QRect(630, 90, 131, 51));
        currentDateLabel = new QLabel(centralwidget);
        currentDateLabel->setObjectName("currentDateLabel");
        currentDateLabel->setGeometry(QRect(620, 20, 151, 61));
        currentDateLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        indexLineEdit = new QLineEdit(centralwidget);
        indexLineEdit->setObjectName("indexLineEdit");
        indexLineEdit->setGeometry(QRect(70, 490, 131, 31));
        showPreviousDayButton = new QPushButton(centralwidget);
        showPreviousDayButton->setObjectName("showPreviousDayButton");
        showPreviousDayButton->setGeometry(QRect(630, 150, 131, 51));
        showWeekNumberButton = new QPushButton(centralwidget);
        showWeekNumberButton->setObjectName("showWeekNumberButton");
        showWeekNumberButton->setGeometry(QRect(630, 210, 131, 51));
        showDurationButton = new QPushButton(centralwidget);
        showDurationButton->setObjectName("showDurationButton");
        showDurationButton->setGeometry(QRect(630, 270, 131, 51));
        BirthdayDateLineEdit = new QLineEdit(centralwidget);
        BirthdayDateLineEdit->setObjectName("BirthdayDateLineEdit");
        BirthdayDateLineEdit->setGeometry(QRect(250, 490, 131, 31));
        IndexOfDateLabel = new QLabel(centralwidget);
        IndexOfDateLabel->setObjectName("IndexOfDateLabel");
        IndexOfDateLabel->setGeometry(QRect(60, 460, 151, 31));
        IndexOfDateLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        BirthdayDateLabel = new QLabel(centralwidget);
        BirthdayDateLabel->setObjectName("BirthdayDateLabel");
        BirthdayDateLabel->setGeometry(QRect(240, 460, 151, 31));
        BirthdayDateLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        showDaysTillBdButton = new QPushButton(centralwidget);
        showDaysTillBdButton->setObjectName("showDaysTillBdButton");
        showDaysTillBdButton->setGeometry(QRect(630, 330, 131, 51));
        AddDateInFileButton = new QPushButton(centralwidget);
        AddDateInFileButton->setObjectName("AddDateInFileButton");
        AddDateInFileButton->setGeometry(QRect(630, 390, 131, 51));
        UpdateDateButton = new QPushButton(centralwidget);
        UpdateDateButton->setObjectName("UpdateDateButton");
        UpdateDateButton->setGeometry(QRect(630, 470, 131, 51));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\275\320\270\321\206\320\260 \320\264\320\275\320\265\320\271", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        currentDateLabel->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        showPreviousDayButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", nullptr));
        showWeekNumberButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\275\320\265\320\264\320\265\320\273\320\270", nullptr));
        showDurationButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\275\320\270\321\206\320\260 \320\262 \320\264\320\275\321\217\321\205", nullptr));
        IndexOfDateLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\224\320\260\321\202\321\213", nullptr));
        BirthdayDateLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\224\320\275\321\217 \320\240\320\276\320\266\320\264\320\265\320\275\320\270\321\217", nullptr));
        showDaysTillBdButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\275\320\265\320\271 \320\264\320\276 \320\224\320\240", nullptr));
        AddDateInFileButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        UpdateDateButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214  \320\264\320\260\321\202\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
