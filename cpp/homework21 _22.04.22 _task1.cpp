// STEP _CPP _homework21 _22.04.22 _task1
/*

Динамическая память


в картинке

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


int* initArr(int sizeArr) {
	int* arr = new int[sizeArr];
	for (int i = 0; i < sizeArr; i++) {
		*(arr + i) = rand() % 10;
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


int* addToEndArr(int* arr, int* sizeArr, int num) {

	int newSizeArr = *sizeArr + 1;

	int* arr2 = new int[newSizeArr];

	for (int i = 0; i < *sizeArr; i++) {
		*(arr2 + i) = *(arr + i);
	}
	*(arr2 + *sizeArr) = num;

	deleteArr(arr);

	*sizeArr = newSizeArr;

	return arr2;
}


int* insElemByIdToArr(int* arr, int* sizeArr, int id, int num) {

	if (id >= 0 && id < *sizeArr) {

		int newSizeArr = *sizeArr + 1;

		int* arr2 = new int[newSizeArr];

		for (int i = 0; i < id; i++) {
			*(arr2 + i) = *(arr + i);
		}

		*(arr2 + id) = num;

		for (int i = id; i < newSizeArr; i++) {
			*(arr2 + i + 1) = *(arr + i);
		}


		deleteArr(arr);

		*sizeArr = newSizeArr;

		return arr2;
	}
	else {
		return arr;
	}


	
}



int* delElemByIdToArr(int* arr, int* sizeArr, int id) {

	if (id >= 0 && id < *sizeArr) {

		int newSizeArr = *sizeArr - 1;

		int* arr2 = new int[newSizeArr];

		for (int i = 0; i < id; i++) {
			*(arr2 + i) = *(arr + i);
		}

		for (int i = id + 1; i < *sizeArr; i++) {
			*(arr2 + i - 1) = *(arr + i);
		}


		deleteArr(arr);

		*sizeArr = newSizeArr;

		return arr2;
	}
	else {
		return arr;
	}
}




int main() {
	setlocale(0, "");
	srand(time(NULL));

	int sizeArr = 10;

	std::cout << "Инициализировали массив: \t";
	int* arr = initArr(sizeArr);
	showArr(arr, sizeArr);
	std::cout << std::endl;

	int addNum = 11;
	std::cout << "Добавили в конец " << addNum << ":\t\t";
	arr = addToEndArr(arr, &sizeArr, addNum);
	showArr(arr, sizeArr);
	std::cout << std::endl;

	int addId = 5;
	addNum = 11;
	std::cout << "Вставили по индексу " << addId << " число " << addNum << ":\t";
	arr = insElemByIdToArr(arr, &sizeArr, addId, addNum);
	showArr(arr, sizeArr);
	std::cout << std::endl;


	int delId = 8;
	std::cout << "Удалили элемент по индексу " << delId << ": ";
	std::cout << " \t";
	arr = delElemByIdToArr(arr, &sizeArr, delId);
	showArr(arr, sizeArr);
	std::cout << std::endl;

	deleteArr(arr);

	return 0;
}