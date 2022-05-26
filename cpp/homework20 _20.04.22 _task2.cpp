// STEP _CPP _homework20 _20.04.22 _task2
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


int getSizeNewArr(int* arr, int sizeArr, bool delNumberType) {
	int nEvenNum;
	nEvenNum = 0;
	for (int i = 0; i < sizeArr; i++) {
		if ((*(arr + i)) % 2 == 0) {
			nEvenNum++;
		}
	}
	return ((delNumberType == true) ? sizeArr - nEvenNum : nEvenNum);
}

int* deleteEvenOddElemArr(int* arr, int sizeArr, int& sizeNewArr, bool delNumberType) {
	// УДАЛЯТЬ: true - четные false - нечетные

	int counter = 0;
	sizeNewArr = getSizeNewArr(arr, sizeArr, delNumberType);
	int* arr2 = new int[sizeNewArr];

	for (int i = 0; i < sizeArr; i++) {
		if (delNumberType == true) {
			if ((*(arr + i)) % 2 != 0) {
				*(arr2 + counter) = *(arr + i);
				counter++;
			}
		}
		else {
			if ((*(arr + i)) % 2 == 0) {
				*(arr2 + counter) = *(arr + i);
				counter++;
			}
		}
	}

	return arr2;
}


int main() {
	setlocale(0, "");
	srand(time(NULL));

	int sizeNewArr;
	bool delNumberType;

	int sizeArr2;
	std::cout << "Размер массива: ";
	std::cin >> sizeArr2;
	

	int* arr2 = new int[sizeArr2];
	initArr(arr2, sizeArr2);
	showArr(arr2, sizeArr2);
	std::cout << std::endl;
	std::cout << "Что удалять: 1 -четные, 0 -нечетные: ";
	std::cin >> delNumberType;
		
	int* arr3 = deleteEvenOddElemArr(arr2, sizeArr2, sizeNewArr, delNumberType);
	showArr(arr3, sizeNewArr);
	std::cout << std::endl;


	delete[] arr2;
	delete[] arr3;

	arr2 = nullptr;
	arr3 = nullptr;

	return 0;
}