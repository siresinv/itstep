#include <iostream>
#include <stdlib.h>
#include <math.h>


// ПОДУМАТЬ
///////////////////////////// Сканирование поля - нахождение кораблей, ошибок. Это в том числе для ручного ввода

// таки что-то придумать для контроля убил/ранил. воо - какие клетки вокруг той в которую попал
//	функцию - какие клетки вокруг той, в которую попали
// но система не будет знать какой корабль убит, но это наверно и не надо
// но это пригодится для умной стрельбы
// еще умный обстрел из статей
// А КАК БЛИН РАМКУ ВОКРУГ КОРАБЛЯ ПРИ ОБСТРЕЛЕ - ТОЧНЕЕ ПРИ ПОЛНОМ ПОТОПЛЕНИИ КОРАБЛЯ


// Например, здесь применить СТРУКТУРЫ???
//const char ICON_SEE = '.';
//const char ICON_SHIP = 'O';
//const char ICON_ABOUT_SHIP = '+';


// вывод кораблей у стеночки - тут установка первой клетки на край и в соответствующем направлением расположение корабля
// сделать совсем рандомно расстановку кораблей а не сначала линкоры, потом крейсеры и т.д. - массив перемещать


const int FIELD_SIZE_X = 20;
const int FIELD_SIZE_Y = 20;


// тут ЭНАМом сделать или структурой
const char ICON_SEE = '.';
const char ICON_SHIP = 'O';
const char ICON_ABOUT_SHIP = '+';
const char ICON_SHOT_MISS = 3;
const char ICON_SHOT_HIT = 176;

enum fieldCellType
{
	// добавить префикс Cell
	fieldSee,
	fieldShip,
	fieldShotMiss,
	fieldShotHit,
	fieldAboutShip
};

enum shipType
{
	empty, // т.к. 0 - это море
	shipBoat,
	shipDestroyer,
	shipCruiser,
	shipLincor
};

enum shotResultType
{
	shotRepeat,
	shotMiss,
	shotHit,
	shotKill
}; 

int* getShipList() {
	int* arrShipList = new int[] {shipLincor, shipCruiser, shipCruiser, shipDestroyer, shipDestroyer, shipDestroyer, shipBoat, shipBoat, shipBoat, shipBoat};
	return arrShipList;
}

int getShipLastCell(int firstCell, int nDeck) {
	return firstCell + nDeck - 1;
}

bool isShipOnField(int letter, int digit, int nDeck, bool direction) {
	if (direction) {
		if (getShipLastCell(digit, nDeck) > FIELD_SIZE_X - 1) {
			return false;
		}
	}
	else {
		if (getShipLastCell(letter, nDeck) > FIELD_SIZE_Y - 1) {
			return false;
		}
	}

	return true;
}

int* getCoordRectAboutShip(int letter, int digit, int nDeck, bool direction){
	/// Возвращает массив с координатами прямоугольника вокруг корабля
	
	int rectX1;
	int rectY1;
	int rectX2;
	int rectY2;
	int shipLastCell;

	rectX1 = (digit > 0) ? digit - 1 : digit;
	rectY1 = (letter > 0) ? letter - 1 : letter;

	if (direction) {
		shipLastCell = getShipLastCell(digit, nDeck);
		rectX2 = (shipLastCell == FIELD_SIZE_X - 1) ? shipLastCell : (shipLastCell + 1);
		rectY2 = (letter == FIELD_SIZE_Y - 1) ? letter : letter + 1;
	}
	else {
		shipLastCell = getShipLastCell(letter, nDeck);
		rectX2 = (digit == FIELD_SIZE_X - 1) ? digit : digit + 1;
		rectY2 = (shipLastCell == FIELD_SIZE_Y - 1) ? shipLastCell : (shipLastCell + 1);
	}

	int* arrCoordRectAboutShip = new int[]{rectX1, rectY1, rectX2, rectY2};
	return arrCoordRectAboutShip;
}

