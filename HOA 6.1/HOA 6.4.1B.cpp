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

    int sequentialSearch(int key) {
        Node* current = head;
        int comparisons = 0;
        while (current != NULL) {
            comparisons++;
            if (current->data == key) {
                return comparisons; // Return number of comparisons when found
            }
            current = current->next;
        }
        return comparisons; // Return total comparisons if not found
    }
};

int main() {
    LinkedList list;
    int arr[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    for (int i = 0; i < 10; ++i) {
        list.insert(arr[i]);
    }

    int key = 18;
    int comparisons = list.sequentialSearch(key);
    std::cout << "Comparisons in linked list search for key " << key << ": " << comparisons << std::endl;

    return 0;
}
