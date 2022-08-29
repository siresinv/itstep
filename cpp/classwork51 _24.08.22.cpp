// STEP _CPP _classwork51 _24.08.22
/*
ООП

Наследование


*/


#include <iostream>


// A -> B -> C



/*

class A { //animal
public:
    virtual void test() { // динамический полиморфизм
        std::cout << "obj A\n";
    }

    void print() { // статический полиморфизм
        std::cout << "obj A\n";
    }
};

class B: public A { //pet
public:
    virtual void test() {
        std::cout << "obj B\n";
    }

    void print() {
        std::cout << "obj A\n";
    }
};

class C: public B { //cow
public:
    virtual void test() {
        std::cout << "obj C\n";
    }

    void print() {
        std::cout << "obj A\n";
    }
};


class x { // если в классе есть хотя бы одна чисто виртуальная функция, то класс - АБСТРАКТНЫЙ
public:
    virtual void func() = 0; // чисто виртуальная функция // 0 - чистый спецификатор
};

*/

class Animal {
protected:
    char nickname[20];

public:
    Animal(const char* uname) {
        strcpy_s(nickname, 20, uname);
    }

    virtual void speak() = 0;
};

class Dog: public Animal{
public:
    Dog(const char* uname): Animal{uname}{};
    virtual void speak() {
        std::cout << nickname << " say gav-gav\n";
    }
};

class Duck : public Animal {
public:
    Duck(const char* uname) : Animal{ uname } {};
    virtual void speak() {
        std::cout << nickname << " say krya-krya\n";
    }
};

class Cat : public Animal {
public:
    Cat(const char* uname) : Animal{ uname } {};
    virtual void speak() {
        std::cout << nickname << " say meow-meow\n";
    }
};


class Lion : public Cat {
public:
    Lion(const char* uname) : Cat{ uname } {};

    virtual void speak(/*int t*/) {
        std::cout << nickname << " say R-R-R-R\n";
    }
};


/*
class Base {
protected:
    int val;
};

class Child1 : public virtual Base {

};

class Child2 : public virtual Base {

};

class Child3 : public Child1, public Child2 {
    int getVal() {
        return val;
        // return Child1::val;
    }
};
*/


class Base {
    char* str1;
    //int size;

public:
    Base(const char* s) :str1{ new char[strlen(s) + 1] } {
        strcpy_s(str1, strlen(s) + 1, s);
    }

    virtual ~Base()
    {
        delete[]str1;
        std::cout << "Base\n";
    }

};


class DoubleString : public Base {
    char* str2;
public:
    DoubleString(const char* s1, const char* s2) :Base{ s1 }, str2{ new char[strlen(s2) + 1] } {
        strcpy_s(str2, strlen(s2) + 1, s2);
    }

    virtual ~DoubleString()
    {
        delete[]str2;
        std::cout << "DoubleString\n";
    }

};



/////////////////////////////////////////////////////////////////////////////////////////////////////

class Employer {
protected:
    char* name;
public:
    Employer(const char* uname): name{new char[strlen(uname)+1]} {
        strcpy_s(name, strlen(uname) + 1, uname);
    }
    virtual void print() = 0;
    virtual ~Employer() { 
        // здесь !!!нужен!!! виртуальный деструктор т.к. чтобы он по указателям в массиве в мейне
        // динамичски проходился по деструкторам объектов созданный с помощью NEW
        std::cout << "delete employer " << name << "\n";

        delete[] name;
    };
};


class Worker : public Employer {
private:
    char* stageName;
public:
    Worker(const char* uname, const char* ustageName) :Employer{ uname }, stageName{ new char[strlen(ustageName) + 1] }{
        strcpy_s(stageName, strlen(ustageName) + 1, ustageName);
    }

    virtual void print() {
        std::cout << "I am a worker " << name << " " << stageName << "\n";
    }

    virtual ~Worker() {
        std::cout << "delete worker " << name << " " << stageName << "\n";
        delete[] stageName;
    }
};


class Manager : public Employer {
private:
    char* stageName;
public:
    Manager(const char* uname, const char* ustageName) :Employer{ uname }, stageName{ new char[strlen(ustageName) + 1] }{
        strcpy_s(stageName, strlen(ustageName) + 1, ustageName);
    }

    virtual void print() {
        std::cout << "I am a Manager " << name << " " << stageName << "\n";
    }

    virtual ~Manager() {
        std::cout << "delete manager " << name << " " << stageName << "\n";
        delete[] stageName;
    }
};


int main()
{
    /*
    A obj_A;
    B obj_B;
    C obj_C;


    A* ptr;
    ptr = &obj_A; // всегда методы объекта A //obj_A.print();
    ptr->print();
    ptr = &obj_B;
    ptr->print();
    ptr = &obj_C;
    ptr->print();

    ptr = &obj_A; // виртуальная функция вызывается динамически
    ptr->test();
    ptr = &obj_B;
    ptr->test();
    ptr = &obj_C;
    ptr->test();
    */


    /*B* ptr2;
    ptr2 = &obj_A;
    ptr2 = &obj_B;
    ptr2 = &obj_C;


    C* ptr3;
    ptr3 = &obj_A;
    ptr3 = &obj_B;
    ptr3 = &obj_C;*/


    /*Animal* animals[4] = { new Duck{"Donald"}, new Dog{"Rex"}, new Cat{"Tom"}, new Lion{"Simba"}};
    for (int i = 0; i < 4; i++) {
        animals[i]->speak();
    }*/


    //DoubleString ds1{ "s1", "s2" };
    /*
    Base* b1 = new DoubleString{ "s1", "s2" };
    delete b1;
    */


    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // ПРОВЕРИТЬ РАБОТУ ДЕСТРУКТОРОВ !!!

    Employer* employers[3] = {new Worker{"vJohn", "SuperWorker"}, new Worker{"vJohn2", "SuperWorker2"}, new Manager{ "vJohn4", "SuperWorker4" } };
    employers[0]->print();
    employers[1]->print();
    employers[2]->print();
    delete employers[0];
    delete employers[1];
    delete employers[2];

    Employer* emp3 = new Manager{ "vJohn3", "SuperWorker3" };
    emp3->print();
    delete emp3;

    Manager m1("Manager1", "SuperManager");
    m1.print();

    return 0;
}


/*
Создать абстрактный базовый класс Employer (служащий)
с чисто виртуальной функцией Print().
Создайте три производных класса: President, Manager,
Worker. Переопределите функцию Print() для вывода
информации, соответствующей каждому типу служащего.
*/