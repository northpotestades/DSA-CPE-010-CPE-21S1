#include <iostream>
using namespace std;

//function prototypes
void displaySum(int a, int b);
bool isGreater(int a, int b);
bool logicalOperations(bool x, bool y);

//driver program
int main() {
	int num1 = 10, num2 = 20;
	bool bool0 = false, bool1 = true;

	//using the functions
	displaySum(num1, num2); //using the function to display the sum of two numbers
	if (isGreater(num1, num2)) { //using the function to check if a number is greater than the second
		cout << "Variable A is greater than Variable B." << endl;
	} else {
		cout << "Variable A is not greater than Variable B." << endl;
	}
	if (logicalOperations(bool0, bool1)) { //using the function to perform logical operations
		cout << "Logical operations completed successfully." << endl;
	}
	return 0;
}

//functions defined

//function that displays the sum of two numbers
void displaySum(int a, int b) {
	int sum = a + b;
	cout << "The sum of " << a << " and " << b << " is: " << sum << endl;
}

//function that checks if the first number is greater than the second number
bool isGreater(int a, int b) {
	return a > b;
}

//function that performs logical operations on two given boolean values
bool logicalOperations(bool x, bool y) {
	cout << "Logical AND of x and y: " << (x && y) << endl;
	cout << "Logical OR of x and y: " << (x || y) << endl;
	cout << "Logical NOT of x: " << (!x) << endl;
	cout << "Logical NOT of y: " << (!y) << endl;
	return true;
}
