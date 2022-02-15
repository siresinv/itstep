// STEP _CPP _homework6 _04.02.22 _task1
// Компьютер угадывает рандомное число

#include <iostream>
#include <stdlib.h>
#include <time.h>


int main()
{
	setlocale(0, "");

	srand(time(NULL));

	const int num = rand() % 1000;

	int nTry;
	int guessNum;
	int minGuessNum;
	int maxGuessNum;

	char guessNumState;

	minGuessNum = 0;
	maxGuessNum = 1000000000;
	nTry = 0;

	do {
		guessNum = (maxGuessNum - minGuessNum) / 2 + minGuessNum;

		
		guessNumState = 1;
		if (num < guessNum) {
			maxGuessNum = guessNum;
			guessNumState = 0;
		}
		else if (num > guessNum) {
			minGuessNum = guessNum;
			guessNumState = 2;
		}

		nTry++;
		std::cout << nTry << " " << guessNum << " ";

		switch (guessNumState) {
		case 0:
			std::cout << " - <" << std::endl;
			break;

		case 1:
			std::cout << " - =" << std::endl;
			break;

		case 2:
			std::cout << " - >" << std::endl;

			break;

		default:
			break;
			std::cout << "" << std::endl;

		}
		
		
		

		

	} while (guessNum != num);



	return 0;


}
