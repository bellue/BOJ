//#pragma once
#include <iostream>
class Node {
public:
	int data;
	Node* nextnode;
	Node* prev;
};

class LinkedList {
public:
	Node* head=NULL;
	Node* tail=NULL;


	void Append(int data);
	void Prepend(int data);
	int Length();
	void Print();
	void PrintReverse();

};
