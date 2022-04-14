// STEP _CPP _homework14 _23.03.22 _task1
/*
	в картинке
	ДНЕЙ МЕЖДУ ДАТАМИ
*/



#include <iostream>



bool isLeapYear(int year);
int getNDaysInMonth(int month, int year);
bool isCorrectDate(int date[]);
bool isFirstDateLess(int date1[], int date2[]);
int diffDays(int date1[], int date2[]);

int main() {
	setlocale(0,"");

	const int DATE_PARAMETRS = 3;
	int date1[DATE_PARAMETRS];
	int date2[DATE_PARAMETRS];

	std::cout << "ВВЕДИТЕ ДВЕ ДАТЫ ДЛЯ ПОДСЧЕТА КОЛИЧЕСТВА ДНЕЙ МЕЖДУ НИМИ" << std::endl << std::endl;

	do {
		std::cout << "ДАТА 1: ДД ММ ГГГГ: ";
		std::cin >> date1[0] >> date1[1] >> date1[2];

		std::cout << "ДАТА 2: ДД ММ ГГГГ: ";
		std::cin >> date2[0] >> date2[1] >> date2[2];
		
		if (!isCorrectDate(date1) || !isCorrectDate(date2)) std::cout << std::endl << "Введена НЕверная дата" << std::endl;
	} while (!isCorrectDate(date1) || !isCorrectDate(date2));


	std::cout << "------------------------------------" << std::endl;

	std::cout << std::endl << "Между " << date1[0] << "." << date1[1] << "." << date1[2]
		<< " и " << date2[0] << "." << date2[1] << "." << date2[2]
		<< " - " << diffDays(date1, date2) << " дн.";
	std::cout << std::endl;

	
	return 0;
}


bool isLeapYear(int year) {
	bool leapYear;
	leapYear = false;
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				leapYear = true;
			}
		}
	}
	return leapYear;
}


int getNDaysInMonth(int month, int year) {
	int arrMonthDayAmount[] = { 31, ((isLeapYear(year) == true)? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return arrMonthDayAmount[month-1];
}


bool isCorrectDate(int date[]) {
	const int MIN_DAY = 1;
	const int MAX_DAY = 31;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;
	int day;
	int month;
	int year;
	bool correctDate;

	day = date[0];
	month = date[1];
	year = date[2];
	correctDate = false;
	if (day >= MIN_DAY && day <= getNDaysInMonth(month, year) //
		&& month >= MIN_MONTH && month <= MAX_MONTH && year > 0) {
			correctDate = true;
	}
	return correctDate;
}


bool isFirstDateLess(int date1[], int date2[]) {
	int day1;
	int month1;
	int year1;
	int day2;
	int month2;
	int year2;

	day1 = date1[0];
	month1 = date1[1];
	year1 = date1[2];
	day2 = date2[0];
	month2 = date2[1];
	year2 = date2[2];

	if (year1 < year2) {
		return true;
	}
	else if (month1 < month2) {
		return true;
	}
	else if (day1 < day2) {
		return true;
	}
	else {
		return false;
	}
}


int diffDays(int date1[], int date2[]) {
	const int MAX_MONTH = 12;
	int startDay;
	int startMonth;
	int startYear;
	int endDay;
	int endMonth;
	int endYear;

	int currentDay;
	int currentMonth;
	int currentYear;

	int shift;
	int nDaysInMonth;
	int dayCounter;


	startDay = date1[0];
	startMonth = date1[1];
	startYear = date1[2];
	endDay = date2[0];
	endMonth = date2[1];
	endYear = date2[2];
	
	currentDay = startDay;
	currentMonth = startMonth;
	currentYear = startYear;

	shift = (isFirstDateLess(date1, date2) == true) ? 1 : -1;
	nDaysInMonth = getNDaysInMonth(currentMonth, currentYear);
	dayCounter = 0;

	while (currentYear != endYear || currentMonth != endMonth || currentDay != endDay) {
		//system("cls"); //чтобы работало быстро - убрать эту строку
		if (currentDay != ((shift == 1)? nDaysInMonth : 1)) {
			currentDay += shift;
		}
		else {
			currentDay = (shift == 1) ? 1 : getNDaysInMonth(currentMonth, currentYear);
			if (currentMonth != ((shift == 1) ? MAX_MONTH : 1)) { 
				currentMonth += shift;
				currentDay = (shift == 1) ? 1 : getNDaysInMonth(currentMonth, currentYear);
			}
			else {
				currentMonth = ((shift == 1) ? 1 : MAX_MONTH);
				currentYear += shift;
			}
			nDaysInMonth = getNDaysInMonth(currentMonth, currentYear);
		}
		dayCounter++;

		//чтобы работало быстро - убрать этот вывод
		std::cout << currentDay << "." << currentMonth 
			<< "." << currentYear << " прошло - " << dayCounter << " дн." << std::endl;
	}

	return dayCounter;
}