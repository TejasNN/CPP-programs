// Write a program in which you have to take two int numbers as input and return the addition of those numbers without using the arithmetic operators.

#include <iostream>
using namespace std;

int Addition(int iNo1, int iNo2)
{
    while(iNo2 != 0)
    {
        unsigned carry = iNo1 & iNo2;

        iNo1 = iNo1 ^ iNo2;

        iNo2 = carry << 1;
    }

    return iNo1;
}

int main()
{
    int iValue1 = 0, iValue2 = 0, iRet = 0;

    cout << "Enter two number for addition seperated by space : ";
    cin >> iValue1 >> iValue2;

    iRet = Addition(iValue1, iValue2);

    cout << "The addition is : " << iRet << endl;

    return 0;
}