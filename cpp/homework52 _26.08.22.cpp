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
	//virtual void calcLeftDownPoint() = 0;
		 virtual void calcRightDownPoint() {
			std::cout << "Point left down Point (" << x << "; " << y << ")";
			std::cout << std::endl;
		};

		 virtual void draw() = 0;
};


class Square : public Point {
protected:
	int a;
public:
	Square(int ux, int uy, int ua) : Point{ ux,uy }, a { ua }{};
	void calcRightDownPoint() {
		std::cout << "Square left down Point (" << Point::x + a << "; " << y - a << ")";
		std::cout << std::endl;
	}

	void draw() {
		int** raw = new int*[a];
		for (int i = 0; i < a; i++) {
			raw[i] = new int[a];
		}

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				raw[i][j] = 1;
			}
		}

		for (int i = 0; i < a; i++) {
			for (int j = 0; j < a; j++) {
				//std::cout << raw[i][j];
				if (raw[i][j] == 1) {
					std::cout << "* ";
				}
				else {
					std::cout << ". ";
				}
				
			}
			std::cout << std::endl;
		}
	}
};


class Rectangle : public Square {
protected:
	int b;
public:
	Rectangle(int ux, int uy, int ua, int ub) : Square{ ux,uy ,ua }, b{ ub }{};
	void calcRightDownPoint() {
		std::cout << "Rectangle left down Point (" << Point::x + a << "; " << y - b << ")";
		std::cout << std::endl;
	}
};


class Circle : public Square {
protected:
	int r;
public:
	Circle(int ux = 0, int uy = 0, int ur = 1) : Square{ ux-ur, uy+ur, ur*2 }, r{ ur }{};
	void calcRightDownPoint() {
		std::cout << "Circle left down Point (" << x + r*2 << "; " << y - r*2 << ")";
		std::cout << std::endl;
	}

	void draw() {
		int** raw = new int* [r*2];
		for (int i = 0; i < r*2; i++) {
			raw[i] = new int[r*2];
		}

		for (int i = 0; i < r*2; i++) {
			for (int j = 0; j < r*2; j++) {
				raw[i][j] = 1;

				

				if ((j - r - x) * (j - r - x) + (i - r - y) *(i - r - y) <= r * r){ //////////////////////////////
					raw[i][j] = 2;
				}

				if (x + j == 0) {
					raw[i][j] = 3;
				}

				if (y - i == 0) {
					raw[i][j] = 4;
				}

			}
		}

		for (int i = 0; i < r*2; i++) {
			for (int j = 0; j < r*2; j++) {
				//std::cout << raw[i][j];
				if (raw[i][j] == 1) {
					std::cout << "* ";
				}
				else if (raw[i][j] == 2) {
					std::cout << "o ";
				}
				else if (raw[i][j] == 3) {
					std::cout << "| ";
				}
				else {
					std::cout << "- ";
				}
					
				

			}
			std::cout << std::endl;
		}
	}

};


class Ellips : public Rectangle {
protected:
	int b;
public:
	Ellips(int ux, int uy, int ua, int ub) : Rectangle{ ux, uy ,ua, ub }, b{ ub }{};
	void calcRightDownPoint() {
		std::cout << "Ellips left down Point (" << x + a << "; " << y - b << ")";
		std::cout << std::endl;
	}
};

int main() {



	Point* figures[4] = { new Square{-1, 7, 12}, new Rectangle{ -1,1,2,3}, new Circle{-5,-5, 10}, new Ellips{-1,1,5,2} };

	/*Point p1{ -1, -1 };
	p1.calcRightDownPoint();*/

	//Point::calcRightDownPoint();

	for (int i = 0; i < 4; i++) {
		figures[i]->calcRightDownPoint();
	}

	figures[0]->draw();
	figures[2]->draw();

	for (int i = 0; i < 4; i++) {
		delete figures[i];
	}

	return 0;
}