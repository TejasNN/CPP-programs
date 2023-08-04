// Accept a number and return modified number if the specified bit is ON by turning it OFF

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT OffBit(UINT iNo)
{
    UINT iMask = 0X00000040;

    UINT iResult = 0; 

    iResult = iNo & iMask;

    if(iResult == iMask)        // Bit is ON
    {
        return (iNo ^ iMask);
    }
    else                        // Bit is OFF
    {
        return iNo;
    }
}

int main()
{
    UINT iValue = 0, iRet = 0;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    iRet = OffBit(iValue);

    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}