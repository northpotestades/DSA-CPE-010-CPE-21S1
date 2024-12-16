#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    char value;
    vector<TreeNode*> children;

    TreeNode(char val) : value(val) {}
};

void addChild(TreeNode* parent, TreeNode* child) {
    parent->children.push_back(child);
}

void displayTree(TreeNode* node, int depth = 0) {
    for (int i = 0; i < depth; ++i) {
        cout << "  ";
    }
    cout << node->value << endl;

    for (auto child : node->children) {
        displayTree(child, depth + 1);
    }
}

void preOrderTraversal(TreeNode* node, char key) {
    if (node == nullptr) return;
    if (node->value == key) {
        cout << key << " was found!" << endl;
        return;
    }
    for (auto child : node->children) {
        preOrderTraversal(child, key);
    }
}

void postOrderTraversal(TreeNode* node, char key) {
    if (node == nullptr) return;
    for (auto child : node->children) {
        postOrderTraversal(child, key);
    }
    if (node->value == key) {
        cout << key << " was found!" << endl;
        return;
    }
}

void inOrderTraversal(TreeNode* node, char key) {
    if (node == nullptr) return;

    int n = node->children.size();

    if (n > 0) {
        inOrderTraversal(node->children[0], key);
    }

    if (node->value == key) {
        cout << key << " was found!" << endl;
        return;
    }

    for (int i = 1; i < n; ++i) {
        inOrderTraversal(node->children[i], key);
    }
}

void findData(TreeNode* root, char choice, char key) {
    if (choice == 'P' || choice == 'p') {
        preOrderTraversal(root, key);
    } else if (choice == 'O' || choice == 'o') {
        postOrderTraversal(root, key);
    } else if (choice == 'I' || choice == 'i') {
        inOrderTraversal(root, key);
    } else {
        cout << "Invalid choice!" << endl;
    }
}

int main() {
    TreeNode* root = new TreeNode('A');

    TreeNode* child1 = new TreeNode('B');
    TreeNode* child2 = new TreeNode('C');
    TreeNode* child3 = new TreeNode('D');
    TreeNode* child4 = new TreeNode('E');
    TreeNode* child5 = new TreeNode('F');
    TreeNode* child6 = new TreeNode('G');

    addChild(root, child1);
    addChild(root, child2);
    addChild(root, child3);
    addChild(root, child4);
    addChild(root, child5);
    addChild(root, child6);

    TreeNode* child3_1 = new TreeNode('H');
    TreeNode* child4_1 = new TreeNode('I');
    TreeNode* child4_2 = new TreeNode('J');
    TreeNode* child5_1 = new TreeNode('K');
    TreeNode* child5_2 = new TreeNode('L');
    TreeNode* child5_3 = new TreeNode('M');
    TreeNode* child6_1 = new TreeNode('N');

    addChild(child3, child3_1);
    addChild(child4, child4_1);
    addChild(child4, child4_2);
    addChild(child5, child5_1);
    addChild(child5, child5_2);
    addChild(child5, child5_3);
    addChild(child6, child6_1);

    TreeNode* child4_2_1 = new TreeNode('P');
    TreeNode* child4_2_2 = new TreeNode('Q');

    addChild(child4_2, child4_2_1);
    addChild(child4_2, child4_2_2);

    cout << "Tree structure:" << endl;
    displayTree(root);
    
	cout << "\nSearching for 'P' with Pre-order traversal:" << endl;
    findData(root, 'P', 'P');
    
    cout << "\nSearching for 'Q' with Post-order traversal:" << endl;
    findData(root, 'O', 'Q');
    
    cout << "\nSearching for 'F' with In-order traversal:" << endl;
    findData(root, 'I', 'F');

	TreeNode* child6_2 = new TreeNode('O');
	addChild(child6, child6_2);
	cout << "\nSearching for 'O' with In-order traversal:" << endl;
    findData(root, 'I', 'O');

    return 0;
}

