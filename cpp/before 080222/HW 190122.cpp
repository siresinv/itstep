// STEP C++ Practic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



//ДЗ от 190122
//||
//task1_hw_190122 - номерзадния_hw(cw)_дата. hw/cw - homework/classwork

/*
Курс «Язык программирования C»
Встреча №4
Тема : Переменные и типы данных
Домашнее задание
Задание 1. Пользователь вводит с клавиатуры время в секундах.Необходимо написать
программу, которая переведет введенные пользователем секунды в часы, минуты, секунды и
выводит их на экран.
Задание 2. Написать программу, которая преобразует введенное с клавиатуры дробное число в
денежный формат.Например, число 12, 5 должно быть преобразовано к виду 12грн 50 коп.
Задание 3. Написать программу, вычисляющую, с какой скоростью бегун пробежал дистанцию.
Рекомендуемый вид экрана во время выполнения программы приведен ниже :
Вычисление скорости бега
Введите длину дистанции(метров) = 1000
Введите время(мин.сек) = 3.25
Дистанция : 1000 м
Время : 3 мин 25 сек = 205 сек
Вы бежали со скоростью 17.56 км / ч
Задание 4. Пользователь указывает цену одой минуты исходящего звонка с одного мобильного
оператора другому, а также продолжительность разговора в минутах и секундах.Необходимо
вычислить денежную сумму на которую был произведен звонок.
Задание 5. Написать программу, которая преобразует введенное пользователем количество
дней в количество полных недель и оставшихся дней.Например, пользователь ввел 17 дней,
программа должна вывести на экран 2 недели и 3 дня.
*/


void task1_hw_190122()
{
    cout << "Преобразование секунд в часы, минуты, секунды" << endl;
    cout << "Введите количество секунд" << endl;
    int sec_amount_input;
    cin >> sec_amount_input;

    //Меньше кода, но менее наглядно
    int hour_amount = sec_amount_input / 3600;
    int min_amount = (sec_amount_input % 3600) / 60;
    int sec_amount = sec_amount_input % 60;
    cout << "--------------------------------" << endl;
    cout << "Часов: " << hour_amount << endl;
    cout << "Минут: " << min_amount << endl;
    cout << "Секунд: " << sec_amount << endl;


    //Больше кода, но более наглядно
    hour_amount = sec_amount_input / 3600;
    int sec_amount_mod = sec_amount_input % 3600;
    min_amount = sec_amount_mod / 60;
    sec_amount = sec_amount_mod % 60;
    cout << "--------------------------------" << endl;
    cout << "Часов: " << hour_amount << endl;
    cout << "Минут: " << min_amount << endl;
    cout << "Секунд: " << sec_amount << endl;
}

void task2_hw_190122()
{
    cout << "Преобразование дробного числа в денежный формат" << endl;
    cout << "Введите дробное число" << endl;
    double fract_number;
    cin >> fract_number;

    cout << "--------------------------------" << endl;

    int all_kop = fract_number * 100; //здесь точность не теряется ли?
    int rub = all_kop / 100;
    int kop = all_kop % 100;

    cout << rub << " руб." << "\t" << kop << " коп.";

}

void task3_hw_190122()
{
    cout << "Вычисление, с какой скоростью бегун пробежал дистанцию" << endl;

    cout << "Введите длину дистанции (м.)" << endl;
    int distance_in_meter;
    cin >> distance_in_meter;

    cout << "Введите время (мин.сек)" << endl;
    double time;
    cin >> time;

    int minutes_amount = time;
    double seconds_amount_fract = time - minutes_amount;
    double seconds_amount = seconds_amount_fract*100; //здесь теряется точность когда float

    //а если вообще ввести дробную дистанцию - 
    //то автоматом целая часть уходит в дистанцию
    //а дробная в секунды
    //время вообще не предлагает ввести
    //ПОЧЕМУ ТАК ???



    cout << "--------------------------------" << endl;
    cout << "Дистанция: " << distance_in_meter << " м." << endl;
    cout << "Время: " << minutes_amount << " мин." << " " << seconds_amount << " сек.";
    double time_in_second = minutes_amount * 60 + seconds_amount;
    cout << " = " << time_in_second << " сек." << endl;
    double speed_meter_in_second = distance_in_meter / time_in_second;
    double speed_kmeter_in_hour = speed_meter_in_second * 0.001 * 3600;
    cout << "--------------------------------" << endl;
    cout << "Вы бежали со скоростью: " << speed_kmeter_in_hour << " км/ч";


}


void task4_hw_190122()
{
    cout << "Введите стоимость одной минуты исходящего звонка (руб.коп)" << endl;
    float minute_cost;
    cin >> minute_cost;

    cout << "Введите продолжительность звонка в минутах и секундах (мин.сек)" << endl;
    float call_time;
    cin >> call_time;

    cout << "--------------------------------" << endl;

    int call_minutes_amount = call_time;

    int call_seconds_amount = int((call_time * 100)) % 100;
        //хитрый ход для вычисления количества секунд отдельно от минут
        //т.е. нахождение первых двух знаков дробной части числа
    

    int call_time_in_minutes  = (call_seconds_amount > 0) ? call_minutes_amount + 1 : call_minutes_amount;
        //выше НЕ нужно чтобы call_minutes_amount инкрементировалась поэтому просто +1
 

    float call_cost_minute_tariff = minute_cost * call_time_in_minutes;
    int call_cost_minute_tariff_rub = call_cost_minute_tariff;
    int call_cost_minute_tariff_kop = int((call_cost_minute_tariff * 100)) % 100;
        //нахождение первых двух знаков дробной части числа
    cout << "Стоимость звонка при поминутной тарификации: " << call_cost_minute_tariff_rub << " руб.";
    cout << call_cost_minute_tariff_kop << " коп." << endl;

    cout << "--------------------------------" << endl;

    int call_time_in_seconds = call_minutes_amount * 60 + call_seconds_amount;
    float second_cost = minute_cost * 0.01667; 
        //по-другому не придумал, как стоимость одной секунды посчитать
        //0.01667 ~= 1/60
    float call_cost_second_tariff = call_time_in_seconds * second_cost;
    int call_cost_second_tariff_rub = call_cost_second_tariff;
    int call_cost_second_tariff_kop = int((call_cost_second_tariff * 100)) % 100;
        //нахождение первых двух знаков дробной части числа
    cout << "Стоимость звонка при посекундной тарификации: " << call_cost_second_tariff_rub << " руб.";
    cout << call_cost_second_tariff_kop << " коп." << endl;
}

void task5_hw_190122()
{
    cout << "Преобразует введенное пользователем количество дней в количество полных недель и оставшихся дней" << endl;
    cout << "Введите количество дней: ";
    int days_amount;
    cin >> days_amount;
    cout << "--------------------------------" << endl;
    cout << "Количество полных недель = " << days_amount / 7 << endl;
    cout << "Количество оставшихся дней = " << days_amount % 7 << endl;

}

int main()
{
    setlocale(0, "");


    //task1_hw_190122();
    //cout << endl;

    //task2_hw_190122();
    //cout << endl;

    //task3_hw_190122();
    //cout << endl;

    //task4_hw_190122();
    //cout << endl;

    //task5_hw_190122();
    //cout << endl;


}


//||
//ДЗ от 190122

