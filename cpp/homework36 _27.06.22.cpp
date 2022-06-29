﻿// STEP _CPP _homework36 _27.06.22
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
	static int num;

public:

	Human(const char* name) :name{ new char[strlen(name)+1] } {
		strcpy_s(this->name, strlen(name) + 1, name);
		std::cout << "Worked CONSTRUCTOR for " << "Human " << ++num << " - " << name << std::endl;
	}
	Human() : Human{ "NoName" } {};

	~Human() {
		if (name) delete[] name;
		name = nullptr;
	}

	static void setNumZero() {
		num = 0;
	}
};


class Flat {
	static int num;
	int nHuman;
	Human* humans;

public:
	Flat() : humans{ new Human[nHuman = rand() % 5 + 1]{"John"}} {
		std::cout << "Worked CONSTRUCTOR for " << "|Flat| " << ++num << std::endl;
		Human::setNumZero();
	};

	~Flat() {
		if (humans) delete[] humans;
		humans = nullptr;
	}

	static void setNumZero() {
		num = 0;
	}

	int getNum() {
		return num;
	}

	int getN_Human() {
		return nHuman;
	}

	void setNum(int num) {
		this->num = num;
	}

	void setN_Human(int nHuman) {
		this->nHuman = nHuman;
	}

};


class House {
	static int num;
	int nFlat;
	Flat* flats;

public:
	House(int nFlat) : flats{ new Flat[nFlat]} {
		std::cout << "Worked CONSTRUCTOR for " << "/\\House/\\ " << ++num << std::endl;
		this->nFlat = nFlat;
		Flat::setNumZero();
	};


	House(const House& obj) : nFlat{obj.nFlat}, flats { new Flat[obj.nFlat] } {
		num = obj.num + 1;
		std::cout << "Worked COPY_CONSTRUCTOR for " << "/\\House/\\ " << num << std::endl;
		//копирование квартир с людьми???
	}

	~House() {
		if (flats) delete[] flats;
		flats = nullptr;
	}

	House* getN() {
		std::cout << "House N" << num;
		return this;
	}

	House* getN_Flat() {
		std::cout << " | Flats amount: " << nFlat;
		return this;
	}

	House* getN_Human() {
		int nHumans = 0;
		for (Flat* flat = flats; flat < flats + nFlat; flat++) {
			nHumans += flat->getN_Human();
		}
		std::cout << " | Humans amount: " << nHumans;
		return this;
	}
};


int Human::num{ 0 };
int Flat::num{ 0 };
int House::num{ 0 };



int main()
{
	srand(time(NULL));

	House h1(3);
	std::cout << std::endl;
	h1.getN()->getN_Human();
	std::cout << std::endl;
	std::cout << std::endl;

	House h2(2);
	std::cout << std::endl;
	h2.getN()->getN_Flat()->getN_Human();
	std::cout << std::endl;
	std::cout << std::endl;

	House h3{h2};
	std::cout << std::endl;
	h3.getN()->getN_Flat()->getN_Human();
	std::cout << std::endl;
	std::cout << std::endl;


	return 0;
}


