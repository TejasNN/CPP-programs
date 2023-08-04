// Write a program to take two decimal input numbers from user and display thier &, |, ^.
#include<iostream>
using namespace std;

void DisplayBinary(int iNo1, int iNo2)
{
    int iResult = 0;

    iResult = iNo1 & iNo2;
    cout<<"Result of & is :"<<iResult<<"\n";

    iResult = iNo1 | iNo2;
    cout<<"Result of | is :"<<iResult<<"\n";

    iResult = iNo1 ^ iNo2;
    cout<<"Result of ^ is :"<<iResult<<"\n";
}
int main()
{
    int iValue1 = 0, iValue2 = 0;

    cout<<"Enter first number :"<<"\n";
    cin>>iValue1;

    cout<<"Enter second number :"<<"\n";
    cin>>iValue2;

    DisplayBinary(iValue1,iValue2);

    return 0;
}