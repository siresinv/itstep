// STEP _CPP _homework51 _24.08.22
/*
ООП

Наследование


*/


#include <iostream>





class Transport {
protected:
    int velocity;
    int costTranspHuman_perKm;
    int costTranspGoods_perKm;
public:
    Transport(int uvelocity, int ucostTranspHuman_perKm, int ucostTranspGoods_perKm) : 
        velocity{ uvelocity }, costTranspHuman_perKm{ ucostTranspHuman_perKm }, costTranspGoods_perKm{ ucostTranspGoods_perKm }{};

    virtual void costTransp(int dist) {
        std::cout << "Time of transportation " << double(dist) / velocity << std::endl;
        std::cout << "Cost of transportation Human " << costTranspHuman_perKm * dist << std::endl;
        std::cout << "Cost of transportation Goods " << costTranspGoods_perKm * dist << std::endl;
        std::cout << std::endl;
    }
};

class Car : public Transport {
public:
    Car(int uvelocity, int ucostTranspHuman_perKm, int ucostTranspGoods_perKm) :
        Transport{ uvelocity, ucostTranspHuman_perKm, ucostTranspGoods_perKm } {};
};


class Bike : public Transport {
public:
    Bike(int uvelocity, int ucostTranspHuman_perKm, int ucostTranspGoods_perKm) :
        Transport{ uvelocity, ucostTranspHuman_perKm, ucostTranspGoods_perKm } {};
};


class Wagon : public Transport {
public:
    Wagon(int uvelocity, int ucostTranspHuman_perKm, int ucostTranspGoods_perKm) :
        Transport{ uvelocity, ucostTranspHuman_perKm, ucostTranspGoods_perKm } {};
};

int main()
{
    
    Transport* transp[3] = { new Car{60, 5, 10}, new Bike{20, 0, 0 }, new Wagon{30, 15, 20} };

    for (size_t i = 0; i < 3; i++) {
        transp[i]->costTransp(10);
    }


    return 0;
}