// Task 5 - Singly Linked List with All Recursive Operations
// DSA Lab 10 - Recursion
// Operations: Insert (begin/end/position), Delete (by value/position),
//             Search, Traversal — all recursive, no loops

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// ─── TRAVERSAL ──────────────────────────────────────────────────────────────
void printList(Node* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    cout << head->data << " -> ";
    printList(head->next);
}

// ─── INSERTION ──────────────────────────────────────────────────────────────

// Insert at beginning
Node* insertAtBegin(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Insert at end (recursive)
Node* insertAtEnd(Node* head, int value) {
    if (head == nullptr)
        return createNode(value);
    head->next = insertAtEnd(head->next, value);
    return head;
}

// Insert at given 1-based position (recursive)
Node* insertAtPosition(Node* head, int value, int pos) {
    if (pos == 1) {
        Node* newNode = createNode(value);
        newNode->next = head;
        return newNode;
    }
    if (head == nullptr) {
        cout << "Position out of range. Inserting at end." << endl;
        return createNode(value);
    }
    head->next = insertAtPosition(head->next, value, pos - 1);
    return head;
}

// ─── DELETION ───────────────────────────────────────────────────────────────

// Delete node by value (first occurrence)
Node* deleteByValue(Node* head, int value) {
    if (head == nullptr) {
        cout << "Value " << value << " not found in list." << endl;
        return nullptr;
    }
    if (head->data == value) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteByValue(head->next, value);
    return head;
}

// Delete node at given 1-based position
Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return nullptr;
    }
    if (pos == 1) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteAtPosition(head->next, pos - 1);
    return head;
}

// ─── SEARCH ─────────────────────────────────────────────────────────────────

// Returns 1-based index of value, or -1 if not found
int search(Node* head, int value, int index = 1) {
    if (head == nullptr)
        return -1;
    if (head->data == value)
        return index;
    return search(head->next, value, index + 1);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* head = nullptr;

    // Insert at end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    cout << "After inserting 10, 20, 30 at end: ";
    printList(head);

    // Insert at beginning
    head = insertAtBegin(head, 5);
    cout << "After inserting 5 at beginning: ";
    printList(head);

    // Insert at position
    head = insertAtPosition(head, 15, 3); // Insert 15 at position 3
    cout << "After inserting 15 at position 3: ";
    printList(head);

    // Search
    int pos = search(head, 20);
    if (pos != -1)
        cout << "Value 20 found at position: " << pos << endl;
    else
        cout << "Value 20 not found." << endl;

    pos = search(head, 99);
    cout << "Value 99 found at position: " << (pos == -1 ? -1 : pos) << endl;

    // Delete by value
    head = deleteByValue(head, 15);
    cout << "After deleting value 15: ";
    printList(head);

    // Delete at position
    head = deleteAtPosition(head, 2); // Delete node at position 2
    cout << "After deleting node at position 2: ";
    printList(head);

    return 0;
}
