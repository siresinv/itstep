// STEP _CPP _homework30 _01.06.22
/*

СТРУКТУРЫ


*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <stdio.h>


struct book
{
    char title[50];
    char author[50];
    char edition[50];
    int price;
};


enum sortBy {
    unsorted,
    sortByTitle,
    sortByAuthor,
    sortByEdition
};

void showBook(book book, sortBy sortby = unsorted) {
    switch (sortby) {
    case unsorted:
        std::cout << book.title << " " << book.author << " " << book.edition << " " << book.price;
        break;

    case sortByTitle:
        std::cout << book.title << "\t\t\t" << book.author << "\t" << book.edition << "\t" << book.price;
        break;

    case sortByAuthor:
        std::cout << book.author << "\t\t\t" << book.title << "\t" << book.edition << "\t" << book.price;
        break;

    case sortByEdition:
        std::cout << book.edition << "\t\t\t" << book.title << "\t" << book.author << "\t" << book.price;
        break;

    default:
        break;
    }
}

void showAllBook(book* shop, int nBook, sortBy sortby = unsorted) {
    for (int i = 0; i < nBook; i++) {
        showBook(shop[i], sortby);
        std::cout << std::endl;
    }
}


void editBook(book& b) {
    std::cout << "Введите название: ";
    gets_s(b.title, 50);
    std::cout << "Введите автора: ";
    gets_s(b.author, 50);
    std::cout << "Введите жанр(ы): ";
    gets_s(b.edition, 50);
    std::cout << "Введите стоимость: ";
    std::cin >> b.price;
}


book searchBookByAuthor(book* shop, const int nBook, char* authorS) {
    char author[50];
    for (int i = 0; i < nBook; i++) {
        strcpy(author, shop[i].author);
        _strlwr(author);
        _strlwr(authorS);
        if (strstr(author, authorS)) {
            return shop[i];
        }
    }
}


book searchBookByTitle(book* shop, int nBook, char* titleS) {
    char title[50];
    for (int i = 0; i < nBook; i++) {
        strcpy(title, shop[i].title);
        _strlwr(title);
        _strlwr(titleS);
        if (strstr(title, titleS)) {
            return shop[i];
        }
    }
}


book* sortShopBy(book* shop, int nBook, sortBy sortby) {
    book tempBook;
    for (int i = 0; i < nBook; i++) {
        tempBook = shop[i];
        for (int j = i+1; j < nBook; j++) {

            switch (sortby) {
            case sortByTitle:
                if (strcmp(shop[i].title, shop[j].title) > 0) {
                    tempBook = shop[j];
                    shop[j] = shop[i];
                    shop[i] = tempBook;
                }
                break;

            case sortByAuthor:
                if (strcmp(shop[i].author, shop[j].author) > 0) {
                    tempBook = shop[j];
                    shop[j] = shop[i];
                    shop[i] = tempBook;
                }
                break;

            case sortByEdition:
                if (strcmp(shop[i].edition, shop[j].edition) > 0) {
                    tempBook = shop[j];
                    shop[j] = shop[i];
                    shop[i] = tempBook;
                }
                break;

            default:
                break;
            }

            
        }
    }
    return shop;
}


int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int nBook = 10;

    book shop[nBook] = { {"Мастер и Маргарита", "Михаил Булгаков", "Роман", 690},
                        {"Преступление и наказание", "Федор Михайлович Достоевский", "Роман", 720},
                        {"Маленький принц", "Антуан де Сент-Экзюпери", "Сказка, повесть", 440},
                        {"Собачье сердце", "Михаил Булгаков", "Повесть", 635},
                        {"Оно", "Стивен Кинг", "Ужасы, фэнтези, драма, детектив", 1050},
                        {"Над пропастью во ржи", "Джером Сэлинджер", "Роман", 1100},
                        {"Герой нашего времени", "Михаил Лермонтов", "Психологический роман", 565},
                        {"Приключения Шерлока Холмса", "Артур Конан Дойл", "Детектив", 1200},
                        {"Портрет Дориана Грея", "Оскар Уайльд", "Роман", 760},
                        {"Властелин колец", "Джон Рональд Руэл Толкин", "Роман", 1350}

    };



    showAllBook(shop, nBook);
    std::cout << std::endl;
    std::cout << std::endl;

    editBook(shop[7]);
    std::cout << std::endl;

    showAllBook(shop, nBook);
    std::cout << std::endl;
    std::cout << std::endl;

    char author[50] = "дост";
    showBook(searchBookByAuthor(shop, nBook, author));
    std::cout << std::endl;
    std::cout << std::endl;

    char title[50] = "мал";
    showBook(searchBookByTitle(shop, nBook, title));
    std::cout << std::endl;
    std::cout << std::endl;

    showAllBook(sortShopBy(shop,nBook, sortByTitle), nBook, sortByTitle);
    std::cout << std::endl;
    std::cout << std::endl;

    showAllBook(sortShopBy(shop, nBook, sortByAuthor), nBook, sortByAuthor);
    std::cout << std::endl;
    std::cout << std::endl;

    showAllBook(sortShopBy(shop, nBook, sortByEdition), nBook, sortByEdition);
    std::cout << std::endl;
    std::cout << std::endl;
	return 0;
}