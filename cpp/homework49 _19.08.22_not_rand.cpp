// STEP _CPP _homework49 _19.08.22_not_rand
/*
ООП

Композиция


*/


#include <iostream>
#include <cmath>
#include <ctime>


class Point {
    int x;
    int y;
public:
    static int pointNo;

    Point() : x{ 0 }, y{ 0 }{pointNo++;};
    void setPoint(int ux, int uy) {
        x = ux;
        y = uy;
    }

    void print() {
        std::cout << "(" << x << ";" << y << ")\n";
    }
};


class Figure {
    Point* arrPoint;
    int nPoint;
public:
    static int figureNo;

    Figure(int nPoint = 4) : arrPoint{ new Point[nPoint] }, nPoint{ nPoint } { // Q1
        figureNo++;
        for (int i = 0; i < nPoint; i++) {
            arrPoint[i].setPoint(rand() % 10, rand() % 10);
        }
    }


    void setFigure(int nPoint) {
        for (int i = 0; i < nPoint; i++) {
            arrPoint[i].setPoint(rand() % 10, rand() % 10);
        }
        this->nPoint = nPoint;
    }

    void print() {
        std::cout << "Figure coord: \n";
        for (int i = 0; i < nPoint; i++) {
            arrPoint[i].print();
        }
    }

    ~Figure() {
        delete arrPoint; // Q2
        arrPoint = nullptr;
    }
};


class Pict {
    Figure* arrFigure;
    int nFigure;
public:
    Pict(int nFigure = 3) : arrFigure{ new Figure[nFigure] }, nFigure{ nFigure }{
        for (int i = 0; i < nFigure; i++) {
            arrFigure[i].setFigure(4);
        }
    }

    void print() {
        std::cout << "[FIGURE LIST] \n\n";
        for (int i = 0; i < nFigure; i++) {
            arrFigure[i].print();
            std::cout << std::endl;
        }
        std::cout << "---TOTAL [" << Figure::figureNo << "] FIGURES---\n";
        std::cout << "---TOTAL [" << Point::pointNo << "] POINTS---\n\n\n";
    }

    ~Pict() {
        delete[] arrFigure; // Q3
        arrFigure = nullptr;
    }
};

int Figure::figureNo{ 0 };
int Point::pointNo{ 0 };

int main()
{
    srand(time(NULL));

    Pict p1{5};
    p1.print();

    Pict p2{ 2 };
    p2.print();

    Pict p3{ 2 };
    p3.print();

    Pict p4;
    p4.print();

    Pict p5;
    p5.print();


    return 0;
}
