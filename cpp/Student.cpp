#include "Student.h"

double Student::getAvr() {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += marks[i];
	}
	return sum / 3.0;
}

void Student::initStudent(const char* surname_, const char* name_, const char* patronymic_, const int* marks_) {
	strcpy_s(fullName.surname, surname_);
	strcpy_s(fullName.name, name_);
	strcpy_s(fullName.patronymic, patronymic_);
	for (int i = 0; i < 3; i++) {
		marks[i] = marks_[i];
	}
}

void Student::printStudent() {
	std::cout << fullName.surname << std::endl; //<< getAvr();
	std::cout << fullName.name << std::endl;
	std::cout << fullName.patronymic << std::endl;
}