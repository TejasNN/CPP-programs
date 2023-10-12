/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number and check whether 9th or 12th bit is ON or OFF.
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
// 	Description :		Returns true if 9th and 12th bit is ON. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CheckBit(UINT iNo)
{
    UINT iResult = 0;
    UINT iMask1 = 0X00000100;
    UINT iMask2 = 0X00000800;
    UINT iMask = 0X00000000;

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
    UINT iValue = 0;
    BOOL bRet = FALSE;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    bRet = CheckBit(iValue);

    if(bRet == TRUE)
    {
        cout<<"9th or 12th bits are ON"<<"\n";
    }
    else
    {
        cout<<"9th or 12th bits are OFF"<<"\n";
    }

    return 0;
}
// Time complexity : O(log n)