// STEP _CPP _classwork16 _06.04.22 _task3
/*
	РЕКУРСИЯ

*/


#include <iostream>



int fact(int num);

template <class T>
T getExpNum(T num, int degree);
//double getExpNum(double num, int degree);

int main() {
	setlocale(0, "");

	std::cout << fact(5);
	std::cout << std::endl;

	std::cout << getExpNum(2.0, -3);
	std::cout << std::endl;

	return 0;
}


int fact(int num) {
	return (num > 1) ? num * fact(num - 1) : 1;
	//return num * fact(num - 1); //при запуске в режиме отладки, можно найти предел стека при рекурсии )))
}



template <class T>
T getExpNum(T num, int degree) {
//double getExpNum(double num, int degree) {

	if (degree > 0) {
		degree--;
		return num * getExpNum(num, degree);
	}
	else if (degree < 0) {
		++degree;
		return 1/num * getExpNum(num, degree);
	}
	else {
		// если не поставить это условие, то double возвращает неправильное значения
		//return 1;
	}
}

