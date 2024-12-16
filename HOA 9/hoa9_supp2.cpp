#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to insert a new node into the BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

// In-order traversal function
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << "-";
        inorder(root->right);
    }
}

// Pre-order traversal function
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << "-";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal function
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "-";
    }
}

void print(int arr[]){
	for (int i=0;i<8;i++)
	{cout<<arr[i]<<"-";
	}
}

int main() {
    // Initialize the root of the BST and insert values
    Node* root = NULL;
    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};
    for (int i = 0; i < 8; i++) {  // Use standard for loop in C++98 style
        root = insert(root, values[i]);
    }

    // Perform and display the traversals
     
    cout << "Initial tree: ";
	print(values);
	cout<<endl;
    
    
    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

