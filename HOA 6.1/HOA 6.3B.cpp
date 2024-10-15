#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "nodes.h"
#include "searching.h"
using namespace std;

int main(){
	char choice = 'y'; int count = 1; int newData;
	Node<int> *temp, *head, *node;
	
	while(choice=='y'){
		std::cout << "Enter data: ";
		std::cin >> newData;
		
		if(count==1){
			head = new_node(newData);
			std::cout << "Successfully added " << head->data << " to the list.\n";
			count++;
		} else if(count==2) {
			node = new_node(newData);
			head->next = node;
			node->next = NULL;
			std::cout << "Successfully added " << node->data << " to the list.\n";
			count++;
		} else {
			temp = head;
			while(true){
				if(temp->next == NULL) break;
				temp = temp->next;
			}
			node = new_node(newData);
			temp->next = node;
			std::cout << "Successfully added " << node->data << " to the list.\n";
			count++;
		}
		std::cout << "Continue? (y/n): ";
		std::cin >> choice;
		if(choice=='n') break;
	}
	
	int dataFind;
	cout << "Enter a number to search: ";
	cin >> dataFind;
    binaryLS(head, dataFind);
    
    return 0;
}
