// STEP _CPP _classwork13 _16.03.22 _task3
/*
Написать функцию, вычисляющую факториал переданного ей числа и возвращающую его
*/


#include <iostream>



int fact(int num);
int fact_recur(int num);

int main() {
	//std::cout << fact(5);
	std::cout << fact_recur(5);
}


int fact(int num) {
	int res = 1;
	for (int i = 1; i <= num; i++) {
		res *= i;
	}
	return res;
}


//САМ СДЕЛЯЛЬ )))
int fact_recur(int num) {
	if (num > 0) {
		return num * fact_recur(num - 1);
	}
}

