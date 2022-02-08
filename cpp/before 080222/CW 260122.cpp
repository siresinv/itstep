// STEP C++ Practic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



//CW от 260122
//||
//task1_cw_260122 - номерзадния_hw(cw)_дата. hw/cw - homework/classwork


// float a = float(1) / 60; 
// )))))))) - ЗАБЫЛ

void task1_сw_260122()
{

    //ДОДЕЛАТЬ МОЖНО


    //float buy_sum;
    //cout << "Введите сумму покупки: ";
    //cin >> buy_sum;

    //if (buy_sum >= 0 && buy_sum < 500)
    //{
    //    cout << "Сумма покупки: " << buy_sum;
    //}
    //else if (buy_sum >= 500 && buy_sum < 1000))
    //{
    //cout << "Сумма покупки: " << buy_sum*0.95;
    //}
    //else if (buy_sum >= 1000 && buy_sum < 1500))
    //{
    //cout << "Сумма покупки: " << buy_sum*0.9;
    //}
    //else if (buy_sum >= 0 && buy_sum < 500))
    //{
    //cout << "Сумма покупки: " << buy_sum*0.85;
    //}
    //else
    //{
    //    cout << "Некоррректная сумма";
    //}


}



void task2_сw_260122()
{

    //Замок. Испытания. Вложенные цсловия
    //Попробовать без вложенных условий
    //МОЖНО САМОСТОЯТЕЛЬНО ПОПРОБОВАТЬ


}


void task3_сw_260122()
{

    //Попадает ли точка в кольцо
    //МОЖНО САМОСТОЯТЕЛЬНО ПОПРОБОВАТЬ


}


void task4_сw_260122()
{

    cout << "Введите первое число: ";
    int num1;
    cin >> num1;

    cout << "Введите второе число: ";
    int num2;
    cin >> num2;

    if (num1 == num2)
    {
        cout << "Числа равны";
    }
    else
    {
        int min_num = (num1 < num2) ? num1 : num2;
        cout << "Меньшее число: " << min_num;

    }
    

}

void task5_сw_260122()
{

    cout << "Введите первое число: ";
    int num1;
    cin >> num1;

    cout << "Введите второе число: ";
    int num2;
    cin >> num2;

    if (num1 == num2)
    {
        cout << "Числа равны";
    }
    else
    {
        int min_num = (num1 < num2) ? num1 : num2;
        cout << min_num << " ";
        int max_num = (min_num == num1) ? num2 : num1;
        cout << "Числа в порядке возрастания: " << min_num << " " << max_num;
    }

    

}


void task6_сw_260122()
{

    cout << "Введите число: ";
    int num;
    cin >> num;

    bool parity = (num % 2 == 0) ? true : false;

    if (parity)
    {
        cout << "Число чётное";
    }
    else
    {
        cout << "Число НЕчётное";
    }


}


int main()
{
    
    setlocale(0, "");    

    task6_сw_260122();
    cout << endl;



}


//||
//ДЗ от 190122

