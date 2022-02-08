// STEP C++ Practic.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//использовал из того, что не проходили:
//  Конкатенация строк - по сути несколько "<<" в одной строке
//  Использование переменных в выводе ccout
//  Определение массива символов, например char step[9] = "________".
//      - один символ отводится как служебный
//  Вызов своей функции из функции main(). void означает функция ничего не возвращает
//  Показалось не сложно. Почитал. Опыт программирования уже есть - PHP, Python
//  Надеюсь, сам всё правильно понял ))
//  Еще доделал задание с объявлением.

#include <iostream>
using namespace std;

void output1()
{
    cout << "=================================================================================\n";
    cout << "|\tX\t|\tY\t|\tX and Y\t|\tX or Y\t|\tnot X\t|\n";
    cout << "=================================================================================\n";
    cout << "|\t0\t|\t0\t|\t0\t|\t0\t|\t1\t|\n";
    cout << "|\t0\t|\t1\t|\t0\t|\t1\t|\t1\t|\n";
    cout << "|\t1\t|\t0\t|\t0\t|\t1\t|\t0\t|\n";
    cout << "|\t1\t|\t1\t|\t1\t|\t1\t|\t0\t|\n";
    cout << "==================================================================================\n";
}


void poem()
{
    cout << "|\tЯ помню чудное мгновение\t|\n";
    cout << "|\tПередо мноя явилась ты\t\t|\n";
    cout << "|\tКак мимолетное видение\t\t|\n";
    cout << "|\tКак гений чистой красоты\t|\n\n";
    cout << "\t\t\tА.С. Пушкин\t";
}


void ad()
{   
    cout << "==================================" << "\n";
    cout << "||" << "Продается велосипед" << "\t\t||" << "\n";
    cout << "||" << "Спортивный. 27 скоростей" << "\t||" << "\n";
    cout << "||" << "Дисковые тормоза" << "\t\t||" << "\n";
    cout << "||" << "Рама - карбон" << "\t\t\t||" << "\n";
    cout << "==================================" << "\n";
    cout << "||" << "Телефон - 222-22-22" << "\t\t||" << "\n";
    cout << "__________________________________" << "\n";
    cout << "|222" << "\t|" << "222" << "\t|" << "222" << "\t|" << "222" << "\t|" << "\n";
    cout << "|22" << "\t|" << "22" << "\t|" << "22" << "\t|" << "22" << "\t|" << "\n";
    cout << "|22" << "\t|" << "22" << "\t|" << "22" << "\t|" << "22" << "\t|";


 
}


void raduga1()
{
    cout << "_________\n";
    cout << "|Каждый\t|\n";
    cout << "\t_________\n";
    cout << "\t|Охотник|\n";
    cout << "\t\t_________\n";
    cout << "\t\t|Желает\t|\n";
    cout << "\t\t\t_________\n";
    cout << "\t\t\t|Знать\t|\n";
    cout << "\t\t\t\t_________\n";
    cout << "\t\t\t\t|Где\t|\n";
    cout << "\t\t\t\t\t_________\n";
    cout << "\t\t\t\t\t|Сидит\t|\n";
    cout << "\t\t\t\t\t\t_________\n";
    cout << "\t\t\t\t\t\t|Фазан\t|\n";
}


void raduga1_1()
{
    cout << "_________\n";
    cout << "|Каждый\t|________\n";
    cout << "\t|Охотник|________\n";
    cout << "\t\t|Желает\t|________\n";
    cout << "\t\t\t|Знать\t|________\n";
    cout << "\t\t\t\t|Где\t|________\n";
    cout << "\t\t\t\t\t|Сидит\t|________\n";
    cout << "\t\t\t\t\t\t|Фазан\t|\n";
}


void raduga1_2()
{
    cout << "_________\n";
    cout << "|Каждый\t|________\n";
    cout << "|\t|Охотник|________\n";
    cout << "|\t|\t|Желает\t|________\n";
    cout << "|\t|\t|\t|Знать\t|________\n";
    cout << "|\t|\t|\t|\t|Где\t|________\n";
    cout << "|\t|\t|\t|\t|\t|Сидит\t|________\n";
    cout << "|\t|\t|\t|\t|\t|\t|Фазан\t|\n";
}


void raduga1_3()
{
    char step[10] = "________|";
    //char wall1[9] = "|___|___";
    //char wall2[9] = "___|___|";
    //char wall_end1[2] = "_";
    //char wall_end2[2] = "|";
    char wall1[9] = "|___|__|";
    char wall2[9] = "|__|___|";
    char wall_end1[2] = "";
    char wall_end2[2] = "";
    cout << "\t\t\t\t\t\t" << step << "\n";
    cout << "\t\t\t\t\t" << step << "Фазан\t" << wall_end1 << "\n";
    cout << "\t\t\t\t" << step << "Сидит\t" << wall1 << wall_end2 << "\n";
    cout << "\t\t\t" << step << "Где\t" << wall2 << wall2 << wall_end1 << "\n";
    cout << "\t\t" << step << "Знать\t" << wall1 << wall1 << wall1 << wall_end2 << "\n";
    cout << "\t" << step << "Желает\t" << wall2 << wall2 << wall2 << wall2 << wall_end1 << "\n";
    cout << "" << step << "Охотник" << wall1 << wall1 << wall1 << wall1 << wall1 << wall_end2 << "\n";
    cout << "|Каждый\t" << wall2 << wall2 << wall2 << wall2 << wall2 << wall2 << wall_end1 << "\n";
    
}


