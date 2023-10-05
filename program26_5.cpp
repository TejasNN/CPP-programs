//////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which checks whether first and last bit is ON or OFF.
//                      First bit means bit number 1 and last bit means bit 32. 
//
/////////////////////////////////////////////////////////////////////////////////////////////////

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
// 	Description :		Returns true if first and last bit of the input number is 1.  
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				06/06/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOL CheckBit(UINT iNo)
{
    UINT iMask = 0X80000001;
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
        cout<<"first and last bit is ON"<<"\n";
    }
    else
    {
        cout<<"first and last bit is OFF"<<"\n";
    }

    return 0;
}
// Time complexity : NA