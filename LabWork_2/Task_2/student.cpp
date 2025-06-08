#include "student.h"

Student::Student() {}
Student::Student(QString n, QString g, QVector<int> w, QVector<int> s) {
    group = g;
    name = n;
    winterMarks = w;
    winterAverage = calcAverage(w);
    summerMarks = s;
    summerAverage = calcAverage(s);
}

double Student::getSummerAverage() {
    return summerAverage;
}

double Student::getWinterAverage() {
    return winterAverage;
}

QString Student::getGroup() {
    return group;
}

QString Student::getName() {
    return name;
}

QVector<int> Student::getSMarks() {
    return summerMarks;
}

QVector<int> Student::getWMarks() {
    return winterMarks;
}

double Student::calcAverage(QVector<int> a) {
    if (a.size() == 0) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
    }
    sum /= a.size();

    return sum;
}
