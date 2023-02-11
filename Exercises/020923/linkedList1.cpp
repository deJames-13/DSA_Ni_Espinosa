#include <iostream>
using namespace std;

// CLASSES and PROPERTIES
class Node // Class Node
{
public:
    int data;   // Data property
    Node *next; // pointer to next NODE
};

void print(Node *n);

int main()
{
    Node *head = NULL; // declares Node HEAD with NULL VALUE
    Node *second = NULL;
    Node *third = NULL;

    head = new Node(); // INITIALIZED Node HEAD
    second = new Node();
    third = new Node();

    head->data = 1;      // ADDS data property to node HEAD
    head->next = second; // points the next NODE to the Node Second

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    print(head);

    return 0;
}

void print(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}