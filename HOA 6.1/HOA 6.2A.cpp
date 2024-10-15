#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"
#include "searching.h"
using namespace std;

const int max_size = 50;

int main(){
	//generate random values
	int data[max_size];
	int n = sizeof(data) / sizeof(data[0]);
	int item;
	
	srand(time(0));
	for(int i = 0; i < max_size; i++){
		data[i] = rand();
	}
	
	//show your datasets content
	for(int i = 0; i < max_size; i++){
		std::cout << data[i] << " ";
	}
	
	cout << "\nEnter a number to search: ";
	cin >> item;
	linearSearch(data,n,item);
	return 0;
}
