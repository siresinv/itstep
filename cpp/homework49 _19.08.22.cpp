// STEP _CPP _homework49 _19.08.22_experiments
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

    Figure(int nPoint = rand() % 6 + 3) : arrPoint{ new Point[nPoint] }, nPoint{ nPoint } {figureNo++; } // Просто рандомное количество точек с нулевыми координатами

    int getN_Point() {
        return nPoint;
    }

    void setFigure(int nPoint) {
        for (int i = 0; i < nPoint; i++) {
            arrPoint[i].setPoint(rand() % 10, rand() % 10);
        }
    }

    void print() {
        std::cout << "Figure coords: {" << nPoint << "} \n";
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
    static int pictureNo;

    Pict(int nFigure = 3) : arrFigure{ new Figure[nFigure] }, nFigure{ nFigure }{
        pictureNo++;
        for (int i = 0; i < nFigure; i++) {
            arrFigure[i].setFigure(arrFigure[i].getN_Point());
        }
    }

    void print() {
        std::cout << "[FIGURE LIST] \n\n";
        for (int i = 0; i < nFigure; i++) {
            arrFigure[i].print();
            std::cout << std::endl;
        }
        std::cout << "---TOTAL [" << Pict::pictureNo << "] PICTURES---\n";
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
int Pict::pictureNo{ 0 };

int main()
{
    srand(time(NULL));

    Pict p1{5};
    p1.print();


    Pict p2;
    p2.print();

    Pict p3{rand()%5+1};
    p3.print();


    return 0;
}
