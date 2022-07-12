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
		this->name = new char[strlen(name) + 1]; //////////////////////////////
		strcpy_s(this->name, strlen(name) + 1, name);
		//std::cout << "Constructor Human" << std::endl;
	}

	void remove() {
		if (name) {
			delete[]name;
			name = nullptr;
			//std::cout << "Destructor Human" << std::endl;
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


	Human& operator=(const Human& obj) {
		if (this != &obj) {
			remove();
			setHuman(obj.name);
		}
		return *this;
	}

	char* getName() {
		return name;
	}

};


class Flat {
private:
	int nHuman;
	Human* humans;

	void setFlat(int nHuman) {
		this->nHuman = nHuman;
		humans = new Human[nHuman];
		//std::cout << "Constructor Flat" << std::endl;
	}

	void remove() {
		if (humans) {
			delete[]humans;
			humans = nullptr;
			//std::cout << "Destructor Flat" << std::endl;
			
		}
	}

public:
	Flat(int nHuman) {
		setFlat(nHuman);
	}

	//Flat() : humans{ new Human[nHuman = rand() % 5 + 1]{"John"} } {};

	Flat() : Flat{ rand() % 5 + 1 } {};

	~Flat() {
		remove();
	}

	Flat& operator=(const Flat& obj) {
		if (this != &obj) {
			remove();
			setFlat(obj.nHuman);
			for (int i = 0; i < obj.nHuman; i++) {
				humans[i] = obj.humans[i];
			}
		}
		return *this;
	}

	char** getHumans() {
		char** humanList = new char* [nHuman];
		for (int i = 0; i < nHuman; i++) {
			humanList[i] = humans[i].getName();
		}
		return humanList;
	}

	int getN_Humans() {
		return nHuman;
	}

};


class House {
private:
	int nFlat;
	Flat* flats;

	void setHouse(int nFlat) {
		this->nFlat = nFlat;
		flats = new Flat[nFlat];
		//std::cout << "Constructor House" << std::endl;
	}

	void remove() {
		if (flats) {
			delete[] flats;
			flats = nullptr;
			//std::cout << "Destructor House" << std::endl;
		}
	};

public:
	House(int nFlat) {
		setHouse(nFlat);
	}

	House() :House(0){};

	~House() {
		remove();
	}

	House& operator=(const House& obj) {

		if (this != &obj) {
			remove();
			setHouse(obj.nFlat);
			for (int i = 0; i < nFlat; i++) {
				flats[i] = obj.flats[i];
			}
		}
		return *this;
	}


	void showHouse() {
		std::cout << "House N: Flat amount: " << nFlat << std::endl;
		
		int nHuman;
		for (int f = 0; f < nFlat; f++) {
			nHuman = flats[f].getN_Humans();
			std::cout << "Flat N: " << f + 1 << " Humans amount: " << nHuman << std::endl;
			for (int h = 0; h < nHuman; h++) {
				std::cout << "Human N:" << h+1 << " - " << flats[f].getHumans()[h] << std::endl;
			}
		}
	}
};



int main()
{
	srand(time(NULL));

	int a = rand() % 5 + 1;

	House h1{3};
	House h2;
	h2 = h1;

	std::cout << std::endl;
	std::cout << std::endl;
	h2.showHouse();
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}
