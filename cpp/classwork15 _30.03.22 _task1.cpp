// STEP _CPP _classwork15 _30.03.22 _task1
/*
* макрос по-модулю
*/


#define ABS(X) ((X > 0)?(X): -(X))
#define MAX(X, Y) ((X > Y)?(X):(Y))
#include <iostream>







int main() {
	setlocale(0,"");

	std::cout << ABS(-5) << std::endl;
	std::cout << MAX(5, 1 + 6);

	return 0;
}

