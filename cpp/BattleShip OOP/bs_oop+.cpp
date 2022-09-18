#define INCORRECT_KEY NULL;

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <vector>


// ������������
// copy(l.begin(), l.end(), std::ostream_iterator<int>(std::cout, " "));
// int getSum(int count, int first,...)
// ��������� ���������� ������ ��� ������ �� �����
// ���� ����� �� �����, �� ���� �� ������������
// ����� ���� ���������� � ������ ����� ����

// const � ������������ ������� �������� � ������ "����������"

// ����������
// ���������� ����� ��� ������������
// ����������� ������������?


const bool IS_SEE_CONST = false; // ��� ������� - ���������� ������������, �����������

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ��������� ����
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const int F_SIZE_H = 10;
const int F_SIZE_W = 10;
const std::string FIELD_PATH = "BattleShip OOP";
const std::string FIELD_NAME[2] = {
	"field1t.f",
	"field2t.f"
};


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ������������ ����
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
enum GAMER_TYPE{
	_HUMAN,
	_PC
};
enum GAME_STATE {
	G_START,
	G_END,
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
// ��������� ����������
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const double GAME_VERSION = 1.2;
const char ICON_SEE = ' ';
const char ICON_SHIP = 219;
const char ICON_SHOT_MISS = '*';
const char ICON_SHOT_HIT = 177;



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// ��������� ��������
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const std::string GAME_STATE_NAME[4] = {
	"Start",
	"End",
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
		w{ F_SIZE_W }, h{ F_SIZE_H }, field_No{ uField_No }, field{ new CELL_TYPE * [F_SIZE_H] }, nShipCells{ 0 } { // ����� ���������� ������ ������� � ������ �������� ��������

		if(IS_SEE_CONST) std::cout << "Field" << this << "\n";

		for (int i = 0; i < h; i++) {
			field[i] = new CELL_TYPE[w];
		}

		// ��������� ������ ���� �� �����
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




class Move {;
protected:
	SHOT_RESULT shotResult;
public:
	Move() :shotResult{ SHOT_NOT } {
		if (IS_SEE_CONST) std::cout << "Move\n";
	}; 


	SHOT_RESULT getShotResult(CELL_TYPE& cell) {

		switch (cell) {
		case C_SHIP:
			return SHOT_HIT;
			shotResult = SHOT_HIT; // ����� �� ���� ���������� ������, � �� �����������
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



//!!!!!!!!!!!!!!!!!!!!!!!!� ���� ���� �� �����������, � ������������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!� ���� ���� �� �����������, � ������������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!� ���� ���� �� �����������, � ������������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!��� ��� ���� ������ � ������������ ���� �������������� � �.�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!��� ��� ���� ������ � ������������ ���� �������������� � �.�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!��� ��� ���� ������ � ������������ ���� �������������� � �.�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!�������� ��� �� ������ �������, � �� �� ��� ������ �� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!�������� ��� �� ������ �������, � �� �� ��� ������ �� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!�������� ��� �� ������ �������, � �� �� ��� ������ �� ������!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Gamer : /*public virtual Field,*/ public Move {
protected:
	GAMER_TYPE type;
	GAMER_STATE state;
	std::string gamerName;
	int field_No;
	bool fVisible;
	int nShot;
	int nHit;
	Field* field;
	
public:
	Gamer(GAMER_TYPE uType = _HUMAN, std::string uGamerName = "John", int uField_No = 1, bool visible = true) :
		state{_WAIT},
		type{ uType }, gamerName{ uGamerName }, fVisible{ visible }, nShot{ 0 }, nHit{ 0 }, field_No{ uField_No },
		field{ new Field{uField_No, visible} }, Move{}{
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

			field->fShow(fVisible);

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
		if (nHit == field->getN_ShipCells()) {
			//state = _WIN;
			return true;
		}
		return false;
	}



	/*~Gamer() {
		if (IS_SEE_CONST)  std::cout << "DE_Gamer" << this << "\n";
	};*/
};



class Game : /*public GameState, */public Intro, public Exit {
protected:
	GAME_STATE state;
	int nGamer;
	Gamer* gamers;
	std::list<Gamer> GamerQueue;
	std::list<Gamer>::iterator itCurrentGamer; // �������� �������� ������, �.�. ��� ��� �����
	std::list<Gamer>::iterator itEnemyGamer; // �������� ����������, �.�. ��� ���� ����� ������� �����
public:
	Game() :state{ G_START }, nGamer{ 2 }, gamers{ new Gamer[2]{ {_HUMAN, "Bill", 1, true}, {_HUMAN, "IBM", 2, true}}} {
		if (IS_SEE_CONST) std::cout << "Game\n";
	};


	void begin() {
		// �������� � "�������" �������. ������ �������������.
		// � ��� ����������� ����, ����������� � ������� ����������� ������, � ��� � �� ����������
		// ������� �������� ���������������� ��� ������������ ����������� � �����������
		// � ��-�� ����� ��������� �������� ����� ����� 10
		for (int i = 0; i < nGamer; i++) {
			GamerQueue.push_back(gamers[i]);
		}
		itCurrentGamer = GamerQueue.begin();

		do {
			// ������ �������� ������ � ������ ����������
			
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


				// ��� ��� ���� - ������� �� ������. ����� �� ����. ������� ����
				


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




int main() {
	srand(time(NULL));

	Game game1;
	game1.begin();
	
}