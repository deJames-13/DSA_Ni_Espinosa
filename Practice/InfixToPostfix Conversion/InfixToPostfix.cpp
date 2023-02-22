#include <iostream>
#include <stack>
using namespace std;

bool isHigher(char top, char curr);

int main()
{
    stack<char> opStacks;
    string operators = "^*/+-";
    string input;
    string output;

    cout << "Insert an infix expression: ";
    getline(cin, input); // ASSUMING THAT THE INFIX EXPRESSION IS ACCURATE
    cout << endl;

    for (int i = 0; i < input.length(); i++)
    {
        char curr = input[i];
        if (curr == ' ')
            continue;

        if (curr == '(')
            opStacks.push(curr);
        else if (curr == ')')
        {
            while (opStacks.top() != '(')
            {
                output += opStacks.top();
                opStacks.pop();
            }
            opStacks.pop();
        }
        else if (operators.find(curr) != operators.npos)
        {
            while (!opStacks.empty() && isHigher(opStacks.top(), curr))
            {
                output += opStacks.top();
                opStacks.pop();
            }
            opStacks.push(curr);
        }
        else
        {
            output += curr;
        }
    }
    while (!opStacks.empty())
    {
        // if (opStacks.top() != '(')
        output += opStacks.top();
        opStacks.pop();
    }

    cout << "Postfix: " << output << endl;
    return 0;
}

bool isHigher(char top, char curr)
{
    switch (top)
    {
    case '^':
        return 1;
    case '*':
        if (curr == '^')
            return 0;
        return 1;
    case '/':
        if (curr == '^')
            return 0;
        return 1;
    case '+':
        if (curr == '^' || curr == '*' || curr == '/')
            return 0;
        return 1;
    case '-':
        if (curr == '^' || curr == '*' || curr == '/')
            return 0;
        return 1;
    default:
        return 0;
    }
}