#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <WinUser.h>
#include <Windows.h>







// - еще умный обстрел из статей
// - вывод кораблей у стеночки - тут установка первой клетки на край и в соответствующем направлением расположение корабля
// 
// 
// ! обстрел рядом с попаданием реализовать - горизонтально/вертикально. потом функцию с возможными положениями клеток
// ! сделать совсем рандомно расстановку кораблей а не сначала линкоры, потом крейсеры и т.д. - массив перемещать
// !! ПЕРЕПИСАТЬ ФУНКЦИИ, КОТОРЫЕ ПОЛУЧАЮТ КООРДИНАТЫ ЯЧЕЙКИ НА ПОЛУЧЕНИЕ ССЫЛКИ НА НЕЕ
// !! РАЗОБРАТЬСЯ С ПЕРЕДАЧЕЙ ССЫЛОК, УКАЗАТЕЛЕЙ - ГЛЕ КУДА ЛУЧШЕ? ИЛИ ВЕЗДЕ ОДНО СДЕЛАТЬ?
// !! ПРОТОТИПЫ ФУНКЦИЙ СДЕЛАТЬ
// !! ПРЕЗЕНТАЦИЮ. БЛОК-СХЕМУ

const int FIELD_SIZE_X = 10;
const int FIELD_SIZE_Y = 10;
const int GAMERS_AMOUNT = 2;

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

enum gamerState // состояния игрока
{
	init,
	ready,
	wait,
	move,
	win,
	lose
};

// добавить перфиксы game / gamer
enum gameState{
	empty,
	prep,
	start,
	paused,
	end,
	stop
};



shipType* getShipList() {
	shipType* arrShipList = new shipType[] {shipLincor, shipCruiser, shipCruiser, shipDestroyer, shipDestroyer, shipDestroyer, shipBoat, shipBoat, shipBoat, shipBoat};
	return arrShipList;
}


/////////// // получение последней(оконечной) клетки корабля
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


