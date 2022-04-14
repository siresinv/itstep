// STEP _CPP _homework16 _06.04.22 _task1
/*
	СОРТИРОВКА

*/

#include <iostream>
#include <stdlib.h>
#include <math.h>




template <class T>
void initArr(T arr[], int sizeArr);

template <class T>
void showArr(T arr[], int sizeArr);

template <class T>
double getAvgArr(T arr[], int sizeArr);

template <class T>
void insertSortDiapason(T arr[], int beginId, int endId);

template <class T>
void reverseArrDiapason(T arr[], int beginId, int endId);



int main() {
	srand(time(NULL));

	const int SIZE_ARR = 21;
	int arr[SIZE_ARR];
	int beginSortId;
	int endSortId;
	int beginReverseId;
	int endReverseId;
	double avg;

	initArr(arr, SIZE_ARR);
	showArr(arr, SIZE_ARR);
	std::cout << std::endl;
	avg = getAvgArr(arr, SIZE_ARR);
	std::cout << "Avg = " << avg;
	std::cout << std::endl;

	if (avg > 0) {
		beginSortId = 0;
		endSortId = (SIZE_ARR / 3) * 2 - 1;
		beginReverseId = endSortId + 1;
		endReverseId = SIZE_ARR - 1;
	}
	else {
		beginSortId = 0;
		endSortId = (SIZE_ARR / 3) - 1;
		beginReverseId = endSortId + 1;
		endReverseId = SIZE_ARR - 1;
	}

	insertSortDiapason(arr, beginSortId, endSortId);
	reverseArrDiapason(arr, beginReverseId, endReverseId);
	showArr(arr, SIZE_ARR);
}

template <class T>
void initArr(T arr[], int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		arr[i] = rand() % 41 - 20;
	}
}


template <class T>
void showArr(T arr[], int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << arr[i] << " ";
		if ((i+1) == sizeArr/3 || (i+1) == (sizeArr/3)*2) {
			std::cout << "|";
		}
	}
}


template <class T>
double getAvgArr(T arr[], int sizeArr) {
	int sum;
	sum = 0;
	for (int i = 0; i < sizeArr; i++) {
		sum += arr[i];
	}
	return sum/double(sizeArr);
}


template <class T>
void insertSortDiapason(T arr[], int beginId, int endId) {
	int temp;
	for (int i = beginId +1; i < endId + 1; i++) {
		for (int j = i ; j > beginId && arr[j] < arr[j - 1]; j--) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
		}
	}
}


template <class T>
void reverseArrDiapason(T arr[], int beginId, int endId) {
	int midId;
	int temp;

	midId = (beginId +1) + (endId - beginId) / 2;
	for (int i = beginId; i < midId; i++){
		temp = arr[i];
		arr[i] = arr[endId - (i - beginId)];
		arr[endId - (i - beginId)] = temp;
	}
}
