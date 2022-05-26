// STEP _CPP _classwork22 _26.04.22 _task1
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


int* delNegNumInArr(int* arr, int* sizeArr) {

	int nPosNum = 0;

	for (int i = 0; i < *sizeArr; i++) {
		if (*(arr + i) >= 0) {
			nPosNum++;
		}
	}

	int newSizeArr = nPosNum;
	int* arr2 = new int[newSizeArr];

	int counter = 0;

	for (int i = 0; i < *sizeArr; i++) {
		if (*(arr + i) >= 0) {
			*(arr2 + counter) = *(arr + i);
			counter++;
		}
	}

	deleteArr(arr);
	*sizeArr = newSizeArr;
	return arr2;
}



int* insSubArrInArr(int* arr, int* sizeArr, int* subArr, int*  sizeArr2, int *insId) {

	int nPosNum = 0;

	int newSizeArr = *sizeArr + *sizeArr2;
	int* arr3 = new int[newSizeArr];

	int counter = 0;
	
	for (int i = 0; i < newSizeArr; i++) {
		if (i < *insId) {
			*(arr3 + counter) = *(arr + i);
		}
		else if (i < *insId + *sizeArr2) {
			*(arr3 + counter) = *(subArr++);
		}
		else {
			*(arr3 + counter) = *(arr + i - *sizeArr2);
		}
		counter++;
	}

	deleteArr(arr);
	*sizeArr = newSizeArr;
	return arr3;
}



int* delBlockInArr(int* arr, int* sizeArr, int* delBeginId, int* delEndId) {

	if (*delBeginId <= (*sizeArr - 1) && *delEndId <= (*sizeArr - 1) && *delBeginId <= *delEndId) {

		int nPosNum = 0;

		int newSizeArr = *sizeArr - (*delEndId - *delBeginId + 1) ;
		int* arr2 = new int[newSizeArr];

		int counter = 0;
		for (int i = 0; i < *sizeArr; i++) {
			if (i < *delBeginId || i > *delEndId) {
				*(arr2 + counter) = *(arr + i);
				counter++;
			}
		}

		deleteArr(arr);
		*sizeArr = newSizeArr;
		return arr2;
	}
	else {
		return nullptr;
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

	std::cout << "Удалили отрицательные: " << ":\t\t";
	arr = delNegNumInArr(arr, &sizeArr);
	showArr(arr, sizeArr);
	std::cout << std::endl;

	int insId = 3;
	int sizeArr2 = 4;
	int* subArr = initArr(sizeArr);
	std::cout << "Добавили в позицию " << insId << " подмассив ";
	showArr(subArr, sizeArr2);
	std::cout << ":\t";
	arr = insSubArrInArr(arr, &sizeArr, subArr, &sizeArr2, &insId);
	showArr(arr, sizeArr);
	std::cout << std::endl;
	
	int delBeginId = 2;
	int delEndId = 3;
	std::cout << "Удалили блок с: " << delBeginId << " по: " << delEndId << " индексы: " << ":\t";
	arr = delBlockInArr(arr, &sizeArr, &delBeginId, &delEndId);
	if(arr){
		showArr(arr, sizeArr);
	}
	std::cout << std::endl;

	deleteArr(subArr);
	deleteArr(arr);

	return 0;
}