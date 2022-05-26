// STEP _CPP _classwork23 _27.04.22 _task1
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
		*(arr + i) = rand() % 10;
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



bool checkSimpleNum(int num){
	bool isSimpleNum = true;

	if (num > 1) {
		for (int i = 2; i <= num / 2; i++) {
			
			if ((num % i) == 0) {
				isSimpleNum = false;
				break;
			}
		}
	}
	else {
		isSimpleNum = false;
	}
	
	

	return isSimpleNum;
}


int* delSimpleNumInArr(int* arr, int* sizeArr) {

	int compositeNum = 0;

	for (int i = 0; i < *sizeArr; i++) {
		if (checkSimpleNum(*(arr + i)) == false) {
			compositeNum++;
		}
	}


	int newSizeArr = compositeNum;
	int* arr2 = new int[newSizeArr];

	int counter = 0;
	for (int i = 0; i < *sizeArr; i++) {
		if (checkSimpleNum(*(arr + i)) == false) {
			*(arr2 + counter) = *(arr + i);
			counter++;
		}
	}


	deleteArr(arr);
	*sizeArr = newSizeArr;
	return arr2;
}





int main() {
	setlocale(0, "");
	srand(time(NULL));

	int sizeArr = 10;

	std::cout << "Инициализировали массив: \t";
	int* arr = initArr(sizeArr);
	showArr(arr, sizeArr);
	std::cout << std::endl;

	std::cout << "Удалили простые числа: " << "\t\t";
	arr = delSimpleNumInArr(arr, &sizeArr);
	showArr(arr, sizeArr);
	std::cout << std::endl;


	deleteArr(arr);

	return 0;
}