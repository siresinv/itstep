// STEP _CPP _classwork38 _04.07.22
/*
ООП НАЧАЛО


*/


#include <iostream>
//#include <math.h>
#include "cw38_Point.h"





// - 1 - обычная перегрузка оперторов
//Point operator+(const Point& point1, const Point& point2) {
//	return Point(point1.getX() + point2.getX(), point1.getY() + point2.getY());
//};

//// - 1 - обычная перегрузка оперторов
//Point operator-(const Point& point1) {
//	return Point(-point1.getX(), -point1.getY());
//};



// - 2 - перегрузка оперторов друж
//Point operator+(const Point& point1, const Point& point2) {
//	return Point(point1.x + point2.x, point1.y + point2.y);
//};

//Point operator-(const Point& point) {
//	return Point(-point.x, -point.y);
//};



bool operator==(const Point& point1, const Point& point2) {
	return (point1.x == point2.x && point1.y == point2.y);
}


bool operator!=(const Point& point1, const Point& point2) {
	return !(point1 == point2);
}



std::ostream& operator<<(std::ostream& out, const Point& point) {
	std::cout << point.x << " " << point.y << std::endl;
	return out;
}


std::istream& operator>>(std::istream& in, Point& point) {
	std::cin >> point.x >> point.y;
	return in;
}



int main()
{
	srand(time(NULL));
/*
	Date d1;
	d1.setDay(22);
	d1.print();

	const Date d2;
	d2.print();


	DynArr da{ 5 };
	//print(da);

	// print(3); // c explicit нельзя
	print(DynArr{ 3 }); // c explicit нельзя

*/

	Point p1{ 1, 2 };
	Point p2{ 1, 3 };

	p1.display();
	p2.display();

	std::cout << Point::isEqual(p1, p2);
	std::cout << std::endl;
	Point::add(p1, p2).display();
	std::cout << std::endl;
	Point::mult(p1, 3).display();
	std::cout << std::endl;

	//Point p3{ p1 + p2 };
	//Point p3 = p1 + p2;
	// Point p3{Point{1,2} + Point{3,4}}; - Для примера что Point в фигурных скобках нужен обязательно
	//p3.display();
	std::cout << std::endl;

	Point p4{ 5,5 };
	(-p4).display();

	//p1+p2+p3

	std::cout << p2++;
	std::cout << p2;
	std::cout << ++p2;

	std::cin >> p2;

	std::cout << p2;

	if (p1 != p2) {
		std::cout << "Objects is not equal";
	}
	else {
		std::cout << "Objects is equal";
	}

	return 0;
}


