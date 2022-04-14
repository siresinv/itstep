// STEP _CPP _homework15 _30.03.22 _task2
/*
	СОРТИРОВКИ

	Задание 1

Написать перегруженные функции (int, double,char) для выполнения следующих задач:
■ Инициализация квадратной матрицы;
■ Вывод матрицы на экран;
■ Определение максимального и минимального элементана главной диагонали матрицы;
■ Сортировка элементов по возрастанию отдельно для каждой строки матрицы.


Здесь можно не перегрузками, а шаблонами

в последнем 3-4 функции сортировки сделать

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>

const int SIZE_MATRIX = 10;
enum sortMethodsList { select, buble, insert, shaker };

void initMatrix(int matrix[][SIZE_MATRIX], int sizeMatrix);
void initMatrix(double matrix[][SIZE_MATRIX], int sizeMatrix);
void initMatrix(char matrix[][SIZE_MATRIX], int sizeMatrix);

template <class T>
void showMatrix(T matrix[][SIZE_MATRIX], int sizeMatrix);

template <class T>
T getMinMainDiag(T matrix[][SIZE_MATRIX], int sizeMatrix);

template <class T>
T getMaxMainDiag(T matrix[][SIZE_MATRIX], int sizeMatrix);

template <class T>
void sortMatrixRows(T matrix[][SIZE_MATRIX], int sizeMatrix, int sortMethod);

template <class T>
void sortMatrixRow(T matrixRow[], int sizeMatrixRow, int sortMethod);

template <class T>
void selectSort(T matrixRow[], int sizeMatrix);

template <class T>
void bubleSort(T matrixRow[], int sizeMatrix);

template <class T>
void insertSort(T matrixRow[], int sizeMatrix);

template <class T>
void shakerSort(T matrixRow[], int sizeMatrix);



int main() {
	setlocale(0, "");
	srand(time(NULL));

	
	double matrix[SIZE_MATRIX][SIZE_MATRIX];

	initMatrix(matrix, SIZE_MATRIX);
	showMatrix(matrix, SIZE_MATRIX);

	std::cout << "Минимум главной диагонали равен: " << getMinMainDiag(matrix, SIZE_MATRIX) << std::endl;
	std::cout << "Максимум главной диагонали равен: " << getMaxMainDiag(matrix, SIZE_MATRIX) << std::endl;
	std::cout << std::endl;

	
	sortMethodsList sortMethod;
	sortMethod = shaker;
	sortMatrixRows(matrix, SIZE_MATRIX, sortMethod);


	std::cout << "Матрица после сортировки строк по возрастанию методом ";

	switch (sortMethod) {
	case select:
		std::cout << "select";
		break;
	case buble:
		std::cout << "buble";
		break;
	case insert:
		std::cout << "insert";
		break;
	case shaker:
		std::cout << "SHAKER";
		break;
	default:
		break;
	}

	std::cout << std::endl << std::endl;

	showMatrix(matrix, SIZE_MATRIX);

	return 0;
}



void initMatrix(int matrix[][SIZE_MATRIX], int sizeMatrix) {
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			matrix[i][j] = rand() % 90 + 10; // целые числа от 10 до 99
		}
	}
}


void initMatrix(double matrix[][SIZE_MATRIX], int sizeMatrix) {
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			matrix[i][j] = rand() / float(100); // 
		}
	}
}


void initMatrix(char matrix[][SIZE_MATRIX], int sizeMatrix) {
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			matrix[i][j] = rand() % 26 + 65; // заглавные буквы латинского алфавита
		}
	}
}


template <class T>
void showMatrix(T matrix[][SIZE_MATRIX], int sizeMatrix) {
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl << std::endl;
	}
}


template <class T>
T getMinMainDiag(T matrix[][SIZE_MATRIX], int sizeMatrix) {
	T min;
	min = matrix[0][0];
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			if (i == j) {
				if (matrix[i][j] < min) min = matrix[i][j];
			}
		}
	}
	return min;
}


template <class T>
T getMaxMainDiag(T matrix[][SIZE_MATRIX], int sizeMatrix) {
	T max;
	max = matrix[0][0];
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			if (i == j) {
				if (matrix[i][j] > max) max = matrix[i][j];
			}
		}
	}
	return max;
}


template <class T>
void sortMatrixRows(T matrix[][SIZE_MATRIX], int sizeMatrix, int sortMethod) {
	T matrixRow[SIZE_MATRIX];

	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			matrixRow[j] = matrix[i][j];
		}
		
		sortMatrixRow(matrixRow, sizeMatrix, sortMethod);

		for (int k = 0; k < sizeMatrix; k++) {
			matrix[i][k] = matrixRow[k];
		}
	}
}


template <class T>
void sortMatrixRow(T matrixRow[], int sizeMatrixRow, int sortMethod) {
	switch (sortMethod) {
	case select:
		selectSort(matrixRow, sizeMatrixRow);
		break;

	case buble:
		bubleSort(matrixRow, sizeMatrixRow);
		break;

	case insert:
		insertSort(matrixRow, sizeMatrixRow);
		break;

	case shaker:
		shakerSort(matrixRow, sizeMatrixRow);
		break;

	default:
		break;
	}
}


template <class T>
void selectSort(T arr[], int sizeArr) {
	int minId;
	T tempCell;

	for (int i = 0; i < sizeArr; i++) {
		minId = i;
		for (int j = i+1; j < sizeArr; j++) {
			if (arr[j] < arr[minId]) {
				minId = j;
			}
		}

		if (minId != i) {
			tempCell = arr[i];
			arr[i] = arr[minId];
			arr[minId] = tempCell;
		}

	}
}


template <class T>
void bubleSort(T arr[], int sizeArr)
{
	for (int i = 0; i < sizeArr; i++) {
		T tempCell;
		for (int j = 0; j < sizeArr-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				tempCell = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tempCell;
			}
		}
	}
}


template <class T>
void insertSort(T arr[], int sizeArr) {
	T tempCell;
	for (int i = 1; i < sizeArr; i++) {
		for (int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
			tempCell = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tempCell;
		}
	}
}


template <class T>
void shakerSort(T arr[], int sizeArr) {
	int left;
	int right;
	T tempCell;
	int swapped;

	left = 0;
	right = sizeArr - 1;
	swapped = sizeArr - 1; //
	do {
		for (int i = left; i < right; i++) {
			if (arr[i] > arr[i+1]) {
				tempCell = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tempCell;
				swapped = i;
			}
		}
		right = swapped;

		for (int j = right;	j > left; j--) {
			if (arr[j] < arr[j - 1]) {
				tempCell = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tempCell;
				swapped = j;
			}
		}
		left = swapped;

	} while (left < right);
}


