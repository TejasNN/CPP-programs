// Accept a number and position of bit and return modified number if the specified bit is ON by turning it OFF

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT OffBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;
    UINT iResult = 0; 

    if((iPos < 1) ||(iPos > 32))
    {
        cout<<"Invalid position"<<"\n";
        return false;
    } 
    iMask = iMask << (iPos - 1);

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
    UINT iValue = 0, iRet = 0, iBit = 0;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    cout<<"Enter the bit position (Range should be 1 to 32): "<<"\n";
    cin>>iBit;

    iRet = OffBit(iValue,iBit);

    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}