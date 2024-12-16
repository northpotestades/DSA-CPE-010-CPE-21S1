#include <iostream>
using namespace std;

// Node structure for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinarySearchTree {
public:
    // Function to insert a new node into the BST
    Node* insert(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);  // Create a new node if tree/subtree is empty
        }

        if (val < root->data) {
            root->left = insert(root->left, val);  // Insert in the left subtree
        } else if (val > root->data) {
            root->right = insert(root->right, val);  // Insert in the right subtree
        }
        
        return root;  // Return the unchanged node pointer
    }

    // Inorder traversal of the BST (prints values in sorted order)
    void inorderTraversal(Node* root) {
        if (root == NULL) return;
        
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
};

int main() {
    BinarySearchTree bst;
    Node* root = NULL;

    // Values to be inserted
    int values[] = {2, 3, 9, 18, 0, 1, 4, 5};
    int numValues = sizeof(values) / sizeof(values[0]);

    // Insert each value into the BST
    for (int i = 0; i < numValues; ++i) {
        root = bst.insert(root, values[i]);
    }

    // Display the BST using Inorder traversal
    cout << "Inorder traversal of BST: ";
    bst.inorderTraversal(root);
    cout << endl;

    return 0;
}



