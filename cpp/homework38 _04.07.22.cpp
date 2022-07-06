// STEP _CPP _homework38 _04.07.22
/*
ООП НАЧАЛО


*/


#include <iostream>
//#include <math.h>


class Human {
private:
	char* name;

	void setHuman(const char* name) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		std::cout << "Constructor Human" << std::endl;
	}

	void remove() {
		if (name) {
			delete[]name;
			name = nullptr;
			std::cout << "Destructor Human" << std::endl;
		}
	}

public:
	Human(const char* name) {
		setHuman(name);
	}
	Human() :Human{ "NoName" } {};

	~Human() {
		remove();
	}

	Human operator=(const Human& obj);

};


class Flat {
private:
	int nHuman;
	Human* humans;

	void setFlat(int nHuman) {
		humans = new Human[nHuman];
		std::cout << "Constructor Flat" << std::endl;
	}

	void remove() {
		if (humans) {
			delete[]humans;
			humans = nullptr;
			std::cout << "Destructor Flat" << std::endl;
		}
	}

public:
	Flat(int nHuman) {
		setFlat(nHuman);
	}

	Flat() :Flat{ 3 }{};

	~Flat() {
		remove();
	}

	Flat operator=(const Flat& obj);

};


class House {
private:
	int nFlat;
	Flat* flats;

	void setHouse(int nFlat) {
		flats = new Flat[nFlat];
		std::cout << "Constructor House" << std::endl;
	}

	void remove() {
		if (flats) {
			delete[] flats;
			flats = nullptr;
			std::cout << "Destructor House" << std::endl;
		}
	};

public:
	House(int nFlat) {
		setHouse(nFlat);
	}

	~House() {
		remove();
	}

	House operator=(const House& obj);
};


Human Human::operator=(const Human& obj) {
	return *this;
}


Flat Flat::operator=(const Flat& obj) {
	return *this;
}


House House::operator=(const House& obj) {
	// проверку, что объект приравнивается не сам себе

	remove();
	setHouse(obj.nFlat);

	return *this;
}



int main()
{
	srand(time(NULL));

	House h1{2};
	House h2{2};
	h2 = h1;

	return 0;
}


