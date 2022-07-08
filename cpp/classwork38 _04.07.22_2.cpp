// STEP _CPP _classwork38 _04.07.22_2
/*
ООП НАЧАЛО

ДАЛЕЕ
констр перемещен
ссылки l r
перегрузка квадр и кругл скобок

*/


#include <iostream>

class Human {
	char* firstName;
	char* secondName;
	void setCharArr(char*& dest, const char* source) {
		dest = new char [strlen(source) + 1];
		strcpy_s(dest, strlen(source) + 1, source);
	}
	void remove() {
		if (firstName) delete[]firstName;
		if (secondName) delete[]secondName;
	}

public:

	Human(const char* fname, const char* sname) {
		if (fname && sname) {
			firstName = new char[strlen(fname) + 1];
			strcpy_s(firstName, strlen(fname) + 1, fname); //+1 ???

			secondName = new char[strlen(sname) + 1];
			strcpy_s(secondName, strlen(sname) + 1, sname);//+1 ???
		}
		else {
			firstName = nullptr;
			secondName = nullptr;
		}
	};

	Human() :Human("", ""){};//nullptr nullptr
	
	Human(const Human& obj) {
		setCharArr(/*this->*/firstName, obj.firstName);
		setCharArr(/*this->*/secondName, obj.secondName);
	};

	~Human() {
		/*if (firstName) delete[]firstName;
		if (secondName) delete[]secondName;*/
		remove();
	};

	void print() {

		std::cout << firstName << " " << secondName << std::endl;

	};

	Human& operator=(const Human& obj){
		if (this != &obj) {
			remove();
			setCharArr(firstName, obj.firstName);
			setCharArr(secondName, obj.secondName);
		}
		return *this;
	};

};


int main()
{

	Human h1("Ivan", "Ivanov");
	h1.print();

	Human h2{ h1 };
	h2.print();

	Human h3;
	h3 = h2;
	h3.print();

	h2 = h2;
	h2.print();

	return 0;
}


