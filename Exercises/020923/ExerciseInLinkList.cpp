#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void runProgram();
void number1();
void number2();
void display_list(Node *node);

int main()
{
    runProgram();
    return 0;
}

void runProgram()
{
    int iChoice = 0;
    char ans = 0;
    cout << "*****************************************\n"
         << "*\tMENU\n"
         << "*****************************************\n"
         << "\t[Options]\n"
         << "[1]->\tLinked List 1\n"
         << "[2]->\tLinked List 2\n"
         << "*****************************************\n";

    cout << "\nEnter your choice: ";
    cin >> iChoice;
    if (iChoice == 1)
    {
        number1();
    }
    else if (iChoice == 2)
    {
        number2();
    }
    else
    {
        cout << "Quit the Program!\n";
    }
    cout << endl;
    do
    {
        cout << "\nDo you want to try Again? ";
        cin >> ans;
        ans = tolower(ans);
    } while (!(ans == 'y' || ans == 'n'));
    cin.clear();
    if (ans == 'y')
    {
        runProgram();
    }
}

void number1()
{
    Node *head = NULL;
    Node *n2 = NULL;
    Node *n3 = NULL;
    Node *n4 = NULL;
    Node *n5 = NULL;
    Node *tail = NULL;

    head = new Node();
    n2 = new Node();
    n3 = new Node();
    n4 = new Node();
    n5 = new Node();
    tail = new Node();

    head->data = 2;
    n2->data = 8;
    n3->data = 14;
    n4->data = 20;
    n5->data = 24;
    tail->data = 28;

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = tail;
    tail->next = NULL;

    display_list(head);
}

void number2()
{
    int iCounter = 0;
    int start = 11;
    Node *nodes[10] = {NULL};
    // INITIALIZE
    while (iCounter < 10)
    {
        nodes[iCounter] = NULL;
        nodes[iCounter] = new Node();
        iCounter++;
    }
    iCounter = 0;
    // MODIFY NODE PROPERTY
    while (iCounter < 10)
    {
        nodes[iCounter]->data = start;
        start += 2;

        if (iCounter + 1 == 10)
        {
            nodes[iCounter]->next = NULL;
            break;
        }
        nodes[iCounter]->next = nodes[iCounter + 1];
        iCounter++;
    }
    display_list(nodes[0]);
}

void display_list(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "\t";
        node = node->next;
    }
}
