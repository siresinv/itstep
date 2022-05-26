// STEP _CPP _classwork23 _27.04.22 _task2
/*

Динамическая память


картинка НА ТЕЛЕФОНЕ

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


//new int[3]{0,0,0}

int* distrNegNullPos(int* arr, int* sizeArr, int sign) {

	int nNeg = 0;
	int nNul = 0;
	int nPos = 0;

	for (int i = 0; i < *sizeArr; i++) {
		if (*(arr + i) < 0) {
			nNeg++;
		}
		else if (*(arr + i) > 0) {
			nPos++;
		}
		else {
			nNul++;
		}
	}

	int* arr1 = new int[nNeg];
	int* arr2 = new int[nPos];
	int* arr3 = new int[nNul];

	nNeg = 0;
	nNul = 0;
	nPos = 0;

	for (int i = 0; i < *sizeArr; i++) {
		if (*(arr + i) < 0) {
			*(arr1 + nNeg++) = *(arr + i);
		}
		else if (*(arr + i) > 0) {
			*(arr2 + nPos++) = *(arr + i);
		}
		else {
			*(arr3 + nNul++) = *(arr + i);
		}
	}


	switch (sign) {
	case -1:
		deleteArr(arr2);
		deleteArr(arr3);
		*sizeArr = nNeg;
		return arr1;
		break;
	case 1:
		deleteArr(arr1);
		deleteArr(arr3);
		*sizeArr = nPos;
		return arr2;
		break;
	case 0:
		deleteArr(arr1);
		deleteArr(arr2);
		*sizeArr = nNul;
		return arr3;
		break;
	default:
		break;
	}
}


int main() {
	setlocale(0, "");
	srand(time(NULL));

	int sizeArr = 10;

	std::cout << "Инициализировали массив: \t";
	int* arr = initArr(sizeArr);
	showArr(arr, sizeArr);
	std::cout << std::endl;


	std::cout << "Вывели отрицательные: \t";
	int* arr1 = distrNegNullPos(arr, &sizeArr, -1);
	showArr(arr1, sizeArr);
	std::cout << std::endl;

	sizeArr = 10;
	std::cout << "Вывели положительные: \t";
	int* arr2 = distrNegNullPos(arr, &sizeArr, 1);
	showArr(arr2, sizeArr);
	std::cout << std::endl;

	sizeArr = 10;
	std::cout << "Вывели нули: \t";
	int* arr3 = distrNegNullPos(arr, &sizeArr, 0);
	showArr(arr3, sizeArr);
	std::cout << std::endl;


	deleteArr(arr);
	deleteArr(arr1);
	deleteArr(arr2);
	deleteArr(arr3);

	return 0;
}

// nullptr почему не пишем ???