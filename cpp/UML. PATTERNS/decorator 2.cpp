#include <iostream>



class IPC {
public:
	//IPC(std::string component) : description{ component } {};
	//IPC(){};
	virtual void setComponent(std::string) = 0;
	virtual std::string getComponent() = 0;
};


class Box: public IPC {
public:
	std::string description;
	//Component(std::string component) : description{ component } {};
	//Box() :description{ "123" }/*, IPC{}*/ {};
	Box() :IPC{} {};

	void setComponent(std::string component) {
		description += component;
	}

	std::string getComponent() {
		return description;
	}
};


class ComponentDecor : public IPC {
public:
	IPC* pc;

	ComponentDecor(IPC* pc) : pc{ pc } {};

	void setComponent(std::string component) {
		pc->setComponent(component);
	}

	std::string getComponent() {
		//return description;
		return "123"; /////////////////////////////////////
	}
};

class CPU : public ComponentDecor {
public:
	CPU(IPC* compPC) : ComponentDecor{ compPC } {};

	void setComponent(std::string component) {
		ComponentDecor::setComponent(component);
		//std::cout << Box::description;
	}

	std::string getComponent() {
		//return description;
		return "1234"; ///////////////////////////////
	}

};

class RAM : public ComponentDecor {

};


int main() {

	IPC* pc = new Box();
	pc = new CPU{ pc };
	pc->setComponent("000");
	pc = new CPU{ pc };
	pc = new CPU{ pc };
	pc = new CPU{ pc };
	std::cout << pc->getComponent();

	return 0;
}