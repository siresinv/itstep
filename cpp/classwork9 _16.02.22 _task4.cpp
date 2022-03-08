// STEP _CPP _classwork9 _16.02.22 _task4
/*
2. В массиве хранится информация о количестве жильцов
каждой квартиры пятиэтажного дома (4 подъезда, на
каждом этаже по 2 квартиры).
1- а) по выбранному номеру квартиры определить количество жильцов, а также их соседей проживающих
на одном этаже;
2- б) определить суммарное количество жильцов для
каждого подъезда;
1- в) определить номера квартир, где живут многодетные
семьи. Условно будем считать таковыми, у которых
количество членов семьи превышает пять человек.

в квартире от 1 до 8

В массив всё записать?
0-вой элемент - значение - 1
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");

	srand(time(NULL));

	const int N_FLOOR = 5; // Количество этажей
	const int N_ENTRY = 4; // Количество подъездов
	const int N_FLOOR_FLAT = 3; // Количество квартир на этаже
	const int N_ALL_FLAT = N_FLOOR * N_ENTRY * N_FLOOR_FLAT; // Общее количество квартир
	const int N_ENTRY_FLAT = N_FLOOR * N_FLOOR_FLAT; // Количство квартир в подъезде
	const int N_MANY_HUMAN = 5; // Сколько жильцов вместе считаются многодетными


	int flatNo;
	int floorNo;
	int entryNo;
	int ManyHumanFlatId; ///// Имя данной переменной и описание ???
	int selectFlatNo; // Номер выбранной квартиры
	int nHumanSelectFlat; // Количество жильцов в выбранной квартире
	bool isEvenSelectFlat; // Четность номера выбранной квартиры
	int neighborFlatNo; // Номер соседней квартиры
	int neighborFlatHumanAmount; // Количество жильцов в соседней квартире

	int arrFlatHumanAmount[N_ALL_FLAT]; // Массив с количеством жильцов в квартирах
	int arrEntryHumanAmount[N_ENTRY] = {}; // Массив с количеством жильцов в подъездах
	int arrManyHumanFlatNo[N_ALL_FLAT] = {}; // Массив для многодетных квартир. Эхх расточительство памяти )))


	for (int i = 0; i < N_ALL_FLAT; i++) {
		arrFlatHumanAmount[i] = rand() % 8 + 1;
	}


	ManyHumanFlatId = 0;
	for (int i = 0; i < N_ALL_FLAT; i++) {
		
		flatNo = i + 1; // Номер квартиры
		entryNo =  i / N_ENTRY_FLAT + 1; // Номер подъезда
		
		arrEntryHumanAmount[entryNo-1] += arrFlatHumanAmount[i];

		if (arrFlatHumanAmount[i] > N_MANY_HUMAN) {
			arrManyHumanFlatNo[ManyHumanFlatId] = flatNo;
			ManyHumanFlatId++;
		}
	}


	std::cout << "Кв.\t" << "Чел." << std::endl;
	for (int i = 0; i < N_ALL_FLAT; i++) {
		flatNo = i + 1;
		std::cout << flatNo << "\t" << arrFlatHumanAmount[i] << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Многодетные квартиры: ";
	for (int i = 0; i < N_ALL_FLAT; i++) {
		if (arrManyHumanFlatNo[i] != 0) {
			std::cout << arrManyHumanFlatNo[i] << " ";
		}
		
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Подъезд\t" << "Чел." << std::endl;
	for (int i = 0; i < N_ENTRY; i++) {
		entryNo = i + 1;
		std::cout << entryNo << "\t" << arrEntryHumanAmount[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;




	selectFlatNo = rand() % N_ALL_FLAT + 1;
	entryNo = selectFlatNo / N_ENTRY_FLAT + ((selectFlatNo % N_ENTRY_FLAT == 0) ? 0 : 1); // Номер подъезда
	floorNo = (selectFlatNo - (entryNo-1) * N_ENTRY_FLAT)/ N_FLOOR_FLAT + ((selectFlatNo % N_FLOOR_FLAT == 0) ? 0 : 1); // Номер этажа
	nHumanSelectFlat = arrFlatHumanAmount[selectFlatNo - 1];
	isEvenSelectFlat = (selectFlatNo % 2 == 0) ? true : false;
	
	//Только при условии, что квартир на этаже - две
	if (isEvenSelectFlat == true) {
		neighborFlatNo = selectFlatNo - 1;
	}
	else {
		neighborFlatNo = selectFlatNo + 1;
	}
	neighborFlatHumanAmount = arrFlatHumanAmount[neighborFlatNo - 1];

	std::cout << "Выбранная квартира: " << selectFlatNo << std::endl;
	std::cout << "Номер подъезда: " << entryNo << std::endl;
	std::cout << "Номер этажа: " << floorNo << std::endl;
	std::cout << "Количество жильцов: " << nHumanSelectFlat << std::endl;
	std::cout << "Номер соседней квартиры: " << neighborFlatNo << std::endl;
	std::cout << "Количество жильцов в соседней квартире: " << neighborFlatHumanAmount << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}

