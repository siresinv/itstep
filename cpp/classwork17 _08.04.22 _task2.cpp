// STEP _CPP _classwork17 _08.04.22 _task2
/*
	РЕКУРСИЯ

картинка

*/


#include <iostream>
#include <stdlib.h>
#include <math.h>

const int N_ROWS= 3;
const int N_COLS = 4;


void initMatrix (int matrix[][N_COLS]);
void showMatrix (int matrix[][N_COLS]);
void shift_R_Matrix (int matrix[][N_COLS], int nShift, int rowId, int colId, int tempCell);

int main() {
	setlocale(0, "");
	srand(time(NULL));

	int matrix[N_ROWS][N_COLS];
	
	int nShift;							// число сдвигов
	int rowId;							// АйДи строки, в которой сдвигается ячейка
	int colId;							// Айди столбца сдвигаемой ячейки
	int tempCell;						// значение временной ячейки

	initMatrix(matrix);
	showMatrix(matrix);
	std::cout << std::endl;

	nShift = 4;							
	rowId = 0;							
	colId = N_COLS - 1;
	tempCell = matrix[rowId][colId];	// значение первой временной ячейки

	shift_R_Matrix(matrix, nShift, rowId, colId, tempCell);
	showMatrix(matrix);

}

void initMatrix(int matrix[][N_COLS]) {
	for (int i = 0; i < N_ROWS; i++) {
		for (int j = 0; j < N_COLS; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void showMatrix(int matrix[][N_COLS]) {
	for (int i = 0; i < N_ROWS; i++) {
		for (int j = 0; j < N_COLS; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void shift_R_Matrix(int matrix[][N_COLS], int nShift, int rowId, int colId, int tempCell) {
	if (nShift > 0) {
		if (colId > 0) {
			matrix[rowId][colId] = matrix[rowId][colId - 1];
			colId--;
		}
		else {
			matrix[rowId][0] = tempCell;
			colId = N_COLS - 1;
			if (rowId == N_ROWS - 1) {
				nShift--;
				rowId = 0;
			}
			else rowId++;
			tempCell = matrix[rowId][colId];
		}
		shift_R_Matrix(matrix, nShift, rowId, colId, tempCell);
	}
}