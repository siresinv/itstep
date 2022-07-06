// STEP _CPP _homework37 _29.06.22
/*
ООП НАЧАЛО

Перегрузить
+ - * / ==


*/


#include <iostream>


class Fract {
private:
	int num;
	int denom;

public:
	Fract(int num, int denom) :num{ num }, denom{ denom }{};
	Fract() :Fract(1, 1) {};
	~Fract() {}; // не обязательно
	Fract(const Fract& obj) :num{obj.num}, denom{obj.denom} {};
	


	int getNum() const {
		return num;
	}

	int getDenom() const {
		return denom;
	}

	void showFract() const {
		std::cout << " " << num;
		std::cout << std::endl;
		std::cout << "-----";
		std::cout << std::endl;
		std::cout << " " << denom;
		std::cout << std::endl;
		std::cout << std::endl;
	}

	//void changeFract();
	static void changeFract(Fract&);
	

	// 2 - friend way
	friend Fract& operator+(const Fract& f1, const Fract& f2);

	// 2 - friend way
	friend Fract& operator*(const Fract& f1, const Fract& f2);

	// 2 - friend way
	friend Fract& operator/(const Fract& f1, const Fract& f2);

	// 3 - class method way
	bool operator==(const Fract& f2) const {
		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
		// Q1: // если без & - то видимо срабатывает конструктор копирования по-умолчанию
		// и данное условие правильно не отрабатывает
		//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
		return (num*f2.denom == denom*f2.num);
	}
};



// 2 - friend way
Fract& operator+(const Fract& f1, const Fract& f2) {
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Q2: // здесь & нужен видимо из-за того, что у объекта есть имя
	// но он все равно уничтожится после отрабатывания функции ???
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	Fract f3;
	f3.num = f1.num * f2.denom + f1.denom * f2.num;
	f3.denom = f1.denom * f2.denom;
	return f3;
} 

// 2 - friend way
Fract& operator*(const Fract& f1, const Fract& f2) {
	Fract f3;
	f3.num = f1.num * f2.num;
	f3.denom = f1.denom * f2.denom;
	return f3;
}


// 2 - friend way
Fract& operator/(const Fract& f1, const Fract& f2) {
	Fract f3;
	f3.num = f1.num * f2.denom;
	f3.denom = f1.denom * f2.num;
	return f3;
}



// 1 common way
Fract operator-(const Fract f1, const Fract f2) {
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// Q3: // здесь & не нужен видимо из-за того, что у объекта нет имени и ...
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	return Fract{ f1.getNum() * f2.getDenom() - f1.getDenom() * f2.getNum(), f1.getDenom() * f2.getDenom()};
}

//// not static
//void Fract::changeFract() {
//	std::cout << "Enter numerator and denominator of fraction: ";
//	std::cin >> num >> denom;
//}


// static
void Fract::changeFract(Fract& obj) {
	std::cout << "Enter numerator and denominator of fraction: ";
	std::cin >> obj.num >> obj.denom;
}


void showFract(const Fract& obj) {
	obj.showFract();
}

int main() {

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// 3 ВОПРОСА - ЗАПИСАНЫ В КОММЕНТАРИЯХ
	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	Fract{ 1,2 }.showFract();
	std::cout << std::endl;std::cout << "------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Fract1 =";
	std::cout << std::endl;
	Fract f1{ 4,5 };
	f1.showFract();

	std::cout << "Fract2 =";
	std::cout << std::endl;
	Fract f2{ 3,8 };
	f2.showFract();

	if (f1 == f2) {
		std::cout << "Fracts is equal";
	}
	else {
		std::cout << "Fracts is not equal";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	Fract f3;
	f3 = f1 + f2;
	std::cout << "Fract1 + Fract2 = ";
	std::cout << std::endl;
	f3.showFract();

	std::cout << "Fract(Fract{1,2} - Fract{2,4}) = ";
	std::cout << std::endl;
	Fract{ Fract{1,2} - Fract{2,4} }.showFract();


	Fract f4;
	f4 = f1 * f2;
	std::cout << "Fract1 * Fract2 = ";
	std::cout << std::endl;
	f4.showFract();

	Fract f5;
	f5 = f1 / f2;
	std::cout << "Fract1 / Fract2 = ";
	std::cout << std::endl;
	f5.showFract();
	std::cout << std::endl;

	std::cout << "------------------------------------";
	std::cout << std::endl;

	std::cout << "Fract6 = ";
	std::cout << std::endl;
	Fract f6{ 5,6 };
	f6.showFract();
	std::cout << "Fract7 = ";
	std::cout << std::endl;
	Fract f7{ f6 };
	f7.showFract();

	if (f6 == f7) {
		std::cout << "Fracts is equal";
	}
	else {
		std::cout << "Fracts is not equal";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "------------------------------------";
	std::cout << std::endl;
	std::cout << "Fract6 = ";
	std::cout << std::endl;
	f6.showFract();
	std::cout << std::endl;
	// f7.changeFract(); // not static
	Fract::changeFract(f7); // static
	std::cout << "Fract7 = ";
	std::cout << std::endl;
	f7.showFract();

	if (f6 == f7) {
		std::cout << "Fracts is equal";
	}
	else {
		std::cout << "Fracts is not equal";
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "------------------------------------";
	std::cout << std::endl;

	std::cout << "Fract6 = ";
	std::cout << std::endl;
	showFract(f6);
	std::cout << "Fract7 = ";
	std::cout << std::endl;
	showFract(f7);
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}