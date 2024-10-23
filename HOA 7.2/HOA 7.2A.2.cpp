#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"
using namespace std;

const int max_size = 100;

int main(){
	int data[max_size];
	int n = sizeof(data) / sizeof(data[0]);
	int item;
	
	srand(time(0));
	for(int i = 0; i < max_size; i++){
		data[i] = rand();
	}
	
	cout << "Before sorting:" << endl;
	for(int i = 0; i < max_size; i++){
		std::cout << data[i] << " ";
	}
	
	cout << "\nAfter sorting:" << endl;
	mergeSort(data, 0, n - 1);
	for(int i = 0; i < max_size; i++){
		std::cout << data[i] << " ";
	}
	return 0;
}
