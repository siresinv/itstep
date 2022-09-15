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

public:
	Field(int uField_No = 1, bool uVisible = true) :
		w{ F_SIZE_W }, h{ F_SIZE_H },  field_No{ uField_No }, field{ new CELL_TYPE * [F_SIZE_H] } { // через одномерный массив сделать и вообще вектором например

		for (int i = 0; i < h; i++) {
			field[i] = new CELL_TYPE[w];
		}

		// Заполнили массив поля из файла
		std::ifstream f(FIELD_PATH + "\/"+ FIELD_NAME[field_No - 1]);
		int cell;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				f >> cell;
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
					//std::cout << ICON_SHIP  << " ";
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
	GamerState(GAMER_STATE uState = _WAIT) :state{ uState } {};
};


class GamerAction {
public:


};


class Gamer:  public Field, public GamerState, public GamerAction{
protected:
	GAMER_TYPE type;
	std::string gamerName;
	int field_No;
	bool fVisible;
	int nShot;
	int nHit;
	
public:
	Gamer(GAMER_TYPE uType = _HUMAN, std::string uGamerName = "John", int uField_No = 1, bool visible = true) :
		type{ uType }, gamerName{ uGamerName },  fVisible{ visible }, nShot{ 0 }, nHit{ 0 }, field_No{ uField_No },
		Field(uField_No, visible) {};

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
		std::cout << "    GAMER " << gamerName << " MOVE " << std::endl;
		std::cout << "    ------------------------------" << std::endl;
	}

	CELL_TYPE& readMove(std::list<Gamer>::iterator itEnemyGamer) {
		int xCell;
		int yCell;

		do {
			std::cout << "    LETTER (1-10): ";
			std::cin >> yCell;

			std::cout << "    DIGIT (1-10): ";
			std::cin >> xCell;

		} while (xCell < 1 || yCell < 1 || xCell > F_SIZE_W || yCell > F_SIZE_H);

		

		return itEnemyGamer->field[yCell-1][xCell-1];
	}

	
	SHOT_RESULT shotResult(CELL_TYPE& cell) {

		switch (cell) {
		case C_SHIP:
			std::cout << "hit\n";
			return SHOT_HIT;
			break;
		case C_HIT:
			std::cout << "repeat\n";
			return SHOT_REPEAT;
			break;
		case C_MISS:
			std::cout << "repeat\n";
			return SHOT_REPEAT;
			break;
		default:
			std::cout << "miss\n";
			return SHOT_MISS;
			break;
		}
	}



	~Gamer() {};
};



class Move {
public:

};










class GameState {
protected:
	GAME_STATE state;
public:

	//Game::getState();

	GameState(GAME_STATE uState = G_WAIT) : state{ uState } {
		std::cout << "GameState\n";
	};

	// консруктор нужен ??? и откуда вообще инициализируется state
	//virtual void setState(GAME_STATE) = 0; // а зачем???
	//virtual GAME_STATE getState() = 0; // а зачем???
};





class GameAction : public GameState {
public:
	GameAction() :GameState{} {
		std::cout << "GameAction\n";
	};

	void setState(GAME_STATE state) {
		this->state = state;
	}

	GAME_STATE getState() {
		return state;
	}

	void gStateShow(GAME_STATE state, int nGamer) {
		std::cout << "    GAME STATE: " << GAME_STATE_NAME[state] << "  GAMERS AMOUNT: " << nGamer << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
};






class Game : public GameAction, public Intro, public Exit {
protected:
	//GAME_STATE state;
	int nGamer;
	Gamer* gamers;
	std::list<Gamer>::iterator itCurrentGamer; // какой игрок ходит
	std::list<Gamer>::iterator itEnemyGamer; // итератор противника
public:
	Game(int uNGamer = 2/*, GAME_STATE uState = G_WAIT*/) :
		/*state{ uState },*/ nGamer{ uNGamer }, gamers{ new Gamer[uNGamer]{ {_HUMAN, "Bill", 1, true}, {_PC, "IBM", 2, true}}} {
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
		itEnemyGamer++; //

		do {
			// тут очередь будет переходить??? - ИЛИ В МУВЕ, т.е. где-то там



			iShow();
			gStateShow(state, nGamer);
			for (int i = 0; i < nGamer; i++) gamers[i].gamerShow(i);


			/*if (itCurrentGamer == GamerQueue.end()) {
				itEnemyGamer = GamerQueue.begin();
			}
			else {
				itEnemyGamer++;
			}*/

			

			itCurrentGamer->MovePrompt();
			CELL_TYPE cell = itCurrentGamer->readMove(itEnemyGamer);
			SHOT_RESULT shotResult = itCurrentGamer->shotResult(cell);


			/////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////////
			
			// запись хода в поле
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
	std::cout << game1.getState();






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