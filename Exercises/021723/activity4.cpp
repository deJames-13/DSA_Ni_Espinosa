#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;
};

void runProgram();

void programA();
void prepend(Node **head, int data);
void append(Node **head, int data);
void insertAfter(Node *prev, int data);

void programB();
void stackProgram1();
void stackProgram2();
void stackProgram3();

void displayList(Node *node);
void displayStack(stack<int> s);

int main()
{
    runProgram();
    return 0;
}

void runProgram()
{
    char choice = 0, ans = 0;
    cout << "\n\n*****************************************\n"
         << "*\tLINEAR DATA STRUCTURE\n"
         << "*****************************************\n"
         << "\t[Options]\n"
         << "[A] ->\tInstering in A Linked List\n"
         << "[B] ->\tItems in the Stacks\n"
         << "*****************************************\n";

    cout << "Choice: ";
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'A')
    {
        programA();
    }
    else if (choice == 'B')
    {
        programB();
    }
    else
    {
        cout << "Quit Program? \n";
    }

    do
    {
        cout << "\n\nDo you want to Try Again? ";
        cin >> ans;
        ans = tolower(ans);
    } while (!(ans == 'y' || ans == 'n'));
    if (ans == 'y')
    {
        runProgram();
    }
    cin.clear();
    cout << "\nExit Program..\n";
}

void programA()
{
    Node *head = NULL;
    append(&head, 34);
    insertAfter(head, 25);
    prepend(&head, 20);
    insertAfter(head, 28);
    prepend(&head, 17);
    append(&head, 32);
    append(&head, 33);
    prepend(&head, 15);
    append(&head, 29);

    displayList(head);
}
void programB()
{
    char choice = 0;
    cout << "\n\n*****************************************\n"
         << "*\tSTACKS MENU\n"
         << "*****************************************\n"
         << "\t[Options]\n"
         << "[1] ->\tStack: [ 5 8 11 14 17 20 23 26 29 32 35 28 ]\n"
         << "[2] ->\tStack: [ 12 9 5 7 19 25 33 41 45 ]\n"
         << "[3] ->\tStack: [ 10 18 22 28 32 37 47 68 70 ]\n"
         << "*****************************************\n";
    cout << "Choice: ";
    cin >> choice;

    if (choice == '1')
    {
        stackProgram1();
    }
    else if (choice == '2')
    {
        stackProgram2();
    }
    else if (choice == '3')
    {
        stackProgram3();
    }
}

void prepend(Node **head, int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = *head;
    *head = node;
}
void append(Node **head, int data)
{
    Node *node = new Node();
    Node *last = NULL;
    node->data = data;
    if (*head == NULL)
    {
        *head = node;
        return;
    }
    last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = node;
}
void insertAfter(Node *prev, int data)
{
    Node *node = new Node();
    node->data = data;
    node->next = prev->next;
    prev->next = node;
}

void stackProgram1()
{
    stack<int> stack1;
    stack1.push(5);
    stack1.push(8);
    stack1.push(11);
    stack1.push(14);
    stack1.push(17);
    stack1.push(20);
    stack1.push(23);
    stack1.push(26);
    stack1.push(29);
    stack1.push(32);
    stack1.push(35);
    stack1.push(38);

    cout << "\n\nDisplaying stack: \n";
    displayStack(stack1);
}
void stackProgram2()
{
    // int arrDatas[] = {45, 41, 33, 25, 19, 7, 5, 9, 12};
    int arrDatas[] = {12, 9, 5, 7, 19, 25, 33, 41, 45};
    int len = 9;
    stack<int> stack2;

    for (int i = 0; i < len; i++)
    {
        stack2.push(arrDatas[i]);
    }

    cout << "\nDisplaying all elements in the stack: \n";
    displayStack(stack2);

    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    cout << "Displaying reamining elements: \n";
    displayStack(stack2);
}
void stackProgram3()
{
    // int arrDatas[] = {70, 68, 47, 37, 32, 28, 22, 18, 10};
    int arrDatas[] = {10, 18, 22, 28, 32, 37, 47, 68, 70};
    int len = 9;
    stack<int> stack3;
    for (int i = 0; i < len; i++)
    {
        stack3.push(arrDatas[i]);
    }

    cout << "\n";
    cout << "Displaying all the elements in the stack\n";
    displayStack(stack3);

    for (int i = 0; i < len - 1; i++)
    {
        stack3.pop();
    }

    cout << "Displaying one last element: \n";
    displayStack(stack3);
}

void displayList(Node *node)
{
    cout << "\nDisplaying List: \n";
    while (node != NULL)
    {
        cout << node->data << "\t";
        node = node->next;
    }
    cout << endl;
}

void displayStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << "\n";
}
