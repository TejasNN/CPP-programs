/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number, position from user and toggle contents of first and last nibble 
//                      of that number (nibble is a group of 4 bits). Return modified number.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		ToggleBit
//	Input :				unsigned integer
//	Output :			unsigned integer
// 	Description :		Returns modified number after toggling the first and last nibble. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UINT ToggleBit(UINT iNo)
{
    UINT iResult = 0;
    UINT iMask1 = 0X0000000F;
    UINT iMask2 = 0X0000000F;
    UINT iMask = 0X00000000;


    if((iNo < 256) || (iNo > 16))
    {
        iMask2 = 0X000000F0;
    }
    else if((iNo < 4095) || (iNo > 256))
    {
        iMask2 = 0X00000F00;
    }
    else
    {
        iMask2 = 0X0000F000;
    }

    iMask = iMask1 | iMask2;

    iResult = iNo ^ iMask;

    return iResult;
}

/////////////////////////////////////////////////////////////////////////////////
//	Entry point function													   //
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    UINT iValue = 0;
    UINT iRet = 0;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    iRet = ToggleBit(iValue);

    cout<<"The modified number is :"<<iRet<<"\n";

    return 0;
}
// Time complexity : NA