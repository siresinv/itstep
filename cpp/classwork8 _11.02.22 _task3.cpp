// STEP _CPP _classwork8 _11.02.22 _task3
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
			if (i >= j)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;
		
	}
	std::cout << std::endl;


	for (int i = 0; i <= size - 1; i++) {
		for (int j = 0; j <= size - 1; j++)
		{
			if (i <= j)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;



	for (int i = 0; i <= size - 1; i++) {
		for (int j = 0; j <= size - 1; j++)
		{
			if (i + j >= size - 1)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;


	for (int i = 0; i <= size - 1; i++) {
		for (int j = 0; j <= size - 1; j++)
		{
			if (i + j <= size - 1)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;



	for (int i = 0; i <= size - 1; i++) {
		for (int j = 0; j <= size - 1; j++)
		{
			if (i + j <= size - 1)
			{
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;


	return 0;

}