void raduga1_4()
{
    char step[9] = "________";
    char wall1[9] = "|__|____";
    char wall2[10] = "|____|__";
    char wall_end1[2] = "|";
    char wall_end2[2] = "|";

    cout << "\t\t\t\t\t\t" << "Фазан\t" << wall_end1 << "\n";
    cout << "\t\t\t\t\t\t" << step << wall_end1 << "\n";

    cout << "\t\t\t\t\t" << "Сидит\t" << wall1 << wall_end1 << "\n";
    cout << "\t\t\t\t\t" << step << wall2 << wall_end2 << "\n";


    cout << "\t\t\t\t" << "Где\t" << wall1 << wall1 << wall_end1 << "\n";
    cout << "\t\t\t\t" << step << wall2 << wall2 << wall_end2 << "\n";

    cout << "\t\t\t" << "Знать\t" << wall1 << wall1 << wall1 << wall_end1 << "\n";
    cout << "\t\t\t" << step << wall2 << wall2 << wall2 << wall_end2 << "\n";

    cout << "\t\t" << "Желает\t" << wall1 << wall1 << wall1 << wall1 << wall_end1 << "\n";
    cout << "\t\t" << step << wall2 << wall2 << wall2 << wall2 << wall_end2 << "\n";

    cout << "\t" << "Охотник\t" << wall1 << wall1 << wall1 << wall1 << wall1 << wall_end1 << "\n";
    cout << "\t" << step << wall2 << wall2 << wall2 << wall2 << wall2 << wall_end2 << "\n";

    cout << "Каждый\t" << wall1 << wall1 << wall1 << wall1 << wall1 << wall1 << wall_end1 << "\n";
    cout << step << wall2 << wall2 << wall2 << wall2 << wall2 << wall2 << wall_end2 << "\n";

    cout << wall1 << wall1 << wall1 << wall1 << wall1 << wall1 << wall1 << wall_end1 << "\n";
}






void output_var_const_120122()
{
    short age;
    age = 15;
    short age2 = 20;
    cout << age << " " << age2 << endl;
    const short age3 = 2;
    //age3 = 20;

}


void output_HoursInYear_120122()
{
    const short HoursInDay = 24;
    short DaysInYear = 365, HoursInYear;
    HoursInYear = HoursInDay * DaysInYear;
    cout << "Hours in Year = " << HoursInYear << endl;
    cout << "Hours in Year = " << HoursInDay * DaysInYear << endl;



}


void output_float_120122()
{
    float Cost = 50;
    short Count = 7;
    float Discount = 0.05;
    float Sale = Cost * Count * (1 - Discount);

    cout << "Sale with Discount = " << Sale << endl;
}


void input_120122()
{
    float Cost;
    cout << "Input Product Cost: ";
    cin >> Cost;

    short Count = 7;
    cout << "Input Product Count: ";
    cin >> Count;

    float Discount = 0.05;
    cout << "Input Discount: ";
    cin >> Discount;

    float Sale = Cost * Count * (1 - Discount);

    //cin >> Cost >> Count;

    cout << "Sale with Discount = " << Sale << endl;

}



void game_120122()
{
    //компьютер всегда говорит, что его число больше 1. Не делали
    short age = 15;
    cout << ++age;

}


void task1_120122()
{
    const float cm_in_inch = 2.54;
    short diagonal_inch;
    cout << "Диагональ телевизора (inch) -> ";
    cin >> diagonal_inch;
    cout << "--------------------------------" << endl;
    float diagonal_cm;
    diagonal_cm = diagonal_inch * cm_in_inch;
    cout << "Диагональ телевизора: " << diagonal_cm << " см.";
}


void task2_120122()
{
    short tel_capacity;
    cout << "Емкость аккумулятора вашего телефона (мАч) -> ";
    cin >> tel_capacity;
    cout << "--------------------------------" << endl;
    short charges_number;
    cout << "На какое количество зарядок необходим PowerBank -> ";
    cin >> charges_number;
    cout << "--------------------------------" << endl;

    short powerbank_capacity;
    powerbank_capacity = tel_capacity * charges_number;
    cout << "PowerBank должен быть емкостью: " << powerbank_capacity << " мАч";
}



