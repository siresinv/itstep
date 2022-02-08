#include <iostream>
using namespace std;



//HW от 260122


int main()
{
	setlocale(0, "");


	/*Задание 1.
	Пользователь вводит с клавиатуры расстояние до аэропорта и время, за которое нужно доехать.
	Вычислить скорость, с которой ему нужно ехать.*/

	cout << "Задание 1" << endl;
	cout << "Введите расстояние до аэропорта (км.): ";
	float distance_airport;
	cin >> distance_airport;
	
	cout << "Введите время, за которое нужно доехать до аропорта (ч.): ";
	float time;
	cin >> time;

	cout << "-----------------------------------------------" << endl;

	float speed = distance_airport / time;
	cout << "Скорость, с которой нужно ехать: " << speed << " км/ч";
	cout << endl << endl;




	/*Задание 2.
	Пользователь вводит с клавиатуры время начала и время завершения телефонного разговора
	(часы, минуты и секунды).Посчитать стоимость разговора, если стоимость минуты – 30 копеек.*/
	
	cout << "Задание 2" << endl;
	cout << "Введите время начала телефонного рвзговора часы минуты секунды (через пробел): " << endl;
	int call_hours_begin, call_minutes_begin, call_seconds_begin;
	cin >> call_hours_begin >> call_minutes_begin >> call_seconds_begin;

	cout << "Введите время завершения телефонного рвзговора часы минуты секунды (через пробел): " << endl;
	int call_hours_end, call_minutes_end, call_seconds_end;
	cin >> call_hours_end >> call_minutes_end >> call_seconds_end;

	cout << endl;
	cout << "Cтоимость минуты – 30 копеек" << endl;
	const int minute_cost_in_kop = 30;

	int call_begin_time = call_hours_begin * 3600 + call_minutes_begin * 60 + call_seconds_begin;
	int call_end_time = call_hours_end * 3600 + call_minutes_end * 60 + call_seconds_end;

	int call_duration_in_seconds = call_end_time - call_begin_time;
	int call_duration_in_minutes = call_duration_in_seconds / 60 + 1; //Поминутная тврификация (+1 - до полной минуты)

	int call_cost_in_kop = call_duration_in_minutes * minute_cost_in_kop;

	cout << "-----------------------------------------------" << endl;
	cout << "Продолжительость разговора при поминутной тарификации " << call_duration_in_minutes << " мин." << endl;
	cout << "Стоимость разговора " << call_cost_in_kop / 100 << " руб. " << call_cost_in_kop % 100 << " коп.";
	cout << endl << endl;




	/*Задание 3.
	Пользователь вводит с клавиатуры расстояние, расход бензина на 100 км и стоимость трех
	видов бензина.Вывести на экран сравнительную таблицу со стоимостью поездки на разных
	видах бензина.*/

	cout << "Задание 3" << endl;
	cout << "Введите расстояние, которое нужно проехать (км): ";
	float distance;
	cin >> distance;

	cout << "Введите расход бензина (л/100км): ";
	float fuel_rate_100km;
	cin >> fuel_rate_100km;

	cout << "Стоимость 1л. Бензина Марка1 (руб.коп.): ";
	float fuel1_cost;
	cin >> fuel1_cost;
	fuel1_cost *= 100;

	cout << "Стоимость 1л. Бензина Марка2 (руб.коп.): ";
	float fuel2_cost;
	cin >> fuel2_cost;
	fuel2_cost *= 100;

	cout << "Стоимость 1л. Бензина Марка3 (руб.коп.): ";
	float fuel3_cost;
	cin >> fuel3_cost;
	fuel3_cost *= 100;

	float fuel_per_trip = distance * fuel_rate_100km * 0.01;

	float trip1_cost = fuel_per_trip * fuel1_cost;
	float trip2_cost = fuel_per_trip * fuel2_cost;
	float trip3_cost = fuel_per_trip * fuel3_cost;

	cout << "-----------------------------------------------" << endl;

	cout << " =======================================" << endl;
	cout << "|" << "Марка бензина" << "\t|" << "Стоимость поездки" << "\t|" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|" << "Марка1" << "\t\t|" << int(trip1_cost) / 100 << " руб. " << int(trip1_cost) % 100 << " коп." << "\t|" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|" << "Марка2" << "\t\t|" << int(trip2_cost) / 100 << " руб. " << int(trip2_cost) % 100 << " коп." << "\t|" << endl;
	cout << "----------------------------------------" << endl;
	cout << "|" << "Марка3" << "\t\t|" << int(trip3_cost) / 100 << " руб. " << int(trip3_cost) % 100 << " коп." << "\t|" << endl;
	cout << " =======================================";
	cout << endl << endl;




	/*Задание 4.
	Пользователь вводит с клавиатуры время в секундах, прошедшее с начала дня.Вывести на
	экран текущее время в часах, минутах и секундах.Посчитать, сколько часов, минут и секунд
	осталось до полуночи.*/

	cout << "Задание 4" << endl;
	cout << "Вводите время в секундах, прошедшее с начала дня: ";
	int time_in_seconds;
	cin >> time_in_seconds;

	int current_hours = time_in_seconds / 3600;
	int current_minutes = (time_in_seconds % 3600) / 60;
	int current_seconds = time_in_seconds % 60;

	int time_in_seconds_till_midnight = 24 * 60 * 60 - time_in_seconds;

	int hours_till_midnight = time_in_seconds_till_midnight / 3600;
	int minutes_till_midnight = (time_in_seconds_till_midnight % 3600) / 60;
	int seconds_till_midnight = time_in_seconds_till_midnight % 60;
	
	cout << "-----------------------------------------------" << endl;

	cout << "Текущее время: ";
	cout << current_hours << " ч : ";
	cout << current_minutes << " м : ";
	cout << current_seconds << " с" << endl;

	cout << "Время до полуночи: ";
	cout << "" << hours_till_midnight << " ч : ";
	cout << "" << minutes_till_midnight << " м : ";
	cout << "" << seconds_till_midnight << " с";
	
	cout << endl << endl;




	/*Задание 5.
	Пользователь вводит с клавиатуры время в секундах, прошедшее с начала рабочего дня.
	Посчитать, сколько целых часов ему осталось сидеть на работе, если рабочий день – 8 часов.*/

	cout << "Задание 5" << endl;
	cout << "Введите время в секундах, прошедшее с начала рабочего дня: ";
	int time_in_seconds1;
	cin >> time_in_seconds1;

	int time_in_seconds_till_workend = 8 * 60 * 60 - time_in_seconds1;

	int hours_till_workend = time_in_seconds_till_workend / 3600;

	cout << "-----------------------------------------------" << endl;
	cout << "Осталось целых часов до конца рабочего дня: " << hours_till_workend;
	cout << endl << endl;

}


//HW от 260122

