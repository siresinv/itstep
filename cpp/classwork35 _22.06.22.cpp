// STEP _CPP _classwork35 _22.06.22
/*
ООП НАЧАЛО



*/


#include <iostream>
#include <math.h>

class Point {
private:
	int x, y;

public:
	Point(int ux, int uy) : x{ ux }, y{ uy }{};
	Point() : Point{ 0,0 } {};
	Point(int ux) : Point{ ux , 0 } {};


	void print() {
		std::cout << x << " " << y;
	}
};

class Rect
{
	int h;
	int w;
	Point leftDown;

public:
	Rect() : h{ 10 }, w{ 10 }{};  //Point() : Point{ 0,0 } {}; ??????
	Rect(int uh, int uw, int p) : h{ uh }, w{ uw }, leftDown{ p }{};
	Rect(int uh, int uw, int p1, int p2) : h{ uh }, w{ uw }, leftDown{ p1, p2 }{};


private:

};


class Man {
	char* name;
	int age;

public:
	Man(const char* nameU, int ageU) : name{ nameU ? new char[strlen(nameU) + 1] : nullptr }, age{ ageU }{ // +1
		if (name) strcpy_s(name, strlen(nameU) + 1, nameU);
	};
	Man() : Man(nullptr, 0) {};
	Man(const char* nameU) : Man(nameU, 0) {};
	Man(int ageU) : Man(nullptr, ageU) {};

	void setName(char* nameU) {
		name = new char[strlen(nameU)];
		strcpy_s(name, strlen(nameU), nameU);
	}

	void setAge(int ageU) {
		age = ageU;
	}

	void print() {
		if (name) {
			std::cout << name << " " << age;
		}
		else {
			std::cout << "Noname" << " " << age;
		}
	}


	~Man() {
		if (name) {
			delete[] name;
		}
	}

};




class Student {
	char name[20];
	static int group;


public:
	Student(const char* nameU) {
		strcpy_s(name, strlen(nameU) + 1, nameU);
	};

	void print() {
		std::cout << name << " " << group << std::endl;
	};

	void setGroup(int groupU) {
		group = groupU;
	}

	static int getGroup() {
		return group;
	}

	//~Student(); // тут статика - удалятор не нужен


};


int Student::group{ 111 };








// *********************************************

class Storage {
	int* arr;
	int size;
	static int usedMemory;

public:
	Storage(int uCount) : arr{ new int[uCount] }, size{ uCount }  {
		int used = size * sizeof(arr[0]); // вместо int
		usedMemory += used;
		std::cout << " increment: " << used << " \n";
		std::cout << " All: " << usedMemory << " \n";
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 10;
		}
	}

	~Storage() {
		int clear = size * sizeof(arr[0]); // вместо int
		usedMemory -= clear;
		std::cout << " decrement: " << clear << " \n";
		std::cout << " All:" << usedMemory << " \n";
		delete[] arr;
	}

	static int getMemory() {
		return usedMemory;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
		}
	}
};

int Storage::usedMemory{ 0 };

int main()
{
	srand(time(NULL));

	/*Point p1;
	p1.print();
	Point p2;
	p2.print();
	Point p3;
	p3.print();*/




	/*Man man1 ("Ivan");
	//Man man1;
	//man1.setAge(50);
	man1.print();
	std::cout << std::endl << std::endl;*/




	/*Student s1("Mary");
	Student s2("Ann");
	s1.print();
	s2.print();
	s1.setGroup(222);
	std::cout << " ++" << Student::getGroup() << "++ ";
	s1.print();
	s2.print();*/




	std::cout << "AllBEGIN: " << Storage::getMemory();
	std::cout << std::endl;

	Storage pool[3]{ rand() % 5 + 1, rand() % 5 + 1, rand() % 5 + 1 };

	for (int i = 0; i < 3; i++) {
		pool[i].print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "AllENd: " << Storage::getMemory();

	/// ЗДЕСЬ СРАБОТАЛ ДЕСТРУКТОР !!! 

	std::cout << std::endl;
	return 0;
}

// (arr[0]); // вместо int
