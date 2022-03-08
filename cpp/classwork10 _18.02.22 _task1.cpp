// STEP _CPP _classwork10 _18.02.22 _task1
/*
4. ¬ массиве хранитс€ информаци€ о стоимости 10 марок
автомобилей. ќпределить сумму наиболее дорогого
автомобил€ и узнать его номер. ≈сли таких автомобилей несколько, определить:
а) номер первого такого автомобил€;
б) номер последнего такого автомобил€.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");

	const int N_AUTO=10;
	int arrAutoCost[N_AUTO] = {1, 5, 3, 4, 5, 3, 5, 2, 1, 0};
	int firstMostCostId;
	int lastMostCostId;

	firstMostCostId = 0;
	lastMostCostId = 0;

	for (int i = 0; i < N_AUTO; i++) {
		std::cout << i + 1 << " - цена " << arrAutoCost[i] << std::endl;


		if (arrAutoCost[firstMostCostId] < arrAutoCost[i]) {
			firstMostCostId = i;
		}


		if (arrAutoCost[N_AUTO - 1 - i] < arrAutoCost[i]) {
			lastMostCostId = i;
		}


	}

	std::cout << "Ќомер первого наидорожайшего автомобил€: " << firstMostCostId +1 << std::endl;
	if (arrAutoCost[lastMostCostId] == arrAutoCost[firstMostCostId]) {
		std::cout << "Ќомер второго наидорожайшего автомобил€: " << lastMostCostId + 1 << std::endl;
	}

	

	return 0;
}

