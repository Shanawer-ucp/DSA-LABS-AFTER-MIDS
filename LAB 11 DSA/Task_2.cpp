// Task 2 - Recursive Inorder and Preorder Traversal
// DSA Lab Week 11
// Tree Structure:
//         40
//        /  \
//      20    60
//     / \   / \
//   10  30 50  70

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);       // Visit left subtree
    cout << root->data << " "; // Print current node
    inorder(root->right);      // Visit right subtree
}

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " "; // Print current node
    preorder(root->left);      // Visit left subtree
    preorder(root->right);     // Visit right subtree
}

int main() {
    // Build the same tree as Task 1
    Node* root  = createNode(40);
    Node* n20   = createNode(20);
    Node* n60   = createNode(60);
    Node* n10   = createNode(10);
    Node* n30   = createNode(30);
    Node* n50   = createNode(50);
    Node* n70   = createNode(70);

    root->left  = n20;
    root->right = n60;
    n20->left   = n10;
    n20->right  = n30;
    n60->left   = n50;
    n60->right  = n70;

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
