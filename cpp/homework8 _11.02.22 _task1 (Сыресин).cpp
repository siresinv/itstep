// STEP _CPP _homework8 _11.02.22 _task1 (Сыресин)
// 
// Вывод на экран фигур на основе матрицы
// \- ; _\  ; \/ ; /\ ; X ; >< ; > ; < ; -/ ; /_


#include <iostream>

int main()
{
	setlocale(0, "");

	const int matrixSize = 15;
	const char MARK = '*';
	const char NO_MARK = '.';
	int figNo;
	
	std::cout << "Вывод на экран фигур на основе матрицы" << std::endl << std::endl;

	do {
		std::cout << "Введите номер фигуры - 1-10; 0 - выход: ";
		std::cin >> figNo;

		

		if (figNo >= 1 && figNo <= 10) {
			std::cout << std::endl << std::endl;
			for (int i = 0; i <= matrixSize - 1; i++) {
				std::cout << "\t\t";
				for (int j = 0; j <= matrixSize - 1; j++){
					switch (figNo) {
					case 1://
						(i <= j) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 2://
						(i >= j) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 3://
						(i <= j && i + j <= matrixSize - 1) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 4://
						(i >= j && i + j >= matrixSize - 1) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 5://
						((i <= j && i + j <= matrixSize - 1) || (i >= j && i + j >= matrixSize - 1)) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 6://
						((i >= j && i + j <= matrixSize - 1) || (i <= j && i + j >= matrixSize - 1)) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 7://
						(i >= j && i + j <= matrixSize - 1) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 8:
						(i <= j && i + j >= matrixSize - 1) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 9://
						(i+j <= matrixSize-1) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					case 10://
						(i+j >= matrixSize - 1) ? std::cout << MARK << " " : std::cout << NO_MARK << " ";
						break;
					default:
						break;
					}
				}
				std::cout << std::endl;
			}
			std::cout << std::endl << std::endl;
		}
		else if (figNo != 0) {
			std::cout << "Не верный номер!" << std::endl << std::endl;
		}
		
	} while (figNo != 0);

	return 0;

}

