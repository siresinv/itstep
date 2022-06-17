#include "Student.h"

double Student::getAvr() {
	double sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += marks[i];
	}
	return sum / 3.0;
}

void Student::initStudent(const char* name1, const int* marks1) {
	strcpy_s(name, name1);
	for (int i = 0; i < 3; i++) {
		marks[i] = marks1[i];
	}
	//marks[0] = marks1[0]; // ))
	//marks[1] = marks1[1]; // ))
	//marks[2] = marks1[2]; // ))
}

void Student::printStudent() {
	std::cout << name << " " << getAvr();
}