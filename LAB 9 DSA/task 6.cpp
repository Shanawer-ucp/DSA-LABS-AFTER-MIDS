#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList
{
    Node* head;

public:

    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
    }

    void insertAtEnd(Node*& temp, int value)
    {
        if (temp == NULL)
        {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = NULL;
            temp = newNode;
            return;
        }

        if (temp->next == NULL)
        {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            newNode->prev = temp;
            temp->next = newNode;
            return;
        }

        insertAtEnd(temp->next, value);
    }

    void insertAtPosition(Node*& temp, int value, int pos)
    {
        if (pos == 1)
        {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = temp;

            if (temp != NULL)
            {
                temp->prev = newNode;
            }

            temp = newNode;
            return;
        }

        if (temp == NULL)
        {
            return;
        }

        if (pos == 2)
        {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL)
            {
                temp->next->prev = newNode;
            }

            temp->next = newNode;
            return;
        }

        insertAtPosition(temp->next, value, pos - 1);
    }

    void deleteByValue(Node*& temp, int value)
    {
        if (temp == NULL)
        {
            return;
        }

        if (temp->data == value)
        {
            Node* del = temp;
            temp = temp->next;

            if (temp != NULL)
            {
                temp->prev = del->prev;
            }

            delete del;
            return;
        }

        deleteByValue(temp->next, value);
    }

    void deleteAtPosition(Node*& temp, int pos)
    {
        if (temp == NULL)
        {
            return;
        }

        if (pos == 1)
        {
            Node* del = temp;
            temp = temp->next;

            if (temp != NULL)
            {
                temp->prev = del->prev;
            }

            delete del;
            return;
        }

        deleteAtPosition(temp->next, pos - 1);
    }

    int search(Node* temp, int value, int pos)
    {
        if (temp == NULL)
        {
            return -1;
        }

        if (temp->data == value)
        {
            return pos;
        }

        return search(temp->next, value, pos + 1);
    }

    void printForward(Node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << " ";
        printForward(temp->next);
    }

    void printReverse(Node* temp)
    {
        if (temp == NULL)
        {
            return;
        }

        cout << temp->data << " ";
        printReverse(temp->prev);
    }

    Node* getLast(Node* temp)
    {
        if (temp == NULL || temp->next == NULL)
        {
            return temp;
        }

        return getLast(temp->next);
    }

    bool palindrome(Node* left, Node* right)
    {
        if (left == NULL || right == NULL)
        {
            return true;
        }

        if (left == right || left->prev == right)
        {
            return true;
        }

        if (left->data != right->data)
        {
            return false;
        }

        return palindrome(left->next, right->prev);
    }

    void showForward()
    {
        printForward(head);
        cout << endl;
    }

    void showReverse()
    {
        Node* last = getLast(head);
        printReverse(last);
        cout << endl;
    }

    bool isPalindrome()
    {
        Node* last = getLast(head);
        return palindrome(head, last);
    }

    Node*& getHead()
    {
        return head;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtBeginning(1);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    list.insertAtEnd(list.getHead(), 5);

    list.insertAtPosition(list.getHead(), 9, 2);

    list.showForward();

    list.deleteByValue(list.getHead(), 5);

    list.showForward();

    list.deleteAtPosition(list.getHead(), 2);

    list.showForward();

    cout << list.search(list.getHead(), 1, 1) << endl;

    list.showReverse();

    if (list.isPalindrome())
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0;
}