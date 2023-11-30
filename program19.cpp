// Count pairs with given sum

#include <iostream>
#include <unordered_map>
using namespace std;

int CountPairsUsingNested(int arr[], int iSize, int iSum)
{
    int iCount = 0;
    for(int i = 0; i < iSize; i++)
    {
        for(int j = i+1; j < iSize; j++)
        {
            if((arr[i] + arr[j]) == iSum)
            {
                iCount++;
            }   
        }
    }
    return iCount;
}

int CountPairsUsingHash(int arr[], int iSize, int iSum)
{
    unordered_map<int,int> countPairs;
    int iCount = 0;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(countPairs.find(iSum - arr[iCnt]) != countPairs.end())
        {
            iCount += countPairs[iSum - arr[iCnt]];
        }
        countPairs[arr[iCnt]]++;
    }
    return iCount;
}

int main()
{
    int arr[] = {1, 5, 7, -1};
    int iSum = 6, iRet = 0;
    int iSize = 0;

    iSize = sizeof(arr) / sizeof(arr[0]);
    iRet = CountPairsUsingNested(arr,iSize,iSum);

    cout << "Count of pairs with sum " << iSum << " is : " << iRet << endl;

    iRet = CountPairsUsingHash(arr,iSize,iSum);

    cout << "Count of pairs with sum " << iSum << " is : " << iRet << endl;

    return 0;
}