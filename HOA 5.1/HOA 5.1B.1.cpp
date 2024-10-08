#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
};

Node *head=NULL, *tail=NULL;
	
void insertNonEmpty(int newData){
	Node *newNode = new Node;
	newNode->data = newData;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}

void insertEmpty(int newData){
	Node *newNode = new Node;
	newNode->data = newData;
	head = tail = newNode;
}

void deleteFront(){
	Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void deleteOne(){
	Node *temp = head;
    head = NULL;
    tail = NULL;
    delete temp;
}

int main(){
	cout << "Inserting into an empty queue." << endl;
	insertEmpty(5);
	cout << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
	cout << "Inserting into a non-empty queue." << endl;
	insertNonEmpty(3);
	cout << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
	cout << "Inserting into a non-empty queue. (2x)" << endl;
	insertNonEmpty(7);
	cout << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
	cout << "Deleting the front of the queue." << endl;
	deleteFront();
	cout << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
	cout << "Deleting the front of the queue. (2x)" << endl;
	deleteFront();
	cout << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
	cout << "Deleting queue with one element." << endl;
	deleteOne();
	cout << "Head: " << head->data << endl;
	cout << "Tail: " << tail->data << endl;
	return 0;
}
