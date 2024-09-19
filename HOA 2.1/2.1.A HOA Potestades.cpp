#include <iostream>
#include <string.h>

class Student{
private:
	std::string studentName;
	int studentAge;
public:
	//constructor
	Student(std::string newName ="John Doe", int newAge=18){
		studentName = std::move(newName);
		studentAge = newAge;
		std::cout << "Constructor Called." << std::endl;
	};
	//deconstructor
	~Student(){
		std::cout << "Destructor Called." << std::endl;
	}
	//Copy Constructor
	Student(const Student &copyStudent){
		std::cout << "Copy Constructor Called" << std::endl;
		studentName = copyStudent.studentName;
		studentAge = copyStudent.studentAge;
}
//Display Attributes
void printDetails(){
std::cout << this->studentName << " " << this->studentAge << std::endl;
}
};

int main() {
	const size_t j = 5;
	
	Student studentList[j] = {};
	std::string namesList[j] = {"Carly", "Freddy", "Sam", "Zack", "Cody"};
	int ageList[j] = {15, 16, 18, 19, 16};
	
	for(int i = 0; i < j; i++){ //loop A
	Student *ptr = new Student(namesList[i], ageList[i]);
	studentList[i] = *ptr;
	}
	
	for(int i = 0; i < j; i++){ //loop B
	studentList[i].printDetails();
	}
	
	return 0;
}
