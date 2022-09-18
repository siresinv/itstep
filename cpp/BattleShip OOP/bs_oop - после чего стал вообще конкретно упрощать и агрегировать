#define INCORRECT_KEY NULL;

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>


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


const bool IS_SEE_CONST = false; // Для отладки - показывать конструкторы, деструкторы

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ ИГРЫ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const int F_SIZE_H = 10;
const int F_SIZE_W = 10;
const std::string FIELD_PATH = "BattleShip OOP";
const std::string FIELD_NAME[2] = {
	"field1t.f",
	"field2t.f"
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
const double GAME_VERSION = 1.1;
const char ICON_SEE = ' ';
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
	int nShipCells;

public:
	Field(int uField_No = 1, bool uVisible = true) :
		w{ F_SIZE_W }, h{ F_SIZE_H }, field_No{ uField_No }, field{ new CELL_TYPE * [F_SIZE_H] }, nShipCells{ 0 } { // через одномерный массив сделать и вообще вектором например

		if(IS_SEE_CONST) std::cout << "Field" << this << "\n";

		for (int i = 0; i < h; i++) {
			field[i] = new CELL_TYPE[w];
		}

		// Заполнили массив поля из файла
		std::ifstream f(FIELD_PATH + "\/"+ FIELD_NAME[field_No - 1]);
		int cell;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				f >> cell;
				if (cell) nShipCells++;
				field[i][j] = (CELL_TYPE)cell;
			}
		}
	};

	int getN_ShipCells() {
		return nShipCells;
	}

	/*Field(const Field& obj) {
		if (IS_SEE_CONST) std::cout << "COPY_Field" << this << "\n";

		this->w = obj.w;
		this->h = obj.h;
		this->field_No = obj.field_No;
		this->shipCells = obj.shipCells;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				
				this->field[i][j] = obj.field[i][j];
			}
		}
	}*/
	

	void fShow(bool fVisible) {
		std::cout << "   1   2   3   4   5   6   7   8   9   10" << std::endl;
		std::cout << "  |---------------------------------------|" << std::endl;
		CELL_TYPE cell;
		for (int i = 0; i < h; i++) {
			std::cout << char(65+i) << " " << "|";
			for (int j = 0; j < w; j++) {
				cell = field[i][j];

				if (cell == C_SEE) {

				}

				switch (cell) {
				case C_SHIP:
					std::cout << " " << ((fVisible) ? ICON_SHIP : ICON_SEE) << " |";
					break;
				case C_HIT:
					std::cout << " " << ICON_SHOT_HIT << " |";
					break;
				case C_MISS:
					std::cout << " " << ICON_SHOT_MISS << " |";
					break;
				default:
					std::cout << " " << ICON_SEE << " |";
					break;
				}
			}
			std::cout << std::endl;
			std::cout << "  |---------------------------------------|" << std::endl;

		}
		std::cout << "    ------------------------------" << std::endl;
	}

	/*~Field() {
		if (IS_SEE_CONST) std::cout << "DE_Field" << this << "\n";
		for (int i = 0; i < F_SIZE_H; i++) {
			delete[] field[i];
			field[i] = nullptr;
		}
		delete[] field;
		field = nullptr;
	};*/
};



class GamerState {
protected:
	GAMER_STATE state;
public:
	GamerState() :state{ _WAIT } {
		if (IS_SEE_CONST) std::cout << "GamerState\n";
	};

	/*~GamerState() {
		if (IS_SEE_CONST) std::cout << "DE_GamerState\n";
	}*/
};



class Move/*: public GamerState*/ {;
protected:
	SHOT_RESULT shotResult;
public:
	Move() :shotResult{ SHOT_NOT }/*, GamerState{}*/ {
		if (IS_SEE_CONST) std::cout << "Move\n";
	}; //


	SHOT_RESULT getShotResult(CELL_TYPE& cell) {

		switch (cell) {
		case C_SHIP:
			return SHOT_HIT;
			shotResult = SHOT_HIT; // чтобы из поля результата брался, а не возвращался
			break;
		case C_HIT:
			return SHOT_REPEAT;
			break;
		case C_MISS:
			return SHOT_REPEAT;
			break;
		default:
			return SHOT_MISS;
			break;
		}
	}

	/*~Move() {
		if (IS_SEE_CONST) std::cout << "DE_Move\n";
	}*/
};



