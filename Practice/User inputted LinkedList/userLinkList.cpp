#include <iostream>
#include <windows.h>
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
            if (this->head == this->tail)
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
            return true;
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
        cout << "HEAD -> ";
        while (n != NULL)
        {
            cout << "[Node: " << n->data << "]"
                 << " -> ";
            n = n->next;
        }
        cout << "TAIL\n";
    }
};

void runProgram();
char menu();
void goBackMenu();
bool checkInput();

void createLinkList();
void commandsMenu(LinkList *chain);
void cmdAdd(LinkList *chain);
void cmdDelete(LinkList *chain);
void cmdSearch(LinkList *chain);

int main()
{
    runProgram();
    return 0;
}

void runProgram()
{
    system("cls");

    char m = menu();
    switch (m)
    {
    case '1':
        createLinkList();
        break;
    case '2':
        cout << "Quitting program!\n";
        exit(0);
        break;
    default:
        cout << "Please enter a valid choice!\n";
        runProgram();
        break;
    }
    goBackMenu();
    cout << "Qutting program;\n";
}
char menu()
{
    char c = 0;
    cout << "*****************************************\n"
         << "*\tMENU\n"
         << "*****************************************\n"
         << "\t[Options]\n"
         << "[1]->\tCreate a Link List\n"
         << "[2]->\tQuit Program\n"
         << "*****************************************\n";
    cout << "\nEnter your choice: ";
    cin >> c;
    if (checkInput())
        menu();
    return c;
}

void goBackMenu()
{
    char ans = 0;
    do
    {
        cout << "Do you want to go back to menu? ";
        cin >> ans;
        ans = tolower(ans);
    } while (!(ans != 'y' || ans != 'n'));
    if (ans == 'y')
    {
        runProgram();
    }
}

void createLinkList()
{
    LinkList *newList = NULL;
    newList = new LinkList();

    cout << "Linked List Created!\n";
    cout << "Choose a command to modify the list!\n";
    commandsMenu(newList);
    newList = NULL;
    delete newList;
    system("cls");
    cout << "Session ended\n";
}

void commandsMenu(LinkList *chain)
{
    system("cls");
    char cmd = 0;
    cin.clear();
    cout << "*****************************************\n"
         << "*\tLinked List Methods\n"
         << "*****************************************\n"
         << "\t[Options]\n"
         << "[a]->\tAdd node.\n"
         << "[s]->\tSearch node.\n"
         << "[d]->\tDelete node.\n"
         << "[p]->\tPrint list.\n"
         << "[q]->\tQuit Link List.\n"
         << "*****************************************\n";
    cout << "\nChoose a method to use: ";
    cin >> cmd;
    switch (cmd)
    {
    case 'a':
        cmdAdd(chain);
        break;
    case 's':
        cmdSearch(chain);
        break;
    case 'd':
        cmdDelete(chain);
        break;
    case 'p':
        chain->print();
        cout << "\n";
        system("pause");
        commandsMenu(chain);
    case 'q':
        cout << "Quitting session...\n";
        break;

    default:
        system("cls");
        cout << "Unknown command!\n";
        commandsMenu(chain);
        break;
    }
}

void cmdAdd(LinkList *chain)
{
    int n = 0;
    char c = 0;
    cout << "\nEnter a node: ";
    cin >> n;
    if (checkInput())
        cmdAdd(chain);

    chain->addNode(n);
    cout << "Node added.\n";
    chain->print();
    do
    {
        cout << "\nAdd again (y/n)? ";
        cin >> c;
        c = tolower(c);
    } while (!(c == 'y' || c == 'n'));
    if (c == 'n')
        commandsMenu(chain);
    else
        cmdAdd(chain);
}

void cmdDelete(LinkList *chain)
{
    int n = 0;
    char c = 0;
    if (chain->head == NULL)
    {
        cout << "\nPlease add a node first!\n";
        system("pause");
        commandsMenu(chain);
    }

    cout << "\nDelete a node: ";
    cin >> n;
    if (checkInput())
        cmdAdd(chain);

    bool isDeleted = chain->deleteNode(n);
    if (isDeleted)
        cout << "Node deleted successfully.\n";
    else
        cout << "Node not found.\n";
    chain->print();
    do
    {
        cout << "\nTry again (y/n)? ";
        cin >> c;
        c = tolower(c);
    } while (!(c == 'y' || c == 'n'));
    if (c == 'n')
        commandsMenu(chain);
    else
        cmdDelete(chain);
}

void cmdSearch(LinkList *chain)
{
    int n = 0;
    char c = 0;
    if (chain->head == NULL)
    {
        cout << "\nPlease add a node first!\n";
        system("pause");
        commandsMenu(chain);
    }
    cout << "\nSearch a node: ";
    cin >> n;
    if (checkInput())
        cmdAdd(chain);

    bool isNode = chain->searchNode(n);
    if (isNode)
        cout << "Node found successfully.\n";
    else
        cout << "Node not found.\n";
    do
    {
        cout << "\nTry again (y/n)? ";
        cin >> c;
        c = tolower(c);
    } while (!(c == 'y' || c == 'n'));
    if (c == 'n')
        commandsMenu(chain);
    else
        cmdDelete(chain);
}

bool checkInput()
{
    if (cin.fail())
    {
        cout << "An error occured!\nPlease input again.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return true;
    }
    return false;
}