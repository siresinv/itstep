// STEP _CPP _homework34 _20.06.22

/*
ООП НАЧАЛО
*/


#include <iostream>
#include "hw34_subscribe.h"


int main()
{

	hw34_subscribe subs1("Ivanov", "Ivan", "Ivanovich");
	hw34_subscribe subs2("Petrov", "Petr", "Petrovich", 834211122, "Good_Man");

	subs1.printSubs();
	std::cout << std::endl;
	subs2.printSubs();

	return 0;
}