/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number, position from user and OFF that bit. Return modified number.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		OffBit
//	Input :				unsigned integer
//	Output :			unsigned integer
// 	Description :		Returns modified number after turning input bit OFF. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UINT OffBit(UINT iNo, UINT iPos)
{
    UINT iResult = 0;
    UINT iMask = 0X00000001;

    if((iPos < 1) || (iPos > 32))
    {
        cout<<"Invalid input"<<"\n";
        return 0;
    } 

    iMask = iMask << (iPos - 1);

    iResult = iNo ^ iMask;

    return iResult;
}

/////////////////////////////////////////////////////////////////////////////////
//	Entry point function													   //
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    UINT iValue = 0, iBit = 0;
    UINT iRet = 0;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    cout<<"Enter the bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit;

    iRet = OffBit(iValue,iBit);

    cout<<"The modified number is :"<<iRet<<"\n";

    return 0;
}
// Time complexity : NA