// STEP _CPP _classwork12 _09.03.22 _task2
/*
в рисунке
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>


const int ROW_NUM = 3;
const int COL_NUM = 4;
int arrNum[ROW_NUM][COL_NUM];
int arrRowSum[ROW_NUM]; // = {};
int arrColSum[COL_NUM];// = {};
int finalSum;


int main() {

	setlocale(0, "");
	srand(time(NULL));

	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {
			arrNum[i][j] = rand() % 10 + 1;
			
		}
	}

	//int i;
	//int j;
	finalSum = 0;
	for (int i = 0; i < ROW_NUM; i++) {
		for (int j = 0; j < COL_NUM; j++) {
			std::cout << arrNum[i][j] << "\t";
			arrRowSum[i] += arrNum[i][j];
			arrColSum[j] += arrNum[i][j];
			finalSum += arrNum[i][j];
		}
		
		std::cout << " | " << arrRowSum[i];
		std::cout << std::endl;
	}

	std::cout << "__________________________________";
	std::cout << std::endl;
	for (int j = 0; j < COL_NUM; j++) {
		std::cout << arrColSum[j] << "\t";
		//finalSum += arrColSum[j];
	}

	std::cout << " | " << finalSum;
	std::cout << std::endl;


	



	return 0;
}

