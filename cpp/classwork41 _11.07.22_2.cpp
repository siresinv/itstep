// STEP _CPP _classwork41 _11.07.22_2
/*
ООП НАЧАЛО


//String
//практика
//шаблоны
//динамические структуры стек, очередь

посмотреть КОДИРОВКИ
СТРИНГ


В ДОМАШКУ - ДОБИТЬ - БЕЗ УЧЕТА РЕГИСТРА

*/


#include <string>
#include <iostream>



int countAll(std::string where, std::string what) {
    int count = 0;
    int pos = where.find(what);
    while (pos != -1) {
        count++;
        pos = where.find(what, pos + 1);
    }
    return count;
}



int* findAll(std::string where, std::string what, int& count) {
    count = countAll(where, what);
    if (count == 0) {
        return nullptr;
    }
    else {
        int* array = new int[count];
        int pos = -1;
        for (int i = 0; i < count; i++) {
            pos = where.find(what, pos + 1);
            array[i] = pos;
        }
        return array;
    }
   
}


void display(int* items, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    
    char mas[20]{ "123" };
    char* mas2 = new char[10]{ "456" };

   

    /*if (mas == mas2) {

    }*/ // так нельзя

    std::string q1{ "Hello, World!" };

    std::cout << q1 << std::endl;

    std::string  q2( 10, '*' );
    std::cout << q2 << std::endl;

    char s1[]{ 'a', 'b', 'c', '\0', 'd', 'e' };
    std::string s2{ 'a', 'b', 'c', '\0', 'd', 'e' };
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;



    std::cout << s2.length() << std::endl;
    std::cout << s2.size() << std::endl;
    std::cout << s2[2] << std::endl;

    //std::cin >> s2;
    getline(std::cin, s2);
    std::cout << s2 << std::endl;

    std::cout << (s1 < s2) << std::endl;
    q2 = s2;
    q2 += s2;
    std::cout << q2 << std::endl;

    std::cout << q2.find("*bn") << std::endl;


    std::string q3{ "qwerty 1232345 dfghdfgh ewrtwert" };
    std::string q4;
    q4.append(q3, 2, 10);
    std::cout << q4 << std::endl;


   

    std::string word;
    std::string text{ "Jingle bells, jingle bells,\n\
            Jingle all the way.\n\
            Oh!what fun it is to ride\n\
            In a one - horse open sleigh.Hey!\n\
            Jingle bells, jingle bells,\n\
            Jingle all the way;\n\
            Oh!what fun it is to ride\n\
            In a one - horse open sleigh" };


    std::cout << "In text: \n\n" << text << std::endl;

    std::cout << "search word: ";
    std::cin >> word;

    int count;
    int* pos = findAll(text, word, count);
    display(pos, count);

    return 0;
}



