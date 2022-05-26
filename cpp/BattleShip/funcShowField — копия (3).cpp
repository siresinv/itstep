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


// вывод кораблей у стеночки - тут установка первой клетки на край и в соответствующем направлением расположение корабля
// сделать совсем рандомно расстановку кораблей а не сначала линкоры, потом крейсеры и т.д. - массив перемещать


const int FIELD_SIZE_X = 10;
const int FIELD_SIZE_Y = 10;


// тут ЭНАМом сделать или структурой или МАССИВОМ
const char ICON_SEE = ' ';
const char ICON_SHIP = 219;
const char ICON_ABOUT_SHIP = ' ';
const char ICON_SHOT_MISS = '.';
const char ICON_SHOT_HIT = 'X';

enum fieldCellType
{
	cellSee,
	cellShip,
	cellShotMiss,
	cellShotHit,
	cellAboutShip
};

enum shipType
{
	shipBoat = 1,
	shipDestroyer,
	shipCruiser,
	shipLincor
};

enum shotResultType
{
	shotRepeat,
	shotMiss,
	shotHit,
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
			if (cell != cellShip) setCell(&cell,cellAboutShip);
		}
	}
}

bool isSetableShip(int** field, int letter, int digit, int nDeck, bool direction) {
	if (direction) {
		for (int i = digit; i <= getShipLastCell(digit, nDeck); i++) {
			if (*(*(field + letter) + i) != cellSee) return false;
		}
	}
	else {
		for (int i = letter; i <= getShipLastCell(letter, nDeck); i++) {
			if (*(*(field + i) + digit) != cellSee) return false;
		}
	}
	return true;
}

bool setShip(int** field, int letter, int digit, int nDeck, bool direction) {
	if (direction) {
		for (int i = digit; i <= getShipLastCell(digit, nDeck); i++) {
			int& cell = *(*(field + letter) + i);
			setCell(&cell, cellShip);
		}
	}
	else {
		for (int i = letter; i <= getShipLastCell(letter, nDeck); i++) {
			int& cell = *(*(field + i) + digit);
			setCell(&cell, cellShip);
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

/*bool isShipAboutShip(int** field, int letter, int digit) {

	int rectX1;
	int rectY1;
	int rectX2;
	int rectY2;

	rectX1 = (digit == 0) ? 0 : digit - 1;
	rectY1 = (letter == 0) ? 0 : letter - 1;
	rectX2 = (digit == FIELD_SIZE_X - 1) ? digit : digit + 1;
	rectY2 = (letter == FIELD_SIZE_Y - 1) ? letter : letter + 1;

	for (int i = rectY1; i <= rectY2; i++) {
		for (int j = rectX1; j <= rectX2; j++) {
			
			if (!(i == letter && j == digit)) {
				if (*(*(field + i) + j) == cellShip) {
					return true;
				} 
			}
		}
	}
	return false;
}*/

int getShotResult(int** field, int letter, int digit) {
	int shotCell = *(*(field + letter) + digit);
	
	if (shotCell == cellSee || shotCell == cellAboutShip) {
		return shotMiss;
	}
	else if (shotCell == cellShotMiss || shotCell == cellShotHit) {
		//doShot(field, letter, digit); //ТУТ ПОДУМАТЬ КАК
		return shotRepeat;
	}
	else {
			return shotHit;
	}
}

void scanFieldAfterHit(int** field, int letter, int digit) {
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		for (int j = 0; j < FIELD_SIZE_X; j++) {
			int shotCell = *(*(field + i) + j);
			if (shotCell == cellShotHit) {

			}
		}
	}
}

void doShot(int** field, int letter, int digit) {
	int& cell = *(*(field + letter) + digit);
	int shortResult = getShotResult(field, letter, digit);
	if (shortResult != shotRepeat){
		switch (shortResult) {
		case shotMiss:
			setCell(&cell, cellShotMiss);
			break;
		case shotHit:
			setCell(&cell, cellShotHit);
			scanFieldAfterHit(field, letter, digit);
			break;
		default:
			break;
		}
	}
}



void createFleet(int** field) {
	int* arrShipList = getShipList();
	for (int i = 0; i < 10; i++) {
		setRandShip(field, arrShipList[i], getRandDirection());
	}
	delete[] arrShipList;
}

void showField(int** field) {
	std::cout << "-----------------------------------------";
	std::cout << std::endl;
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		std::cout << "|";
		for (int j = 0; j < FIELD_SIZE_X; j++) {

			int cell = *(*(field + i) + j);

			if (cell == cellShip) {
				std::cout << " " << ICON_SHIP << " |";
			}
			else if (cell == cellAboutShip) {
				std::cout << " " << ICON_ABOUT_SHIP << " |";
			}
			else if (cell == cellShotMiss) {
				std::cout << " " << ICON_SHOT_MISS << " |";
			}
			else if (cell == cellShotHit) {
				std::cout << " " << ICON_SHOT_HIT << " |";
			}
			else {
				std::cout << " " << ICON_SEE << " |";
			}
		}
		std::cout << std::endl;
		std::cout << "-----------------------------------------";
		std::cout << std::endl;
	}
}

int* getSeeLine() {
	int* seeLine = new int [FIELD_SIZE_X];
	for (int i = 0; i < FIELD_SIZE_X; i++) {
		*(seeLine + i) = cellSee;
	}
	return seeLine;
}

int main() {
	//setlocale(0, "");
	srand(time(NULL));
	
	int randLetter;
	int randDigit;

	// Это тоже в функцию
	// ФОРМИРОВАНИЕ ПЕРВОГО ПОЛЯ
	int** field1 = new int* [FIELD_SIZE_Y];
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		field1[i] = getSeeLine();
	}
	createFleet(field1);
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
	for (int i = 1; i < 100; i++) {
		randLetter = rand() % FIELD_SIZE_Y;
		randDigit = rand() % FIELD_SIZE_X;

		std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
		std::cout << std::endl;
		doShot(field1, randLetter, randDigit);
		showField(field1);
		std::cout << std::endl;
		std::cout << std::endl;
	}
	

	// ГЕНЕРАЦИЯ ВЫСТРЕЛОВ ПОДРЯД
	/*int shotCounter = 0;
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
	}*/


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
	createFleet(field2);
	showField(field2);
	// Удаление массива
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		delete[] field2[i];
	}
	delete[] field2;*/

	


	
}