#include <iostream>
#include <cmath>
using namespace std; //added cmath for math functions and using namespace std

//step 2
class Triangle{
private:
	double totalAngle, angleA, angleB, angleC;
	double sideA, sideB, sideC; //added sides of the triangle
public:
	//step 3
	Triangle(double A, double B, double C);
	Triangle(double A, double B, double C, double sideA, double sideB, double sideC); //constructor for triangle with sides
	void setAngles(double A, double B, double C);
	const bool validateTriangle();
	double area(); //method that calculates the area of the triangle
	double perimeter(); //method that calculates the perimeter of the triangle
	const string triangleType(); //method that determines the kind of triangle
};

//step 4
//constructor that initializes angles and computes the totalAngle
Triangle::Triangle(double A, double B, double C) {
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
}

//constructor that initializes angles, sides and computes the totalAngle
Triangle::Triangle(double A, double B, double C, double asideA, double bsideB, double csideC) {
	angleA = A;
	angleB = B;
	angleC = C;
	sideA = asideA;
	sideB = bsideB;
	sideC = csideC;
	totalAngle = A+B+C;
}

//method that sets new values for the angles and updates the totalAngle
void Triangle::setAngles(double A, double B, double C) {
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
}

//method that sets checks if the total angle is 180, making it a valid triangle
const bool Triangle::validateTriangle() {
	return (totalAngle <= 180);
}

//method that computes the area of a triangle
double Triangle::area() {
	if (!validateTriangle()) return 0;
	double s = perimeter() / 2;
	return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

//method that computes the perimeter of a triangle
double Triangle::perimeter() {
	return sideA + sideB + sideC;
}

//method that determines what type of triangle it is
const string Triangle::triangleType() {
	if (angleA < 90 && angleB < 90 && angleC < 90)
		return "Acute";
	else if (angleA > 90 || angleB > 90 || angleC > 90)
		return "Obtuse";
	else
		return "Other";
}


//step 5
int main(){
	//creates a Triangle object with a set of angles and sides
	Triangle set1(40, 30, 110, 5, 6, 7);
	if (set1.validateTriangle()) {
		cout << "The shape is a valid triangle.\n";
		cout << "Area: " << set1.area() << "\n";
		cout << "Perimeter: " << set1.perimeter() << "\n";
		cout << "Type: " << set1.triangleType() << "\n";
	} else {
		cout << "The shape is NOT a valid triangle.\n";
	}

	return 0;
}
