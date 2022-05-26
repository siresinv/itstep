// STEP _CPP _homework22 _26.04.22 _task1
/*

Динамическая память


картинка в ватсапе

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>


int* initArr(int sizeArr) {
	int* arr = new int[sizeArr];
	for (int i = 0; i < sizeArr; i++) {
		*(arr + i) = rand() % 11 - 5;
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




int mathAction(int* arr1, int* arr2, int* sizeArr1, int* sizeArr2, int (*mathFunc)(int*, int* , int*, int*)) {

	return mathFunc(arr1, arr2, sizeArr1, sizeArr2);
}

int getMax(int* arr1, int* arr2, int* sizeArr1, int* sizeArr2) {
	return 1;
}

int getMin(int* arr1, int* arr2, int* sizeArr1, int* sizeArr2) {
	return 2;
}

int getAvg(int* arr1, int* arr2, int* sizeArr1, int* sizeArr2) {
	return 3;
}



int main() {
	setlocale(0, "");
	srand(time(NULL));


	

	int sizeArr1 = 5;
	int sizeArr2 = 10;

	int* arr1 = initArr(sizeArr1);
	int* arr2 = initArr(sizeArr2);

	//int (*funcPointer)();
	//funcPointer = getMax();

	std::cout << mathAction(arr1, arr2, &sizeArr1, &sizeArr2, getAvg);


	return 0;
}