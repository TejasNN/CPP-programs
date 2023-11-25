// Two sum problem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void TwoSum(vector<int> &numbers, int iTarget)
{
    sort(numbers.begin(), numbers.end());

    for(auto i : numbers)
    {
        cout << i << " ";
    }
    cout << endl;

    int iStart = 0;
    int iEnd = numbers.size() - 1;
    int iAddition = 0;
    while(iStart < iEnd)
    {
        iAddition = numbers.at(iStart) + numbers.at(iEnd);

        if(iAddition == iTarget)
        {
            cout << numbers.at(iStart) << " " << numbers.at(iEnd) << endl;
            iStart++;
            iEnd--;
        }
        else if(iAddition < iTarget)
        {
            iStart++;
        }
        else if(iAddition > iTarget)
        {
            iEnd--;
        }
    }
}

int main()
{
    vector<int> numbers = {1, -1, -1, 2, 2};
    int iTarget = 1;

    TwoSum(numbers,iTarget);

    return 0;
}