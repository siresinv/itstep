// STEP _CPP _classwork17 _08.04.22 _task1
/*
	РЕКУРСИЯ

	Задание 3. Написать рекурсивную функцию, которая
вычисляет сумму всех чисел в диапазоне от a до b. Пользователь вводит a и b. Проиллюстрируйте работу функции
примером.



почему функция возвращает, когда как бы не должна - это в задаче про сложение диапазона
*/


#include <iostream>





int sumDiapason(int num1, int num2);


int main() {
	setlocale(0, "");
	std::cout << sumDiapason(10, 10);
}


int sumDiapason(int num1, int num2) {
	if (num1 < num2) {
		return num1 + sumDiapason(num1 + 1, num2);
	}
	else if (num1 > num2) {
		sumDiapason(num2, num1);
	} 
}




