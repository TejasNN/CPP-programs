// Accept a number and position of bit and return modified number if the specified bit is ON by turning it OFF or if the bit is OFF return the same number as is

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
    iMask = ~iMask;                     // Important to note that we toggled iMask from all 0's to all 1's bits

    iResult = iNo & iMask;

    return iResult;
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