#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdlib.h>
#include <math.h>
//#include <WinUser.h>
#include <Windows.h>


// - расстановка всегда рандомная. компьютер всегда умный
// - попробовать реализовать выбор клетки стрелками
// - еще умный обстрел из статей
// - вывод кораблей у стеночки - тут установка первой клетки на край и в соответствующем направлением расположение корабля
// - в файле всё сохранять и считывать
// - меню в файле хранить можно
// 
// 
// ! обстрел рядом с попаданием реализовать - горизонтально/вертикально. потом функцию с возможными положениями клеток
// ! сделать совсем рандомно расстановку кораблей а не сначала линкоры, потом крейсеры и т.д. - массив перемещать
// !! ПЕРЕПИСАТЬ ФУНКЦИИ, КОТОРЫЕ ПОЛУЧАЮТ КООРДИНАТЫ ЯЧЕЙКИ НА ПОЛУЧЕНИЕ ССЫЛКИ НА НЕЕ
// !! РАЗОБРАТЬСЯ С ПЕРЕДАЧЕЙ ССЫЛОК, УКАЗАТЕЛЕЙ - ГЛЕ КУДА ЛУЧШЕ? ИЛИ ВЕЗДЕ ОДНО СДЕЛАТЬ?
// !! ПРОТОТИПЫ ФУНКЦИЙ СДЕЛАТЬ. функции раскидать последовательно
// !! ПРЕЗЕНТАЦИЮ. БЛОК-СХЕМУ
// ВСЕ НА АНГЛИЙСКОМ
// https://www.cyberforum.ru/cpp-beginners/thread755195.html
// ИСПОЛЬЗОВАТЬ ВСЁ ЧТО ПРОШЛИ - С Т Р О О О О О О К И ! ! !
// с русским не стал заморачиваться из-за кодировок спецсимволов, а потом уж некогда стало)
// https://metanit.com/cpp/tutorial/4.7.php - циклы по массивам можно переделать - более удобно будет
// 


const int FIELD_SIZE_X = 10;
const int FIELD_SIZE_Y = 10;
const int SHIPS_AMOUNT = 10;
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
	gamerInit,
	gamerReady,
	gamerWait,
	gamerMove,
	gamerWin,
	gamerLose
};
enum gameState{
	gameEmpty,
	gamePrep,
	gameStart,
	gamePaused,
	gameEnd,
	gameStop
};

const int MENU_ITEMS_AMOUNT = 10;
const char MENU_ITEM_NAME[MENU_ITEMS_AMOUNT][50] = {
	"[C]reate game",
	"Se[L]ect type of game",
	"[S]tart game",
	"[P]ause",
	"[V]iew Statistic",
	"S[T]op game",
	"[R]estart game",
	"[E]xit",
	"[Y]es",
	"[N]o"
};
const char MENU_HOT_KEY[MENU_ITEMS_AMOUNT] = { 'C', 'L', 'S', 'P', 'V', 'T', 'R', 'E', 'Y', 'N' };


