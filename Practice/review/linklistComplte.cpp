#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

void insertAfter(Node *prev, int data);
void insertAt(Node **head, int index, int data);
void append(Node **head, int data);
void prepend(Node **head, int data);

Node *getNodeAt(Node *head, int index);

int main()
{
    Node *head = NULL;
    head = new Node;
    head->data = 1;
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    int x = 4;
    Node *pos = getNodeAt(head, x);

    cout << "Node at index " << x << " is: " << pos->data << endl;

    return 0;
}

void insertAfter(Node *prev, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}
void insertAt(Node **head, int index, int data)
{
    if (index < 0)
    {
        cout << "Invalid index value.\n";
        return;
    }

    Node *newNode = new Node();
    newNode->data = data;

    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    Node *curr = *head;
    while (index != 1)
    {
        if (curr->next == NULL)
        {
            cout << "Index out of range!\n";
            return;
        }
        curr = curr->next;
        index--;
    }
    curr->next = newNode;
}
void append(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *last = *head;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}
void prepend(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

Node *getNodeAt(Node *head, int index)
{
    if (index < 0)
    {
        cout << "Invalid index value.\n";
        return NULL;
    }
    else if (index == 0)
    {
        return head;
    }
    Node *curr = head;
    while (index != 1)
    {
        if (curr->next == NULL)
        {
            cout << "Index out of range!\n";
            return NULL;
        }
        curr = curr->next;
        index--;
    }
    return curr->next;
}