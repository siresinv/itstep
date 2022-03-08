// STEP _CPP _selfwork6 _16.02.22 _task1 (matrix clock)
// matrix clock
//float rateWH = W_SIZE / float(H_SIZE); //потом как-нибудь

#include <iostream>
#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846
#include <math.h>


const int W_SIZE = 31;
const int H_SIZE = W_SIZE;
int CLOCK_RADIUS = W_SIZE / 2;

const char CLOCK_MARK = ' ';
const char H_WISE_MARK = 254;
const char M_WISE_MARK = '+';
const char S_WISE_MARK = '.';
const char NO_CLOCK_MARK = 177;
const char ZERO_MARK = 254;

const char H_WISE_LENGTH = 50; // в процентах от размера циферблата
const char M_WISE_LENGTH = 70; // в процентах от размера циферблата
const char S_WISE_LENGTH = 90; // в процентах от размера циферблата

// идем от верхнего левого в правый нижний угол
int wMin = -W_SIZE / 2;
int wMax = W_SIZE / 2;
int hMin = -H_SIZE / 2;
int hMax = H_SIZE / 2;

int seconds;
int minutes;
int hours;
int deg;
double radian;

double rateX;
double rateY;

int wise_length;
char wise_mark;
bool isDrawWise;

int main()
{
	for (int t = 60 * 60 * 4; t <= 60*60*12; t++) {
		system("cls");


		for (int wiseNo = 1; wiseNo <= 3; wiseNo++) {
			switch (wiseNo) {
			case 1:
				wise_length = S_WISE_LENGTH;
				wise_mark = S_WISE_MARK;
				seconds = t;
				deg = (360 / 60) * seconds;
				break;

			case 2:
				wise_length = M_WISE_LENGTH;
				wise_mark = M_WISE_MARK;
				minutes = round(t/float(60));
				deg = (360 / 60) * minutes;
				break;

			case 3:
				wise_length = H_WISE_LENGTH;
				wise_mark = H_WISE_MARK;
				hours = round(t / float(3600));
				deg = (360 / 12) * hours;
				break;

			default:
				break;
			}
		

			radian = (deg * M_PI) / 180;
			rateX = sin(radian) / double(cos(radian));
			rateY = 1;

			if (rateX > 1 || rateX < -1) {
				rateX = 1;
				rateY = cos(radian) / double(sin(radian));
			}



			for (int i = hMax; i >= hMin; i--) { 
				for (int j = wMin; j <= wMax; j++) {
					if (i == 0 && j == 0) {
						std::cout << ZERO_MARK << " ";
					}
					else if (round(i * rateX) == round(j * rateY) && sqrt(i * i + j * j) <= round(CLOCK_RADIUS*(wise_length/float(100)))) {

						isDrawWise = false;
						if (sin(radian) >= 0 && cos(radian) >= 0) {
							if (i >= 0 && j >= 0) isDrawWise = true;
						}
						else if (sin(radian) >= 0 && cos(radian) <= 0) {
							if (i <= 0 && j >= 0) isDrawWise = true;
						}
						else if (sin(radian) <= 0 && cos(radian) <= 0) {
							if (i <= 0 && j <= 0) isDrawWise = true;
						}
						else if (sin(radian) <= 0 && cos(radian) >= 0) {
							if (i >= 0 && j <= 0) isDrawWise = true;
						}

						if (isDrawWise == true) {
							std::cout << wise_mark << " ";
						}
						else {
							std::cout << "  ";
						}

					
					}

					else if (sqrt(i * i + j * j) < CLOCK_RADIUS) {
						std::cout << CLOCK_MARK << " ";
					}
					else {
						std::cout << NO_CLOCK_MARK << " ";
					}
				}
				std::cout << std::endl;

			}

	
		}

	}



	return 0;


}