//!!!!!!!!!!!!!!!!!!!!!!!!А ЕСЛИ ПОЛЕ НЕ НАСЛЕДОВАТЬ, А АГРЕГИРОВАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!А ЕСЛИ ПОЛЕ НЕ НАСЛЕДОВАТЬ, А АГРЕГИРОВАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!А ЕСЛИ ПОЛЕ НЕ НАСЛЕДОВАТЬ, А АГРЕГИРОВАТЬ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!ИЛИ ВСЕ ТАКИ ДОБИТЬ С КОПИРОВАНИЕМ ПОЛЯ НАСЛЕДОВАНИЯМИ И Т.Д!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!ИЛИ ВСЕ ТАКИ ДОБИТЬ С КОПИРОВАНИЕМ ПОЛЯ НАСЛЕДОВАНИЯМИ И Т.Д!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!ИЛИ ВСЕ ТАКИ ДОБИТЬ С КОПИРОВАНИЕМ ПОЛЯ НАСЛЕДОВАНИЯМИ И Т.Д!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!РАЗНЕСТИ ЧТО ЛИ МАЛЕНЬ ФУНКЦИИ, А ТО НА ООП ВООБЩЕ НЕ ПОХОЖЕ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!РАЗНЕСТИ ЧТО ЛИ МАЛЕНЬ ФУНКЦИИ, А ТО НА ООП ВООБЩЕ НЕ ПОХОЖЕ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!РАЗНЕСТИ ЧТО ЛИ МАЛЕНЬ ФУНКЦИИ, А ТО НА ООП ВООБЩЕ НЕ ПОХОЖЕ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Gamer : public virtual Field, public Move {
protected:
	GAMER_TYPE type;
	GAMER_STATE state;
	std::string gamerName;
	int field_No;
	bool fVisible;
	int nShot;
	int nHit;
	
public:
	Gamer(GAMER_TYPE uType = _HUMAN, std::string uGamerName = "John", int uField_No = 1, bool visible = true) :
		state{_WAIT},
		type{ uType }, gamerName{ uGamerName }, fVisible{ visible }, nShot{ 0 }, nHit{ 0 }, field_No{ uField_No },
		Field(uField_No, visible), Move{}{
		//if (IS_SEE_CONST)  std::cout << "Gamer" << this << "\n";
	};

	/*Gamer(const Gamer& obj) {
		if (IS_SEE_CONST)  std::cout << "COPY_Gamer" << this << "\n";
		this->type = obj.type;
		this->gamerName = obj.gamerName;
		this->field_No = obj.field_No;
		this->fVisible = obj.fVisible;
		this->nShot = obj.nShot;
		this->nHit = obj.nHit;
		Field(field);
	}*/


	GAMER_STATE getState() {
		return state;
	}

	void setState(GAMER_STATE state) {
		this->state = state;
	}

	void gamerShow() {
			std::cout << "    ------------------------------" << std::endl;
			std::cout << "    " << char(2) << " GAMER " << gamerName << " - " << ((type == _HUMAN) ? "Human" : "PC") << " - " << GAMER_STATE_NAME[state] << std::endl;
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
		std::cout << "    " << char(16) << " GAMER " << gamerName << " - " << GAMER_STATE_NAME[state] << std::endl;
		std::cout << "    ------------------------------" << std::endl;
	}

	CELL_TYPE& doShot(std::list<Gamer>::iterator itEnemyGamer) {
		int xCell;
		char yCell;


		if (type == _HUMAN) {
			do {
				std::cout << "    LETTER (A-J): ";
				std::cin >> yCell;

				std::cout << "    DIGIT (1-10): ";
				std::cin >> xCell;

			} while (xCell < 1 || xCell > F_SIZE_W || !((yCell >= 'A' && yCell <= 'J') || (yCell >= 'a' && yCell <= 'j'))); // yCell - ASCII A-J a-j
		}
		else {
			xCell = rand() % 10 + 1;
			yCell = rand() % 11 + 'A';
		}


		if (yCell >= 'A' && yCell <= 'J') {
			yCell -= 65;
		}
		else {
			yCell -= 97;
		}

		return itEnemyGamer->field[yCell][xCell-1];
	}


	void writeMove(CELL_TYPE& cell, SHOT_RESULT shotResult) {
		this->nShot += 1;
		state = _MOVE;
		switch (shotResult) {
		case SHOT_MISS:
			cell = C_MISS;
			break;
		case SHOT_HIT:
			nHit += 1;
			cell = C_HIT;
			break;
		default:
			break;
		}
		
	}

	bool gamerWin() {
		if (nHit == getN_ShipCells()) {
			//state = _WIN;
			return true;
		}
		return false;
	}



	/*~Gamer() {
		if (IS_SEE_CONST)  std::cout << "DE_Gamer" << this << "\n";
	};*/
};



