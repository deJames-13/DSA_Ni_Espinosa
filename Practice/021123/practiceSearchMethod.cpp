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

    bool deleteNode(int d)
    {
        Node *current = NULL;
        current = this->head;

        if (current == NULL)
        {
            return false;
        }
        if (current->data == d)
        {
            if (this->head == (this->tail))
            {
                this->head == NULL;
                this->tail == NULL;
            }
            else
            {
                this->head = current->next;
            }
            return true;
        }
        while (current->next != 0 && current->next->data != d)
        {
            current = current->next;
        }
        if (current->next != NULL)
        {
            if (current->next == this->tail)
            {
                this->tail = current;
            }
            current->next = current->next->next;
        }

        return false;
    }

    bool searchNode(int d)
    {
        Node *current = NULL;
        current = this->head;

        while (current != NULL && current->data != d)
        {
            current = current->next;
        }
        return (current == NULL ? false : true);
    }

    void print()
    {
        Node *n = NULL;
        n = this->head;
        cout << "\nHEAD -> ";
        while (n != NULL)
        {
            cout << "[Node: " << n->data << "]"
                 << " -> ";
            n = n->next;
        }
        cout << "END\n";
    }
};

void displayList(Node *n);

int main()
{
    LinkList *myChain = new LinkList();
    for (int i = 0; i < 10; i++)
    {
        myChain->addNode(i);
    }

    displayList(myChain->head);

    int findX = 2;
    bool isFound = myChain->searchNode(findX);
    if (isFound)
        cout << "[Node: " << findX << "] Found\n";
    else
        cout << "[Node: " << findX << "] Not Found\n";
    return 0;

    int delX = 2;
    bool isDeleted = myChain->deleteNode(delX);
    if (isDeleted)
        cout << "[Node: " << delX << "] Deleted\n";
    else
        cout << "[Node: " << delX << "] Not Found\n";

    myChain->print();

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
