//STEP C++ _homework6 _04.02.22 _task1


#include <iostream>


int main()
{
	//Задача про улитку, которая ползет за каждый день на 2см дальше предыдушего

	setlocale(0, "");

	const int distanceFirstDay = 15;
	const int nDay = 4;
	const int distanceInc = 2; // Прирост к дистанции

	int distanceNextDays;
	int distanceFull;

	
	distanceNextDays = distanceFirstDay; //
	distanceFull = distanceFirstDay;
	for (int i = 1; i <= nDay-1; i++) { //
		distanceNextDays += distanceInc; 
		distanceFull += distanceNextDays;
	}

	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Вся дистанция за " << nDay << " дн. равна " << distanceFull << std::endl;
}
