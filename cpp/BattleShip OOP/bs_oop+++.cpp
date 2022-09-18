#define INCORRECT_KEY NULL;

#include <iostream>


class Field {
	int** cells;
public:
	Field() : cells{new int* [10]} {
		for (int i = 0; i < 10; i++) {
			cells[i] = new int[10];
		}

		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cells[i][j] = 0;
			}
		}*/
	}

	~Field() {
		for (int i = 0; i < 10; i++) {
			delete[] cells[i];
		}
		delete[] cells;
	}
};

class Gamer {
	Field* field;
public:
	Gamer(): field { new Field{} }{};

	~Gamer() {
		delete field;
	}
};



class Game {
	Gamer* gamers;
public:
	Game() : gamers{ new Gamer[2]{{},{}} } {};
	
	~Game() {
		delete[] gamers;
	}
};




int main() {
	srand(time(NULL));

	Game game1;
	//game1.begin();
	
}