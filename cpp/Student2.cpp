#include "Student2.h"



void Student::printStudent() {
	std::cout << name << std::endl;

}

Student::Student() {
	std::cout << "Constructor worked without param ";
}

Student::Student(const char* name_) {
	strcpy_s(name, 20, name_);
	std::cout << "Constructor worked with param ";
}


Student::Student(const int* marks_, int nMarks) {
	marks = new int[nMarks];
	for (int i = 0; i < nMarks; i++) {
		marks[i] = marks_[i];
	}
	std::cout << "mark ";
}

Student::Student(const char* name_, int* marks_, int nMarks) {
	marks = new int[nMarks];
	strcpy_s(name, 20, name_);
	for (int i = 0; i < nMarks; i++) {
		marks[i] = marks_[i];
	}
	std::cout << "name + mark ";
}


void Student::createName(const char* name_) {
	int lenName = strlen(name_);
	name = new char[lenName];
	strcpy_s(name, lenName + 1, name_);
}


//// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     nullptr'ы в перегруженные методы 