shipType* getShipList() {
	shipType* arrShipList = new shipType[SHIPS_AMOUNT] {shipLincor, shipCruiser, shipCruiser, shipDestroyer, shipDestroyer, shipDestroyer, shipBoat, shipBoat, shipBoat, shipBoat};
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

void createRandFleet(int** field) { // создание флота
	shipType* arrShipList = getShipList();
	
	for (int i = 0; i < SHIPS_AMOUNT; i++) { // 10 - sizeof использовать
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


// ДОПИЛИВАТЬ - КОМУ ЧТО И В КАКИХ СЛУЧАЯХ ВЫВОДИТЬ
void showField(int** field) { // вывод поля на экран
	char firstLetter = 'A';
	std::cout << "    ";
	for (int i = 0; i < FIELD_SIZE_X; i++) {
		std::cout << i + 1 << "   "; // здесь на БУУУУДУЩЕЕ - количество пробелов на один меньше чем количество цифр
	}
	
	std::cout << std::endl;
	std::cout << "  ";
	for (int i = 0; i < FIELD_SIZE_X; i++) {
		std::cout << "----";
	}
	std::cout << "-";
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
		std::cout << "  ";
		for (int i = 0; i < FIELD_SIZE_X; i++) {
			std::cout << "----";
		}
		std::cout << "-";
		std::cout << std::endl;
	}
}

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

struct gamer{
	int number;
	//char name[10];
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
	gamer* gamersList;
};

gamer createGamer(int number, bool type) {
	gamer newGamer;

	newGamer.number = number;
	//strcpy(newGamer.name, name);
	newGamer.type = type; //HUMAN=0/ PC=1
	newGamer.field = createEmptyField();
	newGamer.state = gamerInit;
	newGamer.moveAmount = 0;
	newGamer.liveShipsAmount = 10; // 10
	newGamer.killedShipsAmount = 0;
	newGamer.hitsAmount = 0;

	return newGamer;
}

game createEmptyGame() {
	game newGame;

	newGame.number;
	newGame.state = gameEmpty;
	newGame.type;
	newGame.gamersList;
	return newGame;
}

void getField(gamer gamer) {
	fillFieldSee(gamer.field);
	createRandFleet(gamer.field);
}

void showIntro() {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "   *** BattleShip v1.1 (by SyresinVA) ***" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}


//
void showSelectGameType() {
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Select type of game \n(1 - HUMAN-PC, 2 - PC-PC): " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

//
void selectGameType() {
	
}



//
void showStatistic(game game) {

}





//
enum menuAction {
	doCreate,
	doSelect,
	doStart,
	doPause,
	doStatistic,
	doStop,
	doRestart,
	doExit,
	doYes,
	doNo
};

struct menuItem {
	menuAction action;
	char name[50];
	char key;
};


menuItem* getMenuList() {
	menuItem* menuList = new menuItem[MENU_ITEMS_AMOUNT];
	for (int i = 0; i < MENU_ITEMS_AMOUNT; i++) {
		menuList[i].action = menuAction(i);
		strcpy(menuList[i].name, MENU_ITEM_NAME[i]);
		menuList[i].key = MENU_HOT_KEY[i];
	}
	return menuList;
}

menuItem* getCurrentMenu(menuItem* menuList, menuAction* actionList, int nAction) {
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

void showCurrentMenu(menuItem* currentMenu, int nAction) {
	for (int i = 0; i < nAction; i++) {
		std::cout << currentMenu[i].key << " - " << currentMenu[i].name;
		std::cout << std::endl;
	}
}


int main() {
	
	menuItem* menuList = getMenuList();

	menuAction actionList[] = { doCreate, doCreate, doCreate };
	int nCurrentMenuItem = sizeof(actionList) / sizeof(actionList[0]);
	menuItem* currentMenu = getCurrentMenu(menuList, actionList, nCurrentMenuItem);
	showCurrentMenu(currentMenu, nCurrentMenuItem);


	// delet menuList currentMenu - в соответствующих местах

	srand(time(NULL));


	game currentGame = createEmptyGame(); // создали пустую игру
	


	// выбор типа игры - кто с кем. а если еще и чел-чел
	
	// в любом режиме возможность старта, паузы, просмотра статистики, остановки, перезапуска, создание новой - ЦИФРЫ С ШИФТОМ
	// Очередь ходов - пока не нажата клавиша меню, пока один не выиграл. Если попал, то ход не переходит?
	// при этом выводится окно состояния игры или результаты
	// выход
	// ПРИ ПЕРЕЗАПУСКЕ ПОЛЯ НЕ СТИРАТЬ

	showIntro();
	showSelectGameType();
	selectGameType();



	
	currentGame.number = 1; // присвоили игре номер
	gamer* gamersList = new gamer[GAMERS_AMOUNT]; // создали игроков
	for (int i = 0; i < GAMERS_AMOUNT; i++) {
		gamersList[i] = createGamer(i, 1); // здесь тип игрока выбирается в зависимости от режима
	}
	currentGame.gamersList = gamersList; // поместили игроков в игру
	for (int i = 0; i < GAMERS_AMOUNT; i++) {
		getField(gamersList[i]); // дали игрокам игровые поля, присвоили игрокам статус ГОТОВ
		gamersList[i].state = gamerReady;
	}


	/*do {
		showIntro();
		// проверка существует ли игра, игроки, статусы. Какой пункт меню выбран
		gameState currentGameState = game.state;
		//createMenuItem(currentGameState);
		//createScreen(currentGameState); 

				if (игра не существует  ) {
			showMenu();
			menuItem menuChoice = getMenuChoice();
			continue;
		}
		else {
			menuItem menuChoice = getMenuChoice();
			continue;
		}
		// проверка существует ли игра, игроки, их статусы. Какой пункт меню выбран
		// созданиепунктовменю(играстатус, игрокстатус)
		showMenu();
		menuItem menuChoice = getMenuChoice();
	} while (menuChoice != doExit);*/






	for (int i = 0; i < GAMERS_AMOUNT; i++) {
		showField(gamersList[i].field);
		std::cout << std::endl;
		std::cout << std::endl;
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