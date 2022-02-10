// STEP _CPP _classwork7 _09.02.22 _task8


#include <iostream>

/*
Таблица умножения 2
*/

int main()
{
	setlocale(0, "");

	int i;
	int j;
	for (i = 2; i <= 9; i++)
	{
		for (j=1; j <= 10; j++)
		{
			std::cout << j << " x " << i << " = " << j*i << "\t";
			if (j>3)
			{
				std::cout << std::endl;
			}
		}

		std::cout << std::endl;
	}

	return 0;

}