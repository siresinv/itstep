// STEP _CPP _homework20 _20.04.22 _task1
/*

Динамическая память


ССЫЛКИ

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


int getSameElemAmount(int* arr1, int* arr2, int sizeArr1, int sizeArr2) {

	int nSameElement = 0;

	for (int i = 0; i < sizeArr1; i++) {
		for (int j = 0; j < sizeArr2; j++) {
			if (*(arr1 + i) == *(arr2 + j)) {
				nSameElement++;
				break;
			}
		}
	}

	return nSameElement;
}

int* joinSameElem2Arr(int* arr1, int* arr2, int sizeArr1, int sizeArr2, int* sizeArr3) {
	
	int counter = 0;

	*sizeArr3 = getSameElemAmount(arr1, arr2, sizeArr1, sizeArr2);
	int* arr3 = new int[*sizeArr3];
	
	for (int i = 0; i < sizeArr1; i++) {
		for (int j = 0; j < sizeArr2; j++) {
			if (*(arr1 + i) == *(arr2 + j)) {
				*(arr3 + counter) = *(arr1 + i);
				counter++;
				break;
			}
		}
	}

	return arr3;
}



int main() {
	setlocale(0, "");
	srand(time(NULL));

	

	int sizeArr1;
	std::cout << "Размер первого массива: ";
	std::cin >> sizeArr1;;

	int sizeArr2;
	std::cout << "Размер второго массива: ";
	std::cin >> sizeArr2;

	int* arr1 = new int[sizeArr1];
	initArr(arr1, sizeArr1);

	int* arr2 = new int[sizeArr2];
	initArr(arr2, sizeArr2);

	showArr(arr1, sizeArr1);
	std::cout << std::endl;
	showArr(arr2, sizeArr2);
	std::cout << std::endl;


	std::cout << "Общие элементы";
	std::cout << std::endl;
	int sizeArr3 = 0;
	int* arr3 = joinSameElem2Arr(arr1, arr2, sizeArr1, sizeArr2, &sizeArr3);
	showArr(arr3, sizeArr3);
	std::cout << std::endl;

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	return 0;
}