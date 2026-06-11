// Task 1 - Binary Search Tree: Insert, Delete, Inorder Traversal
// DSA Lab 13 - AVL & BST
// Handles all 3 deletion cases: leaf, one child, two children

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node();
    node->data  = value;
    node->left  = nullptr;
    node->right = nullptr;
    return node;
}

// ─── INSERT ──────────────────────────────────────────────────────────────────
Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data)
        root->left  = insert(root->left,  value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate " << value << " skipped." << endl;
    return root;
}

// ─── FIND MINIMUM (for inorder successor) ────────────────────────────────────
Node* findMin(Node* root) {
    if (root->left == nullptr) return root;
    return findMin(root->left);
}

// ─── DELETE ──────────────────────────────────────────────────────────────────
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        cout << "Value " << key << " not found." << endl;
        return nullptr;
    }

    if (key < root->data)
        root->left  = deleteNode(root->left,  key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2a: Only right child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 2b: Only left child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children — replace with inorder successor
        Node* successor  = findMin(root->right);
        root->data       = successor->data;
        root->right      = deleteNode(root->right, successor->data);
    }
    return root;
}

// ─── INORDER TRAVERSAL ───────────────────────────────────────────────────────
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* root = nullptr;

    // Insert: 50, 30, 70, 20, 40, 60, 80
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values)
        root = insert(root, v);

    cout << "After Insertion (Inorder): ";
    inorder(root);
    cout << endl;

    // Delete: 70
    root = deleteNode(root, 70);

    cout << "After Deletion of 70 (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
