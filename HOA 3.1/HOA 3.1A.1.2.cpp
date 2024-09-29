#include <iostream>
#include <utility>
using namespace std;

class Node{
public:
    char data;
    Node *next;
};

// Linked list traversal
void ListTraversal(Node *head) {
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert a node at the head
Node *InsertatHead(Node *head, char new_data) {
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = head;
    return new_node;
}

// Insert a node at any location
Node *InsertatAnywhere(Node *head, char new_data, int pos){
    if (pos < 1)
        return head;
    if (pos == 1){
        Node *new_node = new Node;
        new_node->data = new_data;
        new_node->next = head;
        return new_node;
    }
    Node *curr = head;
    for (int i = 1;i < pos - 1 && curr != NULL; i++){
        curr = curr->next;
    }
    if (curr == NULL) 
        return head;
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = curr->next;
    curr->next = new_node;
    return head;
}

// Insert a node at the end
Node *InsertatEnd(Node *head, char new_data){
    Node *new_node = new Node;
    if (head == NULL){
        return new_node;
    }
    Node *last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    while (last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return head;
}

// Delete a node from linked list
Node *deleteNode(Node* head, int pos){
	if (head == NULL || pos<1){
		cout << "Invalid position or list is empty." << endl;
	}
	if (pos == 1){
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	Node *current = head;
	for (int i = 1; i < pos - 1 && current != NULL; i++){
		current = current->next;
	}
	if (current == NULL || current->next == NULL){
		cout << "Position exceeds list length." << endl;
	}
	Node *temp = current->next;
	current->next = temp->next;
	delete temp;
	return head;
}

int main(){
	// step 1
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;
    Node *fifth = NULL;
    Node *last = NULL;

    // step 2
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;
    last = new Node;

    // step 3
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '0';
    fourth->next = fifth;

    fifth->data = '1';
    fifth->next = last;

    // step 4
    last->data = '0';
    last->next = NULL;

    //going through each function according to the instructions
    cout << "Traversal:" << endl;
    ListTraversal(head);
    
    cout << "Inserting G at head:" << endl;
    char data = 'G';
    head = InsertatHead(head, data);
    ListTraversal(head);
    
    cout << "Inserting E at position 4:" << endl;
    data = 'E';
    int pos = 4;
    head = InsertatAnywhere(head, data, pos);
    ListTraversal(head);
    
    cout << "Deleting C at position 2:" << endl;
    pos = 2;
    head = deleteNode(head,pos);
    ListTraversal(head);
    
    cout << "Deleting P at position 2:" << endl;
    pos = 2;
    head = deleteNode(head,pos);
    ListTraversal(head);
    
    cout << "Final product:" << endl;
    ListTraversal(head);
  
    return 0;
}
