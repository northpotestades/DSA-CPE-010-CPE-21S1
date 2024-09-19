#include <iostream>
using namespace std;

double KtoF(double K) {
	return ((K - 273.15) * 1.8) + 32;
}

int main() {
	double K, F;
	cout << "Enter temperature in Kelvin: ";
	cin >> K;
	
	F = KtoF(K);
	cout << K << "K is " << F << "F." << endl;
	
	return 0;
}
