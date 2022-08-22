// STEP _CPP _classwork50 _22.08.22
/*
ООП

Наследование


*/

//#DEFINE PI = 3.14;

#include <iostream>

/*
class Point {
    int x;
    int y;
public:
    Point(): x{ 0 }, y{ 0 }{};
    void setPoint(int ux, int uy) {
        x = ux;
        y = uy;
    }
    void print() {
        std::cout << "(" << x << ";" << y << ")" << " ";
    }
};


class Figure {
    Point* arrPoint;
    int count;
public:
    Figure(int uCount = 5) : arrPoint{ new Point[uCount] }, count{ uCount }{
        for (int i = 0; i < count; i++) {
            arrPoint[i].setPoint(rand() % 10, rand() % 10);
        }
    }

    // setFigure;

    void print() {
        for (int i = 0; i < count; i++) {
            arrPoint[i].print();
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }


    ~Figure() {
        delete[] arrPoint;
    }

};
*/



class Point {
protected:
    int x;
    int y;
public:
    Point() : x{ 0 }, y{ 0 }{};
    int& getX() {return x;}
    int& getY() {return y;}
    void print() {
        std::cout << "(" << x << ";" << y << ")" << " ";
    }
};


class Window : public Point {
    int height;
    int width;
public:
    Window(int h, int w) : height{ h }, width{ w }{};

    int& getH() { return height; }
    int& getW() { return width; }

    void moveX(int ux) { x += ux; }
    void moveY(int uy) { y += uy; }

    void print() {
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "H = " << height << std::endl;
        std::cout << "W = " << width << std::endl;
    }
    
};

/*
class A {

};

class B {

};

class C : public A, public B {

};
*/


class Horn{
protected:
    int  lenght;
public:
    Horn() : lenght{ 20 } {};
};

class Hoof {
protected:
    int diametr;
public:
    Hoof() :diametr{ 10 } {};
};

class Elk : public Horn, public Hoof {
    std::string name;
public:
    Elk(const std::string uName) : name{ uName } {};

    void print() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Horn: " << lenght << std::endl;
        std::cout << "Hoof: " << diametr << std::endl;
    }
};


class Student {
protected:
    std::string name;
    int age;
public:
    Student(std::string uName = "Ivan", int uAge = 20) : name{uName}, age{uAge} {};

    void print() {
        std::cout << "Student name: " << name << " age: " << age << std::endl;
    }
};

//////////////////////////////////////////// АГРЕГИРОВАНИЕМ СДЕЛАТЬ
class Aspirant : public Student{
    std::string nameWork;
    bool readyWork;
    
public:
    Aspirant(std::string uName = "Ivan Ivanovich", int uAge = 30, std::string uNameWork = "Work1", bool isReadyWork = 0) : nameWork{ uNameWork }, readyWork{ isReadyWork } {
        Student::name = uName;
        Student::age = uAge;


        ///////////////////////////////////////////////////////////////////////////////////////////
        /*Aspirant2(string name, int num, string utitle, bool udone) :
            Student{ name , num }, title{ utitle }, done{ udone }{};*/
        
    };

    void print() {
        std::cout << "Student name: " << name << " age: " << age << " work: " << nameWork << " " << readyWork << std::endl;
    }
};



class Circle {
protected:
    double r;
    double l;
public:
    Circle(double ur = 1) :r{ ur } {
        l = 2 * 3.14 * r;
    }

    void print() {

    }
};


class Square {
protected:
    double x;
public:
    Square(double ux = 1) : x{ ux } {};

    void print() {

    }
};

//////////////////////////////////////////////////////////////////////////////////////////
class CircleInSquare : public Circle, public Square {
    
public:
    CircleInSquare(double x) : Square{ x }, Circle{ x / 2 } {};
    void print() {
        std::cout << "В квадрат стороной " << x << " вписана окружность длиной " << l << std::endl;
    }

};

int main()
{

    /*Figure f1(10);
    f1.print();*/

    /*Window w1(5, 10);
    w1.print();
    std::cout << w1.getH() << std::endl;
    w1.getX() = 100;
    w1.moveX(-10);
    w1.print();*/


    /*Elk elk1("ELK1");
    elk1.print();*/

    /*Aspirant asp1("John", 35, "SuperWork", 1);
    asp1.print();*/

    CircleInSquare cis1;
    cis1.print();

    return 0;
}




// class NAME : спецификатор NAME_PARENT{
// 
// }

/*
//////////////////////////////////////////// АГРЕГИРОВАНИЕМ СДЕЛАТЬ
Создайте класс Student, который будет содержать
информацию о студенте. С помощью механизма наследования, реализуйте класс Aspirant (аспирант —
студент, который готовится к защите кандидатской
работы) производный от Student.
*/


/*
Используя понятие множественного наследования,
разработайте класс «Окружность, вписанная в квадрат».

результат: в квадрат стороной Х вписана окружность диной L
*/

/* НА ДОМ
Задание №2
Используя механизм множественного наследования разработайте класс “Автомобиль”. Должны быть классы “Колеса», «Двигатель», «Двери» и т.д.



*/
