// STEP _CPP _homework58 _08.09.22
/*
ООП

list


*/

#include <iostream>
#include <list>


typedef std::list<int>L;

class MyList: public L {
public:

	void print() {
		L::iterator iter;
		std::cout << "MyList: ";
		for (iter = begin(); iter != end(); iter++) {
			std::cout << *iter << " ";
		}
		std::cout << std::endl;
	}

	int getMin() {
		L::iterator it;
		int min = *(this->begin());
		for (it = this->begin(); it != this->end(); it++) {
			if (*it < min) {
				min = *it;
			}
		}
		return min;
	}


	int getMax() {
		L::iterator it;
		int max = *(this->begin());
		for (it = this->begin(); it != this->end(); it++) {
			if (*it > max) {
				max = *it;
			}
		}
		return max;
	}

	void inc(int value) {
		L::iterator it;
		for (it = this->begin(); it != this->end(); it++) {
			*it += value;
		}
	}

	void dec(int value) {
		L::iterator it;
		for (it = this->begin(); it != this->end(); it++) {
			*it -= value;
		}
	}
};


int main() {

	MyList l1;

	for (int i = 0; i < 10; i++) {
		l1.push_back(i);
	}

	l1.print();
	std::cout << l1.getMax() << std::endl;
	std::cout << l1.getMin() << std::endl;

	l1.inc(10);
	l1.print();

	l1.dec(5);
	l1.print();


	return 0;
}



/*Создать my_list на основе list

Реализовать функторы:
	() - print
	(5) - add, subtract
	("max"), ("min") - max/min


Примеры вызова: 
	my_list L;
	for (int i = 0; i < 5; i++)
	{
		L.push_back(i);
	}
	L();
	L(-5);
	L();
	L(10);
	L();
	cout << L("max") << " " << L("min") << endl;
	*/