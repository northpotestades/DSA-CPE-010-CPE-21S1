#include <iostream>
using namespace std;
	
struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
public:
	Node*insert(Node* root, int val) {
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
	
	void inorderTransversal (Node* root) {
		if (root == NULL) return;
		
		inorderTransversal(root->left);
		cout << root->data << " ";
		inorderTransversal(root->right);
	}

	void preorder(Node*root)
	{
		if (root != NULL)
		{
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
		}
	}
	void postorder(Node*root)
	{
		if (root != NULL)
		{
			postorder(root->left);
			postorder(root->right);
			cout << root->data << " ";
		}
	}
};

int main() {
	Tree bst;
	Node* root = NULL;
	
	int values[] = {2,3,9,18,0,1,4};
	int numValues = sizeof(values) / sizeof(values[0]);
	
	
	for (int i = 0; i < numValues; ++i) {
		root = bst.insert(root, values[i]);
	}
	
	cout << "Inorder transversal of TREE: ";
	bst.inorderTransversal(root);
	cout << endl;
	
	cout << "Preorder traversal of TREE: ";
	bst.preorder(root);
	cout << endl;
	
	cout << "Postorder traversal of TREE: ";
	bst.postorder(root);
	cout << endl;
	
	return 0;
}


