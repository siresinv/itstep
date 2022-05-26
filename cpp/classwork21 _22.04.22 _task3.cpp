// STEP _CPP _classwork21 _22.04.22 _task3
/*

Динамическая память


ССЫЛКИ


Задание 3. Написать функцию, принимающую в качестве аргумента,
указатели на два массива (А и В) и размеры массивов.
Функция проверяет, является ли массив В подмножеством/подмассивом
массива А и возвращает указатель на начало найденного
фрагмента, либо возвращает 0 в противном случае.

НЕ ПОВТОРЯЮЩИЙСЯ БОЛЬШОЙ МАССИВ СДЕЛАТЬ

И ВСЕ ТАКИ ПОДМАССИВ НАЙТИ
12345678
3456


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


int* getSubSet(int* arr1, int* arr2, int sizeArr1, int sizeArr2) {
	bool isNumInArr;
	for (int i = 0; i < sizeArr2; i++) {
		isNumInArr = false;
		for (int j = 0; j < sizeArr1; j++) {
			if (*(arr1 + j) == *(arr2 + i)) {
				isNumInArr = true;
				break;
			}
		}
		if (isNumInArr == false) {
			return nullptr;
		}
	}
	return arr2;
}


int* getSubArr(int* arr1, int* arr2, int sizeArr1, int sizeArr2) {

	bool isSubSet = false;

	for (int i = 0; i < sizeArr1; i++) {
		if (*(arr1 + i) == *arr2 && sizeArr1 - i - 1 >= sizeArr2 - 1) {
			isSubSet = true;
			for (int j = 0; j < sizeArr2; j++) {
				if (*(arr1 + j + i) != *(arr2 + j)) {
					isSubSet = false;
					break;
				}
			}
			if (isSubSet == true) {
				return arr2;
			}
		}
	}
	return nullptr;
}


int main() {
	setlocale(0, "");
	srand(time(NULL));

	int sizeArr1 = 10;
	int sizeArr2 = 5;

	int* arr1 = new int[sizeArr1] {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	int* arr2 = new int[sizeArr2] {5, 6, 7, 8, 9};

	//initArr(arr1, sizeArr1);
	showArr(arr1, sizeArr1);
	std::cout << std::endl;

	//initArr(arr2, sizeArr2);
	showArr(arr2, sizeArr2);
	std::cout << std::endl;

	//int* subSet = getSubSet(arr1, arr2, sizeArr1, sizeArr2);
	int* subArr = getSubArr(arr1, arr2, sizeArr1, sizeArr2);

	if (subArr){
		showArr(subArr, sizeArr2);
	}
	else {
		std::cout << "Не подмассив";
	}
	
	return 0;
}