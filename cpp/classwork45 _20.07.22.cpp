// STEP _CPP _classwork45 _20.07.22
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
    void insetr(int id);
    void printHead();
    void printTail();
    void print(int id);

};

// эти функции допилить  и операторы перегружать + * []

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

    l.printHead();
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        l.delHead();
    }
    l.printHead();
    std::cout << std::endl;


    for (int i = 0; i < 3; i++) {
        l.delTail();
    }
    l.printHead();
    std::cout << std::endl;

    //l.delTail();

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

}

void List2::delAll(){
    while (head != nullptr) {
        delTail();
    }
}

void List2::insetr(int id){

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

}
