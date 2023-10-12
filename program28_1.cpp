///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number and position from user and check whether the bit at that position is ON or OFF.
//                      If bit is one return true else return false.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;
typedef int BOOL;

#define TRUE 1
#define FALSE 0

//////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		CheckBit
//	Input :				unsigned integer
//	Output :			Boolean
// 	Description :		Returns true if the input bit is ON in input number. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
/////////////////////////////////////////////////////////////////////////////////

BOOL CheckBit(UINT iNo, UINT iPos)
{
    UINT iResult = 0;
    UINT iMask = 0X00000001;

    if((iPos < 1) || (iPos > 32))
    {
        cout<<"Invalid input"<<"\n";
        return FALSE;
    } 


    iMask = iMask << (iPos - 1);

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
    UINT iValue = 0, iBit = 0;
    BOOL bRet = FALSE;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    cout<<"Enter the bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit;

    bRet = CheckBit(iValue,iBit);

    if(bRet == TRUE)
    {
        cout<<"Bit is ON"<<"\n";
    }
    else
    {
        cout<<"Bit is OFF"<<"\n";
    }

    return 0;
}
// Time complexity : NA