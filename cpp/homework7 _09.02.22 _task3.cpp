// STEP _CPP _homework7 _09.02.22 _task3
// Вывод симметричных звездочек
// сделать с коэффициэнтом сжатия // int ratio = width / height;
// Как вариант - с расстоянием от 'начала координат'
// 

#include <iostream>


int main()
{
	setlocale(0, "");



	const char MARK = 'O';
	const char NOT_MARK = ' ';
	const char WALL = '|';
	const char LINE = '-';
	const int ORIGIN = 0; // начало координат. Представим симметричную фигуру с центром в начале координат

	int width = 15;
	int height = 17;
	int ratio = width / height;
	
	int maxWidth = width / 2;
	int minWidth = -maxWidth;
	int maxHeight = height / 2;
	int minHeight = -maxHeight;
	
	char symb;


	// это рабочий вариант
	
	for (int j = maxHeight; j >= minHeight; j--)
	{
		for (int i = minWidth; i <= maxWidth; i++)
		{
			symb = NOT_MARK;
			//if (j == -i || j == i || j == 0 || i == 0) {
			//abs(i)==abs(j) ||
			if (abs(i)/ratio == abs(j) || i*j == 0) { ///
				// Вариант с центром в начале координат - просто для простоты условий в данном If
				symb = MARK;
			}

			std::cout << WALL << " " << symb << " ";
			//std::cout << WALL << " " << i << "; " << j << " ";

		}

		std::cout << WALL << std::endl;
		for (int k = 1; k <= width; k++)
		{
			std::cout << LINE << LINE << LINE << LINE;
		}
		std::cout << std::endl;
	}

	


	// это рабочий вариант
	/*
	for (int i = 1; i <= height; i++)
	{
		
		for (int j = 1; j <= width; j++)
		{
			symb = NOT_MARK;
			if (j == i || width-j+1 == i || j == width/2 + 1 || i == height/2 + 1){
				symb = MARK;
			}

			std::cout << WALL << " " << symb << " ";

		}
		
		std::cout << WALL << std::endl;
		for (int k = 1; k <= height; k++)
		{
			std::cout << LINE << LINE << LINE << LINE;
		}
		std::cout << std::endl;
	}
	*/

	return 0;

}

