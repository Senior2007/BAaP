#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDateTime>
#include <date.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString stringFormat(Date date) const;
    int selectedIndex = -1;
    Date BirthDayDate;
    QString DatesFileName = "";

private slots:
    void on_openFileButton();
    void on_showPreviousDayButton();
    void on_showWeekNumberButton();
    void on_showDurationButton();
    void on_showDaysTillBdButton();
    void on_indexLineEdit();
    void on_birthdayDateLineEdit();
    void on_addDateInFile();
    void on_updateDate();

private:
    Ui::MainWindow *ui;
    QVector<Date> dates = {};
    void loadDatesFromFile(const QString &fileName);
    void displayDates();
    void updateCurrentDate();
};
#endif // MAINWINDOW_H
