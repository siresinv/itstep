// STEP _CPP _classwork14 _23.03.22 _task3
/*

*/



#include <iostream>


void test() {

	static int a = 0;
	a++;
	std::cout << a << std::endl;
}


int main() {

	test();
	test();
	test();

	return 0;
}