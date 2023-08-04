// Write a program to return addition of digits

#include<iostream>
using namespace std;

class Digit
{
	public:
		int iNo;
		
	Digit(int X)
	{
		iNo = X;
	}
	
	int SumDigits()
	{
		int iDigit = 0;
		int iSum = 0;
		
		while(iNo != 0)
		{
			iDigit = iNo % 10;
			iSum = iSum + iDigit;
			iNo = iNo / 10;
		}
		
		return iSum;
	}
};

int main()
{
	int iValue = 0;
	int iRet = 0;
	
	cout<<"Enter a number : "<<"\n";
	cin>>iValue;
	
	Digit dobj1(iValue);
	
	iRet = dobj1.SumDigits();
	
	cout<<"Summation of digits : "<<iRet<<"\n";
	
	cout<<"Enter a number : "<<"\n";
	cin>>iValue;
	
	Digit dobj2(iValue);
	
	iRet = dobj2.SumDigits();
	
	cout<<"Summation of digits : "<<iRet<<"\n";
	
	return 0;
}