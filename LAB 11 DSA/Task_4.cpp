// Task 4 - Iterative Depth First Search (DFS) Using Stack
// DSA Lab Week 11
// Tree Structure:
//         40
//        /  \
//      20    60
//     / \   / \
//   10  30 50  70

#include <iostream>
#include <stack>
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

// DFS uses a stack (LIFO) and produces Root -> Left -> Right order
// Push right child first so left child is processed first (LIFO)
void DFS(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    stack<Node*> s;
    s.push(root); // Start with the root node

    while (!s.empty()) {
        // Pop top node from stack and print it
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        // Push right child first, then left child
        // (so left is processed next due to LIFO order)
        if (current->right != nullptr)
            s.push(current->right);
        if (current->left != nullptr)
            s.push(current->left);
    }
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

    cout << "DFS Traversal: ";
    DFS(root);
    cout << endl;

    return 0;
}
