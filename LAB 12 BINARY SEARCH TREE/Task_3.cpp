// Task 3 - Check if Two BSTs are Identical
// DSA Lab - Binary Search Tree
// Two BSTs are identical if they have the same structure AND same data values

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

// ─── IDENTICAL CHECK ─────────────────────────────────────────────────────────
// Both null     -> identical (base case)
// One null      -> not identical (structure differs)
// Both non-null -> check data and recurse on both subtrees
bool isIdentical(Node* root1, Node* root2) {
    // Both trees are empty at this point
    if (root1 == nullptr && root2 == nullptr)
        return true;

    // One is empty, other is not -> structure mismatch
    if (root1 == nullptr || root2 == nullptr)
        return false;

    // Check current node data AND both subtrees
    return (root1->data == root2->data) &&
           isIdentical(root1->left,  root2->left)  &&
           isIdentical(root1->right, root2->right);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    // ── Test 1: Identical BSTs ──
    Node* bst1 = nullptr;
    Node* bst2 = nullptr;

    int seq1[] = {50, 30, 70, 20, 40, 60, 80};
    int seq2[] = {50, 30, 70, 20, 40, 60, 80};

    for (int v : seq1) bst1 = insert(bst1, v);
    for (int v : seq2) bst2 = insert(bst2, v);

    cout << "=== Test 1 ===" << endl;
    cout << "BST 1 Inorder: "; inorder(bst1); cout << endl;
    cout << "BST 2 Inorder: "; inorder(bst2); cout << endl;
    cout << "Are the two BSTs identical? "
         << (isIdentical(bst1, bst2) ? "YES - Identical" : "NO - Not Identical")
         << endl;

    // ── Test 2: Different data ──
    Node* bst3 = nullptr;
    int seq3[] = {50, 30, 70, 20, 40, 60, 90}; // 90 instead of 80
    for (int v : seq3) bst3 = insert(bst3, v);

    cout << "\n=== Test 2 ===" << endl;
    cout << "BST 1 Inorder: "; inorder(bst1); cout << endl;
    cout << "BST 3 Inorder: "; inorder(bst3); cout << endl;
    cout << "Are the two BSTs identical? "
         << (isIdentical(bst1, bst3) ? "YES - Identical" : "NO - Not Identical")
         << endl;

    // ── Test 3: Different structure ──
    Node* bst4 = nullptr;
    int seq4[] = {50, 30, 70, 20}; // Fewer nodes
    for (int v : seq4) bst4 = insert(bst4, v);

    cout << "\n=== Test 3 ===" << endl;
    cout << "BST 1 Inorder: "; inorder(bst1); cout << endl;
    cout << "BST 4 Inorder: "; inorder(bst4); cout << endl;
    cout << "Are the two BSTs identical? "
         << (isIdentical(bst1, bst4) ? "YES - Identical" : "NO - Not Identical")
         << endl;

    return 0;
}
