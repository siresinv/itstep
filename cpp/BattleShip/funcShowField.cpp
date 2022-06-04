#include <iostream>
#include <stdlib.h>
#include <math.h>







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


const char ICON_SEE = ' ';
const char ICON_SHIP = 219;
const char ICON_ABOUT_SHIP = ' ';
const char ICON_SHOT_MISS = '.';
const char ICON_SHOT_HIT = 'X';

enum fieldCellType // типы клеток поля
{
	cellSee,
	cellShip,
	cellShotMiss,
	cellShotHit,
	cellAboutShip
};

enum shipType // типы кораблей с соответствующим количеством палуб
{
	shipBoat = 1,
	shipDestroyer,
	shipCruiser,
	shipLincor
};

enum shotResultType // результаты выстрелов
{
	shotRepeat,
	shotMiss,
	shotHit
}; 

int* getShipList() {
	int* arrShipList = new int[] {shipLincor, shipCruiser, shipCruiser, shipDestroyer, shipDestroyer, shipDestroyer, shipBoat, shipBoat, shipBoat, shipBoat};
	return arrShipList;
}

int getShipLastCell(int firstCell, int nDeck) { // получение последней(оконечной) клетки корабля
	return firstCell + nDeck - 1;
}

bool isShipOnField(int letter, int digit, int nDeck, bool direction) { // проверка - корабль уместиться на поле при расстановке
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

int* getCoordRectAboutShip(int letter, int digit, int nDeck, bool direction){ // Возвращает массив с координатами прямоугольника вокруг корабля
	
	
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

void setCell(int* cell, int value) { // установка соответствующей клетки на поле
	*cell = value;
}

void setRectAboutShip(int** field, int rectX1, int rectY1, int rectX2, int rectY2) { // установка прямоугольника вокруг корабля
	for (int i = rectY1; i <= rectY2; i++) {
		for (int j = rectX1; j <= rectX2; j++) {
			int& cell = *(*(field + i) + j);
			if (cell != cellShip) setCell(&cell,cellAboutShip);
		}
	}
}

bool isSetableShip(int** field, int letter, int digit, int nDeck, bool direction) { // проверка возможности установки корабля на поле - не мешают ли другие корабли
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

void setShip(int** field, int letter, int digit, int nDeck, bool direction) { // установка корабля на поле
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
}


///////////////
void selectRandShip(int** field, int nDeck, bool direction) { // выбор случайного корабля для установки

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
	
	setShip(field, randLetter, randDigit, nDeck, direction); // - это переместить отсюда

	int* arrCoordRectAboutShip = getCoordRectAboutShip(randLetter, randDigit, nDeck, direction);
	rectX1 = arrCoordRectAboutShip[0];
	rectY1 = arrCoordRectAboutShip[1];
	rectX2 = arrCoordRectAboutShip[2];
	rectY2 = arrCoordRectAboutShip[3];
	delete[]arrCoordRectAboutShip;

	setRectAboutShip(field, rectX1, rectY1, rectX2, rectY2); // - это переместить отсюда
}

bool getRandDirection() { // случайный выбор направления для установки корабля - горизонтально, вертикально
	return ((rand() % 1000) % 2 == 0) ? true : false;
}


// ЗДЕСЬ МОЖНО ЧЕРЕЗ ССЫЛКУ НА ЯЧЕКЙ СДЕЛАТЬ
int getShotResult(int** field, int letter, int digit) { // возвращение результата выстрела
	int shotCell = *(*(field + letter) + digit);
	
	if (shotCell == cellSee || shotCell == cellAboutShip) {
		return shotMiss;
	}
	else if (shotCell == cellShotMiss || shotCell == cellShotHit) {
		return shotRepeat;
	}
	else {
		return shotHit;
	}
}


// ПЕРЕПИСАТЬ ФУНКЦИИ, КОТОРЫЕ ПОЛУЧАЮТ КООРДИНАТЫ ЯЧЕЙКИ НА ПОЛУЧЕНИЕ ССЫЛКИ НА НЕЕ

/////////////// по-красивее переписать
int* getShipFirstCell(int** field, int letter, int digit) { // получение первой клетки корабля после попадания в него
	int i = letter;
	int j = digit;
	//int* arrShipFirstCell = new int[2]; //две координаты

	while (i > 0 && (*(*(field + i - 1) + digit) == cellShip || *(*(field + i - 1) + digit) == cellShotHit)) {
		i--;
	}

	while (j > 0 && (*(*(field + letter) + j - 1) == cellShip || *(*(field + letter) + j - 1) == cellShotHit)) {
		j--;
	}
	//std::cout << "\t" << i << " + " << j;
	//return *(*(field + i) + j);
	int* arrShipFirstCell = new int[2]{ i,j };
	//arrShipFirstCell = {i, j}; // КАК СДКЛАТЬ, ЧТОБЫ ЭТА СТРОКА РАБОТАЛА??????????
	return arrShipFirstCell;
}

bool getShipDirection(int** field, int firstLetter, int firstDigit) { // возвращает направление установки уорабля. TRUE - горизонтально. Одинарный - тоже горизонтально
	if (firstLetter < FIELD_SIZE_Y - 1) {
		int nextCell = *(*(field + firstLetter + 1) + firstDigit);
		//std::cout << "---------" << nextCell << "_____________";
		if (nextCell == cellShip || nextCell == cellShotHit) {
			return false;
		}
	}
	return true;
}

/////////////// по-красивее переписать
int getShipDeckAmount(int** field, int firstLetter, int firstDigit, bool direction) {
	int i = firstLetter;
	int j = firstDigit;
	int nDeck = 1;

	if (direction) {
		while (j < FIELD_SIZE_X - 1 && (*(*(field + i) + j + 1) == cellShip || *(*(field + i) + j + 1) == cellShotHit)) {
			j++;
			nDeck++;
		}
	}
	else {
		while (i < FIELD_SIZE_Y - 1 && (*(*(field + i + 1) + j) == cellShip || *(*(field + i + 1) + j) == cellShotHit)) {
			i++;
			nDeck++;
		}
	}
	return nDeck;
}



/////////////// по-красивее переписать
bool isShipKilled(int** field, int firstLetter, int firstDigit, bool direction, int nDeck) {

	if (direction) {
		for (int j = firstDigit; j <= firstDigit + nDeck - 1; j++) {
			if (*(*(field + firstLetter) + j) == cellShip) return false;
		}
	}
	else {
		for (int i = firstLetter; i <= firstLetter + nDeck - 1; i++) {
			if (*(*(field + i) + firstDigit) == cellShip) return false;
		}
	}
	return true;
}

bool scanShipAfterHit(int** field, int letter, int digit) {
	int* arrShipFirstCell = getShipFirstCell(field, letter, digit);
	int firstLetter = arrShipFirstCell[0];
	int firstDigit = arrShipFirstCell[1];
	bool direction = getShipDirection(field, firstLetter, firstDigit);
	int nDeck = getShipDeckAmount(field, firstLetter, firstDigit, direction);
	bool shipDead = isShipKilled(field, firstLetter, firstDigit, direction, nDeck);
	std::cout << "let:" << firstLetter << " dig:" << firstDigit << " dir:" << direction << " deck:" << nDeck << " dead:" << shipDead;
	std::cout << std::endl;
	return shipDead;
}





int doShot(int** field, int letter, int digit) { // осуществление выстрела
	int& cell = *(*(field + letter) + digit);
	int shotResult = getShotResult(field, letter, digit);
	if (shotResult != shotRepeat){
		switch (shotResult) {
		case shotMiss:
			setCell(&cell, cellShotMiss);
			break;
		case shotHit:
			setCell(&cell, cellShotHit);
			break;
		default:
			break;
		}
	}
	return shotResult;
}


//////////////////
void createFleet(int** field) { // создание флота
	int* arrShipList = getShipList();
	for (int i = 0; i < 10; i++) { // 10 - sizeof использовать
		selectRandShip(field, arrShipList[i], getRandDirection());
	}
	delete[] arrShipList;
}

void showField(int** field) { // вывод поля на экран
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

int** createField() { // создание пустого поля
	int** field = new int* [FIELD_SIZE_Y];
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		field[i] = new int[FIELD_SIZE_X];
	}
	return field;
}

void fillFieldSee(int** field) { // заполнение поля морем
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		for (int j = 0; j < FIELD_SIZE_X; j++) {
			int& cell = *(*(field + i) + j);
			setCell(&cell, cellSee);
		}
	}
}

int main() {
	//setlocale(0, "");
	srand(time(NULL));
	
	int randLetter;
	int randDigit;

	int** field1 = createField();
	fillFieldSee(field1);
	createFleet(field1);
	showField(field1);
	int shotResult;

	std::cout << std::endl;
	std::cout << std::endl;


	// ГЕНЕРАЦИЯ СЛУЧАЙНЫХ ВЫСТРЕЛОВ
	/*for (int i = 1; i < 10; i++) {
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;

			std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
			std::cout << std::endl;
			shotResult = doShot(field1, randLetter, randDigit);
		} while (shotResult == shotRepeat);
		if (shotResult == shotHit) {
			std::cout << scanShipAfterHit(field1, randLetter, randDigit);
		}
		
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;

			std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
			std::cout << std::endl;
			shotResult = doShot(field1, randLetter, randDigit);
		} while (shotResult == shotRepeat);
		if (shotResult == shotHit) {
			std::cout << scanShipAfterHit(field1, randLetter, randDigit);
		}


		showField(field1);
		std::cout << std::endl;
		std::cout << std::endl;

	}	
		*/
		

	// ГЕНЕРАЦИЯ ПОСЛЕДОВАТЕЛЬНЫХ ВЫСТРЕЛОВ
	int shotCounter = 0;
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		for (int j = 0; j < FIELD_SIZE_X; j++) {
			//do {
				//randLetter = rand() % FIELD_SIZE_Y;
				//randDigit = rand() % FIELD_SIZE_X;
			//std::cout << ++shotCounter;
				//std::cout << "--" << i << "-- " << randLetter << ", " << randDigit;
			//std::cout << std::endl;
			shotResult = doShot(field1, i, j);
			//} while (shotResult == shotRepeat);
			if (shotResult == shotHit) {
				scanShipAfterHit(field1, i, j);
				showField(field1);
				std::cout << std::endl;
				std::cout << std::endl;
			}


			/*showField(field1);
			std::cout << std::endl;
			std::cout << std::endl;*/
		}
		
	}

	// Удаление массива поля
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		delete[] field1[i];
	}
	delete[] field1;
}