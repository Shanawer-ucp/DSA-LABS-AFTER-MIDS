// Task 1 - Binary Search Tree: Insert, Traversals, Search
// DSA Lab - Binary Search Tree
// Operations: Insert (no duplicates), Inorder/Preorder/Postorder, Search

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new BST node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// ─── INSERT ──────────────────────────────────────────────────────────────────
// Recursively insert value; ignore duplicates
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate value " << value << " not inserted." << endl;

    return root;
}

// ─── TRAVERSALS ──────────────────────────────────────────────────────────────

// Inorder: Left -> Root -> Right (produces sorted output)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ─── SEARCH ──────────────────────────────────────────────────────────────────
// Returns true if key exists in BST
bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* root = nullptr;

    // Insert sequence: 50 30 70 20 40 60 80
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    cout << "Inserting values: ";
    for (int i = 0; i < n; i++) {
        cout << values[i] << " ";
        root = insert(root, values[i]);
    }
    cout << endl;

    // Test duplicate
    root = insert(root, 30); // Should print duplicate message

    cout << "\nInorder Traversal (sorted): ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal:         ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal:        ";
    postorder(root);
    cout << endl;

    // Search
    int keys[] = {40, 90};
    for (int i = 0; i < 2; i++) {
        cout << "\nSearching for " << keys[i] << ": ";
        if (search(root, keys[i]))
            cout << "Key found in BST" << endl;
        else
            cout << "Key not found in BST" << endl;
    }

    return 0;
}
