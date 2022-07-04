#include "cw38_Point.h"
#include <iostream>

void Point::display() const {
	std::cout << "x:" << x << " y:" << y << std::endl;
};

void Point::read() {

	std::cout << "enter x: ";
	std::cin >> x;
	this->x = x;

	std::cout << "enter y: ";
	std::cin >> y;
	this->y = y;

	// ìîæíî std::cin >> x >> y; // è âñ¸ !!! - ÏÎÏĞÎÁÎÂÀÒÜ ĞÅÀÄ ÈÑÏÎËÜÇÎÂÀÒÜ

};

bool Point::isEqual(const Point& point1, const Point& point2) {
	return (point1.x == point2.x && point1.y == point2.y);
};



Point Point::add(const Point& point1, const Point& point2) {
	return Point{ point1.x + point2.x, point1.y + point2.y };
};

Point Point::mult(const Point point1, double value) {
	return Point{ point1.x * value, point1.y * value };
};


