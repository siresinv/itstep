// STEP _CPP _classwork13 _16.03.22 _task2
/*
Написать функцию, выводящую на экран прямоугольник с высотой N и шириной K.
*/


#include <iostream>



void drawRect(int height, int width);

int main() {
	drawRect(5, 10);
}


void drawRect(int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i == 0) || (i == height - 1) || (j == 0) || (j == width - 1)) {
				std::cout << "*";
			}
			else {
				std::cout << " ";
			}

		}
		std::cout << std::endl;
	}
}