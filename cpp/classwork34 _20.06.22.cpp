// STEP _CPP _classwork34 _20.06.22
/*
ООП НАЧАЛО
*/


#include <iostream>
#include "Student2.h"


int main()
{
	//Student s1;
	//Student s2 {"Sidorov"};
	//Student s3{ new int[3] {1,2,3 }, 3};
	//Student s4 {"Sidorov", new int[3] {1,2,3}, 3};
	//s1.initStudent("Petrov", "Petr", "Petrovich", new int[3]{3, 4, 5});
	//std::cout << s1.getAvr();
	//s1.printStudent();
	std::cout << std::endl;

	//s1.setMakr(12, 1);
	//std::cout << s1.getMakr(1);


	Student* st = new Student[2]{ 
		{},
		{"Sidorov"}
		//{new int[3] {1,2,3 }, 3},
		//{"Sidorov", new int[3] {1,2,3 }, 3}
	};

	//st[0].printStudent();


	//s1.printStudent();
	//int x{5};
	return 0;
}