// *** BattleShip v1.2 (by SyresinVA) ***

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <conio.h>


// КОНСТАНТЫ ПОЛЯ
// КОНСТАНТЫ ПРОРИСОВКИ
// КОНСТАНТЫ МЕНЮ
// ПЕРЕЧИСЛИМЫЕ ТИПЫ
// СТРУКТУРЫ
// ФУНКЦИИ ПРОЦЕССА ИГРЫ - РАССТАНОВКА, СТРЕЛЬБА
// ФУНКЦИИ СОЗДАНИЯ ПОЛЯ
// ФУНКЦИИ ВЫВОДА НА ЭКРАН
// ФУНКЦИИ СОЗДАНИЯ ИГРЫ, ИГРОКА
// ФУНКЦИИ РАБОТЫ С МЕНЮ
// ФУНКЦИИ ВВОДА ХОДА
// main()




//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ ПОЛЯ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const int FIELD_SIZE_X = 10;
const int FIELD_SIZE_Y = 10;
const int SHIPS_AMOUNT = 10;
const int GAMERS_AMOUNT = 2;



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ ПРОРИСОВКИ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const char ICON_SEE = ' ';
const char ICON_SHIP = 219;
const char ICON_ABOUT_SHIP = ' ';
const char ICON_ABOUT_KILLED_SHIP = '.';
const char ICON_SHOT_MISS = '*';
const char ICON_SHOT_HIT = 'X';
const int SEPARATE_LINE_LEN = 45;
const int SEPARATE_LINE_LEN_FOR_DIGIT = 4;



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ МЕНЮ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const int MENU_ITEMS_AMOUNT = 14;

const char MENU_ITEM_NAME[MENU_ITEMS_AMOUNT][30] = {
	"[C]reate game",
	"Se[L]ect type of game",
	"[S]tart game",
	"[P]ause",
	"[V]iew Statistic",
	"[D]elete game",
	"[R]estart game",
	"E[X]it",
	"[M]enu",
	"Res[U]me game",
	"[1] Human - PC",
	"[2] PC - PC",
	"Do mo[V]e",
	""
};



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ПЕРЕЧИСЛИМЫЕ ТИПЫ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
enum fieldCellType // типы клеток поля
{
	cellSee,
	cellShip,
	cellShotMiss,
	cellShotHit,
	cellAboutShip,
	cellAboutKilledShip
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
	gamerInit,
	gamerReady,
	gamerWait,
	gamerMove,
	gamerWin,
	gamerLose
};

enum gameState{ // статусы игры
	gameNotIs,
	gameSelect,
	gameEmpty,
	gameReady,
	gameStart,
	gamePaused,
	gameEnd,
	gameStop
};

enum menuAction { // действия меню
	doCreate,
	doSelect,
	doStart,
	doPause,
	doStatistic,
	doDelete,
	doRestart,
	doExit,
	doMenu,
	doResume,
	doHUM_PC,
	doPC_PC,
	doMove,
	noAction
};

enum gameType{
	gtHumanPC,
	gtPCPC,
};

enum gamerType {
	human,
	pc
};



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// СТРУКТУРЫ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
struct gamer { // игрок
	int number;
	gamerType type;
	int** field;
	int** cleanField;
	gamerState state;
	int moveAmount;
	int liveShipsAmount;
	int killedShipsAmount;
	int hitsAmount;
};

struct game { // игра
	int number;
	gameState state;
	gameType type;
	gamer* gamersList;
};

struct menuItem { // меню
	menuAction action;
	char name[50];
};



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИИ ПРОЦЕССА ИГРЫ - РАССТАНОВКА, СТРЕЛЬБА
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
shipType* getShipList() { // получение списка кораблей
	shipType* arrShipList = new shipType[SHIPS_AMOUNT] {shipLincor, shipCruiser, shipCruiser, shipDestroyer, shipDestroyer, shipDestroyer, shipBoat, shipBoat, shipBoat, shipBoat};
	return arrShipList;
}