class GameState {
protected:
	GAME_STATE state;

public:
	GameState() : state{ G_START } {
		if (IS_SEE_CONST) std::cout << "GameState" << this << "\n";
	};

	~GameState() {
		if (IS_SEE_CONST) std::cout << "DE_GameState" << this << "\n";
	}
};







class Game : public GameState, public Intro, public Exit {
protected:
	int nGamer;
	Gamer* gamers;
	std::list<Gamer> GamerQueue;
	std::list<Gamer>::iterator itCurrentGamer; // итератор текущего игрока, т.е. тот кто ходит
	std::list<Gamer>::iterator itEnemyGamer; // итератор противника, т.е. под кого ходит текущий игрок
public:
	Game() : nGamer{ 2 }, gamers{ new Gamer[2]{ {_HUMAN, "Bill", 1, true}, {_HUMAN, "IBM", 2, true}/*, {_PC, "IBM2", 2, true}*/ }}, GameState{} {
		if (IS_SEE_CONST) std::cout << "Game\n";

		
	};


	void begin() {
		// добавили в "ОЧЕРЕДЬ" игроков. ИГРОКИ СКОПИРОВАЛИСЬ.
		// А КАК СКОПИРОВАТЬ ПОЛЕ, НАХОДЯЩЕЕСЯ В ОБЪЕКТЕ РОДИТЕСКОГО КЛАССА, Я ТАК И НЕ РАЗОБРАЛСЯ
		// ПОЭТОМУ ПРИШЛОСЬ ЗАКОММЕНТИРОВАТЬ ВСЕ КОНСТРУКТОРЫ КОПИРОВАНИЯ И ДЕСТРУКТОРЫ
		// И ИЗ-ЗА ЭТОГО ПРОГРАММА КРАШИТСЯ ХОДОВ ЧЕРЕЗ 10
		for (int i = 0; i < nGamer; i++) {
			GamerQueue.push_back(gamers[i]);
		}
		itCurrentGamer = GamerQueue.begin();

		do {
			// Задали текущего игрока и игрока противника
			
			itEnemyGamer = itCurrentGamer;
			itEnemyGamer++; // ???
			itCurrentGamer->setState(_MOVE);

			iShow();
			std::cout << "  GAME STATE: " << GAME_STATE_NAME[state] << "  GAMERS AMOUNT: " << nGamer << std::endl;
			std::cout << "---------------------------------------" << std::endl << std::endl << std::endl;
			for (auto gamer = GamerQueue.begin(); gamer != GamerQueue.end(); ++gamer) gamer->gamerShow();


			SHOT_RESULT shotResult;

			if (itCurrentGamer->getState() == _MOVE) {
				itCurrentGamer->MovePrompt();
				CELL_TYPE& cell = itCurrentGamer->doShot(itEnemyGamer);
				shotResult = itCurrentGamer->getShotResult(cell);

				if (shotResult != SHOT_REPEAT) {
					itCurrentGamer->writeMove(cell, shotResult);
				}

				bool isEnd = true;

				if (shotResult == SHOT_HIT) {
					std::cout << "-1-";
					if (itCurrentGamer->gamerWin()) {
						std::cout << "-2-";

						itCurrentGamer->setState(_WAIT);
						std::cout << "(" << itCurrentGamer->getState() << ")";

						for (auto gamer = GamerQueue.begin(); gamer != GamerQueue.end(); ++gamer) {
							if (gamer->getState() != _WIN) {
								std::cout << "-3-";

								isEnd = false;
							}
						}
						if (isEnd) state = G_END;
					}
				}
				


				if (shotResult != SHOT_HIT && shotResult != SHOT_REPEAT) {
					itCurrentGamer->setState(_WAIT);
					std::cout << "-4-";

					do {
						GamerQueue.push_back(*itCurrentGamer);
						GamerQueue.pop_front();
						itCurrentGamer = GamerQueue.begin();
					} while (itCurrentGamer->getState() != _WAIT);
					
					itCurrentGamer->setState(_MOVE);
				}
			}
			
			//if (state != G_END) system("cls");
		} while (state != G_END);
		eShow();
	}


	~Game() {
		if (IS_SEE_CONST) std::cout << "DE_Game\n";
		delete[] gamers;
		gamers = nullptr;
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
	srand(time(NULL));

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