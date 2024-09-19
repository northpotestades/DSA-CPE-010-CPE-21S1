#include <iostream>
#include <string>

int main() {
	std::string groceryList[5][3] = {
		{"Jennas_Grocery_List", "", ""},
		{"Apple", "PHP 10", "7x"},
		{"Banana", "PHP 10", "8x"},
		{"Broccoli", "PHP 60", "12x"},
		{"Lettuce", "PHP 50", "10x"}
	};

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << groceryList[i][j] << " ";
	}
	std::cout << std::endl;
	}

	return 0;
}
