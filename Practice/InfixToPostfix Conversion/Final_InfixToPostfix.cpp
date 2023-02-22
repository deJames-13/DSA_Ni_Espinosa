#include <iostream>
#include <stack>
using namespace std;

bool isHigher(char top, char curr);
void popGroup(stack<char> *op, string *res);
void popHigher(stack<char> *op, string *res, char curr);
void popAll(stack<char> *op, string *res);

int main()
{
    string input, output;
    stack<char> opStacks;

    // const means DO NOT CHANGE
    const string validOperands = "qwertyuiopasdfghjklzxcvbnm"; // Restrict operands to alphabet only, any other characters will be ignored
    const string operators = "^*/+-";                          // valid operators

    cout << "Insert an infix expression: ";
    // STEP 1;
    getline(cin, input); // ASSUMING THAT THE INFIX EXPRESSION IS ACCURATE
    cout << endl;

    for (int i = 0; i < input.length(); i++)
    {
        char curr = input[i];

        // STEP 2;
        if (validOperands.find(tolower(curr)) != validOperands.npos)
            output += curr;
        // STEP 3;
        else if (curr == '(')
            opStacks.push(curr);
        // STEP 4;
        else if (operators.find(curr) != operators.npos)
            popHigher(&opStacks, &output, curr);
        // STEP 5;
        else if (curr == ')')
            popGroup(&opStacks, &output);
    }
    // STEP 6;
    popAll(&opStacks, &output);

    // PRINT OUTPUT
    cout << "Postfix: " << output << endl;
    return 0;
}

void popAll(stack<char> *op, string *res)
{
    // this function pops the remaining operators base on STEP 6
    while (!(*op).empty())
    {
        *res += (*op).top();
        (*op).pop();
    }
}

void popGroup(stack<char> *op, string *res)
{
    // this function pops all operators inside the pair of parenthesis
    while ((*op).top() != '(')
    {
        *res += (*op).top();
        (*op).pop();
    }
    (*op).pop();
}

void popHigher(stack<char> *op, string *res, char curr)
{
    // this function pops the TOP of stack base on STEP 4
    while (!(*op).empty() && isHigher((*op).top(), curr))
    {
        (*res) += (*op).top();
        (*op).pop();
    }
    (*op).push(curr);
}

bool isHigher(char top, char curr)
{
    // this function returns if the operator is higher than the current character
    // defaults to false;
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