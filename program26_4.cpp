///////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which checks whether 7th, 8th and 9th bit is ON or OFF. 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef int BOOL;
typedef unsigned int UINT;

#define TRUE 1
#define FALSE 0

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		CheckBit
//	Input :				unsigned integer
//	Output :			boolean
// 	Description :		Returns true if 7th, 8th and 9th bit of the input number is 1.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				06/06/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CheckBit(UINT iNo)
{
    UINT iMask = 0X000001C0;
    UINT iResult = 0;

    iResult = iNo & iMask;

    if(iResult == iMask)
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
        cout<<"7th, 8th and 9th bit is ON"<<"\n";
    }
    else
    {
        cout<<"7th, 8th and 9th is OFF"<<"\n";
    }

    return 0;
}
// Time complexity : NA