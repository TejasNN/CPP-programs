#include <iostream>
#include <vector>
using namespace std;

void printNumbers(const vector<int> &num)
{
    if(num.size() == 0)
    {
        cout << "[] - the list is empty" << endl;
        return;
    }
    cout << "[ ";
    for(int number : num)
    {
        cout << number << " ";
    }
    cout << "]";
}

void AddNumber(vector<int> &num, int iNo)
{
    num.push_back(iNo);
}

double MeanNumber(const vector<int> &num)
{
    double dMean = 0.0;
    int iSum = 0;
    if(num.size() == 0)
    {
        cout << "Unable to calculate mean - No data" << endl;
        return 0;
    }
    for(int iCnt = 0; iCnt < num.size(); iCnt++)
    {
        iSum += num.at(iCnt);
    }
    dMean = static_cast <double> (iSum) / num.size();
    return dMean;
}

int SmallestNumber(const vector<int> &num)
{
    int iSmall = num.at(0);

    if(num.size() == 0)
    {
        cout << "Unable to find small number - No data" << endl;
        return 0;
    }
    for(int iCnt = 0; iCnt < num.size(); iCnt++)
    {
        if(num.at(iCnt) < iSmall)
        {
            iSmall = num.at(iCnt);
        }
    }
    return iSmall;
}

int LargestNumber(const vector<int> &num)
{
    int iLarge = 0;

    if(num.size() == 0)
    {
        cout << "Unable to find small number - No data" << endl;
        return 0;
    }
    for(int iCnt = 0; iCnt < num.size(); iCnt++)
    {
        if(num.at(iCnt) > iLarge)
        {
            iLarge = num.at(iCnt);
        }
    }
    return iLarge;
}

int NumberInstances(const vector<int> &num, int iNo)
{
    int iCount = 0;
    if(num.size() == 0)
    {
        cout << "Unable to find this number - No data" << endl;
        return 0;
    }
    for(int iCnt = 0; iCnt < num.size(); iCnt++)
    {
        if(num.at(iCnt) == iNo)
        {
            iCount++;
        }
    }
    return iCount;
}

void ClearList(vector<int> &num)
{
    num.clear();
}

int main()
{
    vector <int> numbers;
    char cChoice = '\0';
    while(1)
    {
        cout <<"\nP - Print numbers" << endl;
        cout <<"A - Add a number" << endl;
        cout <<"M - Display mean of the numbers" << endl;
        cout <<"S - Display smallest numbers" << endl;
        cout <<"L - Display largest numbers" << endl;
        cout <<"F - Count the instances of number present in list" << endl;
        cout <<"C - Clear the list" << endl;
        cout <<"Q - Quit" << endl;

        cout <<"\n Enter your choice: ";
        cin >> cChoice;

        switch(cChoice)
        {
            case 'P':
            case 'p':
            {
                printNumbers(numbers);
                break;
            }
            case 'A':
            case 'a':
            {
                int iValue = 0;
                cout << "Enter an integer to add to the list: ";
                cin >> iValue;
                AddNumber(numbers, iValue);
                cout << iValue << " added" << endl;
                break;
            }
            case 'M':
            case 'm':
            {
                double dMean = 0.0;
                dMean = MeanNumber(numbers);
                cout << "The mean is : " << dMean << endl;
                break;
            }
            case 'S':
            case 's':
            {
                int iSmall = 0;
                iSmall = SmallestNumber(numbers);
                cout << "The smallest number is : " << iSmall << endl;
                break;
            }
            case 'L':
            case 'l':
            {
                int iLarge = 0;

                iLarge = LargestNumber(numbers);

                cout << "The largest number is : " << iLarge << endl;
                break;
            }
            case 'F':
            case 'f':
            {
                int iCount = 0, iNo = 0;
                cout << "Enter a number to find : ";
                cin >> iNo;
                iCount = NumberInstances(numbers, iNo);
                cout << "The number " << iNo << " appeared " << iCount << " times in list." << endl;
                break;
            }
            case 'C':
            case 'c':
            {
                ClearList(numbers);
                cout << "The list has been cleared successfully." << endl;
                break;
            }
            case 'Q':
            case 'q':
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Unknown selection, please try again" << endl;
                break;
        }
    }

    return 0;
}