// Task 2 - AVL Tree with Insertion and All 4 Rotations
// DSA Lab 13 - AVL & BST
// Rotations: LL (Right), RR (Left), LR (Left-Right), RL (Right-Left)
// Insert sequence: 30, 20, 40, 10, 25, 35, 50, 5

#include <iostream>
using namespace std;

struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

// ─── UTILITY ─────────────────────────────────────────────────────────────────

Node* createNode(int value) {
    Node* node   = new Node();
    node->data   = value;
    node->height = 1;        // New node is always a leaf
    node->left   = nullptr;
    node->right  = nullptr;
    return node;
}

// Height of a node (0 if null)
int height(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Recalculate height from children
void updateHeight(Node* node) {
    if (node == nullptr) return;
    int lh = height(node->left);
    int rh = height(node->right);
    node->height = 1 + (lh > rh ? lh : rh);
}

// Balance factor = height(left) - height(right)
int balanceFactor(Node* node) {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// ─── ROTATIONS ───────────────────────────────────────────────────────────────

// Right Rotation (LL case)
//       y                x
//      / \              / \
//     x   T3   -->    T1   y
//    / \                  / \
//   T1  T2              T2  T3
Node* rotateRight(Node* y) {
    cout << "  [LL] Right Rotation on node " << y->data << endl;
    Node* x  = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left  = T2;

    updateHeight(y);
    updateHeight(x);

    return x; // New root of this subtree
}

// Left Rotation (RR case)
//     x                  y
//    / \                / \
//   T1   y    -->      x   T3
//       / \           / \
//      T2  T3        T1  T2
Node* rotateLeft(Node* x) {
    cout << "  [RR] Left Rotation on node " << x->data << endl;
    Node* y  = x->right;
    Node* T2 = y->left;

    y->left  = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y; // New root of this subtree
}

// Left-Right Rotation (LR case)
// First left-rotate the left child, then right-rotate the root
Node* rotateLR(Node* node) {
    cout << "  [LR] Left-Right Rotation on node " << node->data << endl;
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

// Right-Left Rotation (RL case)
// First right-rotate the right child, then left-rotate the root
Node* rotateRL(Node* node) {
    cout << "  [RL] Right-Left Rotation on node " << node->data << endl;
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}

// ─── AVL INSERT ──────────────────────────────────────────────────────────────
Node* insert(Node* root, int value) {
    // Standard BST insert
    if (root == nullptr) return createNode(value);

    if (value < root->data)
        root->left  = insert(root->left,  value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else {
        cout << "Duplicate " << value << " skipped." << endl;
        return root;
    }

    // Update height of current node
    updateHeight(root);

    // Check balance factor
    int bf = balanceFactor(root);

    // LL Case: Left heavy and new node in left subtree
    if (bf > 1 && value < root->left->data)
        return rotateRight(root);

    // RR Case: Right heavy and new node in right subtree
    if (bf < -1 && value > root->right->data)
        return rotateLeft(root);

    // LR Case: Left heavy and new node in right subtree of left child
    if (bf > 1 && value > root->left->data)
        return rotateLR(root);

    // RL Case: Right heavy and new node in left subtree of right child
    if (bf < -1 && value < root->right->data)
        return rotateRL(root);

    return root; // Already balanced
}

// ─── TRAVERSALS ──────────────────────────────────────────────────────────────
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << "(h=" << root->height
         << ",bf=" << balanceFactor(root) << ") ";
    preorder(root->left);
    preorder(root->right);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* root = nullptr;

    // Insert sequence: 30, 20, 40, 10, 25, 35, 50, 5
    int values[] = {30, 20, 40, 10, 25, 35, 50, 5};
    int n = 8;

    cout << "=== AVL Tree Insertions ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\nInserting " << values[i] << "..." << endl;
        root = insert(root, values[i]);
        cout << "  Inorder after insert: ";
        inorder(root);
        cout << endl;
    }

    cout << "\n=== Final AVL Tree ===" << endl;
    cout << "Inorder (sorted):  ";
    inorder(root);
    cout << endl;

    cout << "Preorder (with height & balance factor):" << endl;
    cout << "  ";
    preorder(root);
    cout << endl;

    cout << "\nRoot: " << root->data
         << "  |  Height: " << root->height
         << "  |  Balance Factor: " << balanceFactor(root) << endl;

    return 0;
}
