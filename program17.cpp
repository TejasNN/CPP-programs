// Move all negative numbers to beginning and positive to end with constant extra space

#include <iostream>
using namespace std;

int * sortNegative(int arr[], int iSize)
{
    int* iStart = NULL;
    int* iEnd = NULL; 

    iStart = arr;
    iEnd = iStart;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        iEnd++;
    }

    iEnd--;

    int iTemp = 0;
    while(iStart < iEnd)
    {
        if((*iStart > 0) && (*iEnd < 0))
        {
            iTemp = *iStart;
            *iStart = *iEnd;
            *iEnd = iTemp;
            iStart++;
            iEnd--;
        }
        else if(*iStart < 0)
        {
            iStart++;
        }
        else if(*iEnd > 0)
        {
            iEnd--;
        }
    }
    return arr;
}

void Display(int brr[], int iSize)
{
    int *crr = NULL;

    crr = sortNegative(brr, iSize);

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout << crr[iCnt] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int iSize = sizeof(arr) / sizeof(arr[0]);
    Display(arr,iSize);
    return 0;
}