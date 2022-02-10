// STEP _CPP _classwork7 _09.02.22 _task7


#include <iostream>

/*
Таблица умножения
*/

int main()
{
	setlocale(0, "");

	int i;
	int j;
	for (i = 1; i <= 9; i++)
	{
		for (j=1; j <= 10; j++)
		{
			std::cout << i << " x " << j << " = " << i*j << std::endl;
		}

		std::cout << std::endl;
	}

	
	
	return 0;

}