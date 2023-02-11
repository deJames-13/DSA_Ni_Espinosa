#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};

class LinkList
{
public:
    Node *head = NULL;
    Node *tail = NULL;

    void addNode(int data)
    {
        Node *node = NULL;
        node = new Node(data);

        if (head == NULL)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            tail->next = node;
            this->tail = node;
        }
    }
};

void displayList(Node *n);

int main()
{
    LinkList *myChain = NULL;
    myChain = new LinkList();
    for (int i = 0; i < 10; i++)
    {
        myChain->addNode(i);
    }
    displayList(myChain->head);
    return 0;
}
void displayList(Node *n)
{
    cout << "\nHEAD -> ";

    while (n != NULL)
    {
        cout << "[Node: " << n->data << "]"
             << " -> ";
        n = n->next;
    }
    cout << "END\n";
}
