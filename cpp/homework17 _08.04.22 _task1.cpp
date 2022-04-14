// STEP _CPP _homework17 _08.04.22 _task1
/*

BULLS AND COWS
*/


#include <iostream>
#include <stdlib.h>
#include <math.h>

const int N_DIGITS = 4;																				// количество цифр в числе
const int N_GAMERS = 3;																				// количество игроков
const int N_MAXTRY = 1600/N_GAMERS;																	// максимальное количество попыток. Экспериментально получено такое число, при котором не происзодит перепонение стека
int arrGamersType[N_GAMERS] = { 2, 1, 2 };															// массив типа каждого игрока. 1 - человек 2- машина


void intro();																						// вывод правил игры
void gamersReady();																					// вывод заголовка списка игроков
																									// вывод информации об игроках
void showGamerList(int arrGamersSecretDigits[][N_DIGITS], int nDigits, int N_GAMERS, int arrGamersMovesAmount[], int arrGamersStatus[], int arrGamersType[]);
bool isCorrectNum(int arrGamersSecretDigits[][N_DIGITS], int nDigits, int gamerId);					// проверка корректности числа - не повторяются ли цифры. Для массива загаднных чисел
bool isCorrectNum(int arrGamerDigits[N_DIGITS], int nDigits, int gamerId);							// проверка корректности числа - не повторяются ли цифры. Для предполагемого числа
bool isCorrectExpNum(int number, int nDigits);														// проверка корректности порядка числа
int getPCSecretNum(int nDigits);																	// получить загаданное число от ПК
int getGamerSecretNum(int nDigits, int gamerId);													// получить загаданное число от Человека
int getGamerNum(int gamerId);																		// получить предполагаемое чсисло от любого игрока
void startGame();																					// вывод информации о старте игры
																									// ОСУЩЕСТВЛЕНИЕ ХОДА
void doMove(int arrGamersSecretDigits[][N_DIGITS], int nDigits, int gamerId, int N_GAMERS, int arrGamersMovesAmount[], int arrGamersStatus[], int arrGamersType[], int targetGamerId);
int getBullsAmount(int arrSecretDigits[][N_DIGITS], int arrGamerDigits[], int nDigits, int gamerId);// получить количество Быков
int getCowsAmount(int arrSecretDigits[][N_DIGITS], int arrGamerDigits[], int nDigits, int gamerId);	// получить количество Коров
																									// вывод информации о ходе
void showGamerMove(int arrGamerDigits[], int nBulls, int nCows, int nDigits, int gamerId, int N_GAMERS, int arrGamersMovesAmount[]);
void endGame();																						// вывод сообщения о конце игры
int getN_GAMERSInGameAmount(int arrGamersStatus[], int N_GAMERS);									// получить количество игроков со статусом "в игре"


int main() {
	//for (int i = 0; i < N_GAMERS; i++) arrGamersType[i] = 2; //для автоматического создания большого массива с игроками типа машина
	setlocale(0, "");
	srand(time(NULL));

	int gamerNum;												// число загаданное игроком
	int nDigits = N_DIGITS;										// количество цифр в числе
	int digit;													//
	bool correctExpNum;											// корректность порядка числа
	
	int gamerId = 0;											// АйДи первого игрока
	int targetGamerId = 1;										// АйДи игрока, чьё число угадывает первый игрок
	int arrGamersMovesAmount[N_GAMERS] = {};					// массив количества ходов каждого игрока
	int arrGamersStatus[N_GAMERS] = {};							// массив статусов игроков. 1 - в игре 2 - угадал 3 - кончились попытки
	for (int i = 0; i < N_GAMERS; i++) arrGamersStatus[i] = 1;	// изначально все в игре
	int arrGamersSecretDigits[N_GAMERS][N_DIGITS] = {};			// массив загаданных чисел(цифр) игроков

	for (int gId = 0; gId < N_GAMERS; gId++) { // перебор количества игров, для загадывания числа
		intro();
		do {
			if (arrGamersType[gId] == 2) {
				gamerNum = getPCSecretNum(nDigits);
			}
			else {
				gamerNum = getGamerSecretNum(nDigits, gId);
			}
			correctExpNum = isCorrectExpNum(gamerNum, nDigits);
			for (int i = 0; i < nDigits; i++) {
				digit = gamerNum / int(pow(10, nDigits - i - 1));
				gamerNum %= int(pow(10, nDigits - i - 1));
				arrGamersSecretDigits[gId][i] = digit;
			}
		} while (!correctExpNum || !isCorrectNum(arrGamersSecretDigits, nDigits, gId));
		system("cls");
	}
	intro();
	gamersReady();
	showGamerList(arrGamersSecretDigits, nDigits, N_GAMERS, arrGamersMovesAmount, arrGamersStatus, arrGamersType);
	startGame();
	doMove(arrGamersSecretDigits, nDigits, gamerId, N_GAMERS, arrGamersMovesAmount, arrGamersStatus, arrGamersType, targetGamerId);
	endGame();
	showGamerList(arrGamersSecretDigits, nDigits, N_GAMERS, arrGamersMovesAmount, arrGamersStatus, arrGamersType);
	return 0;
}

