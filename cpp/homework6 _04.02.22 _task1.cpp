//STEP _CPP _homework6 _04.02.22 _task1

#include <iostream>


int main()
{
	//Задача про улитку, которая ползет за каждый день на 2см дальше предыдущего

	setlocale(0, "");

	const int nDay = 4;
	const int distanceFirstDay = 15;
	const int distanceInc = 2; // Прирост к дистанции

	int distanceCurrentDay;
	int distanceFull;

	
	distanceCurrentDay = distanceFirstDay;
	distanceFull = 0;
	for (int i = 1; i <= nDay; i++) {
		distanceFull += distanceCurrentDay;
		distanceCurrentDay += distanceInc;
	}

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Вся дистанция за " << nDay << " дн. равна " << distanceFull << std::endl;
}
