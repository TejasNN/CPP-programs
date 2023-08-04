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
	
};

int main()
{
	int iValue = 0;
	int iRet = 0;
	
	cout<<"Enter a number : "<<"\n";
	cin>>iValue;
	
	Digit dobj(iValue);
	
	return 0;
}