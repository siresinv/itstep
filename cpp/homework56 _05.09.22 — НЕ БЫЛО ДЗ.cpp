// STEP _CPP _classwork56 _05.09.22
/*
ООП

List


*/


#include <iostream>
#include <list>
#include <cmath>
#include <ctime>

typedef std::list<int> L;

void printList(L& l1, L&l2) {
	L::iterator iter;
	std::cout << "L1: ";
	for (iter = l1.begin(); iter != l1.end(); iter++) {
		std::cout << *iter;
	}
	std::cout << std::endl;
	std::cout << "L2: ";
	for (iter = l2.begin(); iter != l2.end(); iter++) {
		std::cout << *iter;
	}
	std::cout << std::endl;
}


void printList2(L& l1) {
	L::iterator iter;
	std::cout << "L3: ";
	for (iter = l1.begin(); iter != l1.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}


class Mylist : public L {
public:
	int& operator[] (int id) {
		L::iterator it;
		int counter = 0;
		for (it = this->begin(); it != this->end(); it++) {
			if (counter++ == id) {
				return *it;
			}
		}
	}

	int getMin() {
		L::iterator it;
		int min = *(this->begin());
		for (it = this->begin(); it != this->end(); it++) {
 			if (*it < min) {
				min = *it;
			}
		}
		return min;
	}


	int getMax() {
		L::iterator it;
		int max = *(this->begin());
		for (it = this->begin(); it != this->end(); it++) {
			if (*it > max) {
				max = *it;
			}
		}
		return max;
	}

	void inc(int value) {
		L::iterator it;
		for (it = this->begin(); it != this->end(); it++) {
			*it += value;
		}
	}

	void dec(int value) {
		L::iterator it;
		for (it = this->begin(); it != this->end(); it++) {
			*it -= value;
		}
	}


};

int main()
{

	srand(time(NULL));

    L l1, l2;

	for (int i = 0; i < 5; i++) {
		l1.push_back(i);
		l2.push_front(i);
	}

	printList(l1, l2);

	// в 1 списке первый элемент перенести в конец
	// 2 перевернуть
	// вывести оба

	l1.splice(l1.end(), l1, l1.begin());
	/*l1.push_back(*(l1.begin()));
	l1.pop_front();*/


	l2.reverse();
	printList(l1, l2);

	l1.sort();
	l2.sort();
	printList(l1, l2);

	l1.merge(l2);
	printList(l1, l2);

	l1.unique();
	printList(l1, l2);





	////////

	Mylist l3;
	for (int i = 0; i < 15; i++) {
		l3.push_back(/*rand()%100*/i);
	}
	printList2(l3);


	l3[2] = 55;
	std::cout << l3[2];
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << l3.getMin();
	std::cout << std::endl;

	std::cout << l3.getMax();
	std::cout << std::endl;

	l3.inc(10);
	printList2(l3);
	std::cout << std::endl;


	l3.dec(10);
	printList2(l3);
	std::cout << std::endl;


	l3.remove(10);
	printList2(l3);
	std::cout << std::endl;

	l3.sort();
	printList2(l3);
	std::cout << std::endl;

	l3.reverse();
	printList2(l3);
	std::cout << std::endl;

    return 0;
}


/*
В контейнере типа list хранится набор целых чисел. Создайте функции для решения следующих задач:
■ Поиск минимального значения;
■ Поиск максимального значения;
■ Сортировка данных по убыванию;
■ Сортировка данных по возрастанию;
■ Увеличение значений в контейнере на заданную константу;
■ Уменьшение значений в контейнере на заданную константу;
■ Удаление элементов из контейнера равных искомому значению.
*/