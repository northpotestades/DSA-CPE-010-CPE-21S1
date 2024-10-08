// C++ code to illustrate queue in Standard Template Library (STL)
#include <iostream>
#include <queue>
using namespace std;

void display(std::queue <string> q)
{
	std::queue <string> c = q;
	while (!c.empty())
	{
		std::cout << ", " << c.front();
		c.pop();
	}
	std::cout << "\n";
}

int main()
{
	std::queue <string> a;
	a.push("Lebron");
	a.push("Stephen");
	a.push("James");
	
	std::cout << "The queue of students is:";
	display(a);
	
	std::cout << "Are there no students? " << a.empty() << "\n";
	std::cout << "How many students are there? " << a.size() << "\n";
	std::cout << "Which student is at the front? " << a.front() << "\n";
	std::cout << "Which student is at the back? " << a.back() << "\n";
	
	std::cout << "After the student at the front leaves:";
	a.pop();
	display(a);
	
	a.push("Christian");
	std::cout << "The queue a is:";
	display(a);
	
	return 0;
}
