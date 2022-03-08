// STEP _CPP _homework9 _16.02.22 _task3
/*
«јƒјЌ»≈ 3
ѕользователь вводит прибыль фирмы за год (12 мес€цев).
«атем пользователь вводит диапазон (например, 3 и 6 Ч поиск
между 3-м и 6-м мес€цем). Ќеобходимо определить мес€ц,
в котором прибыль была максимальна и мес€ц, в котором
прибыль была минимальна с учетом выбранного диапазона.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");
	srand(time(NULL));

	const int MONTH_PERIOD = 12;
	const int MONTH_BEGIN = 5;
	const int MONTH_END = 7;

	int arrMonthProfit[MONTH_PERIOD];
	int monthIdMinProfit;
	int monthIdMaxProfit;


	for (int i = 0; i < MONTH_PERIOD; i++) {
		arrMonthProfit[i] = rand() % 100001 + 100000;
	}

	monthIdMinProfit = MONTH_BEGIN-1;
	monthIdMaxProfit = MONTH_BEGIN-1;

	for (int i = MONTH_BEGIN-1; i < MONTH_END; i++) {
		if (arrMonthProfit[monthIdMinProfit] > arrMonthProfit[i]) {
			monthIdMinProfit = i;
		}

		if (arrMonthProfit[monthIdMaxProfit] < arrMonthProfit[i]) {
			monthIdMaxProfit = i;
		}

	}

	std::cout << "ћес€ц\t" << "ѕрибыль" << std::endl;
	for (int i = 0; i < MONTH_PERIOD; i++) {
		std::cout << i+1 << "\t" << arrMonthProfit[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "ƒиапазон мес€цев: " << MONTH_BEGIN << " - " << MONTH_END << std::endl;
	std::cout << "¬ " << monthIdMinProfit + 1 << " мес€це прибыль была минимальна€ -  " << arrMonthProfit[monthIdMinProfit] << std::endl;
	std::cout << "¬ " << monthIdMaxProfit + 1 << " мес€це прибыль была максимальна€ -  " << arrMonthProfit[monthIdMaxProfit] << std::endl;

	return 0;
}

