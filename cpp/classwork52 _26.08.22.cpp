// STEP _CPP _classwork52 _26.08.22
/*
ООП

Наследование


*/


#include <iostream>



class homeAnimal {
protected:
    std::string name;

public:
    homeAnimal(std::string uname) : name{ uname }{};

    virtual void sound() = 0;

    void print() {
        std::cout << "My name is " << name << "\n";
    }

    virtual void typeName() = 0;
};


class Dog : public homeAnimal {

public:
    Dog(std::string uname) :homeAnimal{ uname } {};

    virtual void sound() {
        std::cout << "I do GAV-GAV\n";
    }

    virtual void typeName() {
        std::cout << "I am a DOG\n";
    }
};


class Cat : public homeAnimal {

public:
    Cat(std::string uname) :homeAnimal{ uname } {};

    virtual void sound() {
        std::cout << "I do MEOW-MEOW\n";

    }

    virtual void typeName() {
        std::cout << "I am a CAT\n";
    }
};


class Parrot : public homeAnimal {

public:
    Parrot(std::string uname) :homeAnimal{ uname } {};

    virtual void sound() {
        std::cout << "I do CHIRIK-CHIRIK\n";

    }

    virtual void typeName() {
        std::cout << "I am a PARROT\n";
    }
};





/////////////////////////////


class Figure {
public:
    virtual double calcSquare() = 0;
    void print() {
        std::cout << calcSquare() << std::endl;
    }
};


class Rect: public Figure{
    int w;
    int h;
public:
    Rect(int uw, int uh) : w{ uw }, h{ uh }{};
    virtual double calcSquare() {
        return w * h;
    }
};


class Circle : public Figure {
    int r;
public:
    Circle(int ur) : r{ ur } {};
    virtual double calcSquare() {
        return 3.14 * r * r;
    }
};


class RectTriangle : public Rect {

public:
    RectTriangle(int uw, int uh) : Rect{ uw,uh } {};

    virtual double calcSquare() {
        return Rect::calcSquare() / 2;
    }
};


//class Trap : public RectTriangle {
//    int b;
//public:
//    Trap(int ua, int ub, int uh) : a{ ua }, b{ ub }, h{ uh } {};
//
//    virtual double calcSquare() {
//        return RectTriangle::calcSquare() + b * b;
//    }
//};
// 1/2*h*(a+b) ???????? - низя наверно так


class Trap : public Figure {
    int a;
    int b;
    int h;
public:
    Trap(int ua, int ub, int uh) : a{ ua }, b{ ub }, h{ uh } {};
    virtual double calcSquare() {
        return ((a + b) * h) / 2;
    }
};




//////////////////////////////////////

class calcRoot {
public:
    virtual void printRoot() = 0;
};


class LineEquation: public calcRoot {
    // a*x+b = 0
    int a;
    int b;
public:
    LineEquation(int ua, int ub) : a{ ua }, b{ ub }{};
    void printRoot(){
        if (a != 0) {
            std::cout << -b / double(a) << std::endl;
        }
        else if (a == 0 && b == 0) {
            std::cout << "Infinity amount of roots\n";
        }
        else {
            std::cout << "Not roots\n";
        }
        
    }
};

/////// НАСЛЕДОВАТЬ ОТ ЛИНЕЙНОГО

class QuadEquation: public calcRoot {
    // a*x*x + b*x + c = 0
    int a;
    int b;
    int c;

public:
    QuadEquation(int ua, int ub, int uc) : a{ ua }, b{ ub }, c{ uc }{};

    void printRoot() {
        double x1;
        double x2;
        bool isRoot = true;

        int d = b * b - 4 * a * c;
        if (d > 0) {
            x1 = double (-b - sqrt(d)) / 2 * a;
            x2 = double (-b + sqrt(d)) / 2 * a;
        }
        else if (d == 0) {
            x1 = x2 = -b / double(2 * a);

        }
        else {
            isRoot = false;
        }
        if (isRoot) {
            std::cout << "x1= " << x1 << std::endl;
            std::cout << "x2= " << x2 << std::endl;
        }
        else {
            std::cout << "Not roots\n";
        }
        
    }
};

int main()
{
    /*homeAnimal* homeanimals[3] = { new Dog {"REX"}, new Cat{"TOM"}, new Parrot{"KESHA"} };

    for (int i = 0; i < 3; i++) {
        homeanimals[i]->print();
        homeanimals[i]->sound();
        homeanimals[i]->typeName();
    }*/



    /*
    Rect r1{ 3,2 };
    r1.print();

    RectTriangle rt1{ 3,2 };
    rt1.print();

    Circle c1{ 2 };
    c1.print();

    Trap t1{ 3,2,2 };
    t1.print();
    */

    LineEquation le1{ 2,-2 };
    le1.printRoot();

    LineEquation le2{ 0,0 };
    le2.printRoot();

    QuadEquation qe1(1, -8, 12);
    qe1.printRoot();

    QuadEquation qe2(1, 2, 1);
    qe2.printRoot();

    return 0;
}

/*
Создать абстрактный базовый класс с виртуальной
функцией — площадь. Создать производные классы:
прямоугольник, круг, прямоугольный треугольник,
трапеция со своими функциями площади.
*/