int getShipLastCell(int firstCell, int nDeck) { // получение последней(оконечной) клетки корабля (независимо от направления установки корабля)
	// возможно модифицировать - другие функции возможно будет оптимизировать
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

void setRectAboutShip(int** field, int firstLetter, int firstDigit, int nDeck, int direction, fieldCellType cellType) { // установка прямоугольника вокруг корабля

	int* arrCoordRectAboutShip = getCoordRectAboutShip(firstLetter, firstDigit, nDeck, direction);
	int rectX1 = arrCoordRectAboutShip[0];
	int rectY1 = arrCoordRectAboutShip[1];
	int rectX2 = arrCoordRectAboutShip[2];
	int rectY2 = arrCoordRectAboutShip[3];
	delete[]arrCoordRectAboutShip;

	for (int i = rectY1; i <= rectY2; i++) {
		for (int j = rectX1; j <= rectX2; j++) {
			int& cell = *(*(field + i) + j);
			if (cell != cellShip && cell != cellShotHit && cell != cellShotMiss) setCell(&cell, cellType);
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
	else if (shotCell == cellShotMiss || shotCell == cellShotHit || shotCell == cellAboutKilledShip) {
		return shotRepeat;
	}
	else {
		return shotHit;
	}
}

int* getShipFirstCell(int** field, int letter, int digit) { // получение первой клетки корабля после попадания в него
	// по-красивее переписать
	int i = letter;
	int j = digit;

	while (i > 0 && (*(*(field + i - 1) + digit) == cellShip || *(*(field + i - 1) + digit) == cellShotHit)) {
		i--;
	}

	while (j > 0 && (*(*(field + letter) + j - 1) == cellShip || *(*(field + letter) + j - 1) == cellShotHit)) {
		j--;
	}
	int* arrShipFirstCell = new int[2]{ i,j };
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

int getShipDeckAmount(int** field, int firstLetter, int firstDigit, bool direction) { //получение количества палуб корабля
	// по-красивее переписать
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

bool scanShipAfterHit(int** field, int firstLetter, int firstDigit, bool direction, int nDeck) { // возвращает - потоплен корабль или нет
	// по-красивее переписать
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
	delete[] arrShipFirstCell;

	// это лучше убрать отсюда  - кода будет больше, но будет логичнее
	if (shipKilled) {
		setRectAboutShip(field, firstLetter, firstDigit, nDeck, direction, cellAboutKilledShip);
	}

	return shipKilled;
}

shotResultType shotToEnemy(int** field, int letter, int digit) { // осуществление выстрела
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



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИИ СОЗДАНИЯ ПОЛЯ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int** createEmptyField() { // создание пустого поля
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

void createRandFleet(int** field) { // создание флота
	shipType* arrShipList = getShipList();

	for (int i = 0; i < SHIPS_AMOUNT; i++) {
		int nDeck = arrShipList[i];
		int direction = getRandDirection();
		int* arrRandPosition = getRandPosition(field, nDeck, direction);
		int randLetter = arrRandPosition[0];
		int randDigit = arrRandPosition[1];
		setShip(field, randLetter, randDigit, nDeck, direction);
		setRectAboutShip(field, randLetter, randDigit, nDeck, direction, cellAboutShip);
		delete[] arrRandPosition;
	}
	delete[] arrShipList;
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИИ ВЫВОДА НА ЭКРАН
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
void showSeparateLine(int nDash) { // вывод разделительной линии
	for (int i = 0; i < nDash; i++) {
		std::cout << "-";
	}
}

void showIntro() { // Вывод интро
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "   *** BattleShip v1.1 (by SyresinVA) ***" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void showMessage(char* message, int number = NULL) { // Показ сообщения
	showSeparateLine(SEPARATE_LINE_LEN);
	std::cout << std::endl;
	std::cout << message;
	if (number)	std::cout << number;
	std::cout << std::endl;
	std::cout << std::endl;

}

void showField(int** field, bool isShowShip) { // вывод поля на экран
	char firstLetter = 'A';
	std::cout << "    ";
	for (int i = 0; i < FIELD_SIZE_X; i++) {
		std::cout << i + 1 << "   ";
	}

	std::cout << std::endl;
	std::cout << "  ";
	showSeparateLine(FIELD_SIZE_X * SEPARATE_LINE_LEN_FOR_DIGIT);
	std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		std::cout << char(firstLetter + i) << " |";
		for (int j = 0; j < FIELD_SIZE_X; j++) {

			int cell = *(*(field + i) + j);

			if (cell == cellShip) {
				std::cout << " " << ICON_SHIP << " |"; // для отладки
				//std::cout << " " << ((isShowShip) ? ICON_SHIP : ICON_SEE) << " |";
			}
			else if (cell == cellAboutKilledShip) {
				std::cout << " " << ICON_ABOUT_KILLED_SHIP << " |";
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
		std::cout << "  ";
		showSeparateLine(FIELD_SIZE_X * SEPARATE_LINE_LEN_FOR_DIGIT);
		std::cout << "-";
		std::cout << std::endl;
	}
}

// ==========================================================================================================================
void showGameStatictic(game currentGame) { // Вывод статистики игры
	char msg[] = "Game statistic";
	showMessage(msg);
	std::cout << "N: " << currentGame.number << " ";
	std::cout << "Type: " << currentGame.type << " ";
	std::cout << "State: " << currentGame.state << " ";
	std::cout << std::endl;

	showSeparateLine(SEPARATE_LINE_LEN);
	std::cout << std::endl;
}
void showGamerStatistic(gamer currentGamer) {
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИИ СОЗДАНИЯ ИГРЫ, ИГРОКА
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
gamer createGamer(int number) { // Создание структуры игрока с начальными параметрами
	gamer newGamer;

	newGamer.number = number;
	newGamer.type;
	newGamer.field = createEmptyField();
	newGamer.cleanField = createEmptyField();
	newGamer.state = gamerInit;
	newGamer.moveAmount = 0;
	newGamer.liveShipsAmount = SHIPS_AMOUNT;
	newGamer.killedShipsAmount = 0;
	newGamer.hitsAmount = 0;

	return newGamer;
}

void copyField(int** field1, int** field2) { // Копирование игровых полей. Для функционала РЕСТАРТ
	for (int i = 0; i < FIELD_SIZE_Y; i++) {
		for (int j = 0; j < FIELD_SIZE_X; j++) {
			*(*(field1 + i) + j) = *(*(field2 + i) + j);
		}
	}
}

void getField(gamer gamer) { // Предоставление игрогого поля игроку
	fillFieldSee(gamer.field);
	createRandFleet(gamer.field);
	copyField(gamer.cleanField, gamer.field);
}

void putGamerToGame(game currentGame, gamer* gamersList) { // Помещение массива структур игроков в структуру игра
	currentGame.gamersList = gamersList;
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИИ РАБОТЫ С МЕНЮ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
menuItem* getMenuList() { // Создание массива структур с пунктами МЕНЮ
	menuItem* menuList = new menuItem[MENU_ITEMS_AMOUNT];
	for (int i = 0; i < MENU_ITEMS_AMOUNT; i++) {
		menuList[i].action = menuAction(i);
		strcpy(menuList[i].name, MENU_ITEM_NAME[i]);
	}
	return menuList;
}

menuItem* getCurrentMenu(menuItem* menuList, menuAction* actionList, int nAction) { // Возвращает массив структур с пунктами ТЕКУЩЕГО МЕНЮ
	menuItem* currentMenu = new menuItem[nAction];
	for (int i = 0; i < MENU_ITEMS_AMOUNT; i++) {
		for (int j = 0; j < nAction; j++) {
			if (menuList[i].action == actionList[j]) {
				currentMenu[j] = menuList[i];
				continue;
			}
		}
	}

	return currentMenu;
}

void showCurrentMenu(menuItem* currentMenu, int nAction) { // Вывод на экран ТЕКУЩЕГО МЕНЮ
	
	char msg[] = "Menu";
	showMessage(msg);

	for (int i = 0; i < nAction; i++) {
		std::cout << currentMenu[i].name;
		std::cout << std::endl;
	}
	showSeparateLine(SEPARATE_LINE_LEN);
	std::cout << std::endl;
}

menuAction getChoiceAction(int pressedKey) { // возвращает название действия при нажатии допустимой клавиши
	// чтобы русские таки понимал
	//взять букву в скобках и использовать strupr/strlwr, передав сюда ВСЁ меню
	menuAction action = noAction;
	
	switch (pressedKey) {
	case 'C':
	case 'c':
	case 'С':
	case 'с':
		action = doCreate;
		break;

	case 'L':
	case 'l':
	case 'Д':
	case 'д':
		action = doSelect;
		break;

	case 'S':
	case 's':
	case 'Ы':
	case 'ы':
		action = doStart;
		break;

	case 'P':
	case 'p':
	case 'З':
	case 'з':
		action = doPause;
		break;

	case 'U':
	case 'u':
	case 'Г':
	case 'г':
		action = doResume;
		break;

	case 'D':
	case 'd':
	case 'В':
	case 'в':
		action = doDelete;
		break;

	case 'R':
	case 'r':
	case 'К':
	case 'к':
		action = doRestart;
		break;

	case 'M':
	case 'm':
	case 'Ь':
	case 'ь':
		action = doMenu;
		break;

	case 'X':
	case 'x':
	case 'Ч':
	case 'ч':
		action = doExit;
		break;

	case 'V':
	case 'v':
	case 'М':
	case 'м':
		action = doMove;
		break;

	case '1':
		action = doHUM_PC;
		break;

	case '2':
		action = doPC_PC;
		break;

	default:
		break;
	}
	return action;
}

menuAction getAction(menuAction* actionList, menuAction choiceAction, int nAction) { // Возвращает действие корректного выбора в МЕНЮ
	for (int i = 0; i < nAction; i++) {
		if (actionList[i] == choiceAction) return choiceAction;
	}
	return noAction;
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИИ ВВОДА ХОДА
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
char getHumanMoveLetter() { // Возвращет корректную БУКВУ ХОДА
	char letter = 'A';
	char msg[] = "Enter your move";
	showMessage(msg);
	std::cout << "[A-J]: ";
	do {
		letter = _getch();
	} while (!(letter >= 'A' && letter <= 'J') && !(letter >= 'a' && letter <= 'j'));
	return letter;
}

char getHumanMoveDigit() { // Возвращает корректную цифру хода
	char digit = '1';
	std::cout << "[1-0]: ";
	do {
		digit = _getch();
	} while (!(digit >= '0' && digit <= '9'));
	return digit;
}

int convertMoveLetterKeyToDigit(char letter) { // Конвертирует БУКВУ ХОДА в ЦИФРУ("индекс" массива)
	return int(letter) - 64; // - ascii - коды
}

int convertMoveDigitKeyToDigit(char digit) { // Конвертирует ЦИФРУ ХОДА в ЦИФРУ("индекс" массива)
	if (digit == '0') return 10;
	return int(digit) - 48; // - ascii - коды
}

// ==========================================================================================================================
int* getPCMove() { // Возвращает массив (строка, столбец / буква,цифра) хода компьютера
// !! обстрел рядом с попаданием реализовать - горизонтально/вертикально. потом функцию с возможными положениями клеток
	int* arrMovePosition = new int[2]{rand() % 10, rand() % 10};
	return arrMovePosition;
}

int* getMovePosition(gamerType gamerType) { // Возвращает массив (строка, столбец / буква,цифра) с позицией хода
	int* arrMovePosition = new int[2];
	char moveLetterKey;
	char moveDigitKey;
	int moveLetter;
	int moveDigit;

	if (gamerType == human) {
		moveLetterKey = getHumanMoveLetter();
		moveLetterKey = toupper(moveLetterKey);
		std::cout << moveLetterKey << std::endl;
		moveDigitKey = getHumanMoveDigit();
		moveLetter = convertMoveLetterKeyToDigit(moveLetterKey) - 1;
		moveDigit = convertMoveDigitKeyToDigit(moveDigitKey);
		std::cout << moveDigit << std::endl;
		moveDigit--;
		arrMovePosition[0] = moveLetter;
		arrMovePosition[1] = moveDigit;
	}
	else {
		arrMovePosition = getPCMove();
	}
		return arrMovePosition;
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ФУНКЦИЯ main()
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
int main() {
	srand(time(NULL));

	// начальные данные игры
	game currentGame;
	int currentGame_No = 1;
	gameState currentGameState = gameEmpty;
	currentGame.state = currentGameState;
	gamer* gamersList = new gamer[GAMERS_AMOUNT]; // объявили массив структур игроков
	int currentGamer;
	int moveLetter;
	int moveDigit;
	bool isMove = false; // был ли сделан ход

	menuItem* menuList = getMenuList(); // создали массив структур ПУНКТОВ МЕНЮ
	menuAction* currentActionList = new menuAction[4]; // объявили массив возможных в данный момент действий хотя 4 - это максимально возможное количество пунктов меню
	
	do { // тут вся игра включая переходы по меню, пока не произойдет выход из игры
		int* arrMovePosition;
		showIntro();
		int nCurrentMenuItem; // количество пункутов в текущем меню

		switch (currentGameState) { // вывод соответствующих пунктов меню и другие действия в зависимости от статуса игры
		case gameEmpty:
			currentGame.number = currentGame_No;
			nCurrentMenuItem = 2;
			currentActionList[0] = { doSelect };
			currentActionList[1] = { doExit };
			break;

		case gameSelect:
			nCurrentMenuItem = 3;
			currentActionList[0] = { doHUM_PC };
			currentActionList[1] = { doPC_PC };
			currentActionList[2] = { doExit };
			break;

		case gameReady:
			currentGamer = 0;
			gamersList[currentGamer].state = gamerMove;
			showGameStatictic(currentGame);
			nCurrentMenuItem = 3;
			currentActionList[0] = { doStart };
			currentActionList[1] = { doDelete };
			currentActionList[2] = { doExit }; 
			break;

		case gameStart:
			if (gamersList[currentGamer].state == gamerMove) {
				nCurrentMenuItem = 2;
				currentActionList[0] = { doMove };
				currentActionList[1] = { doMenu };
			}
			else {
				nCurrentMenuItem = 1;
				currentActionList[0] = { doMenu };
			}
			
			if (isMove) {
				// ==========================================================================================================================
				// // ПРИ ИГРЕ КОМПЬЮТЕРОВ ЧТОЫБ ПО НАЖАТИЮ ЛЮБОЙ КЛАВИШИ ХОДИЛИ ИЛИ ЭНТРА
				// СТРЕЛЬБА. ПЕРЕХОД ХОДА
				// isGamerWin
				// Проверка статуса игроков - кому ходить и не закончилась ли игра
				shotResultType shotResult;
				//currentGamer = getCurrentGamer();
				//nextGamer = getNextGamer();
				
				gamersList[1].moveAmount++;
				shotResult = shotToEnemy(gamersList[1].field, moveLetter, moveDigit);
				if (shotResult == shotHit) {
					gamersList[1].hitsAmount++;
					if (isShipKilled(gamersList[1].field, moveLetter, moveDigit)) {
						gamersList[1].killedShipsAmount++;
					}
				}
				if (shotResult == shotHit || shotResult == shotRepeat) {
					// ход не переходит
				}

				isMove = false;
			}

			
			// ВЫВОД ПОЛЕЙ
			for (int i = 0; i < GAMERS_AMOUNT; i++) {
				bool isShowShip = true;
				if (currentGame.type == gtHumanPC && gamersList[i].type == pc) {
					isShowShip = false;
				}
				char msg[] = "Gamer N: ";
				showMessage(msg, i + 1);
				showField(gamersList[i].field, isShowShip);
				std::cout << std::endl;
				std::cout << std::endl;
			}
			break;

		case gamePaused:
			nCurrentMenuItem = 4;
			showGameStatictic(currentGame);
			currentActionList[0] = { doDelete };
			currentActionList[1] = { doRestart };
			currentActionList[2] = { doResume };
			currentActionList[3] = { doExit };
			break;

		case gameEnd:
			showGameStatictic(currentGame);
			nCurrentMenuItem = 2;
			currentActionList[0] = { doSelect };
			currentActionList[1] = { doExit };
			break;

		default:
			break;
		}


		// работа меню
		menuItem* currentMenu = getCurrentMenu(menuList, currentActionList, nCurrentMenuItem); // создание массива структур МЕНЮ отображаемого в данный момент
		showCurrentMenu(currentMenu, nCurrentMenuItem);
		menuAction correctAction = noAction;
		do {
			menuAction choiceAction = getChoiceAction(_getch()); // поймали клавишу
			correctAction = getAction(currentActionList, choiceAction, nCurrentMenuItem); // вернули только корректнный выбор из меню

			switch (correctAction) {
			case doSelect:
				currentGameState = gameSelect;
				for (int i = 0; i < GAMERS_AMOUNT; i++) { 
					gamersList[i] = createGamer(i); // создали игрока с пустым игровым полем
					getField(gamersList[i]); // дали игроку флот
					gamersList[i].state = gamerReady;
				}
				gamersList[1].type = pc; // второй игрок в любом случаем - PC
				putGamerToGame(currentGame, gamersList);// поместили игроков в игру
				break;

			case doStart:
				currentGameState = gameStart;
				break;

			case doDelete:
				currentGameState = gameEmpty;
				currentGame_No++;
				break;

			case doRestart:
				currentGameState = gameReady;
				for (int i = 0; i < GAMERS_AMOUNT; i++) {
					copyField(gamersList[i].field, gamersList[i].cleanField);
					gamersList[i].hitsAmount = 0;
					gamersList[i].killedShipsAmount = 0;
					gamersList[i].liveShipsAmount = SHIPS_AMOUNT;
					gamersList[i].moveAmount = 0;
					gamersList[i].state = gamerReady;
				}
				break;

			case doExit:
				exit(0);
				break;


			case doMove:
				arrMovePosition = getMovePosition(gamersList[currentGamer].type);
				moveLetter = arrMovePosition[0];
				moveDigit = arrMovePosition[1];
				std::cout << "Press any key...";
				_getch();
				isMove = true;
				delete[] arrMovePosition;
				break;

			case doMenu:
				currentGameState = gamePaused;
				break;

			case doResume:
				currentGameState = gameStart;
				break;

			case doHUM_PC:
				currentGame.type = gtHumanPC;
				currentGameState = gameReady;
				gamersList[0].type = human;
				break;

			case doPC_PC:
				currentGame.type = gtPCPC;
				currentGameState = gameReady;
				gamersList[0].type = pc;
				break;

			case noAction:
				break;
			default:
				break;
			}

		} while (correctAction == noAction);

		currentGame.state = currentGameState;
	
		delete[] currentMenu;

		system("cls");
	} while (true);

	delete[] currentActionList;
	delete[] menuList;

	// Удаление массива полей игроков - В ФУНКЦИЮ
	for (int g = 0; g < GAMERS_AMOUNT; g++) {
		for (int i = 0; i < FIELD_SIZE_Y; i++) {
			delete[] gamersList[g].field[i];
		}
		delete[] gamersList[g].field;
	}
	
	delete[] gamersList;
}