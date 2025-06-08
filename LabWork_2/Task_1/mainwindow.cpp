#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , BirthDayDate(0, 0, 0), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Date", "Next Day", "Difference"});
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    updateCurrentDate();
    connect(ui->openFileButton, &QPushButton::clicked, this, &MainWindow::on_openFileButton);
    connect(ui->showPreviousDayButton, &QPushButton::clicked, this, &MainWindow::on_showPreviousDayButton);
    connect(ui->showWeekNumberButton, &QPushButton::clicked, this, &MainWindow::on_showWeekNumberButton);
    connect(ui->showDurationButton, &QPushButton::clicked, this, &MainWindow::on_showDurationButton);
    connect(ui->showDaysTillBdButton, &QPushButton::clicked, this, &MainWindow::on_showDaysTillBdButton);
    connect(ui->AddDateInFileButton, &QPushButton::clicked, this, &MainWindow::on_addDateInFile);
    connect(ui->UpdateDateButton, &QPushButton::clicked, this, &MainWindow::on_updateDate);
    connect(ui->indexLineEdit, &QLineEdit::editingFinished, this, &MainWindow::on_indexLineEdit);
    connect(ui->BirthdayDateLineEdit, &QLineEdit::editingFinished, this, &MainWindow::on_birthdayDateLineEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDatesFromFile(const QString &fileName)
{
    dates.clear();
    ui->tableWidget->setRowCount(0);

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        DatesFileName = fileName;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split('.');
            if (parts.size() == 3) {
                int day = parts[0].toInt();
                int month = parts[1].toInt();
                int year = parts[2].toInt();
                dates.append(Date(day, month, year));
            }
        }
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open file!");
    }
}

void MainWindow::on_addDateInFile() {
    if (DatesFileName == "") {
        QMessageBox::warning(this, "Error", "Could not open file!");
        return;
    }

    bool ok;
    QString dateString = QInputDialog::getText(this, "Введите дату", "Введите дату в формате DD.MM.YYYY:", QLineEdit::Normal, "", &ok);

    if (!ok || dateString.isEmpty()) {
        return;
    }

    QDate inputDate = QDate::fromString(dateString, "dd.MM.yyyy");

    if (!inputDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат даты. Введите дату в формате DD.MM.YYYY");
        return;
    }

    int d = inputDate.day(), m = inputDate.month(), y = inputDate.year();
    Date NewDate(d, m, y);

    dates.push_back(NewDate);
    displayDates();

    QFile file(DatesFileName);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Не удалось открыть файл!";
        return;
    }

    QTextStream out(&file);
    out << dateString << '\n';
    file.close();
}

QString MainWindow::stringFormat(Date date) const {
    QString res = "";
    int d = date.getDay(), m = date.getMonth(), y = date.getYear();

    if (d > 9) {
        res += QString::number(d);
    } else {
        res += '0';
        res += QString::number(d);
    }

    res += '.';

    if (m > 9) {
        res += QString::number(m);
    } else {
        res += '0';
        res += QString::number(m);
    }

    res += '.';

    QString s2 = QString::number(y);
    while (s2.size() != 4) {
        s2 = '0' + s2;
    }

    res += s2;

    return res;
}

void MainWindow::displayDates()
{
    ui->tableWidget->setRowCount(dates.size());

    for (int i = 0; i < dates.size(); ++i) {
        Date date = dates[i];
        QString s = stringFormat(date);

        if (ui->tableWidget->item(i, 0)) {
            delete ui->tableWidget->item(i, 0);
        }
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(s));

        Date nextDay = date.NextDay();
        QString ns = stringFormat(nextDay);

        if (ui->tableWidget->item(i, 1)) {
            delete ui->tableWidget->item(i, 1);
        }
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(ns));

        if (ui->tableWidget->item(i, 2)) {
            delete ui->tableWidget->item(i, 2);
        }

        if (i < dates.size() - 1) {
            int difference = date.Duration(dates[i + 1]);
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(difference)));
        } else {
            ui->tableWidget->setItem(i, 2, new QTableWidgetItem("Не определено"));
        }
    }
}

void MainWindow::updateCurrentDate()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDate = currentDateTime.toString("dd.MM.yyyy");
    ui->currentDateLabel->setText("Current Date: " + currentDate);
}


void MainWindow::on_openFileButton()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt)");
    if (!fileName.isEmpty()) {
        loadDatesFromFile(fileName);
        displayDates();
    }
}

