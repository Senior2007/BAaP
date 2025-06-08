#include "date.h"

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}
Date::Date() : day(0), month(0), year(0) {}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

bool Date::IsLeap(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::IsLeap2() const {
    return IsLeap(this->year);
}

int Date::daysInMonth(int month, int year) const {
    if (month < 1 || month > 12) {
        return 0;
    }

    if (IsLeap(year) && month == 2) {
        return 29;
    }

    return days_in_month[month];
}

Date Date::NextDay() const {
    int d = day, m = month, y = year;

    if (d + 1 <= daysInMonth(m, y)) {
        return Date(d + 1, m, y);
    }

    if (m != 12) {
        return Date(1, m + 1, y);
    }

    return Date(1, 1, y + 1);
}


Date Date::PreviousDay() const {
    int d = day, m = month, y = year;

    if (d != 1) {
        return Date(d - 1, m, y);
    }

    if (m != 1) {
        return Date(daysInMonth(m - 1, y), m - 1, y);
    }

    return Date(31, 12, y - 1);
}

int Date::InDays() const {
    int ans = 0;
    for(int y = 1; y < year; y++){
        if (IsLeap(y)) {
            ans += 366;
        } else {
            ans += 365;
        }
    }

    for(int m = 1; m < month; m++) {
        ans += daysInMonth(m, year);
    }
    ans += day - 1;

    return ans;
}


int Date::Duration(Date date) const {
    return date.InDays() - InDays();
}

int Date::DaysTillYourBithday(Date birthdaydate) const {
    int ans = 0;
    Date curdate(day, month, year);

    while(curdate.day != birthdaydate.day || curdate.month != birthdaydate.month) {
        ans++;
        curdate = curdate.NextDay();
    }

    return ans;
}

short Date::DayOfWeek() const {
    return InDays() % 7;
}

short Date::WeekNumber() const {
    Date firstDay(1, 1, year);
    return (firstDay.Duration(*this) + firstDay.DayOfWeek()) / 7 + 1;
}

void Date::print() const {
    std::cout << day << ' ' <<month << ' ' << year << '\n';
}
