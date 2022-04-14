// STEP _CPP _homework18 _13.04.22 _task1-3
/*

BULLS AND COWS
*/


#include <iostream>
#include <stdlib.h>
#include <math.h>



void initArr(int* arr, int sizeArr);
void showArr(int* arr, int sizeArr);
void copyArr(int* arr1, int* arr2, int sizeArr);

void reverceArr1(int* arr, int sizeArr, int counter);
void swapAB1(int& leftId, int& rightId);

void reverceArr2(int* arr, int sizeArr, int counter);
void swapAB2(int* leftId, int* rightId);

void copyReverceArr(int* arr1, int* arr2, int sizeArr);

int main() {
	setlocale(0, "");
	srand(time(NULL));
	const int SIZE_ARR = 10;
	int sizeArr = SIZE_ARR;
	int arr1[SIZE_ARR];
	int arr2[SIZE_ARR];
	int arr3[SIZE_ARR];

	initArr(arr1, sizeArr);
	showArr(arr1, sizeArr);
	std::cout << " - Первый массив" << std::endl;

	copyArr(arr1, arr2, sizeArr); //&sizeArr
	showArr(arr2, sizeArr);
	std::cout << " - первый скопировали во второй" << std::endl;

	reverceArr1(arr2, sizeArr, 0);
	showArr(arr2, sizeArr);
	std::cout << " - Перевернули второй" << std::endl;

	reverceArr2(arr1, sizeArr, 0);
	showArr(arr1, sizeArr);
	std::cout << " - Перевернули первый" << std::endl;


	copyReverceArr(arr1, arr3, sizeArr);
	showArr(arr3, sizeArr);
	std::cout << " - Первый скопировали опять перевернутым в третий" << std::endl;

	return 0;
}


void initArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		*arr++ = rand() % 100;
	}
}

void showArr(int* arr, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		std::cout << *arr++ << " ";
	}
}

void copyArr(int* arr1, int* arr2, int sizeArr) {
	if (sizeArr > 0) {
		*arr2++ = *arr1++;
		copyArr(arr1, arr2, --sizeArr);
	}
}

void reverceArr1(int* arr, int sizeArr, int counter) {
	if (counter < sizeArr/2) {
		int *leftId = (arr + counter);
		int *rightId = (arr + (sizeArr - 1) - counter);
		swapAB1(*leftId, *rightId);
		reverceArr1(arr, sizeArr, ++counter);
	}
}

void swapAB1(int &leftId, int &rightId) {
	int temp = leftId;
	leftId = rightId;
	rightId = temp;
}


void reverceArr2(int* arr, int sizeArr, int counter) {
	if (counter < sizeArr/2) {
		int *leftId = (arr + counter);
		int *rightId = (arr + (sizeArr - 1) - counter);
		swapAB2(leftId, rightId);
		reverceArr2(arr, sizeArr, ++counter);
	}
}


void swapAB2(int* leftId, int* rightId) {
	int temp = *leftId;
	*leftId = *rightId;
	*rightId = temp;
	
}


void copyReverceArr(int* arr1, int* arr2, int sizeArr) {
	for (int i = 0; i < sizeArr; i++) {
		*arr2++ = *((sizeArr - 1) + arr1--);
	}
}