void MainWindow::on_indexLineEdit()
{
    QString indexText = ui->indexLineEdit->text();

    bool ok;
    int index = indexText.toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Error", "Please enter a valid integer!");
        return;
    }

    if (index <= 0 || index > dates.size()) {
        QMessageBox::warning(this, "Error", "Index is out of range!");
        return;
    }

    selectedIndex = index - 1;
}

void MainWindow::on_birthdayDateLineEdit() {
    QString DateText = ui->BirthdayDateLineEdit->text();
    QDate inputDate = QDate::fromString(DateText, "dd.MM.yyyy");

    if (!inputDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат даты. Введите дату в формате DD.MM.YYYY");
        return;
    }

    int d = inputDate.day(), m = inputDate.month(), y = inputDate.year();
    Date BDdate(d, m, y);
    BirthDayDate = BDdate;
}

void MainWindow::on_showPreviousDayButton() {
    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Error", "Date index is not selected");
        return;
    }

    Date PreviousDate = dates[selectedIndex].PreviousDay();
    QMessageBox::information(this, "Information", "Previos day of date number " + QString::number(selectedIndex + 1) + " is " + stringFormat(PreviousDate));
}

void MainWindow::on_showWeekNumberButton() {
    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Error", "Date index is not selected");
        return;
    }

    int number = dates[selectedIndex].WeekNumber();
    QMessageBox::information(this, "Information", "Week number of date number " + QString::number(selectedIndex + 1) + " is " + QString::number(number));
}

void MainWindow::on_updateDate() {
    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Error", "Date index is not selected");
        return;
    }

    if (DatesFileName == "") {
        QMessageBox::warning(this, "Error", "Could not open file!");
        return;
    }

    bool ok;
    QString dateString = QInputDialog::getText(this, "Введите дату", "Введите дату в формате DD.MM.YYYY:", QLineEdit::Normal, "", &ok);

    if (!ok || dateString.isEmpty()) {
        return;
    }

    QDate inputDate = QDate::fromString(dateString, "dd.MM.yyyy");

    if (!inputDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат даты. Введите дату в формате DD.MM.YYYY");
        return;
    }

    int d = inputDate.day(), m = inputDate.month(), y = inputDate.year();
    Date UpdatedDate(d, m, y);

    dates[selectedIndex] = UpdatedDate;
    displayDates();

    QFile file(DatesFileName);
    if (!file.open(QIODevice::ReadWrite)) {
        qWarning() << "Не удалось открыть файл!";
        return;
    }

    if (!file.seek(selectedIndex * 10 + selectedIndex)) {
        qWarning() << "Не удалось переместиться к нужной позиции в файле!";
        file.close();
        return;
    }

    QByteArray data = dateString.toUtf8();
    if (file.write(data) != 10) {
        qWarning() << "Ошибка записи в файл!";
        file.close();
        return;
    }

    file.close();
}

void MainWindow::on_showDurationButton() {
    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Error", "Date index is not selected");
        return;
    }

    bool ok;
    QString dateString = QInputDialog::getText(this, "Введите дату", "Введите дату в формате DD.MM.YYYY:", QLineEdit::Normal, "", &ok);

    if (!ok || dateString.isEmpty()) {
        return;
    }

    QDate inputDate = QDate::fromString(dateString, "dd.MM.yyyy");

    if (!inputDate.isValid()) {
        QMessageBox::warning(this, "Ошибка", "Некорректный формат даты. Введите дату в формате DD.MM.YYYY");
        return;
    }

    int d = inputDate.day(), m = inputDate.month(), y = inputDate.year();
    Date UserDate(d, m, y);
    int dif = dates[selectedIndex].Duration(UserDate);

    QMessageBox::information(this, "Information",
                             "The difference between dates " + stringFormat(dates[selectedIndex]) + " and " + stringFormat(UserDate) + " is " + QString::number(dif));
}

void MainWindow::on_showDaysTillBdButton() {
    if (BirthDayDate.getDay() == 0 && BirthDayDate.getMonth() == 0 && BirthDayDate.getYear() == 0) {
        QMessageBox::warning(this, "Error", "You haven't entered the date of the birthday yet");
        return;
    }

    if (selectedIndex == - 1) {
        QMessageBox::warning(this, "Error", "Date index is not selected");
        return;
    }

    int cnt = dates[selectedIndex].DaysTillYourBithday(BirthDayDate);
    QMessageBox::information(this, "Information", "Your birthday is " + QString::number(cnt) + " day(s) away");
}
