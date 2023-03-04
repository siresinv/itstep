#include <iostream>



class IComponent{
protected:
	
public:
	int a;
	IComponent(int a) : a{ a } {
		std::cout << "IComponent" << this << std::endl;
	};
	virtual void func() = 0;

	~IComponent() {
		std::cout << "IComponent" << "_DESTRUCTOR_" << this << std::endl;
	};
};


class ConcreteComponent: public IComponent {

public:
	ConcreteComponent() : IComponent{ 0 } {
		std::cout << "ConcreteComponent" << this << std::endl;
	};
	void func() {
		std::cout << a;
	}

	~ConcreteComponent() {
		std::cout << "ConcreteComponent" << "_DESTRUCTOR_" << this << std::endl;
	};
};


class ComponentDecor : public IComponent {
protected:
	IComponent* inst;
public:
	ComponentDecor(IComponent* iC, int a) : inst{ iC }, IComponent{ a } {
		std::cout << "ComponentDecor" << this << std::endl;
	};

	void func() {
		inst->func();
	}

	~ComponentDecor() {
		std::cout << "ComponentDecor" << "_DESTRUCTOR_" << this << std::endl;
	};
};


class ConcreteDecor1: public ComponentDecor {

public:
	ConcreteDecor1(IComponent* cd) : ComponentDecor{ cd, 2 } {
		std::cout << "ConcreteDecor1" << this << std::endl;
	};
	void func() {
		ComponentDecor::func();
		std::cout << "3"; 
	}

	~ConcreteDecor1() {
		std::cout << "ConcreteDecor1" << "_DESTRUCTOR_" << this << std::endl;
	};
};


class ConcreteDecor2: public ComponentDecor {

public:

};


class ConcreteDecor3: public ComponentDecor {

public:

};

int main() {

	IComponent* iC = new ConcreteComponent();
	iC->func();
	iC = new ConcreteDecor1{ iC };
	iC = new ConcreteDecor1{ iC };
	iC->func();

	delete iC; /////////////////////////////////////////////////////

	std::cout << " 123 ";
	return 0;
}