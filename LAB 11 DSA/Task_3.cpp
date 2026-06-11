// Task 3 - Breadth First Search (BFS) / Level-Order Traversal
// DSA Lab Week 11
// Tree Structure:
//         40
//        /  \
//      20    60
//     / \   / \
//   10  30 50  70

#include <iostream>
#include <queue>
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

// BFS uses a queue (FIFO) to visit nodes level by level
void BFS(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<Node*> q;
    q.push(root); // Start with the root node

    while (!q.empty()) {
        // Remove front node from queue and print it
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        // Push left child first, then right child
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
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

    cout << "BFS / Level-Order Traversal: ";
    BFS(root);
    cout << endl;

    return 0;
}
