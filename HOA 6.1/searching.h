#include <iostream>
using namespace std;

void linearSearch(int data[], int n, int item){
	for (int i = 0; i < n; i++) {
		if (item == data[i]) {
			cout << "Searching is successful." << endl;
			return;
		}
	}
	cout << "Searching is unsuccessful." << endl;
	return;
}

void linearLS(Node<char>* head, char dataFind) {
    Node<char> *curr = head;
    int index = 0;
    while (curr != NULL) {
        if (curr->data == dataFind) {
            cout << "Searching is successful." << endl;
            return;
        }
        curr = curr->next;
        index++;
    }
    cout << "Searching is unsuccessful." << endl;
    return;
}

void binarySearch(int arr[], int size, int target) {
	int left = 0;
	int right = size - 1;	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		
		if (arr[mid] == target) {
			cout << "Searching is successful at position " << mid << "." << endl;
			return;
		}
		if (arr[mid] < target) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	cout << "Searching is unsuccessful." << endl;
	return;
}

Node<int> *middle(Node<int> *start, Node<int> *last) {
    if (start == NULL) {
        return NULL;
    }
    if (start == last)
        return start;
    Node<int> *slow = start;
    Node<int> *fast = start->next;
    while (fast != last) {
        fast = fast->next;
        slow = slow->next;
        if (fast != last) {
            fast = fast->next;
        }
    }
    return slow;
}

void binaryLS(Node<int> *head, int dataFind){
	Node<int> *start = head;
    Node<int> *last = NULL;
    while (true) {
        Node<int> *mid = middle(start, last);
        if (mid == NULL) {
            cout << "Searching is unsuccessful." << endl;
			    return;
        }
        if (mid->data == dataFind) {
            cout << "Searching is successful." << endl;
            return;
    	}
        else if (start == last)
            break;
        else if (mid->data < dataFind) {
            start = mid->next;
        }
        else if (mid->data > dataFind)
            last = mid;
    }
    cout << "Searching is unsuccessful." << endl;
    return;
}
