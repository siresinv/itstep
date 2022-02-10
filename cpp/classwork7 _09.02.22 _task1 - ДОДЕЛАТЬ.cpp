// STEP _CPP _classwork7 _09.02.22 _task1
// Угадывание случайного числа за определенное количество попыток

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	setlocale(0, "");

	srand(time(NULL));

	int num;
	num = rand() % 10 + 1;
	std::cout << num << std::endl;
	int guessNum;

	int nTry;
	nTry = 5;

	int count = 1;
	guessNum = num + 1; // ))
	while (count <= nTry && guessNum != num)
	{
		std::cout << "";
		std::cin >> guessNum;
		count++;
		
		

	}

	return 0;

}

