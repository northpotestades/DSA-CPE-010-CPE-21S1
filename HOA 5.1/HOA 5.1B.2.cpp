#include <iostream>
using namespace std;

template<typename T>
class Queue{
private:
	T *q_array;
    int q_capacity;
    int q_size;
    int q_front;
    int q_back;
public:
	//constructor
	Queue(int capacity) : q_capacity(capacity), q_size(0), q_front(0), q_back(-1) {
        q_array = new T[q_capacity]; }
	//empty
	bool isEmpty() const {
        return q_size == 0;
    }
    //full
    bool isFull() const {
        return q_size == q_capacity;
    }
	//size
	int size() const {
        return q_size;
    }
    //capacity
    int capacity() const {
        return q_capacity;
    }
	//front
	T front() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty. No front element.");
        }
        return q_array[q_front];
    }
	//back
	T back() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty. No back element.");
        }
        return q_array[q_back];
    }
	//enqueue
	void enqueue(T element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
            return;
        }
        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = element;
        q_size++;
    }
	//dequeue
	T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty. Cannot dequeue.");
        }
        T element = q_array[q_front];
        q_front = (q_front + 1) % q_capacity;
        q_size--;
        return element;
    }
	//destructor
	~Queue(){
		cout << "Deleting the array...";
		delete[] q_array;
	}
};

int main(){
    Queue<int> queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    queue.enqueue(6);

    cout << "Front element: " << queue.front() << endl;
    cout << "Back element: " << queue.back() << endl;

    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;

	cout << "Front element: " << queue.front() << endl;
    cout << "Back element: " << queue.back() << endl;

    cout << "Queue size after dequeuing: " << queue.size() << endl;

    return 0;
}
