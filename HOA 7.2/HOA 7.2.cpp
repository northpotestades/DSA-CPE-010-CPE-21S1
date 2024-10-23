#include <iostream>
#include <cstdlib>
#include <time.h>
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
	
	for(int i = 0; i < max_size; i++){
		std::cout << data[i] << " ";
	}
}
