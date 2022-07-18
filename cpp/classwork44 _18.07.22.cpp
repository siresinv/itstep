// STEP _CPP _classwork43 _15.07.22
/*
ООП

*/


#include <iostream>


struct Node {
    int val;
    Node* next;
};


//queue
class List {
    Node* head;
    Node* tail;
    int count;
public:
    List();
    ~List();
    void add(int x);
    void del();
    void delAll();
    void print();
    int getCount();


    List(const List& obj) {
        Node* temp = obj.head;
        count = 0;
        while (temp != nullptr) {
            add(temp->val);
            temp = temp->next;
        }

        
    }

    /*void operator+(const List& obj2) {
        Node* temp = obj2.head;
        while (temp != nullptr) {
            add(temp->val);
            temp = temp->next;
        }
    }*/


    friend List operator+(const List& obj1, const List& obj2);


};


void operator+(const List& obj1, const List& obj2) {
    Node* temp = obj1.head;
    count = 0;
    while (temp != nullptr) {
        add(temp->val);
        temp = temp->next;
    }

    Node* temp = obj2.head;
    while (temp != nullptr) {
        add(temp->val);
        temp = temp->next;
    }
}


List::List() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

List::~List() {
    delAll();
}




void List::add(int x) {
    Node* temp = new Node;
    temp->val = x;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
    }
    else {
        tail->next = temp;
    }
    tail = temp;
    count++;
}

void List::del() {
    Node* temp = head;
    head = head->next;
    delete temp;
    count--;
}

void List::delAll() {
    while (head != nullptr) {
        del();
    }
}

void List::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int List::getCount() {

    return count;
}



// Перегрузить + (объединить 2 списка) // И СВОИМ СПОСОБОМ СДЕЛАТЬ - копирование списков и тейл первого = хеад второго
// Перегрузить * (общие элементы обоих списков)


int main()
{


    List l1;
    for (int i = 0; i < 6; i++) {
        l1.add(i);
    }

    l1.print();
    l1.del();
    l1.print();
    std::cout << l1.getCount() << std::endl;

    List l2{ l1 };
    l2.print();
    std::cout << l2.getCount() << std::endl;

    //l1 + l2;
    //l1.print();
    //std::cout << l1.getCount() << std::endl;


    List l3 = l1 + l2;;
    //l1 + l2;
    l3.print();
    std::cout << l3.getCount() << std::endl;

    return 0;

}


/*

List operator+(const List& l1, const List& l2)
{
    List l11{ l1 };
    List l22{ l2 };
    l11.tail->next = l22.head;
    l11.tail = l22.tail;
    l11.Count += l22.Count;
    l11.Print();
    cout << l11.GetCount() << endl;
    return l11;
}

*/