#define INCORRECT_KEY NULL;

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>
#include <queue>


// использовать
// copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
// int getSum(int count, int first,...)
// посчитать количество едениц при чтении из файла
// если игрок не ходит, то меню не отображается
// также меню скрывается в момент ввода хода

// const у определенных функций добавить и другие "полезности"

// интерфейсы
// приведение типов при наследовании
// ромбовидное наследование?



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ ИГРЫ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const int F_SIZE_H = 10;
const int F_SIZE_W = 10;
const std::string FIELD_PATH = "BattleShip OOP";
const std::string FIELD_NAME[2] = {
	"field1.f",
	"field2.f"
};


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ПЕРЕЧИСЛИМЫЕ ТИПЫ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
enum GAMER_TYPE{
	_HUMAN,
	_PC
};
enum GAME_STATE {
	G_WAIT,
	G_START,
	G_END,
	G_EXIT
};
enum GAMER_STATE{
	_WAIT,
	_MOVE,
	_WIN
};
enum CELL_TYPE
{
	C_SEE,
	C_SHIP,
	C_HIT,
	C_MISS
};

enum SHOT_RESULT 
{
	SHOT_NOT,
	SHOT_REPEAT,
	SHOT_MISS,
	SHOT_HIT
};

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ ПРОРИСОВКИ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const double GAME_VERSION = 1.0;
const char ICON_SEE = '.';
const char ICON_SHIP = 219;
const char ICON_SHOT_MISS = '*';
const char ICON_SHOT_HIT = 177;



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ СТАТУСОВ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const std::string GAME_STATE_NAME[4] = {
	"Wait",
	"Start",
	"End",
	"Exit"
};
const std::string GAMER_STATE_NAME[3] = {
	"Wait",
	"Move",
	"Win"
};


class Intro {
public:
	void iShow() {
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "BattleShip by Siresin (" << GAME_VERSION << ") // with OOP" << std::endl;
		std::cout << "---------------------------------------" << std::endl;

	}
};

class Exit {
public:
	void eShow() {
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "    !!!    GAME IS OVER    !!!    " << std::endl;
		std::cout << "---------------------------------------" << std::endl;
	}
};


class Field  {
protected:
	int w;
	int h;
	int field_No;
	CELL_TYPE** field;
	int shipCells;

public:
	Field(int uField_No = 1, bool uVisible = true) :
		w{ F_SIZE_W }, h{ F_SIZE_H }, field_No{ uField_No }, field{ new CELL_TYPE * [F_SIZE_H] }, shipCells{ 0 } { // через одномерный массив сделать и вообще вектором например

		std::cout << "Field\n";

		for (int i = 0; i < h; i++) {
			field[i] = new CELL_TYPE[w];
		}

		// Заполнили массив поля из файла
		std::ifstream f(FIELD_PATH + "\/"+ FIELD_NAME[field_No - 1]);
		int cell;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				f >> cell;
				if (cell) shipCells++;
				field[i][j] = (CELL_TYPE)cell;
			}
		}
	};

	

	void fShow(bool fVisible) {
		std::cout << "   1 2 3 4 5 6 7 8 9 10" << std::endl;
		std::cout << "   -------------------" << std::endl;
		CELL_TYPE cell;
		for (int i = 0; i < h; i++) {
			std::cout << char(65+i) << " " << "|"; //8
			for (int j = 0; j < w; j++) {
				cell = field[i][j];

				if (cell == C_SEE) {

				}

				switch (cell) {
				case C_SHIP:
					std::cout << ((fVisible) ? ICON_SHIP : ICON_SEE) << " ";
					break;
				case C_HIT:
					std::cout << ICON_SHOT_HIT << " ";
					break;
				case C_MISS:
					std::cout << ICON_SHOT_MISS << " ";
					break;
				default:
					std::cout << ICON_SEE << " ";
					break;
				}
			}
			std::cout << std::endl;
		}
		std::cout << "    ------------------------------" << std::endl;
	}

	~Field() {
		std::cout << "DE_Field\n";

		/*for (int i = 0; i < F_SIZE_H; i++) {
			delete[] field[i];
			field[i] = nullptr;
		}
		delete[] field;
		field = nullptr;*/
	};
};



