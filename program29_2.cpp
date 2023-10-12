////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																			                                           
//	Problem statement :	Write a program which accept two numbers and display position of common ON bits from those numbers.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

typedef unsigned int UINT;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Function name :		CommonBits
//	Input :				unsigned integer
//	Output :			unsigned integer
// 	Description :		Displays common ON bits of two input numbers. 
// 	Author :			Tejas Nandakumar Nagvekar
// 	Date :				08/06/2023
// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CommonBits(UINT iNo1, UINT iNo2)
{
    UINT iCnt = 1, iCount = 0;
    UINT iMask = 0X00000001;

    for(iCount = 1; iCount <= 32; iCount++)
    {
        if(((iNo1 & iMask) != 0) && ((iNo2 & iMask) != 0))
        {
            cout<<iCnt<<"\t";
            iCnt++;
            iMask = iMask << 1;
        }
        else
        {
            iCnt++;
            iMask = iMask << 1;
        }
    }

}

/////////////////////////////////////////////////////////////////////////////////
//	Entry point function													   //
/////////////////////////////////////////////////////////////////////////////////

int main()
{
    UINT iValue1 = 0, iValue2 = 0, iRet = 0;

    cout<<"Enter first number :"<<"\n";
    cin>>iValue1;

    cout<<"Enter second number :"<<"\n";
    cin>>iValue2;

    CommonBits(iValue1,iValue2);

    return 0;
}
// Time complexity : O(1)