// STEP _CPP _classwork15 _30.03.22 _task4
/*
	СОРТИРОВКИ
*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


void printArr(int arr[], int sizeArr, int currI, int minId) {
	for (int i = 0; i < sizeArr; i++) {
		if (i == currI) std::cout << "|";
		if (i == minId) std::cout << "[";
		std::cout << arr[i];
		if (i != currI && i != minId) std::cout << " ";
		if (i == currI) std::cout << "|";
		if (i == minId) std::cout << "]";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void selectSort(int arr[], int arrSize) {
	int temp;
	int tempId;
	for (int i = 0; i < arrSize; i++) {
		temp = arr[i]; ////
		tempId = i;
		for (int j = i+1; j < arrSize; j++) {
			if (arr[j] < temp) {
				temp = arr[j];
				tempId = j;
			}
		}
		if (tempId != i) {
			arr[tempId] = arr[i];
			arr[i] = temp;
		}

		for (int i = 0; i < 10; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;

	}
}

int selectSort_1(int arr[], int sizeArr) {
	int stepCounter;
	int minId;
	int temp;
	int currI;

	stepCounter = 0;
	for (int i = 0; i < sizeArr; i++) {
		minId = i;
		int j;
		for (j = i+1; j < sizeArr; j++) {
			
			if (arr[j] < arr[minId]) {
				minId = j;
			}
			currI = i;
			
		}

		if (arr[minId] != arr[i]) {
			stepCounter++;
			temp = arr[i];
			arr[i] = arr[minId];
			arr[minId] = temp;
			printArr(arr, sizeArr, i, j);
			
		}
			
	}
	return stepCounter;
}



int selectSort_2(int arr[], int sizeArr) {
	int stepCounter;
	int minId;
	int temp;
	int currI;

	stepCounter = 0;
	for (int i = 0; i < sizeArr; i++) {
		minId = i;
		currI = i;
		for (int j = i + 1; j < sizeArr; j++) {
			
			if (arr[j] < arr[minId]) {
				stepCounter++;
				//stepCounter++;
				minId = j;
				//printArr(arr, sizeArr, currI, minId);
				temp = arr[i];
				arr[i] = arr[minId];
				arr[minId] = temp;
				minId = i;
			}
			printArr(arr, sizeArr, i, j);
		}
		
		/*if (arr[minId] != arr[i]) {
			temp = arr[i];
			arr[i] = arr[minId];
			arr[minId] = temp;
			currI = i;
		}*/
		//printArr(arr, sizeArr, currI, minId);
	}
	return stepCounter;
}



int bubleSort(int arr[], int sizeArr) {
	int stepCounter;
	int temp;

	stepCounter = 0;
	for (int i = 0; i < sizeArr; i++) {
		for (int j = sizeArr - 1; j > i; j--) {
			if (arr[j]<arr[j-1]) {
				stepCounter++;
				printArr(arr, sizeArr, i, j);
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}
	return stepCounter;
}


int bubleSort_1(int arr[], int sizeArr) {
	int stepCounter;
	int temp;

	stepCounter = 0;
	int j = 0;
	for (int i = 0; i < sizeArr-1; i++) {
		for (j = 0; j < sizeArr - i - 1; j++) {
			
			if (arr[j] > arr[j+1]) {
				
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				stepCounter++;
				printArr(arr, sizeArr, i, j);
			}
		}
	}


	return stepCounter;
}


void insertSort(int arr[], int sizeArr) {
	int temp;
	for (int i = 1; i < sizeArr; i++) {
		for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
			temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			printArr(arr, sizeArr, i, j);
		}
	}
}

void shakerSort(int arr[], int arrSize) {


}

int main() {
	setlocale(0, "");
	srand(time(NULL));

	const int SIZE_ARR = 10;
	//int arrNum[SIZE_ARR];

	//int arrNum[SIZE_ARR] = { 5, 2, 7, 1, 3, 8, 4, 5, 9, 0 };
	//int arrNum[SIZE_ARR] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arrNum[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

	/*for (int i = 0; i < SIZE_ARR; i++) {
		arrNum[i] = rand() % 100 + 1;
	}*/


	for (int i = 0; i < SIZE_ARR; i++) {
		std::cout << arrNum[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "___________________" << std::endl;

	//std::cout << bubleSort_1(arrNum, SIZE_ARR);
	insertSort(arrNum, SIZE_ARR);
	std::cout << std::endl;

	//std::cout << selectSort_2(arrNum2, SIZE_ARR);
	//bubleSort(arrNum, 10);
	//insertSort(arrNum, 10); ////

	std::cout << "___________________" << std::endl;
	for (int i = 0; i < SIZE_ARR; i++) {
		std::cout << arrNum[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

