
#include <iostream>
#include <string>
#include <sstream>
#include "list.h"
using namespace std;

void LinkedList::Prepend(int data) {
	Node* newnode = new Node;
	newnode->data = data;
	if (head == NULL) {
		head = newnode;
		tail = newnode;
		newnode->nextnode=newnode->prev=NULL;
	}
	else {
		head->prev=newnode;
		newnode->nextnode=head;
		head=newnode;
		newnode->prev=NULL;
	}
}

void LinkedList::Append(int data) {
	Node* newnode = new Node;
	newnode->data = data;
	if (head == NULL) {
		head = newnode;
		tail = newnode;
		newnode->nextnode=newnode->prev=NULL;
	}
	else {
		tail->nextnode=newnode;
		newnode->prev=tail;
		tail=newnode;
		newnode->nextnode=NULL;
	}


}

int LinkedList::Length() {
	cout<<endl;
	int i = 0;

	while (1) {
		tail=tail->prev;
		i++;
		if(tail->prev==NULL){
		i++;
		break;
		}
	}
	return i;
	
}

void LinkedList::Print() {
	Node* printnode = new Node;
	printnode = head;
	while (head == tail) {
		cout << printnode->data << " ";
		head = printnode->nextnode;
		printnode->nextnode = printnode;
	}
}

void LinkedList::PrintReverse() {

	Node* tmp;
	tmp=tail;
	while (1) {
		cout << tail->data << " ";
		tail = tail->prev;
		if(tail->prev==NULL){
			cout<<tail->data<<" ";
			break;
		}
		
		
	}
	tail=tmp;
}



/*
int main(void) {
    LinkedList list;
    
    string numbers;
    int number;
    getline(cin, numbers);
    
    istringstream is(numbers);
    while (is >> number) {
        if (number % 2)
            list.Append(number);
        else
            list.Prepend(number);
    }
    
	
    list.PrintReverse();
    cout << list.Length() << endl;
    
    return 0;
}
*/