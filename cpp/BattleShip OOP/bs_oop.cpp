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


const bool IS_SEE_CONST = true;

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
	int shipCells;

public:
	Field(int uField_No = 1, bool uVisible = true) :
		w{ F_SIZE_W }, h{ F_SIZE_H }, field_No{ uField_No }, field{ new CELL_TYPE * [F_SIZE_H] }, shipCells{ 0 } { // через одномерный массив сделать и вообще вектором например

		if(IS_SEE_CONST) std::cout << "Field\n";

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

	Field(const Field& obj) {
		this->w = obj.w;
		this->h = obj.h;
		this->field_No = obj.field_No;
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				
				this->field[i][j] = obj.field[i][j];
			}
		}
	}
	

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

	~Field() {
		if (IS_SEE_CONST) std::cout << "DE_Field\n";
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
		//std::cout << "GamerState\n";
	};

	~GamerState() {
		if (IS_SEE_CONST) std::cout << "DE_GamerState\n";
	}
};



class Move: public GamerState {;
protected:
	SHOT_RESULT shotResult;
public:
	Move() :shotResult{ SHOT_NOT }, GamerState{} {
		//std::cout << "Move\n";
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

	~Move() {
		if (IS_SEE_CONST) std::cout << "DE_Move\n";
	}
};




class Gamer : public virtual Field, public Move {
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
		if (IS_SEE_CONST)  std::cout << "Gamer" << this << "\n";
	};

	Gamer(const Gamer& obj){
		this->type = obj.type;
		this->gamerName = obj.gamerName;
		this->field_No = obj.field_No;
		this->fVisible = obj.fVisible;
		this->nShot = obj.nShot;
		this->nHit = obj.nHit;
		Field(field);
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


	~Gamer() {
		if (IS_SEE_CONST) std::cout << "DE_Gamer\n";
	};
};



class GameState {
protected:
	GAME_STATE state;

public:
	GameState() : state{ G_START } {
		if (IS_SEE_CONST) std::cout << "GameState\n";
	};

	~GameState() {
		if (IS_SEE_CONST) std::cout << "DE_GameState\n";
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
	Game() : nGamer{ 2 }, gamers{ new Gamer[2]{ {_HUMAN, "Bill", 1, true}, {_PC, "IBM", 2, false}/*, {_PC, "IBM2", 2, true}*/ }}, GameState{} {
		if (IS_SEE_CONST) std::cout << "Game\n";

		// добавили в "ОЧЕРЕДЬ" игроков. ОНИ СКОПИРОВАЛИСЬ. А ОРИГИНАЛЫ ПУСТЬ ОСТАНУТСЯ ДЛЯ ПЕРЕЗАПУСКА ИГРЫ В ДАЛЬНЕЙШЕМ
		for (int i = 0; i < nGamer; i++) {
			GamerQueue.push_back(gamers[i]);
		}
	};


	void begin() {

				

		do {
			// Задали текущего игрока и игрока противника
			itCurrentGamer = GamerQueue.begin();
			itEnemyGamer = itCurrentGamer;
			itEnemyGamer++; // ???

			iShow();
			std::cout << "  GAME STATE: " << GAME_STATE_NAME[state] << "  GAMERS AMOUNT: " << nGamer << std::endl;
			std::cout << "---------------------------------------" << std::endl << std::endl << std::endl;
			for (auto gamer = GamerQueue.begin(); gamer != GamerQueue.end(); ++gamer) gamer->gamerShow();


			SHOT_RESULT shotResult;
			if (state != G_END) {
				itCurrentGamer->MovePrompt();
				CELL_TYPE& cell = itCurrentGamer->doShot(itEnemyGamer);
				shotResult = itCurrentGamer->getShotResult(cell);
				itCurrentGamer->writeMove(cell, shotResult);
			}
			

			if (shotResult != SHOT_HIT) {
				GamerQueue.push_back(*itCurrentGamer);
				GamerQueue.pop_front();
			}
			
			//if (state != G_EXIT) system("cls");
		} while (state != G_EXIT);
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