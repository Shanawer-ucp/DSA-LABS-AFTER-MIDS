// Task 4 - Convert BST to Sorted Singly Linked List (Library Catalog)
// DSA Lab - Binary Search Tree
// Each BST node holds an ISBN (int) and Title (string)
// Inorder traversal visits nodes in ascending ISBN order
// Each visited node is appended to a singly linked list

#include <iostream>
#include <string>
using namespace std;

// ─── BST NODE ────────────────────────────────────────────────────────────────
struct BSTNode {
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* createBSTNode(int isbn, string title) {
    BSTNode* node = new BSTNode();
    node->isbn  = isbn;
    node->title = title;
    node->left  = nullptr;
    node->right = nullptr;
    return node;
}

// Insert book into BST by ISBN (no duplicates)
BSTNode* insert(BSTNode* root, int isbn, string title) {
    if (root == nullptr)
        return createBSTNode(isbn, title);
    if (isbn < root->isbn)
        root->left  = insert(root->left,  isbn, title);
    else if (isbn > root->isbn)
        root->right = insert(root->right, isbn, title);
    else
        cout << "Duplicate ISBN " << isbn << " not inserted." << endl;
    return root;
}

// ─── LINKED LIST NODE ────────────────────────────────────────────────────────
struct ListNode {
    int isbn;
    string title;
    ListNode* next;
};

ListNode* createListNode(int isbn, string title) {
    ListNode* node = new ListNode();
    node->isbn  = isbn;
    node->title = title;
    node->next  = nullptr;
    return node;
}

// ─── CONVERSION ──────────────────────────────────────────────────────────────
// Inorder traversal of BST; appends each node to the linked list
// Uses tail pointer for O(1) appending without traversing the list each time
void convertToList(BSTNode* root, ListNode*& head, ListNode*& tail) {
    if (root == nullptr)
        return;

    // Visit left subtree first (smaller ISBNs)
    convertToList(root->left, head, tail);

    // Create a linked list node for the current BST node
    ListNode* newNode = createListNode(root->isbn, root->title);

    if (head == nullptr) {
        // First node in the list
        head = newNode;
        tail = newNode;
    } else {
        // Append to the end
        tail->next = newNode;
        tail = newNode;
    }

    // Visit right subtree (larger ISBNs)
    convertToList(root->right, head, tail);
}

// ─── PRINT CATALOG ───────────────────────────────────────────────────────────
void printCatalog(ListNode* head) {
    if (head == nullptr) {
        cout << "Catalog is empty." << endl;
        return;
    }

    cout << left;
    cout << "--------------------------------------" << endl;
    cout << "ISBN        | Title" << endl;
    cout << "--------------------------------------" << endl;

    ListNode* current = head;
    while (current != nullptr) {
        cout << current->isbn << "  | " << current->title << endl;
        current = current->next;
    }
    cout << "--------------------------------------" << endl;
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    BSTNode* root = nullptr;

    // Insert books into BST (by ISBN)
    root = insert(root, 1045, "Data Structures and Algorithms");
    root = insert(root, 2031, "Introduction to C++ Programming");
    root = insert(root, 1120, "Discrete Mathematics");
    root = insert(root, 3005, "Operating Systems Concepts");
    root = insert(root, 1500, "Computer Networks");
    root = insert(root, 2500, "Database Management Systems");
    root = insert(root, 1045, "Duplicate ISBN test");   // Should be rejected

    cout << "Books inserted into BST successfully.\n" << endl;

    // Convert BST to sorted linked list
    ListNode* listHead = nullptr;
    ListNode* listTail = nullptr;
    convertToList(root, listHead, listTail);

    // Print the sorted library catalog
    cout << "Library Catalog (sorted by ISBN):" << endl;
    printCatalog(listHead);

    return 0;
}
