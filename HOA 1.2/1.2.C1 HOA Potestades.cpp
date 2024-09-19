#include <iostream>
using namespace std;

int main() {
	int x, y, store;
	cout << "Enter the first number: ";
	cin >> x;
	cout << "Enter the second number: ";
	cin >> y;
	
	//code to swap the numbers
	store = x; //store is used to hold onto the value of x
	x = y;
	y = store;
	
	cout << "After swapping" << endl;
	cout << "First number: " << x << endl;
	cout << "Second number: " << y << endl;
	
	return 0;
}

