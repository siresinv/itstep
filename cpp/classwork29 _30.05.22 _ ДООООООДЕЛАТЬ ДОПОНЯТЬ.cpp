// STEP _CPP _classwork29 _30.05.22
/*




*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <stdlib.h>


struct date {
	int day;
	int month;
	int year;
};

struct employee{
	char name[20];
	int age;
	date birth;
};


struct struc {
	char ch;
	int i;
};

void showStruct(employee empl) {
	std::cout << empl.name << " ";
	std::cout << empl.age << " ";
	std::cout << empl.birth.day << " ";
	std::cout << empl.birth.month << " ";
	std::cout << empl.birth.year << " ";
}


employee initStruct() {
	employee empl;
	std::cout << "Имя: ";
	std::cin >> empl.name;
	std::cout << "Возраст: ";
	std::cin >> empl.age;
	std::cout << "День: ";
	std::cin >> empl.birth.day;
	std::cout << "Месяц: ";
	std::cin >> empl.birth.month;
	std::cout << "Год: ";
	std::cin >> empl.birth.year;
	return empl;
}

// // ДОДЕЛАТЬ
void initStruct2(char name[], int& age, int& day, int& month, int& year) {
	employee empl2;
	std::cout <<  "Имя: ";
	std::cin >> empl2.name;
	std::cout << "Возраст: ";
	std::cin >> empl2.age;
	std::cout << "День: ";
	std::cin >> empl2.birth.day;
	std::cout << "Месяц: ";
	std::cin >> empl2.birth.month;
	std::cout << "Год: ";
	std::cin >> empl2.birth.year;
}



bool isLeapYear(date date1) {
	if (date1.year) {
		return true;
	}

	return false;
}


// // доделать. А ЕЩЕ МОЖНО ПЕРЕДАВАТЬ ЧЕРЕЗ ССЫЛКУ
void showStruct_pointer(employee empl) {
	std::cout << empl.name << " ";
	std::cout << empl.age << " ";
	std::cout << empl.birth.day << " ";
	std::cout << empl.birth.month << " ";
	std::cout << empl.birth.year << " ";
}

int main() {
	setlocale(0, "");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	date birthday = { 10, 12, 1980 };

	//cout
	//cin

	/*std::cout << birthday.month;

	employee empl;
	std::cin >> empl.birth.month;

	date d = { 12,12,1980 };
	std::cout << d.day << " ";
	std::cout << d.month << " ";
	std::cout << d.year << " ";

	

	date* p2 = &d;
	date d1 = { 12,12,1980 };
	std::cout << p2 -> day << " ";
	std::cout << p2->month << " ";
	std::cout << p2->year << " ";

	date a = d; //копирует, только если d-неуказатель
	std::cout << a.day << " ";
	std::cout << a.month << " ";
	std::cout << a.year << " ";*/


	//employee empl1 = initStruct();


	/*char name[20];
	int age;
	int day;
	int month;
	int year;*/

	/*employee empl2;
	std::cout << "Имя: ";
	std::cin >> name;
	std::cout << "Возраст: ";
	std::cin >> age;
	std::cout << "День: ";
	std::cin >> day;
	std::cout << "Месяц: ";
	std::cin >> month;
	std::cout << "Год: ";
	std::cin >> year;*/
	
	//initStruct2(name, age, day, month, year);
	//employee* empl2;

	//empl1 = { "Ivan", 20 ,{10,12,1980} };
	//empl1 = { "Stepan", 40 ,{10,12,1980} };


	//empl1;
	//showStruct(empl2);

	// std::cout << isLeapYear(date.year); ///////// ДОДЕЛАТЬ

	/*int a;
	char b;
	double c;
	int* p;
	double* z;
	char* y;
	int& x = a;

	std::cout << sizeof(a) << " ";
	std::cout << sizeof(b) << " ";
	std::cout << sizeof(c) << " ";
	std::cout << sizeof(p) << " ";
	std::cout << sizeof(z) << " ";
	std::cout << sizeof(y) << " ";
	std::cout << sizeof(b) << " ";*/


	struc struc1 = { 'k', 100 };

	std::cout << sizeof(struc) << " " << sizeof(struc1);

	return 0;
}