#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"

const int max_size = 50;

int main(){
	//generate random values
	int dataset[max_size];
	srand(time(0));
	for(int i = 0; i < max_size; i++){
		dataset[i] = rand();
	}
	//show your datasets content
	for(int i = 0; i < max_size; i++){
		std::cout << dataset[i] << " ";
	}
	//create linked list for linear search
	Node<char> *name1 = new_node('R');
	Node<char> *name2 = new_node('o');
	Node<char> *name3 = new_node('m');
	Node<char> *name4 = new_node('a');
	Node<char> *name5 = new_node('n');
	
	return 0;
}
