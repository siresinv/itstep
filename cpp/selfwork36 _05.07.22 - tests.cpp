// STEP _CPP _selfwork36 _05.07.22 - tests
/*

*/


#include <iostream>


class Myclass {
	int a;
public:
	explicit Myclass(int aU) :a{ aU } {};
	int geta() { return a; }
};


int main()
{
	Myclass ob1{ 4 };
	//Myclass ob1 = 4;
	std::cout << ob1.geta();


	return 0;
}

