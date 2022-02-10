// STEP _CPP _classwork7 _09.02.22 _task5


#include <iostream>

/*
«а сутки на заводе изготавливаетс€ 4 детали. —уммарное
врем€ изготовлени€ одной детали не должно превышать
120 минут. ѕри этом кажда€ деталь проходит по 2 станка. –азработать программу, котора€ должна подсчитать
количество качественно изготовленных деталей за сутки
без нарушени€ технологии производства.
¬рем€ запрашиваетс€ на каждом станке
*/

int main()
{
	setlocale(0, "");
	
	const int DAY_TIME = 24 * 60;
	const int TIME_LIMIT = 120;
	int prodTime1;
	int prodTime2;
	int prodAllTime = 0;
	int nGoodDetail;
	int nBadDetail;

	std::cout << "";
	std::cin >> prodTime1;

	prodAllTime = prodTime1;



	if (prodAllTime < TIME_LIMIT)
	{
		std::cout << "";
		std::cin >> prodTime2;
	}
	else {

	}
	


	for (int nDatail = 1; i < 4; i++)
	{

	}

	return 0;

}