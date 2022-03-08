// STEP _CPP _classwork9 _16.02.22 _task1
/*
Ќаписать программу, котора€ находит минимальное
и максимальное значение в массиве и показывает их на
экран.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	const int arrSize = 10;
	int arr[arrSize];
	int minElem;
	int maxElem;

	srand(time(NULL));

	for (int i = 0; i < arrSize; i++) {
		arr[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	minElem = arr[0];
	maxElem = arr[0];
	for (int k = 1; k < arrSize; k++) {
		minElem = (minElem > arr[k]) ? arr[k] : minElem;
		maxElem = (maxElem < arr[k]) ? arr[k] : maxElem;
	}

	std::cout << minElem << " " << maxElem;

	return 0;
}