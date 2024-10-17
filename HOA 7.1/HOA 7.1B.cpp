#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"
using namespace std;

const int max_size = 100;

int countVotes(int arr[], int size, int cand){
	int count = 0;
	for (int i = 0; i < size; i++){
		if (arr[i] == cand){
			count++;
		}
	}
	return count;
}

int main(){
	int data[max_size];
	int n = sizeof(data) / sizeof(data[0]);
	int cand;
	
	srand(time(0));
	for(int i = 0; i < max_size; i++){
		data[i] = rand() % (5) + 1;
	}
	
	cout << "Before sorting:" << endl;
	for(int i = 0; i < max_size; i++){
		std::cout << data[i] << " ";
	}
	
	cout << "\nAfter sorting:" << endl;
	insertionSort(data, n);
	for(int i = 0; i < max_size; i++){
		std::cout << data[i] << " ";
	}
	
	cand = 1;
	int count1 = countVotes(data, n, cand);
    std::cout << "\n\nCandidate Bo Dalton Capistrano received: " << count1 << " votes.\n " << std::endl;
    cand = 2;
	int count2 = countVotes(data, n, cand);
    std::cout << "Candidate Cornelius Raymon Agustin received: " << count2 << " votes.\n " << std::endl;
    cand = 3;
	int count3 = countVotes(data, n, cand);
    std::cout << "Candidate Deja Jayla Banaga received: " << count3 << " votes.\n " << std::endl;
    cand = 4;
	int count4 = countVotes(data, n, cand);
    std::cout << "Candidate Lalla Brielle Yabut received: " << count4 << " votes.\n " << std::endl;
    cand = 5;
	int count5 = countVotes(data, n, cand);
    std::cout << "Candidate Franklin Relano Castro received: " << count5 << " votes.\n " << std::endl;
	if(count1>count2&&count1>count3&&count1>count4&&count1>count5){
		cout << "Bo Dalton Capistrano has won with " << count1 << " votes!";
	} else if(count2>count1&&count2>count3&&count2>count4&&count2>count5){
		cout << "Cornelius Raymon Agustin has won with " << count2 << " votes!";
	} else if(count3>count1&&count3>count2&&count3>count4&&count3>count5){
		cout << "Deja Jayla Banaga has won with " << count3 << " votes!";
	} else if(count4>count1&&count4>count2&&count4>count3&&count4>count5){
		cout << "Lalla Brielle Yabut has won with " << count4 << " votes!";
	} else if(count5>count1&&count5>count2&&count5>count3&&count5>count4){
		cout << "Franklin Relano Castro has won with " << count5 << " votes!";
	} else {
		cout << "There is a tie!";
	}
	
	return 0;
}
