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

	// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	Fract(const Fract& obj) {};
	


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

	// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	//static Fract read;
	

	// 2 - friend way
	friend Fract& operator+(const Fract& f1, const Fract& f2);

	// 2 - friend way
	friend Fract& operator*(const Fract& f1, const Fract& f2);

	// 2 - friend way
	friend Fract& operator/(const Fract& f1, const Fract& f2);

	// 3 - class method way
	bool operator==(const Fract& f2) { 
		// если без & - то видимо срабатывает конструктор копирования по-умолчанию
		// и данное условие правильно не отрабатывает
		return (num*f2.denom == denom*f2.num);
	}
};

// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//Fract Fract::read;

// 2 - friend way
Fract& operator+(const Fract& f1, const Fract& f2) {
	// здесь & нужен видимо из-за того, что у объекта есть имя
	// но он все равно уничтожится после отрабатывания функции ???
	Fract f3;
	f3.num = f1.num * f2.denom + f1.denom * f2.num;
	f3.denom = f1.denom * f2.denom;
	return f3;
} 

// 2 - friend way
Fract& operator*(const Fract& f1, const Fract& f2) {
	// здесь & нужен видимо из-за того, что у объекта есть имя
	// но он все равно уничтожится после отрабатывания функции ???
	Fract f3;
	f3.num = f1.num * f2.num;
	f3.denom = f1.denom * f2.denom;
	return f3;
}


// 2 - friend way
Fract& operator/(const Fract& f1, const Fract& f2) {
	// здесь & нужен видимо из-за того, что у объекта есть имя
	// но он все равно уничтожится после отрабатывания функции ???
	Fract f3;
	f3.num = f1.num * f2.denom;
	f3.denom = f1.denom * f2.num;
	return f3;
}



// 1 common way
Fract operator-(const Fract f1, const Fract f2) { 
	// здесь & не нужен видимо из-за того, что у объекта нет имени и ...
	return Fract{ f1.getNum() * f2.getDenom() - f1.getDenom() * f2.getNum(), f1.getDenom() * f2.getDenom()};
}

int main() {
	// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	// ПОКА ЕСТЬ 3 ВОПРОСА - ЗАПИСАНЫ В КОММЕНТАРИЯХ

	Fract{ 1,2 }.showFract();
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

	return 0;
}



// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//void Point::read() {
//
//	std::cout << "enter x: ";
//	std::cin >> x;
//	this->x = x;
//
//	std::cout << "enter y: ";
//	std::cin >> y;
//	this->y = y;
//
//	// можно std::cin >> x >> y; // и всё !!! - ПОПРОБОВАТЬ РЕАД ИСПОЛЬЗОВАТЬ
//
//};



// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+// -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//void print(const DynArr& obj) {
//	for (int i = 0; i < obj.getSize(); i++) {
//		obj.print(i);
//	}
//}