#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vec;
    char cChoice = '\0';
    int iValue = 0, iSmall = 0, iLarge = 0, iSum = 0, iNo = 0, iCount = 0;
    double iMean = 0.0;

    while(1)
    {
        cout <<"\nP - Print numbers" << endl;
        cout <<"A - Add a number" << endl;
        cout <<"M - Display mean of the numbers" << endl;
        cout <<"S - Display smallest numbers" << endl;
        cout <<"L - Display largest numbers" << endl;
        cout <<"F - Find the quantity of number present in list" << endl;
        cout <<"Q - Quit" << endl;

        cout <<"\n Enter your choice: ";
        cin >> cChoice;

        switch(cChoice)
        {
            case 'P':
            case 'p':
            {
                if(vec.size() == 0)
                {
                    cout << "[] - the list is empty";
                }
                
                cout << "[ ";
                for(int iCnt = 0; iCnt < vec.size(); iCnt++)
                {
                    cout << vec.at(iCnt) << " ";
                }
                cout << "]" << endl;
                break;
            }
            case 'A':
            case 'a':
            {
                cout << "Enter an integer to add to the list: ";
                cin >> iValue;
                vec.push_back(iValue);
                cout << iValue << " added" << endl;
                break;
            }
            case 'M':
            case 'm':
            {
                if(vec.size() == 0)
                {
                    cout << "Unable to calculate mean - No data" << endl;
                }

                for(int iCnt = 0; iCnt < vec.size(); iCnt++)
                {
                    iSum += vec.at(iCnt);
                }

                iMean = static_cast <double> (iSum) / vec.size();

                cout << "The mean is : " << iMean << endl;
                break;
            }
            case 'S':
            case 's':
            {
                int iSmall = vec.at(0);

                if(vec.size() == 0)
                {
                    cout << "Unable to find small number - No data" << endl;
                }

                for(int iCnt = 0; iCnt < vec.size(); iCnt++)
                {
                    if(vec.at(iCnt) < iSmall)
                    {
                        iSmall = vec.at(iCnt);
                    }
                }

                cout << "The smallest number is : " << iSmall << endl;
                break;
            }
            case 'L':
            case 'l':
            {
                if(vec.size() == 0)
                {
                    cout << "Unable to find large number - No data" << endl;
                }

                for(int iCnt = 0; iCnt < vec.size(); iCnt++)
                {
                    if(vec.at(iCnt) > iLarge)
                    {
                        iLarge = vec.at(iCnt);
                    }
                }

                cout << "The largest number is : " << iLarge << endl;
                break;
            }
            case 'F':
            case 'f':
            {
                iCount = 0;

                if(vec.size() == 0)
                {
                    cout << "Unable to find this number - No data" << endl;
                }

                cout << "Enter a number to find : ";
                cin >> iNo;
                for(int iCnt = 0; iCnt < vec.size(); iCnt++)
                {
                    if(vec.at(iCnt) == iNo)
                    {
                        iCount++;
                    }
                }
                cout << "The number " << iNo << " appeared " << iCount << " times in list." << endl;
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