///// допиливать - при потоплении как сверять куда ставить. МОЖНО - КЛЕТКИ ВОКРУГ ПОТОПЛЕННОГО КОРАБЛЯ
void setRectAboutShip(int** field, int firstLetter, int firstDigit, int nDeck, int direction) { // установка прямоугольника вокруг корабля

	int* arrCoordRectAboutShip = getCoordRectAboutShip(firstLetter, firstDigit, nDeck, direction);
	int rectX1 = arrCoordRectAboutShip[0];
	int rectY1 = arrCoordRectAboutShip[1];
	int rectX2 = arrCoordRectAboutShip[2];
	int rectY2 = arrCoordRectAboutShip[3];
	delete[]arrCoordRectAboutShip;

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

int* getRandPosition(int** field, int nDeck, bool direction) { // выбор случайной позиции корабля для установки
	int randLetter;
	int randDigit;
	do {
		do {
			randLetter = rand() % FIELD_SIZE_Y;
			randDigit = rand() % FIELD_SIZE_X;
		} while (!isShipOnField(randLetter, randDigit, nDeck, direction));
	} while (!isSetableShip(field, randLetter, randDigit, nDeck, direction));
	int* arrRandPosition = new int[2]{ randLetter, randDigit };
	return arrRandPosition;
}

bool getRandDirection() { // случайный выбор направления для установки корабля - горизонтально, вертикально
	return ((rand() % 2) % 2 == 0) ? true : false;
}

shotResultType getShotResult(int& shotCell) { // возвращение результата выстрела
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

bool getShipDirection(int** field, int firstLetter, int firstDigit) { // возвращает направление установленного корабля. TRUE - горизонтально. Одинарный - тоже горизонтально
	if (firstLetter < FIELD_SIZE_Y - 1) {
		int nextCell = *(*(field + firstLetter + 1) + firstDigit);
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
bool scanShipAfterHit(int** field, int firstLetter, int firstDigit, bool direction, int nDeck) {

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

bool isShipKilled(int** field, int letter, int digit) { // возвращает - корабль потоплен или нет
	int* arrShipFirstCell = getShipFirstCell(field, letter, digit);
	int firstLetter = arrShipFirstCell[0];
	int firstDigit = arrShipFirstCell[1];
	bool direction = getShipDirection(field, firstLetter, firstDigit);
	int nDeck = getShipDeckAmount(field, firstLetter, firstDigit, direction);
	bool shipKilled = scanShipAfterHit(field, firstLetter, firstDigit, direction, nDeck);
	std::cout << "let:" << firstLetter << " dig:" << firstDigit << " dir:" << direction << " deck:" << nDeck << " killed:" << shipKilled;
	std::cout << std::endl;
	delete[] arrShipFirstCell;
	return shipKilled;
}

shotResultType doShot(int** field, int letter, int digit) { // осуществление выстрела
	int& shotCell = *(*(field + letter) + digit);
	shotResultType shotResult = getShotResult(shotCell);
	if (shotResult != shotRepeat){
		switch (shotResult) {
		case shotMiss:
			setCell(&shotCell, cellShotMiss);
			break;
		case shotHit:
			setCell(&shotCell, cellShotHit);
			break;
		default:
			break;
		}
	}
	return shotResult;
}

//////////////////  // 10 - sizeof использовать
void createRandFleet(int** field) { // создание флота
	shipType* arrShipList = getShipList();
	
	for (int i = 0; i < 10; i++) { // 10 - sizeof использовать
		int nDeck = arrShipList[i];
		int direction = getRandDirection();
		int* arrRandPosition = getRandPosition(field, nDeck, direction);
		int randLetter = arrRandPosition[0];
		int randDigit = arrRandPosition[1];
		setShip(field, randLetter, randDigit, nDeck, direction);
		setRectAboutShip(field, randLetter, randDigit, nDeck, direction);
		delete[] arrRandPosition;
	}
	delete[] arrShipList;
}

void showField(int** field) { // вывод поля на экран
	char firstLetter = 'A';
	std::cout << "    1   2   3   4   5   6   7   8   9   10";
	std::cout << std::endl;
	std::cout << "  -----------------------------------------";
	std::cout << std::endl;
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		std::cout << char(firstLetter + i) << " |";
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
		std::cout << "  -----------------------------------------";
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


// удаление структур/экземпляров
// с указателями как-то по особенному обращение ->
// а у ENUM Есть какой-то размер

struct gamer{
	int number;
	char* name[10];
	bool type;
	int** field;
	gamerState state;
	int moveAmount;
	int liveShipsAmount;
	int killedShipsAmount;
	int hitsAmount;
};

struct game{
	int number;
	gameState state;
	bool type; // HUMAN-PC = 0. PC-PC = 1
	gamer* gamersList; // 2
};

gamer createGamer(int number, /*char* name,*/ bool type) {
	gamer newGamer;

	newGamer.number = number;
	//newGamer.name = *name; // ПРОСТО ПОНЯТЬ КАК ЭТО ДЕЛАЕТСЯ И УБРАТЬ - ИМЯ НЕ НУЖНО
	newGamer.type = type; //HUMAN=0/ PC=1
	newGamer.field = createField();
	newGamer.state = init;
	newGamer.moveAmount = 0;
	newGamer.liveShipsAmount = 10; // 10
	newGamer.killedShipsAmount = 0;
	newGamer.hitsAmount = 0;

	return newGamer;
}

game createEmptyGame() {
	game newGame;

	newGame.number;
	newGame.state = empty;
	newGame.type;
	newGame.gamersList;
	return newGame;
}

void getField(gamer gamer) {
	fillFieldSee(gamer.field);
	createRandFleet(gamer.field);
}

void showIntro() {
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "  *** BattleShip v1.1 (by SyresinVA) ***" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}

void showSelectGameType() {
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "Select type of game \n(1 - HUMAN-PC, 2 - PC-PC): " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
}


void selectGameType() {
	
}


// умное сделать - т.е. показывать в определенный момент только то, что нужно
void showMenu() {

}


enum menuItems {
	doCreate = 1,
	doStart,
	doPause,
	doStatistic,
	doStop,
	doRestart,
	doCancel, //???
	doExit
};

menuItems getMenuChoice() {

	return doCancel;
}


void showStatistic(game game) {

}




int main() {
	srand(time(NULL));
	game currentGame = createEmptyGame(); // создали пустую игру
	// Либо это можно через меню один первый раз
	
	// выбор типа игры - кто с кем. а если еще и чел-чел
	// расстановка всегда рандомная
	// компьютер всегда умный
	// попробовать реализовать выбор клетки стрелками
	// https://www.cyberforum.ru/cpp-beginners/thread755195.html
	// в любом режиме возможность старта, паузы, просмотра статистики, остановки, перезапуска, создание новой - ЦИФРЫ С ШИФТОМ
	// Очередь ходов - пока не нажата клавиша меню, пока один не выиграл. Если попал, то ход не переходит?
	// при этом выводится окно состояния игры или результаты
	// выход
	// ВСЕ НА АНГЛИЙСКОМ

	showIntro();
	showSelectGameType();
	selectGameType();

	// ПРИ ПЕРЕЗАПУСКЕ ПОЛЯ НЕ СТИРАТЬ
	
	currentGame.number = 1; // присвоили игре номер
	gamer* gamersList = new gamer[GAMERS_AMOUNT]; // создали игроков
	for (int i = 0; i < GAMERS_AMOUNT; i++) {
		gamersList[i] = createGamer(i, 1);
	}
	currentGame.gamersList = gamersList; // поместили игроков в игру
	for (int i = 0; i < GAMERS_AMOUNT; i++) {
		getField(gamersList[i]); // дали игрокам игровые поля, присвоили игрокам статус ГОТОВ
		gamersList[i].state = ready;
	}
	int a = 1;
	while (a == 1) {
		if (GetAsyncKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/) {
			std::cout << "1";
		}
	}

	showStatistic(currentGame);
	if (currentGame.state) {
		showMenu();
	}
	menuItems menuChoice = getMenuChoice();

	/*do {
		showIntro();
		// проверка существует ли игра, игроки, статусы. Какой пункт меню выбран
		gameState currentGameState = game.state;
		//createMenuItem(currentGameState);
		//createScreen(currentGameState); 

				if (игра не существует  ) {
			showMenu();
			menuItems menuChoice = getMenuChoice();
			continue;
		}
		else {
			menuItems menuChoice = getMenuChoice();
			continue;
		}
		// проверка существует ли игра, игроки, их статусы. Какой пункт меню выбран
		// созданиепунктовменю(играстатус, игрокстатус)
		showMenu();
		menuItems menuChoice = getMenuChoice();
	} while (menuChoice != doExit);*/







	showField(gamersList[0].field);
	shotResultType shotResult;

	std::cout << std::endl;
	std::cout << std::endl;
	showField(gamersList[1].field);

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
			shotResult = doShot(gamersList[0].field, i, j);
			//} while (shotResult == shotRepeat);
			if (shotResult == shotHit) {
				//isShipKilled(gamersList[0].field, i, j);
				//showField(gamersList[0].field);
				//std::cout << std::endl;
				//std::cout << std::endl;
			}


			/*showField(field1);
			std::cout << std::endl;
			std::cout << std::endl;*/
		}
	}

	// Удаление массива полей игроков - В ФУНКЦИЮ
	for (int g = 0; g < GAMERS_AMOUNT; g++) {
		for (int i = 0; i < FIELD_SIZE_Y; i++) {
			delete[] gamersList[g].field[i];
		}
		delete[] gamersList[g].field;
	}
	
	delete[] gamersList;
}