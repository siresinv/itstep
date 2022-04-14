// STEP _CPP _homework16 _06.04.22 _task1
/*
	СОРТИРОВКА

*/

#include <iostream>
#include <stdlib.h>
#include <math.h>




template <class T>
T initArr(T arr[], int sizeArr);

template <class T>
void showArr(T arr[], int sizeArr);

template <class T>
double getAvgArr(T arr[], int sizeArr);

template <class T>
void insertSortDiapason(T arr[], int begin, int end);

template <class T>
void reverseArrDiapason(T arr[], int begin, int end);



int main() {
	const int SIZE_ARR = 20;
	int arr[SIZE_ARR];
	int beginSort;
	int endSort;
	int beginReverse;
	int endReverse;

	initArr(arr, SIZE_ARR);
	showArr(arr, SIZE_ARR);
	std::cout << std::endl;

	if (getAvgArr(arr, SIZE_ARR) > 0) {
		beginSort = 0;
		endSort = (SIZE_ARR / 3) * 2 + 1;
		beginReverse = (SIZE_ARR / 3) * 2 + 2;
		endReverse = SIZE_ARR;
	}
	else {
		beginSort = 0;
		endSort = (SIZE_ARR / 3) + 1;
		beginReverse = (SIZE_ARR / 3) + 2;
		endReverse = SIZE_ARR;
	}

	insertSortDiapason(arr, beginSort, endSort);
	reverseArrDiapason(arr, beginReverse, endReverse);
	showArr(arr, SIZE_ARR);
}

template <class T>
T initArr(T arr[], int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		arr[i] = rand() % 41 - 20;
	}
}


template <class T>
void showArr(T arr[], int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << arr[i] << " ";
	}
}


template <class T>
double getAvgArr(T arr[], int sizeArr) {
	int sum;
	
	sum = 0;
	for (int i = 0; i < sizeArr; i++) {
		sum += arr[i];
	}

	return sum/sizeArr;
}


template <class T>
void insertSortDiapason(T arr[], int begin, int end) {


}


template <class T>
void reverseArrDiapason(T arr[], int begin, int end) {
	int temp;

	for (int i = begin; i < end/2; i++) {
		temp = arr[i];
		arr[i] = arr[]
	}

}
