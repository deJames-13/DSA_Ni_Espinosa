#include <iostream>
using namespace std;

class Node
{
public:
    int data = 0;
    Node *prev = NULL; // use of nullptr instead of NULL is suggested
    Node *next = NULL;

    Node(int value)
    {
        this->data = value;
    }
};

void displayList(Node *n);
void displayReversedList(Node *n);

int main()
{
    Node *head = NULL;
    Node *n1 = NULL;
    Node *n2 = NULL;
    Node *n3 = NULL;
    Node *n4 = NULL;
    Node *tail = NULL;

    head = new Node(6);
    n1 = new Node(9);
    n2 = new Node(4);
    n3 = new Node(2);
    n4 = new Node(0);
    tail = new Node(13);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = tail;
    tail->next = NULL;

    head->prev = NULL;
    n1->prev = head;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;
    tail->prev = n4;

    displayList(head);
    cout << "\nReversed List\n";
    displayReversedList(tail);
    return 0;
}

void displayList(Node *n)
{
    while (n != NULL)
    {
        cout << "[Node: " << n->data << "] -> ";
        n = n->next;
    }
    cout << "END\n";
}
void displayReversedList(Node *n)
{
    while (n != NULL)
    {
        cout << "[Node: " << n->data << "] -> ";
        n = n->prev;
    }
    cout << "END\n";
}