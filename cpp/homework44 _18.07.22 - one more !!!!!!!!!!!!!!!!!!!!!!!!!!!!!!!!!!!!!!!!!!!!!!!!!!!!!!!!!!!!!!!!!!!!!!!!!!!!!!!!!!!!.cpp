// STEP _CPP _homework44 _18.07.22 - one more
/*
ООП

*/

#include <iostream>


struct Node{
	int val;
	Node* next;
};


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
	int getCount();

	void print();


	//копирование
	//+ *

	friend List operator+(const List& obj1, const List& obj2);

	friend List operator*(const List& obj1, const List& obj2);



};

List::List(const List& obj) {
	Node* temp = obj.head;
	count = 0;
	while (temp != nullptr) {
		add(temp->val);
		temp = temp->next;
	}

}

List::List(){
	head = nullptr;
	tail = nullptr;
	count = 0;
}

List::~List(){
}

void List::add(int x){
}

void List::del(){
}

void List::delAll(){
}

int List::getCount(){
	return count;
}

void List::print(){
}

List operator+(const List& obj1, const List& obj2){
	return List();
}

List operator*(const List& obj1, const List& obj2){
	return List();
}
