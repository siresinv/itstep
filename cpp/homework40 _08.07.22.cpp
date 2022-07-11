// STEP _CPP _homework40 _08.07.22
/*
ООП НАЧАЛО


// ЭТО ДОДЕЛАТЬ - В ДОМАШКУ
// ДАЛЕЕ
//String
//практика
//шаблоны
//динамические структуры стек, очередь


*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



class Date {

    int day;
    int month;
    int year;

public:
    Date() :day{ 12 }, month{ 2 }, year{ 1981 }{};
    void print() {
        std::cout << day << " " << month << " " << year << std::endl;
    }

    void operator()() {
        day++;
    }


    void operator()(int x) {
        month += x;
    }


    friend bool operator==(const Date& date1, const Date& date2);
    friend bool operator!=(const Date& date1, const Date& date2);

    Date& operator=(const Date& date2) {
        day = date2.day;
        month = date2.month;
        year = date2.year;
        return *this;
    }

    Date& operator+=(int days) {
        day += days;
        if (day>30) {
            month += day / 30;
            day %= 30;
            if (month > 12) {
                year += month / 12;
                month = month % 12;
            }
        }
        return *this;
    }


    Date& operator-=(int days) {
        day -= days;
        if (day < 1) {
            month += day / 30 - 1;
            day = 30 + day % 30;
            if (month < 1) {
                year -= month / 12 - 1;
                month = 12 + month % 12;
            }
        }
        return *this;
    }


    friend Date& operator++(Date& date);

    friend Date& operator--(Date& date);

    friend bool operator>(const Date& date1, const Date& date2);

    friend bool operator<(const Date& date1, const Date& date2);

    friend std::ostream& operator<<(std::ostream& out, const Date& date);

    friend std::istream& operator>>(std::istream& in, Date& date);

};


bool operator==(const Date& date1, const Date& date2) {
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}

bool operator!=(const Date& date1, const Date& date2) {
    return !(date1 == date2);
}



Date& operator++(Date& date) {
    ++date.day;
    if (date.day > 30) {
        date.day = 1;
        ++date.month;
        if (date.month > 12) {
            date.month = 1;
            ++date.year;
        }
    }
    return date; // *this - разыменовываем
}


Date& operator--(Date& date) {
    --date.day;
    if (date.day < 1) {
        date.day = 30;
        --date.month;
        if (date.month < 1) {
            date.month = 12;
            --date.year;
        }
    }
    return date; // *this - разыменовываем
}


bool operator>(const Date& date1, const Date& date2) {
    if (date1.year > date2.year) {
        return true;
    }
    else if (date1.year == date2.year) {
        if (date1.month > date2.month) {
            return true;
        }
        else if (date1.month == date2.month) {
            if (date1.day > date2.day) {
                return true;
            }
        }
    }
    return false;
}


bool operator<(const Date& date1, const Date& date2) {

    if (!(date1>date2) && date1 != date2) {
        return true;
    }
    return false;
}



std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.day << " " << date.month << date.year;
    return out;
}


std::istream& operator>>(std::istream& in, Date& date) {
    std::cin >> date.day >> date.month >> date.year;
    return in;
}



int main()
{



    Date d1;
    d1.print();
    d1();
    d1.print();
    d1 += 50;
    d1.print();

    d1 -= 70;
    d1.print();

    std::cin >> d1;
    d1.print();



    return 0;
}
