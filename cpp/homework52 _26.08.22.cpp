// STEP _CPP _homework52 _26.08.22.cpp
/*
ООП

Наследование


*/


#include <iostream>


class Point {
protected:
	int x;
	int y;

public:
	Point(int ux, int uy) : x{ ux }, y{ uy } {};
	virtual void calcRightDownPoint() = 0;
		 /*virtual void calcRightDownPoint() {
			std::cout << "Point right down Point (" << x << "; " << y << ")";
			std::cout << std::endl;
		};*/
};


class Square : public Point {
protected:
	int a;
public:
	Square(int ux, int uy, int ua) : Point{ ux,uy }, a { ua }{};
	void calcRightDownPoint() {
		//Point::calcRightDownPoint();
		std::cout << "Square right down Point (" << x + a << "; " << y - a << ")";
		std::cout << std::endl;
	}
};


class Rectangle : public Square {
protected:
	int b;
public:
	Rectangle(int ux, int uy, int ua, int ub) : Square{ ux,uy ,ua }, b{ ub }{};
	void calcRightDownPoint() {
		std::cout << "Rectangle right down Point (" << x + a << "; " << y - b << ")";
		std::cout << std::endl;
	}
};


class Circle : public Square {
protected:
	int r;
public:
	Circle(int ux = 0, int uy = 0, int ur = 1) : Square{ ux-ur, uy+ur, ur*2 }, r{ ur }{};
	void calcRightDownPoint() {
		std::cout << "Circle right down Point (" << x + r*2 << "; " << y - r*2 << ")";
		std::cout << std::endl;
	}
};


class Ellips : public Rectangle {
protected:
	int b;
public:
	Ellips(int ux, int uy, int ua, int ub) : Rectangle{ ux, uy ,ua, ub }, b{ ub }{};
	void calcRightDownPoint() {
		std::cout << "Ellips right down Point (" << x + a << "; " << y - b << ")";
		std::cout << std::endl;
	}
};

int main() {
	
	Point* figures[4] = { new Square{-1, 7, 12}, new Rectangle{ -1,1,2,3}, new Circle{-5,-5, 10}, new Ellips{-1,1,5,2} };

	//Point->calcRightDownPoint();

	for (int i = 0; i < 4; i++) {
		figures[i]->calcRightDownPoint();
	}

	for (int i = 0; i < 4; i++) {
		delete figures[i];
	}

	return 0;
}