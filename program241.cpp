// Aceept a number and position from user and check if that position bit is on or off 

#include<iostream>
using namespace std;

typedef unsigned int UINT;

bool CheckBit(UINT iNo, UINT iPos)
{
    UINT iMask = 0X00000001;
    UINT iResult = 0;

    if((iPos < 1) ||(iPos > 32))
    {
        cout<<"Invalid posiiton"<<"\n";
        return false;
    } 

    iMask = iMask << (iPos - 1);

    iResult = iNo & iMask;
    if(iResult == iMask)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    UINT iValue = 0, iBit = 0;
    bool bRet = false;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    cout<<"Enter the bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit;

    bRet = CheckBit(iValue, iBit);

    if(bRet == true)
    {
        cout<<"Bit is ON"<<"\n";
    }
    else
    {
        cout<<"Bit is OFF"<<"\n";
    }
    return 0;
}