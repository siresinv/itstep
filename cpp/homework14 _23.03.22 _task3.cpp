// STEP _CPP _homework14 _23.03.22 _task3
/*
	в картинке
*/



#include <iostream>
#include <stdlib.h>
#include <math.h>







int getNumSignAmount(int arrNum[], int sizeArr, int signNum);

int main() {
	setlocale(0, "");
	srand(time(NULL));

	enum signs {
		neg, nul, pos //0-положительное 1-ноль 2-орицательное
	};
	//signs signNum;

	const int N_NUM = 10;
	int arrNum[N_NUM];

	for (int i = 0; i < N_NUM; i++) {
		arrNum[i] = rand() % 11 - 5;
	}

	for (int i = 0; i < N_NUM; i++) {
		std::cout << arrNum[i] << " ";
	}

	std::cout << std::endl;

	//signNum = neg;
	std::cout << "Количество отрицательных чисел в массиве - " << getNumSignAmount(arrNum, N_NUM, neg);
	std::cout << std::endl;
	std::cout << "Количество чисел в массиве равных нулю - " << getNumSignAmount(arrNum, N_NUM, nul);
	std::cout << std::endl;
	std::cout << "Количество положительных чисел в массиве - " << getNumSignAmount(arrNum, N_NUM, pos);
	std::cout << std::endl;

	return 0;
}


int getNumSignAmount(int arrNum[], int sizeArr, int signNum) {
	int signAmount = 0;
	for (int i = 0; i < sizeArr; i++) {

		switch (signNum) {
			//0-положительное 1-ноль 2-орицательное
		case 0:
			if (arrNum[i] < 0) signAmount++;
			break; 
		case 1:
			if (arrNum[i] == 0) signAmount++;
			break; 
		case 2:
			if (arrNum[i] > 0) signAmount++;
			break;
		default:
			break;
		}

	}

	return signAmount;
}