class GamerState {
protected:
	GAMER_STATE state;
public:
	GamerState() :state{ _WAIT } {
		std::cout << "GamerState\n";
	};

	~GamerState() {
		std::cout << "DE_GamerState\n";
	}
};



class Move: public GamerState {;
protected:
	SHOT_RESULT shotResult;
public:
	Move() :shotResult{ SHOT_NOT }, GamerState{} {
		std::cout << "Move\n";
	}; //


	SHOT_RESULT getShotResult(CELL_TYPE& cell) {

		switch (cell) {
		case C_SHIP:
			std::cout << "hit\n";
			shotResult = SHOT_HIT;
			//cell = C_HIT;
			return SHOT_HIT;
			break;
		case C_HIT:
			std::cout << "repeat\n";
			shotResult = SHOT_REPEAT;
			return SHOT_REPEAT;
			break;
		case C_MISS:
			std::cout << "repeat\n";
			shotResult = SHOT_REPEAT;
			return SHOT_REPEAT;
			break;
		default:
			std::cout << "miss\n";
			shotResult = SHOT_MISS;
			//cell = C_MISS;
			return SHOT_MISS;
			break;
		}
	}


	



	~Move() {
		std::cout << "DE_Move\n";
	}
};




class Gamer : public Field, public Move {
protected:
	GAMER_TYPE type;
	std::string gamerName;
	int field_No;
	bool fVisible;
	int nShot;
	int nHit;
	
public:
	Gamer(GAMER_TYPE uType = _HUMAN, std::string uGamerName = "John", int uField_No = 1, bool visible = true) :
		type{ uType }, gamerName{ uGamerName }, fVisible{ visible }, nShot{ 0 }, nHit{ 0 }, field_No{ uField_No },
		Field(uField_No, visible), Move{}{
		std::cout << "Gamer\n";
	};

	void gamerShow(int id) {
			std::cout << "    ------------------------------" << std::endl;
			std::cout << "    GAMER " << gamerName << " - " << ((type == _HUMAN) ? "Human" : "PC") << " - " << GAMER_STATE_NAME[state] << std::endl;
			std::cout << "    ------------------------------" << std::endl;

			fShow(fVisible);

			std::cout << "    Shots count: " << nShot << " / Hits count: " << nHit << std::endl;
			std::cout << "    ------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
	}

	void MovePrompt() {
		std::cout << "    ------------------------------" << std::endl;
		std::cout << "    GAMER " << gamerName << " - " << GAMER_STATE_NAME[state] << std::endl;
		std::cout << "    ------------------------------" << std::endl;
	}

	CELL_TYPE& doShot(std::list<Gamer>::iterator itEnemyGamer) {
		int xCell;
		char yCell;

		do {
			std::cout << "    LETTER (A-J): ";
			std::cin >> yCell;

			std::cout << "    DIGIT (1-10): ";
			std::cin >> xCell;

		} while (xCell < 1 || xCell > F_SIZE_W || !((yCell >= 'A' && yCell <= 'J') || (yCell >= 'a' && yCell <='j'))); // yCell - ASCII A-J a-j

		if (yCell >= 'A' && yCell <= 'J') {
			yCell -= 65;
		}
		else {
			yCell -= 97;
		}

		return itEnemyGamer->field[yCell][xCell-1];
	}


	/*
	C_SEE,
	C_SHIP,
	C_HIT,
	C_MISS
	*/

	void writeMoveToArr(CELL_TYPE& cell, SHOT_RESULT shotResult) {
		switch (shotResult) {
		case SHOT_MISS:
			cell = C_MISS;
			break;
		case SHOT_HIT:
			cell = C_HIT;
			break;
		default:
			break;
		}
		
	}

	~Gamer() {
		std::cout << "DE_Gamer\n";
	};
};



