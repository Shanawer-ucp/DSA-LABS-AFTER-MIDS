// Task 3 - AVL Tree Step-by-Step Trace
// DSA Lab 13 - AVL & BST
// Sequence: 10, 20, 30, 60, 50, 70, 5
// After each insertion: prints the tree, balance factors, and any rotation applied
// This file serves as both runnable code AND a logic trace (no code required per task)

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int  data;
    int  height;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node   = new Node();
    node->data   = value;
    node->height = 1;
    node->left   = nullptr;
    node->right  = nullptr;
    return node;
}

int height(Node* n)       { return n ? n->height : 0; }
int max2(int a, int b)    { return a > b ? a : b; }

void updateHeight(Node* n) {
    if (n) n->height = 1 + max2(height(n->left), height(n->right));
}

int bf(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

// ─── ROTATIONS ───────────────────────────────────────────────────────────────
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;
    x->right = y;
    y->left  = T;
    updateHeight(y);
    updateHeight(x);
    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;
    y->left  = x;
    x->right = T;
    updateHeight(x);
    updateHeight(y);
    return y;
}

// ─── AVL INSERT (with rotation name output) ──────────────────────────────────
Node* insert(Node* root, int value, string& rotationDone) {
    if (!root) return createNode(value);

    if      (value < root->data) root->left  = insert(root->left,  value, rotationDone);
    else if (value > root->data) root->right = insert(root->right, value, rotationDone);
    else return root;

    updateHeight(root);
    int b = bf(root);

    // LL
    if (b > 1 && value < root->left->data) {
        rotationDone = "Right Rotation (LL case) at node " + to_string(root->data);
        return rotateRight(root);
    }
    // RR
    if (b < -1 && value > root->right->data) {
        rotationDone = "Left Rotation (RR case) at node " + to_string(root->data);
        return rotateLeft(root);
    }
    // LR
    if (b > 1 && value > root->left->data) {
        rotationDone = "Left-Right Rotation (LR case) at node " + to_string(root->data);
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    // RL
    if (b < -1 && value < root->right->data) {
        rotationDone = "Right-Left Rotation (RL case) at node " + to_string(root->data);
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

// ─── PRINT HELPERS ───────────────────────────────────────────────────────────
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Simple indented tree print
void printTree(Node* root, string prefix = "", bool isLeft = true) {
    if (!root) return;
    cout << prefix;
    cout << (isLeft ? "|-- " : "\\-- ");
    cout << root->data
         << " (h=" << root->height
         << ", bf=" << bf(root) << ")" << endl;
    printTree(root->left,  prefix + (isLeft ? "|   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "|   " : "    "), false);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* root = nullptr;
    int values[] = {10, 20, 30, 60, 50, 70, 5};
    int n = 7;

    cout << "================================================" << endl;
    cout << "  AVL Tree Step-by-Step Trace" << endl;
    cout << "  Sequence: 10, 20, 30, 60, 50, 70, 5" << endl;
    cout << "================================================" << endl;

    for (int i = 0; i < n; i++) {
        string rotationDone = "None";
        root = insert(root, values[i], rotationDone);

        cout << "\n--- Step " << (i + 1)
             << ": Insert " << values[i] << " ---" << endl;
        cout << "Rotation: " << rotationDone << endl;
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
        cout << "Tree structure:" << endl;
        printTree(root->left,  "    ", true);
        cout << "    " << root->data
             << " <-- ROOT (h=" << root->height
             << ", bf=" << bf(root) << ")" << endl;
        printTree(root->right, "    ", false);
    }

    cout << "\n================================================" << endl;
    cout << "  LOGIC TRACE SUMMARY" << endl;
    cout << "================================================" << endl;
    cout << "\nStep 1: Insert 10 -> Tree: [10]  No rotation needed." << endl;
    cout << "Step 2: Insert 20 -> Tree: [10,20]  No rotation needed." << endl;
    cout << "Step 3: Insert 30 -> bf(10)=-2, RR case"
         << "\n        Left Rotation at 10 -> New root: 20" << endl;
    cout << "        Tree:  20\n               / \\\n              10  30" << endl;
    cout << "\nStep 4: Insert 60 -> bf(30)=-1 -> No rotation." << endl;
    cout << "\nStep 5: Insert 50 -> bf(30)=-2, RL case (50 < 60)"
         << "\n        Right-Left Rotation at 30 -> 50 becomes new right child of 20" << endl;
    cout << "        Tree:  20\n               / \\\n              10  50\n"
         << "                 / \\\n                30  60" << endl;
    cout << "\nStep 6: Insert 70 -> bf(20)=-2, RR case"
         << "\n        Left Rotation at 20 -> New root: 50" << endl;
    cout << "        Tree:     50\n                 / \\\n"
         << "                20  60\n               / \\  \\\n"
         << "              10  30  70" << endl;
    cout << "\nStep 7: Insert 5 -> bf(10)=1 -> No rotation needed." << endl;
    cout << "\nFinal Inorder: 5 10 20 30 50 60 70" << endl;
    cout << "================================================" << endl;

    return 0;
}