void task3_120122()
{
    // необязательная

    cout << "Вычисление объема параллелепипеда" << endl << "Введите исходные данные" << endl;
    int lenght;
    cout << "Длина (см) -> ";
    cin >> lenght;
    cout << endl;
    int width;
    cout << "Ширина (см) -> ";
    cin >> width;
    cout << endl; 
    int height;
    cout << "Высота (см) -> ";
    cin >> height;
    cout << endl;

    // long long ????
    double volume;
    volume = lenght * width * height;
    cout << "Объем: " << volume << " куб. см.";
}


void task4_120122()
{
    cout << "Вычисление количества корма для хомяка" << endl << "Введите исходные данные" << endl;
    int feed_per_day_gr;
    cout << "Расход корма за один день (г.) -> ";
    cin >> feed_per_day_gr;
    float feed_per_day_kg = feed_per_day_gr * 0.001;
    cout << "--------------------------------" << endl;

    float feed_per_month_kg;
    feed_per_month_kg = feed_per_day_kg * 30;
    cout << "Объем корма на 30 дней: " << feed_per_month_kg << " кг.";
}





//ДЗ от 120122
//||
//task1_hw_120122 - номерзадния_hw(cw)_дата. hw/cw - homework/classwork

/*
Курс «Язык программирования C»
Встреча №3
Тема : Введение в язык программирования "C"
Домашнее задание
Задание 1 : Заданы три сопротивлении R1, R2, R3.Вычислить значение сопротивления R0 по
формуле : 1 / R0 = 1 / R1 + 1 / R2 + 1 / R3.
Контрольный пример : R1 = 2, R2 = 4, R3 = 8 R0 = 1.142857
Задание 2 : По заданной длине окружности найти площадь круга по формуле S = pi * R2, радиус
вычислить из формулы длины окружности : L = 2 * pi * R
Примечание pi = 3.14
Задание 3 : Вычислить пройденное расстояние при прямолинейном равноускоренном движении
по формуле S = v * t + (a * t2) / 2, где v – скорость, t – время, а – ускорение.
*/



void task1_hw_120122()
{
    cout << "Задание 1 : Вычисление сопротивления R0 по формуле : 1/R0 = 1/R1 + 1/R2 + 1/R3" << endl << "Введите исходные данные" << endl;
    float r1;
    cout << "R1(ом) -> ";
    cin >> r1;
    float r2;
    cout << "R2(ом) -> ";
    cin >> r2;
    float r3;
    cout << "R3(ом) -> ";
    cin >> r3;
    cout << "--------------------------------" << endl;

    float r0;
    r0 = 1 / (1 / r1 + 1 / r2 + 1 / r3);
    cout << "R0: " << r0 << " Ом";
}

void task2_hw_120122()
{
    cout << " Задание 2 : По заданной длине окружности найти площадь круга по формуле S = pi * R2" << endl << "Введите исходные данные" << endl;

    const float pi = 3.14;
    float r;
    cout << "R(см) -> ";
    cin >> r;
    cout << "--------------------------------" << endl;

    float s;
    s= pi*r*r;
    cout << "S: " << s << " кв.см";
    cout << "\n\n";


    cout << "Радиус вычислить из формулы длины окружности : L = 2 * pi * R" << endl << "Введите исходные данные" << endl;

 
    float l;
    cout << "L(см) -> ";
    cin >> l;
    cout << "--------------------------------" << endl;

    r = l/(2*pi);
    cout << "R: " << r << "см";
    cout << "\n\n";

}

void task3_hw_120122()
{
    cout << "Задание 3 : Вычислить пройденное расстояние при прямолинейном равноускоренном движении по формуле S = v * t + (a * t2) / 2, где v – скорость, t – время, а – ускорение." << endl << "Введите исходные данные" << endl;
    float v;
    cout << "v(м/с) -> ";
    cin >> v;
    float t;
    cout << "t(с) -> ";
    cin >> t;
    float a;
    cout << "a(м/с2) -> ";
    cin >> a;
    cout << "--------------------------------" << endl;

    float s;
    s = v*t + (a*t*t)/2;
    cout << "S: " << s << " м";
}

//||
//ДЗ от 120122








int main()
{
    setlocale(0, "");

    //output1();
    //cout << "\n\n";
    //poem();
    //cout << "\n\n";
    //raduga1();
    //cout << "\n\n";
    //raduga1_1();
    // cout << "\n\n";
    //raduga1_2();
    //cout << "\n\n";
    //raduga1_3();
    //cout << "\n\n";
    //raduga1_4();
    //cout << "\n\n";
    //ad();
    //cout << "\n\n";

    //output_var_const_120122();
    //cout << "\n\n";
    //output_HoursInYear_120122();
    //cout << "\n\n";

    //output_float_120122();
    //cout << endl;

    /*input_120122();
    cout << endl;*/

    //game_120122();
    //cout << endl;

    //task1_120122();
    //cout << endl;

    //task2_120122();
    //cout << endl;

    //task3_120122();
    //cout << endl;

    //task4_120122();
    //cout << endl;

    //task1_hw_120122();
    //cout << endl;

    //task2_hw_120122();
    //cout << endl;

    task3_hw_120122();
    cout << endl;


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
