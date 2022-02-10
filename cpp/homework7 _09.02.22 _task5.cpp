// STEP _CPP _homework7 _09.02.22 _task5

// Запросить ЗП 12 сотрудников за три месяца - СДЕЛАЕМ РАНДОМНО
// Вывести общую ЗП каждому сотруднику за квартал
// Вывести общую ЗП всем сотрудникам за квартал


#include <iostream>
#include <stdlib.h>
#include <time.h>



int main()
{
	setlocale(0, "");
	srand(time(NULL));


	const int N_EMPL = 12;
	const int N_MONTH = 3;
	const int MIN_SALARY = 40000;
	const int MAX_SALARY = 50000;

	int emplNo;
	int monthNo;
	int emplSalary;
	int emplTotalSalary;
	int allEmplSalary;

	allEmplSalary = 0;
	for (emplNo = 1; emplNo <= N_EMPL; emplNo++) {
		std::cout << "Сотрудник N: " << emplNo << std::endl;
		std::cout << std::endl;
		std::cout << "Месяц \t" << "Зарплата \t" << std::endl;
		emplTotalSalary = 0;
		for (monthNo = 1; monthNo <= N_MONTH; monthNo++) {
			emplSalary = rand() % (MAX_SALARY - MIN_SALARY) + MIN_SALARY + 1;
			std::cout << monthNo << "\t" << emplSalary << "\t" << std::endl;
			emplTotalSalary += emplSalary;
		}
		std::cout << std::endl;
		std::cout << "Общая зарплата за " << N_MONTH << " месяца: " << emplTotalSalary << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		allEmplSalary += emplTotalSalary;
	}

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Общая зарплата " << N_EMPL << " сотрудников за " << N_MONTH << " месяца: " << allEmplSalary << std::endl;
	std::cout << std::endl;


	return 0;

}

