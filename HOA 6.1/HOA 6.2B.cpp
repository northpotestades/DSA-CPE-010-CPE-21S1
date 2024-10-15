#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"
#include "searching.h"
using namespace std;

int main(){
	//create linked list for linear search
	Node<char> *name1 = new_node('R');
	Node<char> *name2 = new_node('o');
	Node<char> *name3 = new_node('m');
	Node<char> *name4 = new_node('a');
	Node<char> *name5 = new_node('n');
	
	//linked list
	name1->next = name2;
	name2->next = name3;
	name3->next = name4;
	name4->next = name5;
	name5->next = NULL;
	
	//linear search
	char item;
	cout << "Enter a letter to search: ";
	cin >> item;
	linearLS(name1, item);
	return 0;
}
