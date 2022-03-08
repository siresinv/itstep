// STEP _CPP _homework10 _18.02.22 _task3
/*
ЗАДАНИЕ 3
Пользователь вводит данные о своих расходах в долларах за неделю (каждый день). Написать программу, которая
вычисляет:
■ среднюю (за неделю) потраченную сумму;
■ общую сумму, потраченную пользователем за неделю;
■ количество дней и их названия (например, «вторник»),
когда сумма расхода (в день) превысила 100 долларов.
!!!ENUM!!!
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {


	setlocale(0, "");

	srand(time(NULL));

	const int N_DAYS = 7;
	const int SMALL_COST = 100;

	int arrMoneyPerDay[N_DAYS];
	int arrBigCostDays[N_DAYS];
	int weekSum;
	int avgSum;
	int weekDay;
	int dayCount;

	enum daysOfWeek {mon, tue, wed, thu, fri, sat, sun};

	for (int i = 0; i < N_DAYS; i++) {
		arrMoneyPerDay[i] = rand() % 200 + 1;
	}

	weekSum = 0;
	dayCount = 0;
	for (int i = 0; i < N_DAYS; i++) {
		weekSum += arrMoneyPerDay[i];
		if (arrMoneyPerDay[i] > SMALL_COST) {
			weekDay = i;
			arrBigCostDays[dayCount] = weekDay;
			dayCount++;
		}
		std::cout << i + 1 << " - " << arrMoneyPerDay[i] << std::endl;
	}
	avgSum = weekSum / N_DAYS;

	std::cout << std::endl;

	std::cout << "Средняя за неделю дневная сумма: " << avgSum << std::endl;
	std::cout << "Общая сумма за неделю: " << weekSum << std::endl;
	
	if (dayCount > 0) {
		std::cout << dayCount << "дн., в которых сумма расходов превысила " << SMALL_COST << std::endl;

		for (int i = 0; i < N_DAYS; i++) {
			weekDay = arrBigCostDays[i];
			switch (weekDay) {
			case mon:
				std::cout << "понедельник";
				break;
			case tue:
				std::cout << "вторник";
				break;
			case wed:
				std::cout << "среду";
				break;
			case thu:
				std::cout << "четверг";
				break;
			case fri:
				std::cout << "пятницу";
				break;
			case sat:
				std::cout << "субботу";
				break;
			case sun:
				std::cout << "воскресенье";
				break;
			default:
				break;
			}
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}

