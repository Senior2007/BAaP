#ifndef STUDENT_H
#define STUDENT_H

#include <QString>
#include <QVector>

class Student
{
public:
    Student();
    Student(QString n, QString g, QVector<int> w, QVector<int> s);
    double calcAverage(QVector<int> a);
    double getWinterAverage();
    double getSummerAverage();
    QString getName();
    QString getGroup();
    QVector<int> getWMarks();
    QVector<int> getSMarks();

private:
    QString name;
    QString group;
    QVector<int> winterMarks;
    QVector<int> summerMarks;
    double winterAverage;
    double summerAverage;
};

#endif // STUDENT_H
