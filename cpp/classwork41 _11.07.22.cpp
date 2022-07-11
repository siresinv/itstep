// STEP _CPP _classwork41 _11.07.22
/*
ООП НАЧАЛО


//String
//практика
//шаблоны
//динамические структуры стек, очередь



СЛЕДУЮЩАЯ ТЕМА


*/



#include <iostream>




class Circle {
    double rad;
    double lenCircle;

    /*double getLenCircle(int rad) {
        return 2 * 3.14 * rad;
    }*/

public:
    Circle(double r) : rad{ r } {
        lenCircle = 2 * 3.14 * r;
    }

    Circle() :Circle(5){};

    bool operator==(const Circle c2) const {
        if (rad == c2.rad) {
            return true;
        }
        return false;
    }


    bool operator>(const Circle c2) const {
        /*if (getLenCircle(rad) > getLenCircle(c2.rad)) {
            return true;
        }*/
        return lenCircle > c2.lenCircle;
    }

    Circle& operator+=(int amount) {
        rad += amount;
        lenCircle = 2 * 3.14 * rad;
        return *this;
    }

    Circle& operator-=(int amount) {
        rad -= amount;
        lenCircle = 2 * 3.14 * rad;
        return *this;
    }

};



class Airplane {
    char type[4];
    int maxPass;
    int currentPass;

public:
    Airplane(const char* uType, int uMaxPass, int uCurrentPass) : maxPass{uMaxPass}, currentPass{ uCurrentPass }{
        strcpy_s(type, 4, uType);
    };

    Airplane() :Airplane("AR1", 100, 0) {};


    bool operator==(const Airplane air2 ) const {
        return !strcmp(type, air2.type);
    }

    bool operator>(const Airplane air2) const {
        return maxPass > air2.maxPass;
    }


    Airplane& operator++() {
        if (currentPass < maxPass)  ++currentPass;
        return *this;
    }

    void operator--() {
        if (currentPass > 0)  --currentPass;
    }

    void print() {
        std::cout << type << " " << maxPass << " " << currentPass << std::endl;
    }

};


int main()
{
    Airplane air1;
    Airplane air2("AR1", 100, 0);
    air1.print();
    --air1;
    air1.print();
    (++air1).print();

    std::cout << ((air1 == air2) ? "Same" : "Other");

    return 0;
}



