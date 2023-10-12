/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number, two positions from user and check whether bit at first
//                      position or bit at second position is ON or OFF.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;
typedef int BOOL;

#define TRUE 1
#define FALSE 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		CheckBit
//	Input :				unsigned integer
//	Output :			Boolean
// 	Description :		Returns true if any of two input position bits are ON. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CheckBit(UINT iNo, UINT iPos1, UINT iPos2)
{
    UINT iResult = 0;
    UINT iMask1 = 0X00000001;
    UINT iMask2 = 0X00000001;
    UINT iMask = 0X00000000;

    if((iPos1 < 1) || (iPos1 > 32) || (iPos2 < 1) || (iPos2 > 32))
    {
        cout<<"Invalid input"<<"\n";
        return FALSE;
    }

    iMask1 = iMask1 << (iPos1 - 1);
    iMask2 = iMask2 << (iPos2 - 1);

    iMask = iMask1 | iMask2;

    iResult = iNo & iMask;

    if((iResult == iMask1) || (iResult == iMask2))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//	Entry point function													   //
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    UINT iValue = 0, iBit1 = 0, iBit2 = 0;
    BOOL bRet = FALSE;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    cout<<"Enter the first bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit1;

    cout<<"Enter the second bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit2;

    bRet = CheckBit(iValue,iBit1,iBit2);

    if(bRet == TRUE)
    {
        cout<<"Bits are ON"<<"\n";
    }
    else
    {
        cout<<"Bits are OFF"<<"\n";
    }

    return 0;
}
// Time complexity : O(log n)