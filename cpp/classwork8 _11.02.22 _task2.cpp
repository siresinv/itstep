// STEP _CPP _classwork8 _11.02.22 _task2
// Вывести матрицы, выделяя главную и побочную диагональ (каждую отдельно)

#include <iostream>


int main()
{
	setlocale(0, "");

	int size;

	std::cout << "Ведите размер матрицы: ";
	std::cin >> size;


	for (int i = 0; i <= size - 1; i++) {
		for (int j = 0; j <= size - 1; j++)
		{
			if (i == j || i+j == size - 1 || i == size / 2 || j == size / 2)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
		
	}

	return 0;

}

