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
	_SEE,
	_SHIP,
	_HIT,
	_MISS
};


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// КОНСТАНТЫ ПРОРИСОВКИ
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const double GAME_VERSION = 1.0;
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
//////////////////////////////////////////////////////////



class Field  {
protected:
	int w;
	int h;
	bool visible;
	int** field;

public:
	Field(int uW = 10, int uH = 10, bool uVisible = true) : w{ uW }, h{ uH }, visible{ uVisible }, field{ new int* [uH] } { // через одномерный массив сделать
		

		for (int i = 0; i < h; i++) {
			field[i] = new int[w];
		}

		std::ifstream in("gamer1.txt");

		/*if (!in) {
			std::cout << "ERROR!!!";
		}
		else {
			std::cout << "NO ERROR!!!";
		}*/
		

		int cell;

		/*in >> cell;

		std::cout << cell << " -- ";*/

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				
				// считываем в массив из файла
				in >> cell;
				//field[j][i] = cell;
				field[j][i] = 0;
			}
		}



		/*
		std::ifstream inf("cw57.txt", std::ios::in);
		std::string word;

		while (!inf.eof()) {

		}
		*/



	};

	void fShow(bool fVisible) {
		std::cout << "    A B C D E F G H I J" << std::endl;
		std::cout << "    -------------------" << std::endl;
		for (int i = 0; i < h; i++) {
			std::cout << i + 1 << ((i > 8) ? " " : "  ") << "|"; //8
			for (int j = 0; j < w; j++) {
				std::cout << field[j][i] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "    ------------------------------" << std::endl;
	}


	/*
	if (cell == cellShip) {
				//std::cout << " " << ICON_SHIP << " |"; // для отладки
				std::cout << " " << ((isShowShip) ? ICON_SHIP : ICON_SEE) << " |";
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
	*/


	~Field() {};
};



class GamerState {
protected:
	GAMER_STATE state;
public:
	GamerState(GAMER_STATE uState = _WAIT) :state{ uState } {};
};



class Gamer:  public Field, public GamerState{
protected:
	GAMER_TYPE type;
	bool fVisible;
	int nShot;
	int nHit;
	Field* field;
public:
	Gamer(GAMER_TYPE uType = _HUMAN, bool visible = true) :type{ uType }, fVisible{ visible }, nShot{ 0 }, nHit{ 0 }, field{ new Field } {}; // ??????

	void gamerShow(int id) {
			std::cout << "    ------------------------------" << std::endl;
			std::cout << "    GAMER " << id + 1 << " - " << ((type == _HUMAN) ? "Human" : "PC") << " - " << GAMER_STATE_NAME[state] << std::endl;
			std::cout << "    ------------------------------" << std::endl;

			fShow(fVisible);

			std::cout << "    Shots count: " << nShot << " / Hits count: " << nHit << std::endl;;
			std::cout << "    ------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
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
	GAME_STATE state;
	int nGamer;
	Gamer* gamers;
public:
	Game(int uNGamer = 2/*, GAME_STATE uState = G_WAIT*/) : /*state{ uState },*/ nGamer{ uNGamer }, gamers{ new Gamer[uNGamer]{ {_HUMAN,true}, {_PC, false} } } {
		std::cout << "Game\n";

	};

	void begin() {

		std::list<Gamer> GamerQueue;
		for (int i = 0; i < nGamer; i++) {
			GamerQueue.push_back(gamers[i]);
		}
		std::list<Gamer>::iterator itCurrentGamer = GamerQueue.begin();

		do {
			// тут очередь будет переходить???
			iShow();
			gStateShow(state, nGamer);
			for (int i = 0; i < nGamer; i++) gamers[i].gamerShow(i);
			if (state != G_EXIT) system("cls");
		} while (state != G_EXIT);
		eShow();
	}


	~Game() {};
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