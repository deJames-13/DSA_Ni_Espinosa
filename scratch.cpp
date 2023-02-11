#include <iostream>
using namespace std;

int main()
{
    int iCounter = 0;
    int start = 11;
    while (iCounter != 10)
    {
        cout << start << "\n";
        start += 2;
        iCounter++;
    }

    return 0;
}