// Accept a number and return modified number by toggling the position bit

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT ToggleBit(UINT iNo)
{
    UINT iMask = 0X00000040;

    return (iNo ^ iMask);
}

int main()
{
    UINT iValue = 0, iRet = 0, iBit = 0;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    iRet = ToggleBit(iValue);

    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}