#include <iostream>
#include <math.h>

using namespace std;


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









/*!

void task1_hw_280122()
{
	cout << "Программа  определяет, является ли введенное число – счастливым" << endl;
	cout << "Введите целое шестизначное число: ";
	int num;
	cin >> num;

	const int min_6_digits_number = 100000;
	int min_6_digits_number_amount = num / min_6_digits_number;
	bool num_is_6_digits = (min_6_digits_number_amount >= 1 && min_6_digits_number_amount < 10) ? true : false;

	cout << endl << "----------------------------------------------------" << endl;

	if (!num_is_6_digits)
	{
		cout << "НЕ шестизначное число " << endl;
	}
	else
	{
		int num_modified = num;

		int digit_6 = num_modified % 10;
		num_modified /= 10;

		int digit_5 = num_modified % 10;
		num_modified /= 10;

		int digit_4 = num_modified % 10;
		num_modified /= 10;

		int digit_3 = num_modified % 10;
		num_modified /= 10;

		int digit_2 = num_modified % 10;
		num_modified /= 10;

		int digit_1 = num_modified % 10;
		// либо тут уже просто digit_1 = num_modified


		int first_3_digits_sum = digit_1 + digit_2 + digit_3;
		int second_3_digits_sum = digit_4 + digit_5 + digit_6;

		cout << digit_1 << " + " << digit_2 << " + " << digit_3 << " = " << first_3_digits_sum << endl;
		cout << digit_4 << " + " << digit_5 << " + " << digit_6 << " = " << second_3_digits_sum << endl;

		if (first_3_digits_sum == second_3_digits_sum)
		{
			cout << "Число счастливое" << endl;
		}
		else
		{
			cout << "Число НЕ счастливое" << endl;
		}

		cout << endl;

	}

}

*/



/*!
void task2_hw_280122()
{

	const int exponent1 = 1;
	const int exponent2 = 10;
	const int exponent3 = 100;
	const int exponent4 = 1000;

	cout << "Пользователь вводит целое четырехзначное число. Необходимо поменять в этом числе 1 и 2 цифры, а также 3 и 4 цифры. Если пользователь вводит не четырехзначное число – вывести сообщение об ошибке." << endl;
	cout << "Введите целое четырехзначное число: ";
	int num;
	cin >> num;

	int min_4_digits_number = 1000;
	int min_4_digits_number_amount = num / min_4_digits_number;
	bool num_is_4_digits = (min_4_digits_number_amount >= 1 && min_4_digits_number_amount < 10) ? true : false;

	if (!num_is_4_digits)
	{
		cout << "Число НЕ четырехзначное!" << endl;
	}
	else
	{
		int num_exponent = num;

		int digit_4 = num_exponent % 10;
		num_exponent /= 10;

		int digit_3 = num_exponent % 10;
		num_exponent /= 10;

		int digit_2 = num_exponent % 10;
		num_exponent /= 10;

		int digit_1 = num_exponent % 10;
		// либо тут уже просто digit_1 = num_exponent

		int num_modified = digit_2 * exponent4 + digit_1 * exponent3 + digit_4 * exponent2 + digit_3 * exponent1;
		//т.е. чтобы получить новое число - умножаем соответсвующие цифры на порядок(1000,100,10,1) и складываем

		cout << endl << "----------------------------------------------------" << endl;

		cout << "Новое число: " << num_modified << endl;
		cout << endl;
	}

}
*/



/*!
void task3_hw_280122()
{
	cout << "Программа определяет максимальное из 7 чисел" << endl;
	cout << "Введите 7 чисел через пробел: ";
	int num1, num2, num3, num4, num5, num6, num7;
	cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7;

	int max_num = num1;
	max_num = (num2 > max_num) ? num2 : max_num;
	max_num = (num3 > max_num) ? num3 : max_num;
	max_num = (num4 > max_num) ? num4 : max_num;
	max_num = (num5 > max_num) ? num5 : max_num;
	max_num = (num6 > max_num) ? num6 : max_num;
	max_num = (num7 > max_num) ? num7 : max_num;

	cout << endl << "----------------------------------------------------" << endl;

	cout << "Максимальное число: " << max_num << endl;
	cout << endl;

}
*/


