// STEP _CPP _homework50 _22.08.22
/*
ООП

Наследование


*/


#include <iostream>


//-+-+-+-+ Car

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




//-+-+-+-+ Animal

/*
class Animal {
public:
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
*/

class Pet {
protected:
    std::string nickname;
    std::string breed;
    std::string hostName;
    int age;

public:
    Pet(std::string nic = "Bethoven", std::string br = "serbernar", std::string hN = "John", int age = 2) :
        nickname{ nic }, breed{ br }, hostName{ hN }, age{ age }{};


    void eat() {};
    void drink() {};
    void sleep() {};

    void print_p() {
        //std::cout << "This is a typical pet: " << std::endl;
        std::cout << "Nickname: " << nickname << std::endl;
        std::cout << "Breed: " << breed << std::endl;
        std::cout << "Hostname: " << hostName << std::endl;
        std::cout << "Pet age: " << age << std::endl;
    }
};


class Dog : public Pet {
    bool trained;
    int nCommand;
public:
    Dog(std::string nic = "Bethoven", std::string br = "serbernar", std::string hN = "John", int age = 2, bool train = false, int nCom = 0) :
        Pet{nic, br, hN, age}, trained{ train }, nCommand{ ((trained) ? nCom : 0) }{};

    void print() {
        std::cout << "A DOG" << std::endl;
        print_p();
        std::cout << ((trained) ? "trained" : "not trained") << std::endl;
        std::cout << "Known command amount: " << nCommand << std::endl;
        std::cout << std::endl;
    }
};


class Cat : public Pet {
    int sleepHours;
public:
    Cat(std::string nic = "Tom", std::string br = "russian blue", std::string hN = "John", int age = 2, int sH = 18) :
        Pet{ nic, br, hN, age }, sleepHours{ sH }{};

    void print() {
        std::cout << "A CAT" << std::endl;
        print_p();
        std::cout << "Sleep hours by day: " << sleepHours << std::endl;
        std::cout << std::endl;
    }
};

int main()
{

    Car car1{ 16, 113, "type1" };
    car1.print();
    std::cout << std::endl;
    Car car2{ 21, 500, "type2", "BMW", "crossover", "black"};
    car2.print();
    std::cout << std::endl;


    Dog dog1;
    dog1.print();

    Dog dog2("Balto", "siberian husky","Gan", 5, true, 10);
    dog2.print();

    Cat cat1;
    cat1.print();

    Cat cat2("Bob", "street");
    cat2.print();

    return 0;
}


/* НА ДОМ
Задание №1
Используя механизм множественного наследования разработайте класс “Автомобиль”. Должны быть классы “Колеса», «Двигатель», «Двери» и т.д.

Задание 2
Животные

*/
