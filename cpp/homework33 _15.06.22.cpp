// STEP _CPP _homework33 _15.06.22

/*
ООП НАЧАЛО
*/


#include <iostream>
#include "Student.h"


int main()
{
	Student s1;
	s1.initStudent("Ivaov", "Ian", "iaoich", new int[3]{3, 4, 5});
	//std::cout << s1.getAvr();
	s1.printStudent();
	std::cout << std::endl;

	s1.setMakr(12, 1);
	std::cout << s1.getMakr(1);

	s1.setBithDay(12, 12, 1912);

	s1.setName("Ivanov", "Ivan", "OneOfEach");
	std::cout << s1.getName().patronymic;
	s1.printStudent();


	//int x{5};
	return 0;
}