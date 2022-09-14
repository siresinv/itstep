// STEP _CPP _classwork60 _14.09.22 - last
/*
ООП




*/




#include <iostream>
#include <vector>

template <class T>
class Pair {
protected:
    T a;
    T b;
public:
    Pair(T ua, T ub) : a{ ua }, b{ ub }{};

    void print() {
        std::cout << a << " " << b << std::endl;
    }

};


template <class T>
class Trio: public Pair<T> {
    T c;
public:
    Trio(T ua, T ub, T uc) : c{ uc }, Pair<T>{ ua, ub } {};

    void print() {
        std::cout << Pair<T>::a << " " << Pair<T>::b << " " << c << std::endl;
    }

};


//Point -> Rect (point, h, w)



template <class T>
class Point {
protected:
    T x;
    T y;
public:
    Point(T ux, T uy) : x{ ux }, y{ uy }{};
    void print() {
        std::cout << x << " " << y << std::endl;
    }
};


template <class T>
class Square : public Point<T> {
protected:
    T a;
public:
    Square(T ux, T uy, T ua) : a{ ua }, Point<T>{ ux,uy } {};
    void print() {
        std::cout << Point<T>::x << " " << Point<T>::y << a << std::endl;
    }
};


template <class T>
class Rect : public Square<T> {
protected:
    T b;
public:
    Rect(T ux, T uy, T ua, T ub) : b{ ub }, Square<T>{ ux, uy, ua } {};
    void print() {
        std::cout << Square<T>::x << " " << Square<T>::y << " " << Square<T>::a << " " << b << std::endl;
    }
};


// Предположим, у вас есть список целых чисел и вы хотите найти сумму всех четных и сумму всех нечетных.
//// но надо было сделать, чтобы по очереди в мейне числа через функтор передавались, а не вектор целиком
class EvenOdd {
    int sumEven;
    int sumOdd;
public:
    EvenOdd() :sumEven{ 0 }, sumOdd{ 0 } {};

    int getSumEven() {
        return sumEven;
    }

    int getSumOdd() {
        return sumOdd;
    }

    void operator()(/*const*/ std::vector<int>& v1) {
        for ( /*auto*/ std::vector<int>::iterator i = v1.begin(); i != v1.end(); ++i) {
            if (*i % 2 == 0) {
                sumEven += *i;
            }
            else {
                sumOdd += *i;
            }
        }
    }
}​​;


int main()
{

    /*
    Trio<int> t{ 1,2,3 };
    t.print();

    Rect<int> rect1{ 0,0,5,5 };
    rect1.print();
    */

    std::vector<int> v1{ 1,2,3,4,5,6,7,8,9,0 };
    EvenOdd f;
    f(v1);
    std::cout << f.getSumEven();
    std::cout << std::endl;
    std::cout << f.getSumOdd();




    return 0;
}


