#pragma once
#include <iostream>


class Point {
	double x, y;

public:
	Point(double ux, double uy) : x{ ux }, y{ uy }{};
	Point() : Point{ 0,0 } {};
	void display() const;

	void read();

	static bool isEqual(const Point& point1, const Point& point2);
	static Point add(const Point& point1, const Point& point2);
	static Point mult(const Point point1, double value);

	double getX() const {
		return x;
	};


	double getY() const {
		return y;
	};

	// - 2 - перегрузка оперторов друж
	//friend Point operator+(const Point& point1, const Point& point2);

	// - 2 - перегрузка оперторов друж
	//friend Point operator-(const Point& point);

	//// - 3 - перегрузка оперторов через метод класса
//Point operator+(const Point& point) {
//	return Point(x + point.x, y+point.y);
//}

	Point operator-() {
		return Point(-x, -y);
	}


	Point& operator++() { //перегрузка префиксной формы
		++x;
		++y;
		return *this;
	}


	const Point operator++(int) { //перегрузка постфиксной формы //int - фиктивный параметр
		Point p{ *this };
		++(*this);
		return p;
	}


	friend bool operator==(const Point& point1, const Point& point2);

	friend bool operator!=(const Point& point1, const Point& point2);

	friend std::ostream& operator<<(std::ostream& out, const Point& point);

	friend std::istream& operator>>(std::istream& in, Point& point);


};