/*!
void task4_hw_280122()

//В общем, решил заморочиться )) с проверками, високосными годами и т.д.
//СРАВНИВАЛ С ОНЛАЙН СЕРВИСАМИ - ВСЁ РАБОТАЕТ
{
	const int any_leap_year = 2020; //Любой известный високосный год для дальнейшего сравнения
	const int jan = 31;
	const int mar = 31;
	const int apr = 30;
	const int may = 31;
	const int jun = 30;
	const int jul = 31;
	const int avg = 31;
	const int sep = 30;
	const int okt = 31;
	const int nov = 30;
	const int dec = 31;

	cout << "Пользователь вводит две даты (день, месяц, год в виде целых чисел). Необходимо определить и вывести количество дней между этими двумя датами" << endl;
	cout << "Ведите две даты (в порядке возрастания)" << endl;

	cout << "Введите через пробел День Месяц Год первой даты : ";
	int date1_day, date1_month_number, date1_year;
	cin >> date1_day >> date1_month_number >> date1_year;

	cout << "Введите через пробел День Месяц Год второй даты : ";
	int date2_day, date2_month_number, date2_year;
	cin >> date2_day >> date2_month_number >> date2_year;


	int feb;

	bool date1_is_leap_year = ((any_leap_year - date1_year) % 4 == 0) ? true : false;
	feb = (!date1_is_leap_year) ? 28 : 29;

	bool date2_is_leap_year = ((any_leap_year - date2_year) % 4 == 0) ? true : false;
	feb = (!date2_is_leap_year) ? 28 : 29;


	bool date_correct = true;

	//проверка корректности дат
	if (date1_month_number > 12 || date2_month_number > 12)
	{
		date_correct = false;
	}
	else
	{
		switch (date1_month_number)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date1_day > jan) { date_correct = false; } //т.е. если фактически >31
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date1_day > apr) { date_correct = false; } //т.е. если фактически >30
			break;
		case 2:
			if (date1_day > feb) { date_correct = false; }; //т.е. если фактически >28(29)
			break;
		default:
			break;
		}


		switch (date2_month_number)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (date2_day > jan) { date_correct = false; } //т.е. если фактически >31
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date2_day > apr) { date_correct = false; } //т.е. если фактически >30
			break;
		case 2:
			if (date2_day > feb) { date_correct = false; }//т.е. если фактически >28(29)
			break;
		default:
			break;
		}
	}


	//проверка на неубывание второй даты
	if (date_correct)
	{
		if (date2_year < date1_year)
		{
			date_correct = false;
		}
		else if (date2_year == date1_year)
		{
			if (date2_month_number < date1_month_number)
			{
				date_correct = false;
			}
			else if (date2_month_number == date1_month_number)
			{
				if (date2_day < date1_day)
				{
					date_correct = false;
				}
			}
		}
	}


	cout << endl << "----------------------------------------------------" << endl;

	if (!date_correct)
	{
		cout  << "Некорректный ввод дат!" << endl;
	}
	else
	{
		int date1_days_in_full_months = 0;
		date1_days_in_full_months += (date1_month_number > 1) ? jan : 0;
		date1_days_in_full_months += (date1_month_number > 2) ? feb : 0;
		date1_days_in_full_months += (date1_month_number > 3) ? mar : 0;
		date1_days_in_full_months += (date1_month_number > 4) ? apr : 0;
		date1_days_in_full_months += (date1_month_number > 5) ? may : 0;
		date1_days_in_full_months += (date1_month_number > 6) ? jun : 0;
		date1_days_in_full_months += (date1_month_number > 7) ? jul : 0;
		date1_days_in_full_months += (date1_month_number > 8) ? avg : 0;
		date1_days_in_full_months += (date1_month_number > 9) ? sep : 0;
		date1_days_in_full_months += (date1_month_number > 10) ? okt : 0;
		date1_days_in_full_months += (date1_month_number > 11) ? nov : 0;
		int date1_day_number = date1_days_in_full_months + date1_day; //Получили номер дня в году1

		int date2_days_in_full_months = 0;
		date2_days_in_full_months += (date2_month_number > 1) ? jan : 0;
		date2_days_in_full_months += (date2_month_number > 2) ? feb : 0;
		date2_days_in_full_months += (date2_month_number > 3) ? mar : 0;
		date2_days_in_full_months += (date2_month_number > 4) ? apr : 0;
		date2_days_in_full_months += (date2_month_number > 5) ? may : 0;
		date2_days_in_full_months += (date2_month_number > 6) ? jun : 0;
		date2_days_in_full_months += (date2_month_number > 7) ? jul : 0;
		date2_days_in_full_months += (date2_month_number > 8) ? avg : 0;
		date2_days_in_full_months += (date2_month_number > 9) ? sep : 0;
		date2_days_in_full_months += (date2_month_number > 10) ? okt : 0;
		date2_days_in_full_months += (date2_month_number > 11) ? nov : 0;
		int date2_day_number = date2_days_in_full_months + date2_day; //Получили номер дня в году2


		//ИГРЫ РАЗУМА !!! ))))) Находим количество високосных годов между двумя  датами
		int full_years_amount = date2_year - date1_year; //количество полных лет между двумя датами. первый год тоже сичтается за полный
		int leap_in_full_years_amount = full_years_amount / 4; //количство високосных годов между двумя датами


		//дальше самая жесть ))) - выявлена закономерность, при каких условиях добавляется високосный год
		if (date1_is_leap_year)
		{
			leap_in_full_years_amount += (full_years_amount % 4 > 1) ? 1 : 0;
		}
		else
		{
			int date1_nearest_leap_year = (date1_year / 4) * 4; //Находим ближайший к году1 високосный год и меньший года1
			int year_difference = date1_year - date1_nearest_leap_year;

			switch (year_difference)
			{
			case 2:
				leap_in_full_years_amount += (full_years_amount % 4 == 3) ? 1 : 0;
				break;
			case 3:
				leap_in_full_years_amount += (full_years_amount % 4 >= 2) ? 1 : 0;
				break;
			default:
				break;
			}
		}


		int days_in_full_years = full_years_amount * 365 + leap_in_full_years_amount;
		int date_difference = days_in_full_years + date2_day_number - date1_day_number;
		cout << "Разница между датами: " << date_difference << " дн." << endl;
	}
}
*/




void task5_hw_280122()

//// Задание 2: Зарплата менеджера составляет 200$ + процент от продаж, продажи до 500$ - 3%, от
//500 до 1000 – 5 %, свыше 1000 – 8 % .Пользователь вводит с клавиатуры уровень продаж для
//трех менеджеров.Определить их зарплату, определить лучшего менеджера, начислить ему
//премию 200$, вывести итоги на экран.

{
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


int main()
{
	setlocale(0, "");

	//task1_hw_280122();
	//cout << endl;

	//task2_hw_280122();
	//cout << endl;

	//task3_hw_280122();
	//cout << endl;

	//task4_hw_280122();
	//cout << endl;

	task5_hw_280122();
	cout << endl;
}

//HW от 280122

