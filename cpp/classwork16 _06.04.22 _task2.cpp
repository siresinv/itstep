// STEP _CPP _classwork16 _06.04.22 _task2
/*
	СОРТИРОВКИ

2. Дан массив случайных чисел в диапазоне от –20 до +20.
Необходимо найти позиции крайних отрицательных
элементов (самого левого отрицательного элемента
и самого правого отрицательного элемента) и отсортировать элементы, находящиеся между ними.

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>

template <class T>
void selectSortDiapason(T arr[], int begin, int end);

template <class T>
void showArr(T arr[], int sizeArr);

template <class T>
T get_LR_NegativeId(T arr[], int sizeArr, char side); //side: l - left, r - right




int main() {
	srand(time(NULL));

	const int SIZE_ARR = 10;
	int arr[SIZE_ARR];
	int begin;
	int end;

	for (int i = 0; i < SIZE_ARR; i++) {
		arr[i] = rand() % 41 - 20;
	}

	showArr(arr, SIZE_ARR);
	std::cout << std::endl;
	std::cout << std::endl;
	if (get_LR_NegativeId(arr, SIZE_ARR, 'l') != -1 && get_LR_NegativeId(arr, SIZE_ARR, 'r') != -1) {
		begin = get_LR_NegativeId(arr, SIZE_ARR, 'l');
		end = get_LR_NegativeId(arr, SIZE_ARR, 'r');
		selectSortDiapason(arr, begin, end);
	}
	showArr(arr, SIZE_ARR);
	std::cout << std::endl;
	
	return 0;
}


template <class T>
void selectSortDiapason(T arr[], int begin, int end) {
	int searchId;
	T temp;

	for (int i = begin; i <= end; i++) {
		searchId = i;
		for (int j = i + 1; j <= end; j++) {
			if (arr[j] < arr[searchId]) {
				searchId = j;
			}
		}
		if (i != searchId) {
			temp = arr[i];
			arr[i] = arr[searchId];
			arr[searchId] = temp;
		}
	}
}


template <class T>
void showArr(T arr[], int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << arr[i] << " ";
	}
}


template <class T>
T get_LR_NegativeId(T arr[], int sizeArr, char side) { //side: l - left, r - right

	for (int i = 0; i < sizeArr; i++) {
		if (side == 'l') {
			if (arr[i] < 0) return i;
		}
		else {
			if (arr[sizeArr - i - 1] < 0) return sizeArr - i - 1;
		}
		
	}
	return -1;
}

