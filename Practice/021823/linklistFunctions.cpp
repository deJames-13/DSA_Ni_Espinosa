#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
    // Node(int data)
    // {
    //     this->data = data;
    // }
};

void append(Node **head, int data);
void prepend(Node **head, int data);
void insertAfter(Node *prev, int data);
void insertAt(Node **head, int index, int data);

void displayList(Node *node);

int main()
{
    Node *head = new Node();
    head->data = 1;        // index 0
    append(&head, 2);      // 1
    append(&head, 3);      // 2
    append(&head, 4);      // 3
    insertAt(&head, 4, 5); // 4
    insertAt(&head, 3, 6); // 1 2 3 6 4 5

    displayList(head);
    return 0;
}

void displayList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "\t";
        node = node->next;
    }
}

void append(Node **head, int data)
{
    Node *newNode = NULL;
    Node *last = NULL;
    newNode = new Node();
    newNode->data = data;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}
void prepend(Node **head, int data)
{
    Node *newNode = NULL;
    newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void insertAfter(Node *prev, int data)
{
    Node *newNode = NULL;
    newNode = new Node();
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}
void insertAt(Node **head, int index, int data)
{
    if (index < 0)
    {
        cout << "Invalid index. " << endl;
        return;
    }
    Node *curr = *head;
    Node *newNode = new Node();
    newNode->data = data;
    if (index == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    while (index != 1)
    {
        if (curr->next == NULL)
        {
            cout << "Invalid index. " << endl;
            return;
        }
        curr = curr->next;
        index--;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}