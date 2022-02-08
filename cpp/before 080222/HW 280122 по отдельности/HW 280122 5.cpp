//HW от 280122

/*
Встреча №7
Тема: Логические операторы и операторы ветвлений
Домашнее задание
Задание 1: Пользователь вводит с клавиатуры целое шестизначное число. Написать программу,
которая определяет, является ли введенное число – счастливым (Счастливым считается
шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр). Если
пользователь ввел не шестизначное число – сообщение об ошибке.
Задание 2: Пользователь вводит четырехзначное число. Необходимо поменять в этом числе 1 и
2 цифры, а также 3 и 4 цифры. Если пользователь вводит не четырехзначное число – вывести
сообщение об ошибке.
Задание 3: Пользователь вводит с клавиатуры 7 целых чисел. Напишите программу, которая
определяет максимальное из этих 7 чисел (Подсказка – решение должно быть простым).

Встреча №8
Тема: Логические операторы и операторы ветвлений
Домашнее задание
Задание 1: Пользователь вводит две даты (день, месяц, год в виде целых чисел). Необходимо
определить и вывести количество дней между этими двумя датами. Для расчетов учитывать
високосные года, а также корректное число дней в месяцах (март – 31, сентябрь – 30, февраль
не високосного года – 28 и т.д.).
Задание 2: Зарплата менеджера составляет 200$ + процент от продаж, продажи до 500$ - 3%, от
500 до 1000 – 5%, свыше 1000 – 8%. Пользователь вводит с клавиатуры уровень продаж для
трех менеджеров. Определить их зарплату, определить лучшего менеджера, начислить ему
премию 200$, вывести итоги на экран.
*/

#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	setlocale(0, "");
	const int manager_base_salary = 200;
	const int sale1 = 500;
	const int sale2 = 1000;
	const float percent1_sale = 0.03;
	const float percent2_sale = 0.05;
	const float percent3_sale = 0.08;
	const int salary_premium = 200;
	
	
	int manager_number;
	float manager_sale, manager_salary;
	float manager1_sale, manager2_sale, manager3_sale;
	float manager1_salary, manager2_salary, manager3_salary;
	int best_manager_number;
	float max_sale;

	manager1_salary = manager_base_salary;
	manager2_salary = manager_base_salary;
	manager3_salary = manager_base_salary;

	cout << "Введите через пробел уровень продаж трёх менеджеров ($): ";
	cin >> manager1_sale >> manager2_sale >> manager3_sale;

	//Вычислили зарплату с процентом от продаж. Использование тренарного оператора в тренарном операторе - работает!
	manager1_salary += (manager1_sale < sale1) ? manager1_sale * percent1_sale : (manager1_sale > sale2) ? manager1_sale * percent3_sale : manager1_sale * percent2_sale;
	manager2_salary += (manager2_sale < sale1) ? manager2_sale * percent1_sale : (manager2_sale > sale2) ? manager2_sale * percent3_sale : manager2_sale * percent2_sale;
	manager3_salary += (manager3_sale < sale1) ? manager3_sale * percent1_sale : (manager3_sale > sale2) ? manager3_sale * percent3_sale : manager3_sale * percent2_sale;
	//Вычислили зарплату с процентом от продаж. Использование тренарного оператора в тренарном операторе - работает!


	//Нашли лучшего. Если продажи одинаковы, то лучшим становиться тот, которого вводили раньше
	max_sale = manager1_sale;
	best_manager_number = 1;

	if (manager2_sale > max_sale)
	{
		max_sale = manager2_sale;
		best_manager_number = 2;
	}

	if (manager3_sale > max_sale)
	{
		//max_sale = manager3_sale; //не обязательно эту строчку писать
		best_manager_number = 3;
	}
	//Нашли лучшего. Если продажи одинаковы, то лучшим становиться тот, которого вводили раньше


	//Прибавили премию лучшему
	switch (best_manager_number)
	{
	case 1:
		manager1_salary += salary_premium;
		break;
	case 2:
		manager2_salary += salary_premium;
		break;
	case 3:
		manager3_salary += salary_premium;
		break;
	default:
		break;
	}
	//Прибавили премию лучшему


	//Вывели итоги
	cout << endl << "----------------------------------------------------" << endl;

	manager_number = 1;
	manager_sale = manager1_sale;
	manager_salary = manager1_salary;
	cout << "[Менеджер" << manager_number << "] " << "Продажи ($):" << manager_sale << " Зарплата ($):" << manager_salary;
	(best_manager_number == manager_number) ? cout << " [Лучший]" : cout << " [______]";
	cout << endl;

	manager_number = 2;
	manager_sale = manager2_sale;
	manager_salary = manager2_salary;
	cout << "[Менеджер" << manager_number << "] " << "Продажи ($):" << manager_sale << " Зарплата ($):" << manager_salary;
	(best_manager_number == manager_number) ? cout << " [Лучший]" : cout << " [______]";
	cout << endl;

	manager_number = 3;
	manager_sale = manager3_sale;
	manager_salary = manager3_salary;
	cout << "[Менеджер" << manager_number << "] " << "Продажи ($):" << manager_sale << " Зарплата ($):" << manager_salary;
	(best_manager_number == manager_number) ? cout << " [Лучший]" : cout << "[______]";
	cout << endl;
}
