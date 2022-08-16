// STEP _CPP _homework46 _12.08.22
/*
ООП

*/

#include <iostream>


struct Node {
    int val;
    Node* next;
    Node* prev;
};


class List2 {
    Node* head;
    Node* tail;
    int count;

public:
    List2();
    List2(const List2& obj);
    ~List2();
    int getCount();
    void addTail(int x);
    void delTail();
    void addHead(int x);
    void delHead();
    void del(int id);
    void delAll();
    void insert(int value, int id);
    void printHead();
    void printTail();
    void print(int id);

    List2& operator= (const List2& l);
    List2 operator+ (const List2& l);
    bool operator== (const List2& l);
    bool operator!= (const List2& l);
    bool operator< (const List2& l);
    bool operator> (const List2& l);
    bool operator<= (const List2& l);
    bool operator>= (const List2& l);
    List2 operator- ();

    Node& operator[] (int id);

};



int main()
{


    List2 l;
    for (int i = 0; i < 5; i++) {
        l.addTail(i);
    }
    l.printHead();
    std::cout << std::endl;

    l.printTail();
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        l.addHead(i);
    }
    l.printHead();
    std::cout << std::endl;

    l.printTail();
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        l.delHead();
    }
    l.printHead();
    std::cout << std::endl;


    for (int i = 0; i < 2; i++) {
        l.delTail();
    }
    l.printHead();
    std::cout << std::endl;

    l[2].val = 99;
    l.printHead();
    std::cout << std::endl;

    l.print(0);
    std::cout << std::endl;
    l.print(1);
    std::cout << std::endl;
    l.print(2);
    std::cout << std::endl;

    /*l.del(1);
    l.printHead();
    std::cout << std::endl;

    l.insert(88, 1);
    l.printHead();
    std::cout << std::endl;*/


    List2 l2;
    for (int i = 0; i < 5; i++) {
        l2.addTail(i*2);
    }
    l2.printHead();
    std::cout << std::endl;

    /*l2 = l;
    l2.printHead();
    std::cout << std::endl;*/

    List2 l3;
    l3 = l + l2;
    l3.printHead();
    std::cout << std::endl;
    l.printHead();
    std::cout << std::endl;

    //l.delTail();

    if (l == l2) {
        std::cout << "==";
    }
    else {
        std::cout << "!=";
    }
    std::cout << std::endl;
    l.printHead();
    std::cout << std::endl;
    l2.printHead();
    std::cout << std::endl;

    l = l2;

    if (l == l2) {
        std::cout << "==";
    }
    else {
        std::cout << "!=";
    }
    std::cout << std::endl;

    l.printHead();
    std::cout << std::endl;
    l2.printHead();
    std::cout << std::endl;

    (-l2).printHead();
    std::cout << std::endl;
    l2.printHead();
    std::cout << std::endl;

    l2.del(4);
    l2.del(2);
    l2.del(0);
    l2.printHead();
    std::cout << std::endl;

    l2.insert(55, 1);
    l2.insert(66, 1);
    l2.insert(77, 0);
    l2.printHead();
    std::cout << std::endl;

    return 0;

}

List2::List2(){
    head = nullptr;
    tail = nullptr;
    count = 0;
}

List2::List2(const List2& obj){
    head = nullptr;
    tail = nullptr;
    count = 0;
    Node* temp = obj.head;

    while (temp != nullptr) {
        addTail(temp->val);
        temp = temp->next;
    }
}

List2::~List2(){
    delAll();
}

int List2::getCount(){
    return count;
}


void List2::addHead(int x) {
    Node* temp = new Node;
    temp->val = x;
    temp->next = head;
    temp->prev = nullptr;

    if (tail == nullptr) {
        tail = temp;
    }
    else {
        head->prev = temp;
    }
    head = temp;
    count++;
}


void List2::addTail(int x){
    Node* temp = new Node;
    temp->val = x;
    temp->next = nullptr;
    temp->prev = tail;

    if (head == nullptr) {
        head = temp;
    }
    else {
        tail->next = temp;
    }
    tail = temp;
    count++;
}


void List2::delTail(){
    if (tail != nullptr) {
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        if (tail != nullptr) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        count--;
    }
}



void List2::delHead(){
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        count--;
    }
}


void List2::del(int id){
    if (id == 0) {
        delHead();
    }
    else if (id == count -1) {
        delTail();
    }
    else {

        Node* temp;

        if (id < count / 2) {
            temp = head;
            for (int i = 0; i < id; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail;
            for (int i = count - 1; i > id; i--) {
                temp = temp->prev;
            }
        }

        Node* NEXT = temp->next;
        Node* PREV = temp->prev;

        NEXT->prev = PREV;
        PREV->next = NEXT;

        delete[] temp;
        count--;
    }
}

void List2::delAll(){
    while (head != nullptr) {
        delTail();
    }
}


void List2::insert(int value, int id){
    if (id == 0) {
        addHead(value);
    }
    else if (id == count - 1) {
        addTail(value);
    }
    else {

        Node* temp;

        if (id < count / 2) {
            temp = head;
            for (int i = 0; i < id; i++) {
                temp = temp->next;
            }
        }
        else {
            temp = tail;
            for (int i = count - 1; i > id; i--) {
                temp = temp->prev;
            }
        }

        Node* NEXT = temp->next;
        Node* PREV = temp->prev;

        Node* newNode = new Node;
        newNode->val = value;
        newNode->next = temp;
        newNode->prev = PREV;
        PREV->next = newNode;
        temp->prev = newNode;

        count++;
    }
}


void List2::printHead(){
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}

void List2::printTail(){
    Node* temp = tail;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->prev;
    }
    //std::cout << head->val;
}


void List2::print(int id){

    Node* temp;
    if (id <= count/2) {
        temp = head;
        for (int i = 0; i < id; i++) {
            temp = temp->next;
        }
    }
    else {
        temp = tail;
        for (int i = count - 1; i > id; i--) {
            temp = temp->prev;
        }
    }
    std::cout << temp->val;
}

List2& List2::operator=(const List2& l)
{
    delAll();
    Node* temp;
    temp = l.head;
    while (temp != nullptr) {
        addTail(temp->val);
        temp = temp->next;
    }
    return *this;
}


List2 List2::operator+(const List2& l)
{

    List2 l2{ *this };
    //l2 = *this;

    Node* temp;
    temp = l.head;
    while (temp != nullptr) {
        l2.addTail(temp->val);
        temp = temp->next;
    }
    return l2;
}

bool List2::operator==(const List2& l)
{
    if (count == l.count) {
        Node* temp1 = head;
        Node* temp2 = l.head;
        while (temp1 != nullptr) {
            if (temp1->val != temp2->val) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }
    return false;
}

bool List2::operator!=(const List2& l)
{
    return !(*this == l);
}

bool List2::operator<(const List2& l)
{
    return count < l.count;
}

bool List2::operator>(const List2& l)
{
    return count > l.count;
}

bool List2::operator<=(const List2& l)
{
    return (*this < l || *this == l);
}

bool List2::operator>=(const List2& l)
{
    return (*this > l || *this == l);
}

List2 List2::operator-()
{
    List2 l2;
    /*l2.count = 0;
    l2.head = nullptr;
    l2.tail = nullptr;*/

    Node* temp;
    temp = head;
    while (temp != nullptr) {
        l2.addHead(temp->val);
        temp = temp->next;
    }
    return l2;
}




Node& List2::operator[](int id)
{
    Node* temp = head;
    int id_count = 0;
    while (temp != nullptr) {
        if (id_count == id) {
            return *temp;
        }
        id_count++;
        temp = temp->next;
    }
}


