//AbstractFactory.cpp - 081122

#include <iostream>

class AbstractWater {

};

class CocaWater: public AbstractWater {

};

class PepsiWater : public AbstractWater {

};


class AbstractBottle {
public:
	virtual void interact(AbstractWater water) {};
};

class CocaBottle: public AbstractBottle {
public:
	void interact(AbstractWater water) {
		std::cout << this << " intearcts with " << "water COCA";
	}
};

class PepsiBottle: public AbstractBottle {
public:
	virtual void interact(AbstractWater water) {
		std::cout << this << " interact with " << "water PEPSI";
	}
};




class AbstractFactory{
public:
	virtual AbstractWater creatWater() {};
	virtual AbstractBottle creatBottle() {};

};

class CocaFactory : public AbstractFactory{
public:
	AbstractWater creatWater() {
		CocaWater cw;
		//return new CocaWater(); // ?????????????????????????????????????????
		return cw;
	};
	AbstractBottle creatBottle() {
		CocaBottle cb;
		return cb;
	}

};

class PepsiFactory: public AbstractFactory {
public:
	AbstractWater creatWater() {
		PepsiWater pw;
		return pw;
	}
	AbstractBottle creatBottle() {
		PepsiBottle pb;
		return pb;
	}
};



class Client {
	AbstractBottle bottle;
	AbstractWater water;
public:
	Client(AbstractFactory factory) {
		water = factory.creatWater();
		bottle = factory.creatBottle();
	}

	void run() {
		bottle.interact(water);
	}


};


int main() {

	CocaFactory cf;
	//Client client {new CocaFactory}; //???????????????????????????
	//Client client{ cf };


	return 0;
}