// STEP _CPP _classwork50 _22.08.22
/*
ООП

Наследование


*/


#include <iostream>


class Wheel {
protected:
    int radius;
public:
    Wheel(int r = 16) :radius{ r } {};
    void print_w() {
        std::cout << "whell radius: " << radius;
    }
};


class Engine {
protected:
    int power;
public:
    Engine(int pw = 113) :power{ pw } {};
    void print_e() {
        std::cout << "engine power: " << power;
    }
};


class Door {
protected:
    std::string typeDoor;
public:
    Door(std::string tp = "type1") :typeDoor{ tp } {};

    void print_d() {
        std::cout << "door type: " << typeDoor;
    }
};


class Car :public Wheel, public Engine, public Door {
    std::string brand;
    std::string body;
    std::string color;
    int nWhell;
    int nDoor;
public:
    Car(int r, int pw, std::string tp, std::string br = "renault", std::string bd = "sedan", std::string col = "white", int nW = 4, int nD = 4) :
        Wheel{r}, Engine{pw}, Door{tp}, brand{ br }, body{ bd }, color{ col }, nWhell{ nW }, nDoor{ nD }{};

    void print() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Body: " << body << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Whell amount: " << nWhell << std::endl;
        std::cout << "Door amount: " << nDoor << std::endl;
        std::cout << "Whell radius: " << radius << std::endl;
        std::cout << "Engine power: " << power << std::endl;
        std::cout << "Door type: " << typeDoor << std::endl;
    }
};


//-+-+-+-+

class Animal {
protected:
    std::string classAnimal; // класс // млекопит птицы
    std::string group; // отряд // хищные попугаеобразные
    std::string family; // семейство // кошачьи псовые попугаевые
    std::string species; // вид // собака кошка попугай

public:
    Animal(std::string cl = "mammal", std::string gr = "predator", std::string fam = "cat", std::string spec = "cat") :
        classAnimal{ cl }, group{ gr }, family{ fam }, species{ spec } {};

    void eat() {};
    void drink() {};
    void sleep() {};

    void print_a() {
        std::cout << "This is a typical animal: " << std::endl;
        std::cout << ": " << classAnimal << std::endl;
        std::cout << ": " << classAnimal << std::endl;
        std::cout << ": " << classAnimal << std::endl;
        std::cout << ": " << classAnimal << std::endl;
    }
};


class Pet :public Animal {
protected:
    std::string nickname;
    std::string breed;
    std::string hostName;
    int age;

public:
    //Pet()
    void print() {
        std::cout << "This is a typical pet: " << std::endl;
        //
        //
    }
};


class Dog : public Pet, public Animal { ////////////////////////
    bool trained;
    int nCommand; //
public:
    ///////////////////////////////////////////////////////////////////////////////
    Dog(bool train = false, int nCom = 0) :
        Pet{}, Animal{}, trained{ train }, nCommand{ nCom }{};

    void print() {

    }
};

int main()
{

    /*Car car1{ 16, 113, "type1" };
    car1.print();
    std::cout << std::endl;
    Car car2{ 21, 500, "type2", "BMW", "crossover", "black"};
    car2.print();
    std::cout << std::endl;*/





    return 0;
}


/* НА ДОМ
Задание №1
Используя механизм множественного наследования разработайте класс “Автомобиль”. Должны быть классы “Колеса», «Двигатель», «Двери» и т.д.

Задание 2
Животные

*/
