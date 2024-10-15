#include <iostream>

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void insert(int data) {
        Node* newNode = new Node{data, head};
        head = newNode;
    }

    int countOccurrences(int key) {
        Node* current = head;
        int count = 0;
        while (current != NULL) {
            if (current->data == key) {
                count++;
            }
            current = current->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    for (int i = 0; i < 10; ++i) {
        list.insert(arr[i]);
    }

    int key = 18;
    int count = list.countOccurrences(key);
    std::cout << "Occurrences of " << key << " in linked list: " << count << std::endl;

    return 0;
}
