// STEP _CPP _classwork14 _23.03.22 _task1
/*

*/


#include <iostream>




int a = 10;



void test()
{
	int a = 5;
	std::cout << a << std::endl;
	a = 20;
	::a = 30;
	std::cout << ::a << std::endl;
	int x = ::a;
}



int main()
{
	setlocale(0, "");
	int mas[2][5] = { 4,9,8,7,5,6,4,8,7,9 };
	test();
	std::cout << a << std::endl;
}