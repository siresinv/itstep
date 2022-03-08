// STEP _CPP _homework11 _02.03.22 _task2
/*
	В картинке
*/

#include <iostream>
#include <math.h>
#include <stdlib.h>

const int matrixSize = 7;
const char MARK = '*';
const char NO_MARK = '.';
const char NUMBER_MARK1 = '[';
const char NUMBER_MARK2 = ']';
int figNo;
int arrNumbers[matrixSize][matrixSize];
int printNumber;
int maxNumber;
bool isPrintNumber;
bool isFirstElement;

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	
	std::cout << "Вывод на экран фигур на основе матрицы" << std::endl << std::endl;

	do {
		
		for (size_t i = 0; i < matrixSize; i++) {
			for (int j = 0; j < matrixSize; j++) {
				arrNumbers[i][j] = rand() % 100;
			}
		}

		std::cout << "Введите номер фигуры - 1-10; 0 - выход: ";
		std::cin >> figNo;

		if (figNo >= 1 && figNo <= 10) {
			std::cout << std::endl;
			std::cout << std::endl;
			
			isFirstElement = true;
			for (int i = 0; i < matrixSize; i++) {
				std::cout << "\t\t";

				for (int j = 0; j < matrixSize; j++) {
					printNumber = arrNumbers[i][j];

					isPrintNumber = false;
					switch (figNo) {
					case 1:
						if (i <= j) isPrintNumber = true;
						break;
					case 2:
						if (i >= j) isPrintNumber = true;
						break;
					case 3:
						if (i <= j && i + j <= matrixSize - 1) isPrintNumber = true;
						break;
					case 4:
						if (i >= j && i + j >= matrixSize - 1) isPrintNumber = true;
						break;
					case 5:
						if ((i <= j && i + j <= matrixSize - 1) || (i >= j && i + j >= matrixSize - 1))  isPrintNumber = true;
						break;
					case 6:
						if ((i >= j && i + j <= matrixSize - 1) || (i <= j && i + j >= matrixSize - 1)) isPrintNumber = true;
						break;
					case 7:
						if (i >= j && i + j <= matrixSize - 1) isPrintNumber = true;
						break;
					case 8:
						if (i <= j && i + j >= matrixSize - 1) isPrintNumber = true;
						break;
					case 9:
						if (i + j <= matrixSize - 1)  isPrintNumber = true;
						break;
					case 10:
						if (i + j >= matrixSize - 1) isPrintNumber = true;
						break;
					default:
						break;
					}

					if (isPrintNumber == true){
						std::cout << NUMBER_MARK1 << printNumber << NUMBER_MARK2 << "\t";
						if (isFirstElement == true) {
							maxNumber = arrNumbers[i][j];
							isFirstElement = false;
						}
						if (maxNumber < arrNumbers[i][j]) maxNumber = arrNumbers[i][j];
					}
					else {
						std::cout << printNumber << "\t";
					}
				}

				std::cout << std::endl;
				std::cout << std::endl;
				std::cout << std::endl;
			}
			std::cout << std::endl;
			std::cout << "Наибольшее из чисел в скобках - " << maxNumber;
			std::cout << std::endl;
			std::cout << std::endl;
		}
		else if (figNo != 0) {
			std::cout << "Не верный номер!" << std::endl << std::endl;
		}

	} while (figNo != 0);

	return 0;

}

