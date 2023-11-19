#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 0, j = 0, k = 0, m = 0;
    string user_string;

    cout << "Enter a string : ";
    cin >> user_string;

    char* ch = &user_string[0];

    for(i = 1; i <= user_string.length(); i++)
    {
        for(j = user_string.length(); j >= i; j--)
        {
            cout << " ";
        }
        for(k = 1; k <= i; k++)
        {
            cout << *ch;
            ch++;
        }
        ch--;
        for(m = 1; m < i; m++)
        {
            --ch;
            cout << *ch;
        }
        cout << endl;
        ch = &user_string[0];
    }
    return 0;
}