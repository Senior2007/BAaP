#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    students.clear();
    curGroup = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addStudentButton_clicked()
{
    QString fio = ui->nameEdit->text();
    QString group = ui->groupeEdit->text();
    QString winter = ui->winterEdit->text();
    QString summer = ui->summerEdit->text();
    QVector<int> wm, sm;

    int i = 0;
    while (i < winter.size()) {
        if (i + 1 < winter.size() && winter[i + 1] != ',') {
            wm.push_back(10);
            i += 3;
        } else {
            wm.push_back(winter[i].digitValue());
            i += 2;
        }
    }

    i = 0;
    while (i < summer.size()) {
        if (i + 1 < summer.size() && summer[i + 1] != ',') {
            sm.push_back(10);
            i += 3;
        } else {
            sm.push_back(summer[i].digitValue());
            i += 2;
        }
    }

    Student cur(fio, group, wm, sm);
    students.push_back(cur);
    ui->summerAverage->setText("Ср балл за лето : " + QString::number(cur.getSummerAverage()));
    ui->winterAverage->setText("Ср балл за зиму : " + QString::number(cur.getWinterAverage()));

    displayStudents();
}


void MainWindow::displayStudents() {
    ui->listWidget->clear();

    for (int i = 0; i < students.size(); i++) {
        QString fio = students[i].getName();
        QString group = students[i].getGroup();
        QString winter = "(", summer = "(";
        QVector<int> wMarks = students[i].getWMarks(), sMarks = students[i].getSMarks();
        int d1 = wMarks.size(), d2 = sMarks.size(), idx = 0;

        for (auto u : wMarks) {
            winter += QString::number(u);
            if (idx != d1 - 1) winter += ',';
            idx++;
        }

        idx = 0;
        for (auto u : sMarks) {
            summer += QString::number(u);
            if (idx != d2 - 1) summer += ',';
            idx++;
        }

        winter += ')';
        summer += ')';

        ui->listWidget->addItem(fio + ", " + group + ", " + winter + " " + summer);
    }
}

void MainWindow::on_debtorsButton_clicked()
{
    ui->listWidget->clear();

    for (auto u : students) {
        bool pr = 0;
        for (auto v : u.getWMarks()) {
            if (v < 4) {
                pr = 1;
            }
        }
        if (pr) {
            QString winter = "(", summer = "(";
            QVector<int> wMarks = u.getWMarks(), sMarks = u.getSMarks();
            int d1 = wMarks.size(), d2 = sMarks.size(), idx = 0;

            for (auto u : wMarks) {
                winter += QString::number(u);
                if (idx != d1 - 1) winter += ',';
                idx++;
            }

            idx = 0;
            for (auto u : sMarks) {
                summer += QString::number(u);
                if (idx != d2 - 1) summer += ',';
                idx++;
            }

            winter += ')';
            summer += ')';
            ui->listWidget->addItem(u.getName() + ", " + u.getGroup() + ", " + winter + " " + summer);
        }
    }
}


void MainWindow::on_showListButton_clicked()
{
    displayStudents();
}


void MainWindow::on_curGrouplineEdit_editingFinished()
{
    curGroup = ui->curGrouplineEdit->text();
}


bool MainWindow::cmp(Student a, Student b) {
    return a.getName() < b.getName();
}

void MainWindow::on_sortButton_clicked()
{
    if (curGroup == "") {
        statusBar()->showMessage("Вы не ввели номер группы!", 3000);
        return;
    }
    qDebug() << curGroup;

    QVector<Student> StudentsByGroup;

    for (auto u : students) {
        if (u.getGroup() == curGroup) {
            StudentsByGroup.push_back(u);
        }
    }

    std::sort(StudentsByGroup.begin(), StudentsByGroup.end(), cmp);

    ui->listWidget->clear();
    for (auto u : StudentsByGroup) {
        QString fio = u.getName();
        QString group = u.getGroup();
        QString winter = "(", summer = "(";
        QVector<int> wMarks = u.getWMarks(), sMarks = u.getSMarks();
        int d1 = wMarks.size(), d2 = sMarks.size(), idx = 0;

        for (auto u : wMarks) {
            winter += QString::number(u);
            if (idx != d1 - 1) winter += ',';
            idx++;
        }

        idx = 0;
        for (auto u : sMarks) {
            summer += QString::number(u);
            if (idx != d2 - 1) summer += ',';
            idx++;
        }

        winter += ')';
        summer += ')';

        ui->listWidget->addItem(fio + ", " + group + ", " + winter + " " + summer);
    }
}


void MainWindow::on_ExpulsionButton_clicked()
{
    QVector<Student> ExpStudents;
    for (auto u : students) {
        QVector<int> wMarks = u.getWMarks(), sMarks = u.getSMarks();
        int cntW = 0, cntS = 0;

        for (auto mark : wMarks) {
            if (mark < 4) {
                cntW++;
            }
        }

        for (auto mark : sMarks) {
            if (mark < 4) {
                cntS++;
            }
        }

        if (cntS >= 2 && cntW >= 1) {
            ExpStudents.push_back(u);
        }
    }

    ui->listWidget->clear();
    for (auto u : ExpStudents) {
        QString fio = u.getName();
        QString group = u.getGroup();
        QString winter = "(", summer = "(";
        QVector<int> wMarks = u.getWMarks(), sMarks = u.getSMarks();
        int d1 = wMarks.size(), d2 = sMarks.size(), idx = 0;

        for (auto u : wMarks) {
            winter += QString::number(u);
            if (idx != d1 - 1) winter += ',';
            idx++;
        }

        idx = 0;
        for (auto u : sMarks) {
            summer += QString::number(u);
            if (idx != d2 - 1) summer += ',';
            idx++;
        }

        winter += ')';
        summer += ')';

        ui->listWidget->addItem(fio + ", " + group + ", " + winter + " " + summer);
    }
}

