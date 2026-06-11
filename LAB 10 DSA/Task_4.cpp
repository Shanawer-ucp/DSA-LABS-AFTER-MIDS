// Task 4 - Singly Linked List Recursive Traversal
// DSA Lab 10 - Recursion

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Helper to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Recursively print all nodes from head to end
void printList(Node* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    cout << head->data << " -> ";
    printList(head->next);
}

int main() {
    // Build list: 10 -> 20 -> 30 -> 40 -> 50
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    cout << "Linked List (recursive traversal): ";
    printList(head);

    return 0;
}
