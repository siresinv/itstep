// STEP _CPP _classwork8 _11.02.22 _task1
// Вывести на экран прямоугольник из зведочек N на M.

#include <iostream>


int main()
{
	setlocale(0, "");

	int width;
	int height;

	std::cout << "Ведите ширину прямоугольника: ";
	std::cin >> width;
	std::cout << "Ведите высоту прямоугольника: ";
	std::cin >> height;

	for (int i = 1; i <= height; i++) {
		for (int j = 1; j <= width; j++)
		{
			if (i == 1 || i == height || j == 1 || j == width)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
			
			//if (asd ad )
			//for (int k = 2; k <= width-1; k++)  { std::cout << " "; }




		}
		std::cout << std::endl;
		
	}

	return 0;

}