void MainWindow::loadStudentFromFile(const QString &fileName)
{
    students.clear();

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        StudentFileName = fileName;
        QString fio = "", group = "";
        QVector<int> wMarks, sMarks;
        int idx = 0;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();

            if (idx == 0) {
                fio = line;
            }

            if (idx == 1) {
                group = line;
            }

            if (idx == 2) {
                int i = 0;
                while (i < line.size()) {
                    if (i + 1 < line.size() && line[i + 1] != ',') {
                        wMarks.push_back(10);
                        i += 3;
                    } else {
                        wMarks.push_back(line[i].digitValue());
                        i += 2;
                    }
                }
            }

            if (idx == 3) {
                int i = 0;
                while (i < line.size()) {
                    if (i + 1 < line.size() && line[i + 1] != ',') {
                        sMarks.push_back(10);
                        i += 3;
                    } else {
                        sMarks.push_back(line[i].digitValue());
                        i += 2;
                    }
                }

                Student st(fio, group, wMarks, sMarks);
                students.push_back(st);
                wMarks.clear();
                sMarks.clear();
            }

            idx++;
            idx %= 4;
        }
        file.close();
    } else {
        statusBar()->showMessage("Could not open file!", 3000);
    }

    displayStudents();
}

void MainWindow::on_fileButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        loadStudentFromFile(fileName);
        displayStudents();
    }
}


void MainWindow::on_findButton_clicked()
{
    bool ok;
    QString fio = QInputDialog::getText(this, "Поиск", "Пожалуйста, введите ФИО:", QLineEdit::Normal, "", &ok);

    if (ok && !fio.isEmpty()) {
        ui->listWidget->clear();
        for (auto u : students) {
            if (u.getName().startsWith(fio)) {
                QString fio = u.getName();
                QString group = u.getGroup();
                QString winter = "(", summer = "(";
                QVector<int> wMarks = u.getWMarks(), sMarks = u.getSMarks();
                int d1 = wMarks.size(), d2 = sMarks.size(), idx = 0;

                for (auto u : wMarks) {
                    winter += QString::number(u);
                    if (idx != d1 - 1) winter += ',';
                    idx++;
                }

                idx = 0;
                for (auto u : sMarks) {
                    summer += QString::number(u);
                    if (idx != d2 - 1) summer += ',';
                    idx++;
                }

                winter += ')';
                summer += ')';

                ui->listWidget->addItem(fio + ", " + group + ", " + winter + " " + summer);
            }
        }
    } else {
        statusBar()->showMessage("Отмена действия", 1000);
    }
}


void MainWindow::on_removeButton_clicked()
{
    bool ok;
    int idx = QInputDialog::getInt(this,"Ввод индекса", "Пожалуйста, введите индекс:", 0, 1, students.size(), 1, &ok);

    if (ok) {
        idx--;
        students.erase(students.begin() + idx);
        displayStudents();
    } else {
        statusBar()->showMessage("Некорректный ввод", 3000);
    }
}


void MainWindow::on_saveFileButton_clicked()
{
    if (StudentFileName == "") {
        statusBar()->showMessage("Вы не открывали файл", 1000);
        return;
    }

    QFile file(StudentFileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка: не удалось открыть файл";
        return;
    }

    QTextStream out(&file);
    for (auto u : students) {
        out << u.getName() << '\n';
        out << u.getGroup() << '\n';
        int wCount = u.getWMarks().size(), sCount = u.getSMarks().size();
        QVector<int> winter = u.getWMarks(), summer = u.getSMarks();

        for (int i = 0; i < wCount; i++) {
            out << winter[i];
            if (i != wCount - 1) {
                out << ',';
            }
        }
        out << '\n';
        for (int i = 0; i < sCount; i++) {
            out << summer[i];
            if (i != sCount - 1) {
                out << ',';
            }
        }
        out << '\n';
    }

    file.close();
}


void MainWindow::on_updateButton_clicked()
{
    bool ok;
    int idx = QInputDialog::getInt(this,"Ввод индекса", "Пожалуйста, введите индекс:", 0, 1, students.size(), 1, &ok);

    if (ok) {
        idx--;
        QString fio = ui->nameEdit->text();
        QString group = ui->groupeEdit->text();
        QString winter = ui->winterEdit->text();
        QString summer = ui->summerEdit->text();
        QVector<int> wm, sm;

        int i = 0;
        while (i < winter.size()) {
            if (i + 1 < winter.size() && winter[i + 1] != ',') {
                wm.push_back(10);
                i += 3;
            } else {
                wm.push_back(winter[i].digitValue());
                i += 2;
            }
        }

        i = 0;
        while (i < summer.size()) {
            if (i + 1 < summer.size() && summer[i + 1] != ',') {
                sm.push_back(10);
                i += 3;
            } else {
                sm.push_back(summer[i].digitValue());
                i += 2;
            }
        }

        Student cur(fio, group, wm, sm);
        students[idx] = cur;
        ui->summerAverage->setText("Ср балл за лето : " + QString::number(cur.getSummerAverage()));
        ui->winterAverage->setText("Ср балл за зиму : " + QString::number(cur.getWinterAverage()));
        displayStudents();
    } else {
        statusBar()->showMessage("Некорректный ввод", 3000);
    }
}

