////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number and range of position from the user.Toggle all bits from that range.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		ToggleBitRange
//	Input :				unsigned integer
//	Output :			unsigned integer
// 	Description :		Returns modified number after toggling input range of bits. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UINT ToggleBitRange(UINT iNo, UINT iStart, UINT iEnd)
{
    UINT iResult = iNo;
    UINT iMask = 0X00000001;

    for(iMask = iStart; iMask <= iEnd; iMask++)
    {
        if((iNo & (1 <<(iMask - 1))) != 0)
        {
            iResult = iResult ^ (1 <<(iMask - 1));
        }
        else
        {
            iResult = iResult | (1 <<(iMask - 1));
        }
    }
    
    return iResult;
}

/////////////////////////////////////////////////////////////////////////////////
//	Entry point function													   //
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    UINT iValue = 0, iBit1 = 0, iBit2 = 0, iRet = 0;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    cout<<"Enter the first bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit1;

    cout<<"Enter the second bit position (Range should be 1 to 32)"<<"\n";
    cin>>iBit2;

    iRet = ToggleBitRange(iValue,iBit1,iBit2);

    cout<<"The modified number is : "<<iRet<<"\n";

    return 0;
}
// Time complexity : O(log n)