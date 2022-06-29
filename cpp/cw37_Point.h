#pragma once


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
		
