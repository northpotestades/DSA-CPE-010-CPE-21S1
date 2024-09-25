#include <iostream>
#include <queue>
using namespace std;

void display(queue <string> pl)
{
    while(!pl.empty())
    {
        cout<<pl.front()<<"\n";
        pl.pop();
    }
}

int main() {
    queue <string> pl;
    //add items into queue
    pl.push("C++");
    pl.push("Java");
    pl.push("Python");
    cout<<"Initial queue: ";
    display(pl);

    pl.pop();
    pl.pop();
    cout<<"Final queue: ";
    display(pl);
    return 0;
}