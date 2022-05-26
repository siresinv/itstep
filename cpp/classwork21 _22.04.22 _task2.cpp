// STEP _CPP _classwork21 _22.04.22 _task2
/*

Динамическая память


ССЫЛКИ


Задание 2. Написать функцию, которая получает указатель на массив и его размер,
и возвращает количество отрицательных, положительных и нулевых элементов массива.

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


void initArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		*(arr + i) = rand() % 10 - 5;
	}
}


void showArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << *arr++ << " ";
	}
}


int* getPosNegNul_amount(int* arr, int sizeArr) {
	int num;
	int* resultArr = new int[3]{ 0, 0, 0 };


	for (int i = 0; i < sizeArr; i++) {
		num = *(arr + i);


		if (num > 0) {
			*resultArr += 1;
		}
		else if (num < 0) {
			*(resultArr)++;
		}
		else {
			*(resultArr +2)++;
		}
	}

	return resultArr;
}



int main() {
	setlocale(0, "");
	srand(time(NULL));

	int* arr = new int[7];

	initArr(arr, 7);
	showArr(arr, 7);
	std::cout << std::endl;

	showArr (getPosNegNul_amount(arr, 7), 3);
	
	return 0;
}