void setCell(int* cell, int value) {
	*cell = value;
}

void setRectAboutShip(int** field, int rectX1, int rectY1, int rectX2, int rectY2) {
	for (int i = rectY1; i <= rectY2; i++) {
		for (int j = rectX1; j <= rectX2; j++) {
			int& cell = *(*(field + i) + j);
			if (cell != fieldShip) setCell(&cell,fieldAboutShip);
		}
	}
}

bool isSetableShip(int** field, int letter, int digit, int nDeck, bool direction) {
	if (direction) {
		for (int i = digit; i <= getShipLastCell(digit, nDeck); i++) {
			if (*(*(field + letter) + i) != fieldSee) return false;
		}
	}
	else {
		for (int i = letter; i <= getShipLastCell(letter, nDeck); i++) {
			if (*(*(field + i) + digit) != fieldSee) return false;
		}
	}
	return true;
}

bool setShip(int** field, int letter, int digit, int nDeck, bool direction) {
	if (direction) {
		for (int i = digit; i <= getShipLastCell(digit, nDeck); i++) {
			int& cell = *(*(field + letter) + i);
			setCell(&cell, fieldShip);
		}
	}
	else {
		for (int i = letter; i <= getShipLastCell(letter, nDeck); i++) {
			int& cell = *(*(field + i) + digit);
			setCell(&cell, fieldShip);
		}
	}
	return true;
}

void setRandShip(int** field, int nDeck, bool direction) {

	int randLetter;
	int randDigit;
	int rectX1;
	int rectY1;
	int rectX2;
	int rectY2;

	do {
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;
		} while (!isShipOnField(randLetter, randDigit, nDeck, direction));
	} while (!isSetableShip(field, randLetter, randDigit, nDeck, direction));
	
	setShip(field, randLetter, randDigit, nDeck, direction);

	int* arrCoordRectAboutShip = getCoordRectAboutShip(randLetter, randDigit, nDeck, direction);
	rectX1 = arrCoordRectAboutShip[0];
	rectY1 = arrCoordRectAboutShip[1];
	rectX2 = arrCoordRectAboutShip[2];
	rectY2 = arrCoordRectAboutShip[3];
	delete[]arrCoordRectAboutShip;

	setRectAboutShip(field, rectX1, rectY1, rectX2, rectY2);
}

bool getRandDirection() {
	return ((rand() % 1000) % 2 == 0) ? true : false;
}

//int getCellAboutShip

int getShotResult(int** field, int letter, int digit) {
	// ТУТ ДОПИЛИВАТЬ
	// NULL тут как срабатвает. НИХЕРА ПОХОДУ НЕ СРАБАТЫВАЕТ)))
	int shotCell = *(*(field + letter) + digit);
	
	if (shotCell == fieldSee || shotCell == fieldAboutShip) {
		return shotMiss;
	}
	else if (shotCell == fieldShotMiss || shotCell == fieldShotHit) { // || shotCell == fieldShotKill ???
		return shotRepeat;
	}
	else {
		return shotHit;
		//for (int i = 0; i < FIELD_SIZE_Y; i++) {
		//	for (int j = 0; j < FIELD_SIZE_X; j++) {
		//		if (abs(letter - i) == fieldShip || abs(digit - j) == fieldShip) { // ЗДЕСЬ ВЫХОД ЗА ГРАНИЦЫ МАССИВА
		//			if (*(*(field + i) + j) == fieldShip) {
		//				return shotHit;
		//			}
		//		}
		//	}
		//}
	}
	//return shotHit;
}

