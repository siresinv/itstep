// STEP _CPP _homework15 _30.03.22 _task1
/*
5. Реализуйте перегруженные функции для
■ Нахождения максимального значения двух целых;
■ Нахождения максимального значения трёх целых.
*/


#include <iostream>

int getMax(int num1, int num2) {
	return (num1 > num2) ? num1 : num2;
}

int getMax(int num1, int num2, int num3) {
	int max;
	max = (num1 > num2) ? num1 : num2;
	max = (max > num3) ? max : num3;
	return max;
}

int main() {
	setlocale(0, "");

	std::cout << getMax(9, 2) << std::endl;
	std::cout << getMax(5, 7, 3) << std::endl;

	return 0;
}

