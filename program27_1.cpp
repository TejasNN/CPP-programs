///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept one number from user and OFF 7th bit of that number if it is ON.
//                      Return modified number.          
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		OffBit
//	Input :				unsigned integer
//	Output :			unsigned integer
// 	Description :		Returns modified number if the 7th bit of input number is ON by turning it OFF. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				07/06/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////////

UINT OffBit(UINT iNo)
{
    UINT iResult = 0;
    UINT iMask = 0X00000040;

    iResult = iNo & iMask;
    
    if(iResult == iMask)
    {
        return (iNo ^ iMask);
    }
    else
    {
        return iNo;
    }   
}

/////////////////////////////////////////////////////////////////////////////////
//	Entry point function													   //
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    UINT iValue = 0, iRet = 0;

    cout<<"Enter a number :"<<"\n";
    cin>>iValue;

    iRet = OffBit(iValue);

    cout<<"The modified number is : "<<iRet<<"\n";

    return 0;
}
// Time complexity : NA