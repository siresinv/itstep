// STEP _CPP _homework6 _04.02.22 _task2
// Задача про студента с монетой

#include <iostream>


int main()
{
	setlocale(0, "");

	const int N_COIN_TRY = 9; //Общее количество подбрасываний

	int nFrontCoin; // Количество выпаданий "орла"
	char userAnswer; // 1 или 0
	bool isEvenNumber;
	bool decision;


	nFrontCoin = 0;
	int i = 1;
	while (i <= N_COIN_TRY) {
		std::cout << "Подбрасывание N " << i << " - `орел` или `решка` - [1] / [0]: ";
		std::cin >> userAnswer;
		if (userAnswer == '1' || userAnswer == '0') {
			if (userAnswer == '1') {
				nFrontCoin++;
			}
			i++;
		}
		else {
			std::cout << "Неверный ввод!" << std::endl;
		}	
	}

	
	if (nFrontCoin % 2 == 0) {
		isEvenNumber = true;
	}
	else {
		isEvenNumber = false;
	}

	if (isEvenNumber == true) {
		decision = true;
	}
	else {
		decision = false;
	}


	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Количество выпаданий `орла`: " << nFrontCoin << std::endl;
	std::cout << "Решение в ";

	if (decision == true) {
		std::cout << "положительную";
	}
	else {
		std::cout << "отрицательную";;
	}

	std::cout << " сторону!";
	std::cout << std::endl;
	

}
