// Task 2 - BST Node Deletion (All 3 Cases)
// DSA Lab - Binary Search Tree
// Case 1: Leaf node       -> simply remove
// Case 2: One child       -> bypass deleted node
// Case 3: Two children    -> replace with inorder successor

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

Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data)      root->left  = insert(root->left,  value);
    else if (value > root->data) root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Find the minimum node in a subtree (leftmost node)
Node* findMin(Node* root) {
    if (root->left == nullptr)
        return root;
    return findMin(root->left);
}

// ─── DELETE ──────────────────────────────────────────────────────────────────
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        cout << "Key " << key << " not found in BST." << endl;
        return nullptr;
    }

    if (key < root->data) {
        // Key is in the left subtree
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        // Key is in the right subtree
        root->right = deleteNode(root->right, key);
    }
    else {
        // Found the node to delete

        // Case 1: Leaf node (no children)
        if (root->left == nullptr && root->right == nullptr) {
            cout << "Case 1: Deleting leaf node " << key << endl;
            delete root;
            return nullptr;
        }

        // Case 2a: Only right child exists
        if (root->left == nullptr) {
            cout << "Case 2: Deleting node " << key << " (has right child only)" << endl;
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2b: Only left child exists
        if (root->right == nullptr) {
            cout << "Case 2: Deleting node " << key << " (has left child only)" << endl;
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        // Replace with inorder successor (smallest in right subtree)
        cout << "Case 3: Deleting node " << key << " (has two children)" << endl;
        Node* successor = findMin(root->right);
        cout << "Inorder successor: " << successor->data << endl;
        root->data = successor->data;                         // Copy successor value
        root->right = deleteNode(root->right, successor->data); // Delete successor
    }

    return root;
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* root = nullptr;

    // Build BST: 50 30 70 20 40 60 80
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insert(root, v);

    cout << "Initial BST (Inorder): ";
    inorder(root);
    cout << "\n" << endl;

    // Case 1: Delete leaf node 20
    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    inorder(root);
    cout << "\n" << endl;

    // Case 2: Delete node with one child (30 now only has 40)
    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    inorder(root);
    cout << "\n" << endl;

    // Case 3: Delete root 50 (has two children)
    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    inorder(root);
    cout << "\n" << endl;

    // Delete non-existent key
    root = deleteNode(root, 99);

    return 0;
}
