// STEP _CPP _classwork37 _29.06.22
/*
ООП НАЧАЛО


БУДЕТ НА СЛЕД УРОКЕ
конст метод
иксплисит констр
перегруз операт
*/


#include <iostream>
#include <math.h>
#include "cw37_Point.h"

class DynArr {
	int sizeArr;
	int* arr;

public:
	explicit DynArr(int uSizeArr = 10) :sizeArr{ uSizeArr }, arr{ new int[uSizeArr] }{};
	~DynArr() {
		if (arr) delete[] arr;
	};

	void print(int index) const{
		std::cout << arr[index] << " ";
	}

	int getSize() const {
		return sizeArr;
	}
};


void print(const DynArr& obj) {
	for (int i = 0; i < obj.getSize(); i++) {
		obj.print(i);
	}
}


class Date {
	int day, month, year;

public:
	Date() : day{ 1 }, month{ 10 }, year{ 2000 }{};
	void setDay(int day) {
		this->day = day;
	}
	void setMonth(int month) {
		this->month = month;
	}
	void setYear(int year) {
		this->year = year;
	}

	int getDay() const {
		return day;
	}
	int getMonth() const {
		return month;
	}
	int getYear() const {
		return year;
	}
	void print() const {
		std::cout << day << " " << month << " " << year << std::endl;
	}
};



// - 1 - обычная перегрузка оперторов
//Point operator+(const Point& point1, const Point& point2) {
//	return Point(point1.getX() + point2.getX(), point1.getY() + point2.getY());
//};

// - 1 - обычная перегрузка оперторов
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


//// - 3 - перегрузка оперторов
//Point operator+(const Point& point) {
//	return Point(x + point.x, y+point.y);
//}

Point operator-() {
	return Point(-x, -y);
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
	//p3.display();
	std::cout << std::endl;

	Point p4{ 5,5 };
	p4.display();

	//p1+p2+p3

	return 0;
}


