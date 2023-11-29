// Program to cyclically rotate an array by one

#include <iostream>
using namespace std;

void arrayRotationByOne(int arr[], int iSize)
{
    int iStart = 0, iEnd = iSize - 1, iTemp = 0;
    while(iStart != iEnd)
    {
        iTemp = arr[iStart];
        arr[iStart] = arr[iEnd];
        arr[iEnd] = iTemp;
        iStart++;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int iSize = 0;
    iSize = sizeof(arr) / sizeof(arr[0]);

    arrayRotationByOne(arr, iSize);

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << arr[iCnt] << " ";
    }
    cout << endl;

    arrayRotationByOne(arr, iSize);         // rotate array by two

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << arr[iCnt] << " ";
    }
    cout << endl;

    arrayRotationByOne(arr, iSize);         // rotate array by three

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << arr[iCnt] << " ";
    }
    cout << endl;
    
    return 0;
}