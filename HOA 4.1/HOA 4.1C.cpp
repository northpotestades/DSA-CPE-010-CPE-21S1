#include <stack>
#include <string>
#include <iostream>

bool isMatching(char opening, char closing) {
	if (opening == '(' && closing == ')') return true;
	if (opening == '{' && closing == '}') return true;
	if (opening == '[' && closing == ']') return true;
	return false;
}

bool isBalanced(std::string expression) {
	std::stack<char> s;
	for (char c : expression) {
		if (c == '(' || c == '{' || c == '[') {
			s.push(c);
		} else if (c == ')' || c == '}' || c == ']') {
			if (s.empty()) {
				std::cout << "Error: Closing symbol without matching opening symbol" << std::endl;
				return false;
			}
			char opening = s.top();
			s.pop();
			if (!isMatching(opening, c)) {
				std::cout << "Error: Mismatched symbols" << std::endl;
				return false;
			}
		}
	}
	if (!s.empty()) {
		std::cout << "Error: Unbalanced expression" << std::endl;
		return false;
	}
	return true;
}

int main() {
	std::string expression;
	std::cout << "Enter an expression: ";
	std::getline(std::cin, expression);
	if (isBalanced(expression)) {
		std::cout << "Expression is balanced" << std::endl;
	}
	return 0;
}
