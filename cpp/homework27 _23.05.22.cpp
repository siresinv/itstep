// STEP _CPP _homework27 _23.05.22
/*

ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ


*/

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <Windows.h>
#include <math.h>
#include <stdlib.h>



int** initArr(int row, int col) {
	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}
	return arr;
}

int** fillArr(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 10;
		}
	}
	return arr;
}

void showArr(int** arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void deleteArr(int** arr, int row) {
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[]arr;
}


int** sumArr(int** arr1, int** arr2, int row, int col) {

	int** arr3 = initArr(row, col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*(*(arr3 + i) +j) = arr1[i][j] + arr2[i][j];
		}
	}
	return arr3;
}

int main() {
	setlocale(0, "");
	srand(time(NULL));


	int row;
	int col;

	std::cout << "Количество строк массива: ";
	std::cin >> row;
	std::cout << "Количество столбцов массива: ";
	std::cin >> col;

	int** arr1 = initArr(row, col);
	int** arr2 = initArr(row, col);
	fillArr(arr1, row, col);
	fillArr(arr2, row, col);
	
	showArr(arr1, row, col);
	std::cout << std::endl;
	std::cout << std::endl;

	showArr(arr2, row, col);
	std::cout << std::endl;
	std::cout << std::endl;

	int** arr3 = sumArr(arr1, arr2, row, col);
	showArr(arr3, row, col);
	std::cout << std::endl;
	std::cout << std::endl;

	deleteArr(arr1, row);
	deleteArr(arr2, row);
	deleteArr(arr3, row);

	return 0;
}