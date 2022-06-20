#pragma once
#include <iostream>

class classwork34_point
{
private:
	int x;
	int y;

public:
	classwork34_point() {
		x = 0;
		y = 0;
	}

	classwork34_point(int x_) {
		x = x_;
		y = 0;
	}

	classwork34_point(int x_, int y_) {
		x = x_;
		y = y_;
	}


	~classwork34_point() {
		std::cout << "Destructor worked";
	};

	void printPoint() {
		// но это только при динамическом выделении
		std::cout << " x: " << x << " y:" << y;
	}

};

