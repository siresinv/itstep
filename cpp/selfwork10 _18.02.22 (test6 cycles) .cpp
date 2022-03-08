// STEP _CPP _homework6 _04.02.22 _task1
// Компьютер угадывает рандомное число

#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main()
{
	int i = 1;
	while (i % 5 != 0) {
		{
			cout << i;
		}
		i++;
	}
	return 0;
}