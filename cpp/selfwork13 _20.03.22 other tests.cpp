// STEP _CPP _selfwork13 _20.03.22 other tests

#include <iostream>


int power(int base, int exp);
int a;

int asd();

int main() {

	std::cout << power(3, 3);
	std::cout << asd();
}


int power(int base, int exp) {

	int i;
	i = 1;
	for (; exp; exp--) {
		std::cout << exp << " ";
		i *= base;
	}

	return i;
}

int asd() {
	a = 1;
	return a;
}