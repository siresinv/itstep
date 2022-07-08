// STEP _CPP _classwork40 _08.07.22
/*
ООП НАЧАЛО


констр перемещен
ссылки l- r - value
перегрузка квадр и кругл скобок



СЛЕДУЮЩАЯ ТЕМА


*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int gold = 0;
int silver = 1;
int bronze = 2;

class MedalRow {
    char country[4];
    int medals[3];

public:
    MedalRow(const char* uCountry, int* uMedals) {
        //strcpy(country, uCountry);

        uCountry? strcpy(country, uCountry) : strcpy(country, "NON");

        for (int i = 0; i < 3; i++) {
            medals[i] = uMedals ? uMedals[i] : 0;
        }
    }



    MedalRow() : MedalRow{ nullptr, nullptr } {};

    void print() const {
        std::cout << country << " ";

        for (int i = 0; i < 3; i++) {
            std::cout << medals[i] << " ";
        }
        std::cout << std::endl;
    }


    int operator[](int i) const {
        return medals[i];
    }

    int& operator[](int i) {
        return medals[i];
    }



    MedalRow& setCountry(const char* uCountry) {
        strcpy(country, uCountry);
        return *this;
    }


    const char* getCountry() const {
        return country;
    }

};

/*

RUS 1 2 3
USA 0 0 2
RUS 1 2 4
*/

class MedalsTable {
    MedalRow medals[10];
    int size;

    int findCountry(const char* uCountry) const {
        //вернуть индекс страны или -1
        for (int i = 0; i < size; i++) {
            if (strcmp(medals[i].getCountry(), uCountry) == 0) {
                return i;
            }
        }
        return -1;
    }

public:
    MedalsTable() : size{ 0 } {};

    void print() const {
        for (int i = 0; i < size; i++) {
            medals[i].print();
        }
    }


    MedalRow operator[](const char* uCountry) const {
        int id = findCountry(uCountry);
        return medals[id];
    }

    MedalRow& operator[](const char* uCountry) {
        int id = findCountry(uCountry);
        if (id == -1) {
            id = size++;
            medals[id].setCountry(uCountry);
        }
        return medals[id];
    }







};


class Date {

    int day;
    int month;
    int year;

public:
    Date() :day{ 1 }, month{ 2 }, year{ 3 }{};
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

    friend Date& operator++(Date& date);

    friend bool operator>(const Date& date1, const Date& date2);

    friend bool operator<(const Date& date1, const Date& date2);

    friend std::ostream& operator<<(const Date& date);

};


bool operator==(const Date& date1, const Date& date2) {
    return (date1.day == date2.day && date1.month == date2.month && date1.year == date2.year);
}

bool operator!=(const Date& date1, const Date& date2) {
    return !(date1 == date2);
}



// нормально чтобы увеличивал
Date& operator++(Date& date) {
    ++date.day;
    ++date.month;
    ++date.year;
    return date; // *this - разыменуем
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


///////////////
std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.day << " " << date.month << date.year;
    return out;
}


/*



*/

int main()
{

    /*MedalRow m1;
    m1.print();
    MedalRow m2{ "RUS", new int[3]{1,3,2} };
    m2.print();*/

    /*MedalsTable mt1;
    mt1["RUS"][silver] = 10;
    mt1["USA"][silver] = 5;
    mt1["RUS"][gold] = 8;
    mt1["RUS"][bronze] = 12;
    mt1["UKR"][gold] = 9;
    mt1["RUS"][silver] = 11;
    mt1.print();

    const MedalsTable mt2{ mt1 };
    mt2.print();*/


    Date d1;
    d1.print();
    d1();
    d1.print();



    return 0;
}

// ЭТО ДОДЕЛАТЬ - В ДОМАШКУ
// ДАЛЕЕ
//String
//практика
//шаблоны
//динамические структуры стек, очередь
