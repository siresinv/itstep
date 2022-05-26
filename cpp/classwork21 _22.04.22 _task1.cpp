// STEP _CPP _classwork21 _22.04.22 _task1
/*

Динамическая память


ССЫЛКИ


Написать функцию, которая получает указатель на массив и его размер,
и возвращает сумму и произведение его элементов в двух параметрах

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


void initArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		*(arr + i) = rand() % 10;
	}
}


void showArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << *arr++ << " ";
	}
}


int* getSumAndMult(int* arr, int sizeArr) {

	//int* resultArr = new int[2];
	//resultArr[0] = 0;
	//resultArr[1] = 1;

	int* resultArr = new int[2]{ 0, 1 };
	//*resultArr = 0; // - это просто для примера
	//*(resultArr + 1) = 1; // - это просто для примера


	for (int i = 0; i < sizeArr; i++) {
		resultArr[0] += *(arr + i);
		resultArr[1] *= *(arr + i);
	}

	return resultArr;
}


void getSumAndMult2(int* arr, int sizeArr, int* sum, int* mult) {
	
	*sum = 0;
	*mult = 1;

	for (int i = 0; i < sizeArr; i++) {
		*sum += *(arr + i);
		*mult *= *(arr + i);
	}
}


int main() {
	setlocale(0, "");
	srand(time(NULL));

	int* arr = new int[3];

	int sum;
	int mult;

	initArr(arr, 3);
	showArr(arr, 3);
	std::cout << std::endl;


	//showArr ( getSumAndMult(arr, 3), 2);
	getSumAndMult2(arr, 3, &sum, &mult);
	std::cout << sum << " " << mult;
	
	return 0;
}