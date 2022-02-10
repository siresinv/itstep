// STEP _CPP _homework7 _09.02.22 _task3
// Вывод симметричной звездочки
// 
// С коэффициэнтом - float ratio = width / float(height);
// - т.е. если стороны не равны - диагональ рисуется лесенкой


#include <iostream>
#include <stdlib.h>
#include <time.h>


int main()
{
	setlocale(0, "");
	srand(time(NULL));


	const char MARK = 'O';
	const char NOT_MARK = ' ';
	const char WALL = '|';
	const char LINE = '-';

	int width;
	int height;
	char symb;

	// Выбираем два случайных нечетных числа от 7 до 25
	do
	{
		width = rand() % 20 + 6;
	} while (width % 2 == 0);
	
	do
	{
		height = rand() % 20 + 6;
	} while (height % 2 == 0);


	float wRatio; // Коэффициент соотношения сторон
	float hRatio; // Коэффициент соотношения сторон
	if (width > height){
		wRatio = width / float(height);
		hRatio = 1;
	}
	else {
		hRatio = height / float(width);
		wRatio = 1;
	}

	// Представим звездочку как симметричную фигуру с центром в начале координат
	// - поэтому границы задаются следущим образом
	int maxWidth = width / 2;
	int minWidth = -maxWidth;
	int maxHeight = height / 2;
	int minHeight = -maxHeight;
	
	for (int j = maxHeight; j >= minHeight; j--)
	{
		for (int i = minWidth; i <= maxWidth; i++)
		{
			symb = NOT_MARK;
			if (int (abs(i) / wRatio) == int(abs(j) / hRatio) || i * j == 0) { 
				symb = MARK;
			}
			std::cout << WALL << " " << symb << " ";
		}


		// Код ниже - рисует крайнюю правую стенку и разделительную горизонтальную линию
		std::cout << WALL << std::endl;
		for (int k = 1; k <= width; k++)
		{
			std::cout << LINE << LINE << LINE << LINE;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Размер звездочки: " << width << " x " << height << std::endl;


	return 0;

}