void intro() {
	std::cout << "**************************************************************************************";
	std::cout << std::endl;
	std::cout << "| " << "\t\t\t\t";
	std::cout << "ИГРА \"БЫКИ И КОРОВЫ\"";
	std::cout  << "\t\t\t\t" << "     |";
	std::cout << std::endl;
	std::cout << "| " << "\t";
	std::cout << "Игроки загадывают " << N_DIGITS << "-значное число. Цифры не могут повторяться";
	std::cout << "\t\t" << "     |";
	std::cout << std::endl;
	std::cout << "| " << "\t\t\t";
	std::cout << "После каждой попытки программа сообщает:";
	std::cout << "\t\t" << "     |";
	std::cout << std::endl;
	std::cout << "| " << "сколько цифр числа угадано (БЫКИ) и сколько цифр находятся на своем месте (КОРОВЫ)";
	std::cout << " |";
	std::cout << std::endl;
	std::cout << "| " << "\t\t\t";
	std::cout << "Максимальное число попыток - " << N_MAXTRY;
	std::cout << "\t\t\t" << "     |";
	std::cout << std::endl;
	std::cout << "**************************************************************************************";
	std::cout << std::endl;
	std::cout << std::endl;
}

void gamersReady() {
	std::cout << "---------------------  С П И С О К  И Г Р О К О В ----------------------";
	std::cout << std::endl;
}

