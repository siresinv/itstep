// STEP _CPP _classwork23 _27.04.22 _task3
/*

Задание 1. Создайте приложение Калькулятор. Нужно
поддерживать операции +, –, *, /.
Реализовать меню без использования операторов if
и switch при помощи массива функций.


*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


int* initArr(int sizeArr) {
	int* arr = new int[sizeArr];
	for (int i = 0; i < sizeArr; i++) {
		*(arr + i) = rand() % 10 + 10;
	}
	return arr;
}


void showArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << *arr++ << " ";
	}
}



void deleteArr(int* arr) {
	delete[] arr;
}




double getPlus(int num1, int num2) {
	return num1 + num2;
}

double getMinus(int num1, int num2) {
	return num1 - num2;
}

double getMult(int num1, int num2) {
	return num1 * num2;
}

double getDiv(int num1, int num2) {
	return num1 / double(num2);
}



int main() {
	setlocale(0, "");
	srand(time(NULL));

	int num1;
	int num2;
	char oper;
	char asciiSignStar = '*';

	std::cout << "Первое число: ";
	std::cin >> num1;
	std::cout << std::endl;

	std::cout << "Второе число: ";
	std::cin >> num2;
	std::cout << std::endl;


	//* + - /   -    42 43 45 47 - ASCII codes
	double operArr[6]{ getMult(num1, num2), getPlus(num1, num2), 0, getMinus(num1, num2), 0, getDiv(num1, num2) };

	std::cout << "Выберите операцию (+ - * /): ";
	std::cin >> oper;
	std::cout << std::endl;

	std::cout << "Результат: ";

	std::cout << operArr[oper - asciiSignStar];
	std::cout << std::endl;


	return 0;
}