// Aceept no from user and check if it's 7th and 14th and 21st bit is on or off 

#include<iostream>
using namespace std;

typedef unsigned int UINT;

bool CheckBit(UINT iNo)
{
    UINT iMask = 0X00102040;
    UINT iResult = 0;

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
    UINT iValue = 0;
    bool bRet = false;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    bRet = CheckBit(iValue);

    if(bRet == true)
    {
        cout<<"7th, 14th and 21st bits are ON"<<"\n";
    }
    else
    {
        cout<<"7th, 14th and 21st bits are OFF"<<"\n";
    }
    return 0;
}