void showGamerList(int arrGamersSecretDigits[][N_DIGITS], int nDigits, int N_GAMERS, int arrGamersMovesAmount[], int arrGamersStatus[], int arrGamersType[]) {
	for (int i = 0; i < N_GAMERS; i++) {
		std::cout << "[И:" << i + 1 << "]-" << ((arrGamersType[i] == 1) ? "Ч " : "К ");
		std::cout << "[Х:" << arrGamersMovesAmount[i] << "] \t";
		if (getN_GAMERSInGameAmount(arrGamersStatus, N_GAMERS) == 0) {
			std::cout << "|";
			for (int j = 0; j < nDigits; j++) {
				std::cout << arrGamersSecretDigits[i][j] << "|";
			}
			std::cout << ((arrGamersStatus[i] == 2) ? " ВЫИГРАЛ" : " ПРОИГРАЛ");
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int getPCSecretNum(int nDigits) {
	return rand() % (9 * int(pow(10, nDigits - 1))) + int(pow(10, nDigits - 1));
}

int getGamerSecretNum(int nDigits, int gamerId) {
	int gamerSecretNum;
	std::cout << "\t\t\t\t";
	std::cout << "[И:" << gamerId + 1 << "] ";
	std::cout << "загадайте " << nDigits << "-значное число: ";
	std::cin >> gamerSecretNum;
	return gamerSecretNum;
}

int getGamerNum(int gamerId) {
	int gamerNum;
	std::cout << "\t\t\t\t";
	std::cout << "[И:" << gamerId + 1 <<"] ";
	std::cout << "введите ваш вариант: ";
	std::cin >> gamerNum;
	return gamerNum;
}

bool isCorrectNum(int arrGamersSecretDigits[][N_DIGITS], int nDigits, int gamerId) {
	for (int i = 0; i < nDigits -1; i++) {
		for (int j = i+1; j < nDigits; j++) {
			if (arrGamersSecretDigits[gamerId][i] == arrGamersSecretDigits[gamerId][j]) return false;
		}
	}
	return true;
}

bool isCorrectNum(int arrGamerDigits[N_DIGITS], int nDigits, int gamerId) {
	for (int i = 0; i < nDigits - 1; i++) {
		for (int j = i + 1; j < nDigits; j++) {
			if (arrGamerDigits[i] == arrGamerDigits[j]) return false;
		}
	}
	return true;
}

bool isCorrectExpNum(int number, int nDigits) {
	int expAmount = number / pow(10, nDigits - 1);
	if (expAmount > 0 && expAmount < 10) {
		return true;
	}
	return false;
}

void startGame() {
	std::cout << "---------------------- И Г Р А   Н А Ч А Л А С Ь ----------------------";
	std::cout << std::endl;
}

void doMove(int arrGamersSecretDigits[][N_DIGITS], int nDigits, int gamerId, int N_GAMERS, int arrGamersMovesAmount[], int arrGamersStatus[], int arrGamersType[], int targetGamerId) {
	int gamerNum;					// предполагаемое число
	int arrGamerDigits[N_DIGITS];	// массив цифр, получаемых из предполагаемого числа
	int digit;						//
	int nBulls;						// количество быков
	int nCows;						// количество коров
	bool correctExpNum;				// корректность порядка числа
	int nextGamerId;				// 

	while (getN_GAMERSInGameAmount(arrGamersStatus, N_GAMERS) > 0) {
		if (arrGamersStatus[gamerId] == 1) {
			arrGamersMovesAmount[gamerId] += 1;
			do {
				if (arrGamersType[gamerId] == 2) {
					gamerNum = getPCSecretNum(nDigits);
				}
				else if (arrGamersType[gamerId] == 1) {
					gamerNum = getGamerNum(gamerId);
				}
				correctExpNum = isCorrectExpNum(gamerNum, nDigits);
				for (int i = 0; i < nDigits; i++) {
					digit = gamerNum / int(pow(10, nDigits - i - 1));
					gamerNum %= int(pow(10, nDigits - i - 1));
					arrGamerDigits[i] = digit;
				}
			} while (!correctExpNum || !isCorrectNum(arrGamerDigits, nDigits, gamerId));

			nBulls = getBullsAmount(arrGamersSecretDigits, arrGamerDigits, nDigits, targetGamerId);
			nCows = getCowsAmount(arrGamersSecretDigits, arrGamerDigits, nDigits, targetGamerId);
			showGamerMove(arrGamerDigits, nBulls, nCows, nDigits, gamerId, N_GAMERS, arrGamersMovesAmount);
			if (nCows == nDigits) {
				arrGamersStatus[gamerId] = 2;
			}
			else if (arrGamersMovesAmount[gamerId] == N_MAXTRY) {
				arrGamersStatus[gamerId] = 3;
			}
		}
		nextGamerId = (gamerId == N_GAMERS - 1) ? 0 : gamerId + 1;
		targetGamerId = (nextGamerId == N_GAMERS - 1) ? 0 : nextGamerId + 1;
		doMove(arrGamersSecretDigits, nDigits, nextGamerId, N_GAMERS, arrGamersMovesAmount, arrGamersStatus, arrGamersType, targetGamerId);
	}
}

int getBullsAmount(int arrGamersSecretDigits[][N_DIGITS], int arrGamerDigits[], int nDigits, int gamerId) {
	int nBulls = 0;
	for (int i = 0; i < nDigits; i++) {
		for (int j = 0; j < nDigits; j++) {
			if (arrGamersSecretDigits[gamerId][j] == arrGamerDigits[i]) nBulls++;
		}
	}
	return nBulls;
}

int getCowsAmount(int arrGamersSecretDigits[][N_DIGITS], int arrGamerDigits[], int nDigits, int gamerId) {
	int nCows = 0;
	for (int i = 0; i < nDigits; i++) {
		for (int j = 0; j < nDigits; j++) {
			if (arrGamersSecretDigits[gamerId][j] == arrGamerDigits[i] && j == i) nCows++;
		}
	}
	return nCows;
}

void showGamerMove(int arrGamerDigits[], int nBulls, int nCows, int nDigits, int gamerId, int N_GAMERS, int arrGamersMovesAmount[]) {
	std::cout << "[И:" << gamerId + 1 << "] ";
	std::cout << "[Х:" << arrGamersMovesAmount[gamerId] << "] |";
	for (int i = 0; i < nDigits; i++) {
		std::cout << arrGamerDigits[i] << "|";
	}
	std::cout << " Б:" << nBulls << " ";
	std::cout << "К:" << nCows;
	std::cout << std::endl;
}

void endGame() {
	std::cout << std::endl;
	std::cout << "--------------------  Р Е З У Л Ь Т А Т Ы  И Г Р Ы  --------------------";
	std::cout << std::endl;
}

int getN_GAMERSInGameAmount(int arrGamersStatus[], int N_GAMERS) {
	int gamerInGameAmount = 0;
	for (int i = 0; i < N_GAMERS; i++) {
		if (arrGamersStatus[i] == 1) {
			gamerInGameAmount++;
		}
	}
	return gamerInGameAmount;
}