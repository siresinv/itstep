#include <iostream>
#include <conio.h>
#include <fstream>




const bool IS_SEE_CONST = false; // дКЪ НРКЮДЙХ - ОНЙЮГШБЮРЭ ЙНМЯРПСЙРНПШ, ДЕЯРПСЙРНПШ

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// йнмярюмрш хцпш
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const int F_SIZE_H = 10;
const int F_SIZE_W = 10;
const std::string FIELD_PATH = "BattleShip OOP";
const std::string FIELD_NAME[2] = {
	"field1.f",
	"field2.f"
};


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// оепевхякхлше рхош
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
// йнмярюмрш опнпхянбйх
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const double GAME_VERSION = 1.3;
const char ICON_SEE = ' ';
const char ICON_SHIP = 219;
const char ICON_SHOT_MISS = '*';
const char ICON_SHOT_HIT = 177;



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// йнмярюмрш ярюрсянб
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
const std::string GAME_TYPE_NAME[2] = {
	"Human",
	"PC",
};
const std::string GAME_STATE_NAME[2] = {
	"Start",
	"End",
};
const std::string GAMER_STATE_NAME[3] = {
	"Wait",
	"Move",
	"Win"
};




//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
// хмтнплюжхнммше йкюяяш. опхберярбхе. йнмеж хцпш
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
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



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	йкюяя онке хцпнйю
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
class Field  {
	int w;
	int h;
	int field_No;
	CELL_TYPE** cells;
	int nShipCells;

public:
	Field(int field_No) :
		w{ F_SIZE_W }, h{ F_SIZE_H }, field_No{ field_No }, cells{ new CELL_TYPE * [F_SIZE_H] }, nShipCells{ 0 } {

		for (int i = 0; i < h; i++) {
			cells[i] = new CELL_TYPE[w];
		}

		// гЮОНКМХКХ ЛЮЯЯХБ ОНКЪ ХГ ТЮИКЮ
		std::ifstream f(FIELD_PATH + "\/"+ FIELD_NAME[field_No - 1]);
		int cell;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				f >> cell;
				if (cell) nShipCells++;
				cells[i][j] = (CELL_TYPE)cell;
			}
		}
		if (IS_SEE_CONST) std::cout << "Field" << this << "\n";
	};

	~Field() {
		for (int i = 0; i < F_SIZE_H; i++) {
			delete[] cells[i];
			cells[i] = nullptr;
		}
		delete[] cells;
		cells = nullptr;
		if (IS_SEE_CONST) std::cout << "DE_Field" << this << "\n";
	};

	void show(bool fVisible) {
		std::cout << "   1   2   3   4   5   6   7   8   9   10" << std::endl;
		std::cout << "  |---------------------------------------|" << std::endl;
		CELL_TYPE cell;
		for (int i = 0; i < h; i++) {
			std::cout << char(65+i) << " " << "|";
			for (int j = 0; j < w; j++) {
				cell = cells[i][j];

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

	CELL_TYPE** getCells() {
		return cells;
	}

	int getN_ShipCells() {
		return nShipCells;
	}
};


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	йкюяя хцпнй
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
class Gamer {
	GAMER_STATE state;
	GAMER_TYPE type;
	std::string gamerName;
	int field_No;
	bool fVisible;
	int nShot;
	int nHit;
	Field* field;
	
public:
	Gamer(GAMER_TYPE type, std::string gamerName, int field_No, bool fVisible) :
		state{_WAIT}, type{ type }, gamerName{ gamerName }, fVisible{ fVisible }, nShot{ 0 }, nHit{ 0 }, field_No{ field_No },
		field{ new Field{field_No} }{

		if (IS_SEE_CONST)  std::cout << "Gamer" << this << "\n";
	};

	~Gamer() {
		delete field;
		field = nullptr;
		if (IS_SEE_CONST)  std::cout << "DE_Gamer" << this << "\n";
	};

	GAMER_STATE getState() {
		return state;
	}

	void setState(GAMER_STATE state) {
		this->state = state;
	}

	void show() {
		std::cout << "    ------------------------------" << std::endl;
		std::cout << "    " << char(2) << " GAMER " << gamerName << " - " << GAME_TYPE_NAME[type] << " - " << GAMER_STATE_NAME[state] << std::endl;
		std::cout << "    ------------------------------" << std::endl;

		field->show(fVisible);

		std::cout << "    Shots count: " << nShot << " / Hits count: " << nHit << std::endl;
		std::cout << "    ------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	void showMovePrompt() {
		std::cout << "    ------------------------------" << std::endl;
		std::cout << "    " << char(16) << " GAMER " << gamerName << " - " << GAMER_STATE_NAME[state] << std::endl;
		std::cout << "    ------------------------------" << std::endl;
	}
	
	CELL_TYPE& doShot(const Gamer* pEnemy) {
		int xCell;
		char yCell;


		if (type == _HUMAN) {
			do {
				std::cout << "    LETTER (A-J): ";
				std::cin >> yCell;

				std::cout << "    DIGIT (1-10): ";
				std::cin >> xCell;

			} while (xCell < 1 || xCell > F_SIZE_W || !((yCell >= 'A' && yCell <= 'J') || (yCell >= 'a' && yCell <= 'j')));
		}
		else {
			yCell = rand() % 10 + 'A';
			std::cout << "    LETTER (A-J): " << yCell << std::endl;
			xCell = rand() % 10 + 1;
			std::cout << "    DIGIT (1-10): " << xCell << std::endl;
			std::cout << "Press any key...";
			_getch();
		}


		if (yCell >= 'A' && yCell <= 'J') {
			yCell -= 65;
		}
		else {
			yCell -= 97;
		}

		return pEnemy->field->getCells()[yCell][xCell - 1];
	}

	SHOT_RESULT getShotResult(const CELL_TYPE& cell) {

		switch (cell) {
		case C_SHIP:
			return SHOT_HIT;
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

	bool isWin() {
		if (nHit == field->getN_ShipCells()) {
			state = _WIN;
			return true;
		}
		return false;
	}
};


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//	йкюяя хцпю
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
class Game: public Intro, public Exit {
	GAME_STATE state;
	int nGamer;
	Gamer* gamers;
public:
	Game() :state{ G_START }, nGamer{ 2 }, gamers{ new Gamer[2]{ {_HUMAN, "Bill", 1, true}, {_PC, "IBM", 2, false}}} {
		if (IS_SEE_CONST) std::cout << "Game" << this << "\n";
	};

	~Game() {
		delete[] gamers;
		gamers = nullptr;
		if (IS_SEE_CONST) std::cout << "DE_Game" << this << "\n";
	};

	bool isGamers() {															// опнбепйю - нярюкхяэ кх хцпнйх б хцпе;
		for (int i = 0; i < nGamer; i++) {
			if (gamers[i].getState() != _WIN) {
				return true;
			}
		}
		return false;
	}


	void begin() {
		int idCurrentGamer = 0;
		int idEnemyGamer;
		do {

			// нопедекхкх рейсыецн хцпнйю х хцпнйю опнрхбмхйю
			if (gamers[idCurrentGamer].getState() != _WIN) {							// опнбепхкх, рейсыхи хцпнй сфе ме бшхцпюк
				gamers[idCurrentGamer].setState(_MOVE);									// сярюмнбхкх хцпнйс ярюрся - ундхрэ
			}
			idEnemyGamer = ((idCurrentGamer) ? 0 : 1);									// нопедекхкх хцпнйю опнрхбмхйю
			// нопедекхкх рейсыецн хцпнйю х хцпнйю опнрхбмхйю


			// бшбекх хмтнплюжхч на хцпе, хцпнйюу
			iShow();
			std::cout << "  GAME STATE: " << GAME_STATE_NAME[state] << "  GAMERS AMOUNT: " << nGamer << std::endl;
			std::cout << "---------------------------------------" << std::endl << std::endl << std::endl;
			for (int i = 0; i < nGamer; i++) {
				gamers[i].show();
			}
			// бшбекх хмтнплюжхч на хцпе, хцпнйюу

			
			// рср бяъ кнцхйю хцпш - опнбепйю/ялемю ярюрсянб, гюохяэ/оепеунд ундю
			if (!isGamers()) {															// опнбепйю - нярюкхяэ кх хцпнйх б хцпе;
				state = G_END;															// сярюмнбхкх ярюрся хцпю нйнмвемю
			}
			else {
				if (gamers[idCurrentGamer].getState() == _MOVE) {						// опнбепхкх, врн с хцпнйю еярэ ярюрся - ундхрэ
					gamers[idCurrentGamer].showMovePrompt();							// яннаыемхе: ядекюире унд
					Gamer* pEnemy = &gamers[idEnemyGamer];								// сйюгюрекэ мю хцпнйю опнрхбмхйю
					CELL_TYPE& cell = gamers[idCurrentGamer].doShot(pEnemy);			// ядекюкх бшярпек. онксвхкх йкерйс, он йнрнпни ярпекъкх
					SHOT_RESULT shotResult = gamers[idCurrentGamer].getShotResult(cell);// нопедекхкх пегскэрюр бшярпекю

					if (shotResult != SHOT_REPEAT) {									// еякх ме онбрнп ундю
						gamers[idCurrentGamer].writeMove(cell, shotResult);				// гюохяэ ундю
						if (shotResult == SHOT_HIT) {									// еякх еярэ оноюдюмхе
							if (gamers[idCurrentGamer].isWin()) {						// опнбепхкх, ме бшхцпюк кх хцпнй
								idCurrentGamer = idEnemyGamer;							// оепеунд ундю
							}
						}
						else {
							gamers[idCurrentGamer].setState(_WAIT);						// сярюмнбхкх хцпнйс ярюрся нфхдюмхъ ундю
							idCurrentGamer = idEnemyGamer;								// оепеунд ундю
						}
					}
				}
				else {
					idCurrentGamer = idEnemyGamer;										// оепеунд ундю
				}
			}
			// рср бяъ кнцхйю хцпш - опнбепйю/ялемю ярюрсянб, гюохяэ/оепеунд ундю


			if (state != G_END) system("cls");
		} while (state != G_END);
		eShow();
	}



};


int main() {
	srand(time(NULL));

	Game game1;
	game1.begin();
}