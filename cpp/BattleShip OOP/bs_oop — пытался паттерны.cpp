#include <iostream>



class Field : public Ship {
protected:
	int w;
	int h;
	Cell** field; // или корабли сюда и вообще наследованием

public:
	virtual void display() = 0;

};




class Gamer {
protected:
	std::string		name;
	bool			type;
	int				type;
	int				shotCount;
	int				hitCount;
	int				killCount;
	Field			field;

public:
	virtual void 
};


class Action { //GamerAction

};

class ShipState {

};

/*

class Display
class Menu


*/

class Game: public Gamer, public g_Action {
protected:
	int number;
	int type;
	int state;


public:
};



class g_Action { // interface
public:
	virtual int		g_checkState() = 0;
	virtual void	g_changeState() = 0;
	virtual void	g_createGame() = 0;
	virtual void	g_createGamer() = 0;
	virtual void	g_createQueue() = 0;
	virtual void	g_nextInQueue() = 0;
	virtual void	g_viewMenu() = 0;
	virtual void	g_viewGame() = 0;
	virtual void	g_viewGamer() = 0;
	virtual void	g_viewStatistic() = 0;
	virtual void	g_viewEnterMove() = 0;


};



class checkState: public g_Action {
public:
	int g_checkState() {
		int a;
	}
};



class Key: public g_Action {
public:
	void readKey() {
		g_changeState();
	} // virtual
};



int main() {

}