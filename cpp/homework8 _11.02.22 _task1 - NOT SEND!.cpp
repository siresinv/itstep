// STEP _CPP _classwork8 _11.02.22 _task3
// Вывести на экран фигуры \- ; _\  ; \/ ; /\ ; X ; >< ; > ; < ; -/ ; /_
// Вариант с разными длинами сторон

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main()
{
	setlocale(0, "");

	std::cout << "Вывод на экран фигур на основе матрицы" << std::endl;
	std::cout << "Размер матрицы выбирается случайно (от 5 до 19)" << std::endl;
	std::cout << "Матрица не обязательно будет квадратной" << std::endl;
	
	const int nFig = 1; //char???
	const char MARK = '*';
	const char NO_MARK = ' ';
	
	//char figNo; //int???
	int wSize; // Размер матрицы по ширине 
	int hSize; // Размер матрицы по высоте
	float wCoef = 1.0; // Коэффициент для ширины. По-умолчанию - 1 - для квадратной матрицы
	float hCoef = 1.0; // Коэффициент для высоты. По-умолчанию - 1 - для квадратной матрицы
	int iInt; // Номер строки матрицы после применения коэффициента
	int jInt; // Номер столбца матрицы после применения коэффициента
	int minSize; // minSize = ширине или высоте - смотря, что меньше

	srand(time(NULL));
	do {
		// Выбираем два случайных нечетных числа от 9 до 25
		
		wSize = rand() % 17 + 9;
		hSize = rand() % 17 + 9;
	} while (wSize % 2 == 0 || hSize % 2 == 0);
	
	std::cout << wSize << " " << hSize << std::endl;

	// При неравных ширине и высоте - определям коэффициенты для ширины и высоты
	// и меньший размер
	minSize = wSize;
	if (wSize > hSize) {
		wCoef = wSize / float(hSize);
		hCoef = 1.0;
		minSize = hSize;
	}
	else if (wSize < hSize) {
		hCoef = hSize / float(wSize);
		wCoef = 1.0;
		minSize = wSize;
	}

	//std::cout << wCoef << " " << hCoef;

	//figNo = 0;



	for (int figNo = 0; figNo < nFig; figNo++) {

		for (int i = 0; i <= hSize - 1; i++) {
			// Вывод фигуры
			for (int j = 0; j <= wSize - 1; j++){
				iInt = round(i / hCoef); // round ceil floor trunc
				jInt = round(j / wCoef); // round ceil floor trunc
				
				switch (figNo) {
				// Вывод в зависимости от номера фигуры
				case 0:
					(iInt >= jInt && iInt + jInt <= minSize - 1) ? std::cout << MARK : std::cout << NO_MARK;
					break;
				default:
					break;
				}

			}
			std::cout << std::endl;
		
		}
		std::cout << std::endl;

	}
	

	return 0;

}

