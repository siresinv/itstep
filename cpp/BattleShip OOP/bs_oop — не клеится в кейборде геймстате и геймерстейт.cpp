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

enum GAMER_TYPE
{
	_HUMAN,
	_PC
};

enum GAMER_STATE
{
	_WAIT,
	_MOVE,
	_WIN
};


enum GAME_STATE
{
	G_WAIT,
	G_START,
	G_END,
	G_EXIT
};


class Field  { // или фстреам через интерфейм типа
protected:
	int w;
	int h;
	bool visible;
	bool printable;
	int** field;

public:
	Field(int uW = 10, int uH = 10, bool uVisible = true) : w{ uW }, h{ uH }, visible{ uVisible }, printable{ false }, field{ new int* [uH] } { // через одномерный массив сделать
		

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


	};

	void fShow() {
		if (printable) {
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
	}

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
	bool visible; // куда его?
	int nShot; // куда его?
	int nHit; // куда его?
	Field* field;
public:
	Gamer(GAMER_TYPE uType = _HUMAN, bool uVisible = true) :type{ uType }, visible{ uVisible }, nShot{ 0 }, nHit{ 0 }, field{ new Field } {}; // ??????

	void gamerShow(int id) {
		if (visible) {
			std::cout << "    ------------------------------" << std::endl;
			std::cout << "    GAMER " << id + 1 << " - " << ((type == _HUMAN) ? "Human" : "PC") << " - " << state << std::endl;
			std::cout << "    ------------------------------" << std::endl;

			fShow();

			std::cout << "    Shots count: " << nShot << " / Hits count: " << nHit << std::endl;;
			std::cout << "    ------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}

	~Gamer() {};
};







class Move {
public:

};


class Menu {
	bool visible;
public:
	Menu() : visible{ true } {};
	void mShow(GAME_STATE state) {
		if (visible) {
			//if (state == 0) {
				std::cout << "    ------------------------------" << std::endl;
				std::cout << "    MENU" << std::endl;
				std::cout << "    ------------------------------" << std::endl;

				const char* menuItem[5]{
					"[S]tart",
					"E[X]it",
					"[R]estart",
					"[M]ove",
					"[V]iew Enemy Field"
				};
				for (int i = 0; i < 5; i++) {

					if (state == G_START) {
						if (i != 0) {
							std::cout << "    " << menuItem[i] << std::endl;
						}
					}
					else {
						if (i != 2 && i != 3 && i != 4) {
							std::cout << "    " << menuItem[i] << std::endl;
						}
					}
				}
			//}
		}
		
	}
};


class Intro {
public:
	void iShow() {
		std::cout << "---------------------------------------" << std::endl;
		std::cout << "BattleShip by Siresin (1.0) // with OOP" << std::endl;
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


class GameState: public Intro, public Exit {
protected:
	GAME_STATE state;
public:
	GameState(GAME_STATE uState = G_WAIT) : state{ uState } {};

	void setState(GAME_STATE state) {
		this->state = state;
	}

	GAME_STATE getState() {
		return state;
	}
};





class Keyboard: public GameState/*, public GamerState*/ {
public:
	char readKey(int state) {
		char key;
		std::cout << "    [Your choice]: ";
		std::cin >> key;
		return key;
	}

	void checkKey(char key) {
		switch (key) {
		case 's':
			setState(G_START);
			break;

		case 'x':
			setState(G_EXIT);
			break;
		default:
			break;
		}
	}

};











class Game:  public Menu, public Keyboard{
protected:
	int nGamer;
	Gamer* gamers;
public:
	//////////////////////////////////////////////////////////////////////////////
	Game(int uNGamer = 2) : /*GameAction{ uState },*/ nGamer{ uNGamer }, gamers {new Gamer[uNGamer]} {};

	void gStateShow() {
		std::cout << "    GAME STATE: " << state << "  GAMERS AMOUNT: " << nGamer << std::endl;
		std::cout << "---------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}



	void begin() {
		do {
			// тут очередь будет переходить???
			iShow(); gStateShow(); for (int i = 0; i < nGamer; i++) gamers[i].gamerShow(i);
			mShow(state);
			char key = readKey(state);
			checkKey(key);
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