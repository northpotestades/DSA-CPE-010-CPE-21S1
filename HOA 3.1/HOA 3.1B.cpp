#include <iostream>
#include <utility>
using namespace std;

class Node{
public:
    string data;
    Node *next;
};

// Linked list traversal
void ListTraversal(Node *head) {
    while (head != NULL){
        cout << head->data << "\n";
        head = head->next;
    }
    cout << endl;
}

// Insert a node at the head
Node *InsertatHead(Node *head, string new_data){
    Node *new_node = new Node;
    new_node->data = new_data;
    new_node->next = head;
    return new_node;
}

// Insert a node at any location
Node *InsertatAnywhere(Node *head, string new_data, int pos){
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
Node *InsertatEnd(Node *head, string new_data){
    Node *new_node = new Node;
    if (head == NULL) {
        return new_node;
    }
    Node *last = head;
    new_node->data = new_data;
    new_node->next = NULL;
    while (last->next != NULL) {
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
    head->data = "We Cry Together";
    head->next = second;

    second->data = "LOVE. FEAT. ZACARI.";
    second->next = third;

    third->data = "FE!N (feat. Playboi Carti)";
    third->next = fourth;

    fourth->data = "Mirror";
    fourth->next = fifth;

    fifth->data = "Bound 2";
    fifth->next = last;

    // step 4
    last->data = "Doomsday";
    last->next = NULL;

    //listing out all of the songs
    ListTraversal(head);
    //adding a song at the start of the playlist
    string data = "durag activity (with Travis Scott)";
    head = InsertatHead(head, data);
    ListTraversal(head);
    //adding a song at position 4 in the playlist
    data = "WISHLIST [with Armani White]";
    int pos = 4;
    head = InsertatAnywhere(head, data, pos);
    ListTraversal(head);
    //adding a song at the end of the playlist
    data = "Oldie";
    head = InsertatEnd(head, data);
    ListTraversal(head);
    //deleting a song at position 2 in the playlist
    pos = 2;
    head = deleteNode(head,pos);
    ListTraversal(head);
  
    return 0;
}
