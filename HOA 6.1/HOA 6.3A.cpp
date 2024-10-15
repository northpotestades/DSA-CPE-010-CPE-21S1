#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"
#include "searching.h"
using namespace std;

const int max_size = 50;

int main(){
	//generate random values
	int data[] = {3, 5, 7, 9, 11, 13};
	int n = sizeof(data) / sizeof(data[0]);
	int item;

	for(int i = 0; i < n; i++){
		std::cout << data[i] << " ";
	}
	
	cout << "\nEnter a number to search: ";
	cin >> item;
	binarySearch(data,n,item);
	return 0;
}
