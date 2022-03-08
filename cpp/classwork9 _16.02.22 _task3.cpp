// STEP _CPP _classwork9 _16.02.22 _task3
/*
3. ƒана температура воздуха за каждый день €нвар€.
ќпределить:
а) среднюю температуру за мес€ц;
б) сколько раз температура воздуха опускалась нижеуказанной метки.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {

	setlocale(0, "");

	const int arrSize = 31;
	const int minTemp = -24;
	int janTemp[arrSize];
	int minTempCount;
	int sumTemp;
	float avgTemp;

	srand(time(NULL));

	for (int i = 0; i < arrSize; i++) {
		janTemp[i] = rand() % 16 -25;
	}

	for (int i = 0; i < arrSize; i++) {
		std::cout << janTemp[i] << " ";
	}

	std::cout << std::endl;


	minTempCount = 0;
	sumTemp = 0;
	for (int k = 0; k < arrSize; k++) {
		if (janTemp[k]< minTemp) {
			minTempCount++;
		}
		sumTemp += janTemp[k];
	}

	avgTemp = sumTemp / float(arrSize);
	std::cout << "ќпускалась ниже " << minTemp << " " << minTempCount << " раз. " << "—редн€€ температура: " << avgTemp;

	std::cout << std::endl;

	return 0;
}