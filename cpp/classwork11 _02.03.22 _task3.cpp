// STEP _CPP _classwork11 _02.03.22 _task3
/*
 в картинке
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>


const int N_MONTH = 12;
int arrProfit[N_MONTH] = {1,2,3,4,5,6,6,1,7,8,9,9};
int minProfit;
int maxProfit;


int main() {

	setlocale(0, "");
	srand(time(NULL));

	/*for (int i = 0; i < N_MONTH; i++) {
		arrProfit[i] = rand() % 100 + 1;
	}*/
	
	minProfit = arrProfit[0];
	maxProfit = arrProfit[0];


	for (int i = 0; i < N_MONTH; i++) {
		if (minProfit > arrProfit[i]) {
			 minProfit = arrProfit[i];
			 
		}

		if (maxProfit < arrProfit[i]) {
			maxProfit = arrProfit[i];
		}

	}

	for (int i = 0; i < N_MONTH; i++) {
		std::cout << i+1 << " - " << arrProfit[i] << std::endl;
		
	}

	
	std::cout << "Минимальные месяца: ";
	for (int i = 0; i < N_MONTH; i++) {

		if (arrProfit[i] == minProfit) {
			std::cout << i+1 << " - " << arrProfit[i] << " ";
		}
	}

	std::cout << "Максимальные месяца: ";
	for (int i = 0; i < N_MONTH; i++) {
		if (arrProfit[i] == maxProfit) {
			std::cout << i + 1 << " - " << arrProfit[i] << " ";
		}
	}
	




	return 0;
}