void doShot(int** field, int letter, int digit) {
	int& cell = *(*(field + letter) + digit);
	if (!shotRepeat){
		switch (getShotResult(field, letter, digit)) {
		case shotMiss:
			setCell(&cell, fieldShotMiss);
			break;
		case shotHit:
			setCell(&cell, fieldShotHit);
			break;
		case shotKill:
			setCell(&cell, 219); ///
			// СКАНИРОВАНИЕ ПОЛЯ ДЛЯ РАССТАНОВКИ КЛЕТОК ВОКРУГ КОРАБЛЯ
			// ЛИБО ПО-ДРУГОМУ ПОДУМАТЬ ОБОЗНАЧЕНИЕ ПОТОПЛЕНИЯ КОРАБЛЯ
			break;
		default:
			break;
		}
	}
}

void createField(int** field) {
	int* arrShipList = getShipList();
	for (int i = 0; i < 10; i++) {
		setRandShip(field, arrShipList[i], getRandDirection());
	}
	delete[] arrShipList;
}

void showField(int** field) {
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		for (int j = 0; j < FIELD_SIZE_X; j++) {

			int cell = *(*(field + i) + j);

			if (cell == fieldShip) {
				std::cout << ICON_SHIP << " ";
			}
			else if (cell == fieldAboutShip) {
				std::cout << ICON_ABOUT_SHIP << " ";
			}
			else if (cell == fieldShotMiss) {
				std::cout << ICON_SHOT_MISS << " ";
			}
			else if (cell == fieldShotHit) {
				std::cout << ICON_SHOT_HIT << " ";
			}
			else {
				std::cout << ICON_SEE << " ";
			}
		}
		std::cout << std::endl;
	}
}

int* getSeeLine() {
	int* seeLine = new int [FIELD_SIZE_X];
	for (int i = 0; i < FIELD_SIZE_X; i++) {
		*(seeLine + i) = fieldSee;
	}
	return seeLine;
}

int main() {

	srand(time(NULL));
	
	int randLetter;
	int randDigit;

	// ФОРМИРОВАНИЕ ПЕРВОГО ПОЛЯ
	int** field1 = new int* [FIELD_SIZE_Y];
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		field1[i] = getSeeLine(); //new int [FIELD_SIZE_X]{}; // не уверен, что будет удаляться массив, точнее, что этот по ссылке получает массив из функции
	}
	createField(field1);
	showField(field1);

	std::cout << std::endl;
	std::cout << std::endl;




	
	/*
	doShot(field1, 5, 5);
	showField(field1);
	std::cout << std::endl;
	std::cout << std::endl;

	doShot(field1, 5, 5);
	showField(field1);
	std::cout << std::endl;
	std::cout << std::endl;*/


	// ГЕНЕРАЦИЯ СЛУЧАЙНЫХ ВЫСТРЕЛОВ
	/*for (int i = 1; i < 100; i++) {
		randLetter = rand() % FIELD_SIZE_Y;
		randDigit = rand() % FIELD_SIZE_X;

		std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
		std::cout << std::endl;
		doShot(field1, randLetter, randDigit);
		showField(field1);
		std::cout << std::endl;
		std::cout << std::endl;
	}*/
	

	// ГЕНЕРАЦИЯ ВЫСТРЕЛОВ ПОДРЯД
	int shotCounter = 0;
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		for (int j = 0; j < FIELD_SIZE_X; j++) {
			randLetter = i;
			randDigit = j;
			shotCounter++;
			std::cout << "--" << shotCounter << "-- " << randLetter << ", " << randDigit;
			std::cout << std::endl;
			doShot(field1, randLetter, randDigit);
			showField(field1);
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}


	// Удаление массива
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		delete[] field1[i];
	}
	delete[] field1;

	



	// ФОРМИРОВАНИЕ ВТОРОГО ПОЛЯ
	/*int** field2 = new int* [FIELD_SIZE_Y];
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		field2[i] = getSeeLine(); //new int [FIELD_SIZE_X]{}; // не уверен, что будет удаляться массив, точнее, что этот по ссылке получает массив из функции
	}
	createField(field2);
	showField(field2);
	// Удаление массива
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		delete[] field2[i];
	}
	delete[] field2;*/

	


	
}