#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
//#include <QDebug>

class Date
{
public:
    Date(int d = 0, int m = 0, int y = 0);
    Date();
    Date NextDay() const;
    Date PreviousDay() const;
    bool IsLeap(int year) const;
    bool IsLeap2() const;
    short DayOfWeek() const;
    short WeekNumber() const;
    int DaysTillYourBithday(Date birthday) const;
    int Duration(Date date) const;
    int InDays() const;
    void print() const; //Для дебага
    int getDay() const;
    int getMonth() const;
    int getYear() const;

private:
    int day;
    int month;
    int year;
    static constexpr int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31};
    bool isLeapYear(int year) const;
    int daysInMonth(int month, int year) const;
};

#endif // DATE_H
