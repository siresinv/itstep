// STEP _CPP _classwork10 _18.02.22 _task4
/*
—жать (сдвинуть элементы) массив, удалив из
него все 0, и заполнить освободившиес€ справа элементы
значени€ми -1.
ћассив тот же самый!!

i++;
с конца
ћ≈Ќя“№ ћ≈—“јћ» ЁЋ≈ћ≈Ќ“џ!

ћћћ.... не работает так
т.е. если больше двух подр€д нулей
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {

	setlocale(0, "");

	const int size = 11;
	int mas[size] = { 9,0,0,0,7,8,0,6,9,5,4 };
	for (int i = 0; i < 10; i++) {
		if (mas[i] == 0) {
			for (int j = i; j < size - 1; j++) {
				mas[j] = mas[j + 1];
			}
			mas[size - 1] = -1;
			i--;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;


	return 0;
}

