// STEP _CPP _classwork27 _23.05.22
/*

ДВУМЕРНЫЕ ДИНАМИЧЕСКИЕ МАССИВЫ


*/

//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//#include <Windows.h>
#include <math.h>
#include <stdlib.h>



void task1() {
	
	int row = 5;
	int col = 10;

	int** arr = new int* [row];
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 10;
		}
	}


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}


	for (int i = 0; i < 5; i++) {
		delete[]arr[i];
	}
	delete[]arr;
}



void task2() {
	int*** arr2 = new int** [2];
	for (int i = 0; i < 2; i++) {
		arr2[i] = new int* [3];
		for (int j = 0; j < 3; j++) {
			arr2[i][j] = new int[4];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				arr2[i][j][k] = rand() % 10;
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				std::cout << arr2[i][j][k]<< " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			delete[]arr2[i][j];
		}
		delete[]arr2[i];
	}
	delete[]arr2;
}




void task3() {
	int**** arr3 = new int*** [2];
	for (int i = 0; i < 2; i++) {
		arr3[i] = new int** [3];
		for (int j = 0; j < 3; j++) {
			arr3[i][j] = new int* [4];
			for (int k = 0; k < 5; k++) {
				arr3[i][j][k] = new int[5];
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 5; l++) {
					arr3[i][j][k][l] = rand() % 10;
				}
			}
		}
	}


	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 5; l++) {
					std::cout << arr3[i][j][k][l] << " ";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}


	//////////////////////////////////////////////////////////////////
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				delete[]arr3[i][j][k];
			}
			// delete[]arr3[i][j]; // РУГАЕТСЯ НА ЭТУ СТРОКУ И ВСЁ!!!
		}
		delete[]arr3[i];
	}
	delete[]arr3;
}



int** initMatrix(int row, int col) {
	int** matrix = new int* [row];
	for (int i = 0; i < row; i++) {
		matrix[i] = new int[col];
	}
	return matrix;
}

int** fillMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
	return matrix;
}

void showMatrix(int** matrix, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void deleteMatrix(int** matrix, int row) {
	for (int i = 0; i < row; i++) {
		delete[] matrix[i];
	}
	delete[]matrix;
}


//////////////////////////////////////////////////////////////////
int** task4_multMatrix(int** matrix1, int** matrix2, int row, int col) {

	int** matrix3 = initMatrix(row, col);
	int cell = 0;


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int k = 0; k < ; k++) {

			}

			matrix3[i][0] += [i][j] * [j][i];


		}
	}

	return matrix3;
}

int main() {
	setlocale(0, "");
	srand(time(NULL));

	//task1();
	//task2();
	task3();


	int row1;
	int col1_row2;
	int col2;

	std::cout << "Количество строк первой матрицы: ";
	std::cin >> row1;
	std::cout << "Количество столбцов первой матрицы (строк второй матрицы):";
	std::cin >> col1_row2;
	std::cout << "Количество столбцов второй матрицы:";
	std::cin >> col2;

	int** matrix1 = initMatrix(row1, col1_row2);
	int** matrix2 = initMatrix(col1_row2, col2);
	fillMatrix(matrix1, row1, col1_row2);
	fillMatrix(matrix2, col1_row2, col2);
	
	showMatrix(matrix1, row1, col1_row2);
	std::cout << std::endl;
	std::cout << std::endl;

	showMatrix(matrix2, col1_row2, col2);
	std::cout << std::endl;
	std::cout << std::endl;

	int** matrix3 = task4_multMatrix(matrix1, matrix2, row1, col2);
	showMatrix(matrix3, row1, col2);
	std::cout << std::endl;
	std::cout << std::endl;

	deleteMatrix(matrix1, row1);
	deleteMatrix(matrix2, col1_row2);
	deleteMatrix(matrix3, row1);

	return 0;
}