class GameState {
protected:
	GAME_STATE state;
	std::list<Gamer>::iterator itCurrentGamer; // итератор текущего игрока, т.е. тот кто ходит
	std::list<Gamer>::iterator itEnemyGamer; // итератор противника, т.е. под кого ходит текущий игрок
public:
	GameState() : state{ G_START } {
		std::cout << "GameState\n";
	};

	~GameState() {
		std::cout << "DE_GameState\n";
	}
};







class Game : public GameState, public Intro, public Exit {
protected:
	int nGamer;
	Gamer* gamers;
public:
	Game() : nGamer{ 2 }, gamers{ new Gamer[2]{ {_HUMAN, "Bill", 1, true}, {_PC, "IBM", 2, false}} }, GameState{} {
		std::cout << "Game\n";
	};

	void begin() {

		// добавили в "ОЧЕРЕДЬ" игроков. Задали текущего игрока и игрока противника
		std::list<Gamer> GamerQueue;
		for (int i = 0; i < nGamer; i++) {
			GamerQueue.push_back(gamers[i]);
		}
		itCurrentGamer = GamerQueue.begin();
		itEnemyGamer = itCurrentGamer;
		itEnemyGamer++;

		do {
			// тут очередь будет переходить??? - !!!ИЛИ В МУВЕ!!!, т.е. где-то там

			iShow();
			std::cout << "    GAME STATE: " << GAME_STATE_NAME[state] << "  GAMERS AMOUNT: " << nGamer << std::endl;
			std::cout << "---------------------------------------" << std::endl << std::endl << std::endl;
			for (int i = 0; i < nGamer; i++) gamers[i].gamerShow(i);


			/*if (itCurrentGamer == GamerQueue.end()) {
				itEnemyGamer = GamerQueue.begin();
			}
			else {
				itEnemyGamer++;
			}*/

			if (state) {

			}

			itCurrentGamer->MovePrompt();
			CELL_TYPE& cell = itCurrentGamer->doShot(itEnemyGamer); // itEnemyGamer можно в функции вычислять по итератору itCurrentGamer
			SHOT_RESULT shotResult = itCurrentGamer->getShotResult(cell);
			itEnemyGamer->writeMoveToArr(cell, shotResult);
			
			// запись хода в поле

			

			//changeStates(itCurrentGamer); // функтором пусть будет. да еще какие-то классы можно так сделать

			if (shotResult == SHOT_HIT) {
				// переход хода
				// проверка смена статусов
				// и т.д.
			}


			if (state != G_EXIT) system("cls");
		} while (state != G_EXIT);
		eShow();
	}


	~Game() {
		std::cout << "DE_Game\n";
		/*delete[] gamers;
		gamers = nullptr;*/
	};
};




// CLASSWORK 120922

/*
bool isEven(int num) {
	return !(num % 2);
}

int getSum(int count, int first, ...) {
	int sum = 0;
	int* p = &first;

	while (count--) {
		sum += *p;
		p++;
	}
	return sum;
}

int getSum2(int first, ...) {
	int sum = 0;
	int* p = &first;
	while (*p) {
		sum += *p;
		p++;
	}
	return sum;
}

*/

int main() {

	Game game1;
	game1.begin();
	//std::cout << game1.getState();






	// CLASSWORK 120922

	/*
	std::list<int> l;
	std::list<int>::iterator iter;

	for (int i = 0; i < 10; i++) {
		l.push_back(i);
	}
	for (iter = l.begin(); iter != l.end(); iter++) {
		std::cout << *iter << " ";
	}

	std::cout << std::endl;
	copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::list<int>::iterator iter2;
	iter2 = remove_if(l.begin(), l.end(), isEven);
	copy(l.begin(), iter2, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	l.erase(iter2, l.end());
	copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	std::vector<int> v{ 1,5,6,8,7 };
	std::random_shuffle(v.begin(), v.end());
	copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::sort(v.begin(), v.end());
	copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	*/


	/*std::cout << getSum(3, 1, 2, 3) << std::endl;
	std::cout << getSum2(1, 2, 3, 4, 0) << std::endl;*/
}