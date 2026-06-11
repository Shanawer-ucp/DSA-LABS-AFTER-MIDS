// Task 1 - Binary Tree Implementation Using Linked Representation
// DSA Lab Week 11
// Tree Structure:
//         40
//        /  \
//      20    60
//     / \   / \
//   10  30 50  70

#include <iostream>
using namespace std;

// Node structure with data, left, and right pointers
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to print all leaf nodes (nodes with no children)
void printLeafNodes(Node* root) {
    if (root == nullptr)
        return;

    // If both children are NULL, it is a leaf node
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }

    // Recursively check left and right subtrees
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

int main() {
    // Create all seven nodes manually
    Node* root  = createNode(40);
    Node* n20   = createNode(20);
    Node* n60   = createNode(60);
    Node* n10   = createNode(10);
    Node* n30   = createNode(30);
    Node* n50   = createNode(50);
    Node* n70   = createNode(70);

    // Link nodes according to the diagram
    root->left  = n20;
    root->right = n60;
    n20->left   = n10;
    n20->right  = n30;
    n60->left   = n50;
    n60->right  = n70;

    // Print root node value
    cout << "Root Node: " << root->data << endl;

    // Print left and right child of root
    cout << "Left Child of Root: " << root->left->data << endl;
    cout << "Right Child of Root: " << root->right->data << endl;

    // Print all leaf nodes
    cout << "Leaf Nodes: ";
    printLeafNodes(root);
    cout << endl;

    return 0;
}
