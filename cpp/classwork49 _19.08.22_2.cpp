// STEP _CPP _classwork49 _19.08.22_2
/*
ООП

Вложенные классы


*/


#include <iostream>


/*
class B {

};


class A {
    //
    //
    //
private:
    class B;
public:
    B* ptr; //вложенный
    //B& t; - нельзя
    //B s; - нельзя
};

class A::B {
    static int test;
public:
    B(int value = 0);
    int x;
    int y;
    int z;
};


int A::B::test = 10;

A::B::B(int val) {
    x = 5;
    y = val;
}
*/


/*
class A {
    //
    //
    //
private:
    class First;

    class Second {
        First* ptr;
    };

    class First {
        Second* ptr;
    };
};
*/

/*
class A {
    //
    //
    //
    //int init(int value);
    ////////////////////////// ????????????????????????? В ВИДЕО
public:
    class B {
        B(int value = 0){
            x = value;
        };
        void test(A& a1);
        int x;
    };
};
*/

/*
A::B::B(int value) {
    x = init(x);
}
*/

/*
void A::B::test(A& a1) {
    //x = a1.init(5);
}
*/




class Point {
    int x;
    int y;

public:
    Point() : x{ 0 }, y{ 0 }{};
    void setPoint(int ux, int uy) {
        x = ux;
        y = uy;
    }

    void print() {
        std::cout << "(" << x << ";" << y << ")\n";
    }

    /*int getX() { return x; }
    int getY() { return y; }*/
};


class Figure {
    Point* arrP;
    int nP;
public:
    Figure(int nP = 5) : arrP{ new Point[nP] }, nP{ nP } {
        for (int i = 0; i < nP; i++) {
            arrP[i].setPoint(rand() % 10, rand() % 10);
        }
    }

    //////////////
    void setFigure(int nP) {
        for (int i = 0; i < nP; i++) {
            //this->arrP[i].setPoint(arrP[i].getX(), arrP[i].getY());
            this->arrP[i].setPoint(rand() % 10, rand() % 10);
        }
        this->nP = nP;
    }

    void print() {
        std::cout << "Figure coord: \n";
        for (int i = 0; i < nP; i++) {
            arrP[i].print();
        }
    }

};


class Pict {
    Figure* arrF;
    int nF;
public:
    Pict(int nF = 3): arrF{ new Figure[nF] }, nF{ nF }{
        for (int i = 0; i < nF; i++) {
            ///////////////////
            arrF[i].setFigure(rand() % 5);
        }
    }

    void print() {
        std::cout << "Figure list: \n";
        for (int i = 0; i < nF; i++) {
            arrF[i].print();
        }
    }
};

// НА ДОМ - КЛАСС - РИСУНОК - МАССИВ ФИГУР


int main()
{
    /*
    A a1;
    A::B c;
    c.test(a1); /// ???
    */

    //A x;
    //B y; // внешний

    //A::B c; // вложенный
    //std::cin >> c.y;


    //Figure f1;
    //f1.print();

    Pict p1{10};
    p1.print();

    return 0;
}
