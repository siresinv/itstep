// STEP _CPP _classwork15 _30.03.22 _task2
/*

*/


#include <iostream>


int sum(int a, int b) {
	return a + b;
}

double sum(int a, double b, int c) {
	return a + b + c;
}


int main() {
	setlocale(0,"");

	std::cout << sum(5, 5) << " " << sum(2, 2.2, 3);

	return 0;
}

