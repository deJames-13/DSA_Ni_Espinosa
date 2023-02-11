#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int n)
    {
        this->data = n;
    }
};

void displayList(Node *n);
Node *createNode(int d);

int main()
{
    Node *head = createNode(1);
    Node *n1 = createNode(2);
    Node *n2 = createNode(3);
    Node *n3 = createNode(4);
    Node *tail = createNode(5);

    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = tail;

    displayList(head);

    return 0;
}

Node *createNode(int d)
{
    Node *n = NULL;
    n = new Node(d);

    return n;
}

void displayList(Node *n)
{
    while (n != NULL)
    {
        cout << "[Node: " << n->data << "]"
             << " -> ";
        n = n->next;
    }
    cout << "END\n";
}
