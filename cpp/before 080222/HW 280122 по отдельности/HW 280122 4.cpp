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
//В общем, решил заморочиться )) с проверками, високосными годами и т.д.
//СРАВНИВАЛ С ОНЛАЙН СЕРВИСАМИ - ВСЁ РАБОТАЕТ
{
	setlocale(0, "");

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
