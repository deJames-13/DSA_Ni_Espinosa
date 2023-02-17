#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

void prepend(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(Node *prev, int data)
{
    if (prev == NULL)
    {
        cout << "Previous node not found!\n";
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

void append(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    Node *last = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

void display(Node *n)
{
    while (n != NULL)
    {
        cout << "[Node: " << n->data << "] ->";
        n = n->next;
    }
    cout << "END\n";
}

int main()
{
    Node *head = new Node();

    prepend(&head, 1);
    insertAfter(head, 2);
    append(&head, 3);

    display(head);

    return 0;
}