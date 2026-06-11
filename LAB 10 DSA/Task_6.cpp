// Task 6 - Doubly Linked List with Recursive Operations + Palindrome Check
// DSA Lab 10 - Recursion
// No loops used anywhere

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

// Get last node recursively (used in reverse print and palindrome)
Node* getLastNode(Node* head) {
    if (head->next == nullptr)
        return head;
    return getLastNode(head->next);
}

// ─── TRAVERSAL ──────────────────────────────────────────────────────────────

void printForward(Node* head) {
    if (head == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    cout << head->data << " <-> ";
    printForward(head->next);
}

void printReverse(Node* tail) {
    if (tail == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    cout << tail->data << " <-> ";
    printReverse(tail->prev);
}

// ─── INSERTION ──────────────────────────────────────────────────────────────

Node* insertAtBegin(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

Node* insertAtEnd(Node* head, int value) {
    if (head == nullptr)
        return createNode(value);
    head->next = insertAtEnd(head->next, value);
    if (head->next != nullptr)
        head->next->prev = head;
    return head;
}

Node* insertAtPosition(Node* head, int value, int pos) {
    if (pos == 1)
        return insertAtBegin(head, value);
    if (head == nullptr) {
        cout << "Position out of range. Inserting at end." << endl;
        return createNode(value);
    }
    head->next = insertAtPosition(head->next, value, pos - 1);
    if (head->next != nullptr)
        head->next->prev = head;
    return head;
}

// ─── DELETION ───────────────────────────────────────────────────────────────

Node* deleteByValue(Node* head, int value) {
    if (head == nullptr) {
        cout << "Value " << value << " not found." << endl;
        return nullptr;
    }
    if (head->data == value) {
        Node* temp = head->next;
        if (temp != nullptr)
            temp->prev = nullptr;
        delete head;
        return temp;
    }
    head->next = deleteByValue(head->next, value);
    if (head->next != nullptr)
        head->next->prev = head;
    return head;
}

Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) {
        cout << "Position out of range." << endl;
        return nullptr;
    }
    if (pos == 1) {
        Node* temp = head->next;
        if (temp != nullptr)
            temp->prev = nullptr;
        delete head;
        return temp;
    }
    head->next = deleteAtPosition(head->next, pos - 1);
    if (head->next != nullptr)
        head->next->prev = head;
    return head;
}

// ─── SEARCH ─────────────────────────────────────────────────────────────────

int search(Node* head, int value, int index = 1) {
    if (head == nullptr)
        return -1;
    if (head->data == value)
        return index;
    return search(head->next, value, index + 1);
}

// ─── PALINDROME CHECK ────────────────────────────────────────────────────────
// Compares front and rear nodes, moves inward recursively
// Uses a pointer-to-pointer for the front node so it advances across calls

bool palindromeHelper(Node*& front, Node* back) {
    // Base case: reached middle or passed it
    if (back == nullptr)
        return true;

    // Recurse to the end first
    bool result = palindromeHelper(front, back->next);

    // On the way back, compare front and back
    if (!result)
        return false;

    if (front->data != back->data)
        return false;

    // Move front pointer forward
    front = front->next;
    return true;
}

bool isPalindrome(Node* head) {
    Node* front = head;
    return palindromeHelper(front, head);
}

// ─── MAIN ────────────────────────────────────────────────────────────────────
int main() {
    Node* head = nullptr;

    // Build list: 1 <-> 2 <-> 3 <-> 2 <-> 1
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 1);

    cout << "Forward:  ";
    printForward(head);

    Node* tail = getLastNode(head);
    cout << "Reverse:  ";
    printReverse(tail);

    cout << "Palindrome check (1 2 3 2 1): "
         << (isPalindrome(head) ? "YES" : "NO") << endl;

    // Insert at beginning
    head = insertAtBegin(head, 99);
    cout << "\nAfter inserting 99 at beginning: ";
    printForward(head);

    // Insert at position 3
    head = insertAtPosition(head, 55, 3);
    cout << "After inserting 55 at position 3: ";
    printForward(head);

    // Search
    int pos = search(head, 55);
    cout << "Search for 55: found at position " << pos << endl;

    // Delete by value
    head = deleteByValue(head, 55);
    cout << "After deleting value 55: ";
    printForward(head);

    // Delete at position 1
    head = deleteAtPosition(head, 1);
    cout << "After deleting node at position 1: ";
    printForward(head);

    // Non-palindrome test
    Node* head2 = nullptr;
    head2 = insertAtEnd(head2, 1);
    head2 = insertAtEnd(head2, 2);
    head2 = insertAtEnd(head2, 3);
    cout << "\nPalindrome check (1 2 3): "
         << (isPalindrome(head2) ? "YES" : "NO") << endl;

    return 0;
}
