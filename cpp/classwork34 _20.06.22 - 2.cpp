// STEP _CPP _classwork34 _20.06.22 - 2
/*
ООП НАЧАЛО


Создать класс Точка
Точка имеет поля х у
Необходимо создать три вида конструкторов:
1 заполняет точку 0 0,
2 заполняет значениями ux 0,
3 заполняет точку ux uy
добавить print()

*/


#include <iostream>
#include "classwork34_point.h"


int main()
{

	classwork34_point* point = new classwork34_point[3]{
		{},
		{1},
		{1,2}
	};
	

	for (int i = 0; i < 3; i++) {
		point[i].printPoint();
	}

	std::cout << std::endl;

	for (classwork34_point* p = point; p < point + 3; p++) {
		p->printPoint();
	}

	return 0;
}

// делегирование конструкторов

// 