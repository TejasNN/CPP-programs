// Accept a number and return modified number if the specified bit is ON by turning it OFF or just return the same number

#include<iostream>
using namespace std;

typedef unsigned int UINT;

UINT OffBit(UINT iNo)
{
    UINT iResult = 0; 
    return (iNo & 0XFFFFFFBF);  
}

int main()
{
    UINT iValue = 0, iRet = 0, iBit = 0;

    cout<<"Enter number : "<<"\n";
    cin>>iValue;

    iRet = OffBit(iValue);

    cout<<"Result is : "<<iRet<<"\n";

    return 0;
}