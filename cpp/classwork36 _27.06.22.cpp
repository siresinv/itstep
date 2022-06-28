// STEP _CPP _classwork36 _27.06.22
/*
ООП НАЧАЛО

this


Задание самостоятельно на дом
Создайте программу, имитирующую многоквартирный
дом. Необходимо иметь классы “Человек”, “Квартира”,
“Дом”. Класс “Квартира” содержит динамический массив
объектов класса “Человек”. Класс “Дом” содержит массив
объектов класса “Квартира”.
Каждый из классов содержит переменные-члены и функции-члены, которые необходимы для предметной области
класса. Обращаем ваше внимание, что память под строковые значения выделяется динамически. Например, для
ФИО в классе “Человек”. Не забывайте обеспечить классы
различными конструкторами (конструктор копирования
обязателен), деструкторами. В main протестировать работу полученного набора классов.


плюс предыдущую доделать и добавить к новому ДЗ конструктор копирования и другое из этого задания

БУДЕТ НА СЛЕД УРОКЕ
конст метод
икспликт констр
пергруз операт
*/


#include <iostream>
#include <math.h>


class Human {
	char* name;

public:

};


class Flat {
	int num;
	int nHuman;
	Human* humans;
public:
	Flat(int size) :humans{ new Human[num] } {};
};


class House {
	int nFlat;
	Flat* flats;
public:

};







//**************************************

class DynArr {
	int* arr;
	int sizeArr;

public:
	DynArr(int uSizeArr) : arr{ new int[uSizeArr] }, sizeArr{ uSizeArr } {
		std::cout << "Worked CONSTRUCTOR for " << this << std::endl;
	}


	DynArr(const DynArr& obj) : arr{ new int[obj.sizeArr] }, sizeArr{ obj.sizeArr } {
		std::cout << "Worked COPY_CONSTRUCTOR for " << this << std::endl;
		for (int i = 0; i < sizeArr; i++) {
			arr[i] = obj.arr[i];
		}
	}



	void print() {
		for (int i = 0; i < sizeArr; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	DynArr& randomize() {
		for (int i = 0; i < sizeArr; i++) {
			arr[i] = rand() % 10;
		}
		return *this;
	}

	~DynArr() {
		if (arr) delete[] arr;
		std::cout << "Worked DESTRUCTOR for " << this << std::endl;
	}

};





//**************************************

class Date {
	int day, month, year;

public:
	Date(int d, int m, int y) : day{ d }, month{ m }, year{ y } {
		std::cout << "Worked CONSTRUCTOR for " << this << std::endl;
	}

	Date() : Date(10, 11, 1970) {};

	Date(const Date& obj): day{ obj.day }, month{ obj.month }, year{ obj.year }{
		std::cout << "Worked COPY_CONSTRUCTOR for " << this << std::endl;
	}

	void print() {
		std::cout << this->day << " " << this->month << " " << this->year << std::endl;
	}

	Date* setDay(int day) {
		this->day = day;
		return this;
	}

	Date& setMonth(int month) {
		this->month = month;
		return *this;
	}

	Date& setYear(int year) {
		this->year = year;
		return *this;
	}

	~Date() {
		std::cout << "Worked DESTRUCTOR for " << this << std::endl;
	};

};


int main()
{
	srand(time(NULL));




	//**************************************

	//Date d;
	//d.print();

	///*d.setDay(5);
	//d.setMonth(12);
	//d.setYear(1980);*/

	//d.setDay(22)->setMonth(9).setYear(2000);

	//Date d2{ 2,2, 1922 };
	//d2.print();

	//Date d3{ d };
	//d3.print();

	////std::cout << "__" << &d2 << "__";






//**************************************

	DynArr da1{ 10 }; // (10)
	da1.randomize().print();

	DynArr da2{ da1 };
	da2.print();
	
	return 0;
}


