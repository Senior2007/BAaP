#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
//#include <QMessageBox>
#include <student.h>

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
    QVector<Student> students;
    void displayStudents();
    QString curGroup;
    static bool cmp(Student a, Student b);
    void loadStudentFromFile(const QString &fileName);
    QString StudentFileName = "";

private slots:
    void on_addStudentButton_clicked();

    void on_debtorsButton_clicked();

    void on_showListButton_clicked();

    void on_curGrouplineEdit_editingFinished();

    void on_sortButton_clicked();

    void on_ExpulsionButton_clicked();

    void on_fileButton_clicked();

    void on_findButton_clicked();

    void on_removeButton_clicked();

    void on_saveFileButton_clicked();

    void on_updateButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
