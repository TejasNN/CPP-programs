#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE;

class SinglyLL
{
    private:
        PNODE First;        // Characteristics
        int iCount;         // Characteristics

    public:
        SinglyLL();
        ~SinglyLL();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

void SinglyLL:: InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;    // c code : newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(First == NULL)   // LL is empty
    {
        First = newn;        
    }
    else                // LL contains at least one node in it
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

void SinglyLL:: InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;    // c code : newn = (PNODE)malloc(sizeof(NODE));

    newn->data = iNo;
    newn->next = NULL;

    if(First == NULL)   // LL is empty
    {
        First = newn;        
    }
    else                // LL contains at least one node in it
    {
        PNODE temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }    

        temp->next = newn;
    }
    iCount++;
}

void SinglyLL :: DeleteFirst()
{
    if(First == NULL)               //  Empty LL
    {
        return;
    }
    else if(First->next == NULL)    //  Single node in LL
    {
        delete First;              //  free(First);
        First = NULL;        
    }
    else                            //  More than one node in LL
    {
        PNODE temp = First;

        First = First->next;    
        delete temp;
    }
    iCount--;
}

void SinglyLL :: DeleteLast()
{
    if(First == NULL)               //  Empty LL
    {
        return;
    }
    else if(First->next == NULL)    //  Single node in LL
    {
        delete First;              //  free(First);
        First = NULL;        
    }
    else                            //  More than one node in LL
    {
        PNODE temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

void SinglyLL:: Display()
{
    PNODE temp = First;

    cout<<"Elements of the linked list are : "<<"\n";

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<" NULL"<<"\n";
}

int SinglyLL:: Count()
{
    return iCount;
}

SinglyLL :: SinglyLL()
{
    cout<<"Inside constructor"<<"\n";

    First = NULL;
    iCount = 0;
}

SinglyLL :: ~SinglyLL()
{
    cout<<"Inside destructor"<<"\n";
    PNODE temp = NULL;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        temp = First;
        First = First->next;
        delete temp;
    }
}

void SinglyLL :: InsertAtPos(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE temp = First;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        PNODE newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

void SinglyLL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = First;
        PNODE tempX = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        tempX = temp->next;
        temp->next = temp->next->next;

        delete tempX;

        iCount--;
    }    
}

int main()
{
    SinglyLL obj;
    int iChoice = 0;
    int iValue = 0;
    int iPosition = 0;

    cout<<"Marvellous LinkedList Application\n";

    while(1)            // Unconditional loop where it only breaks if we write break keyword
    {
        cout<<"-----------------------------------------------------------------\n";
        
        cout<<"Please enter your choice\n";

        cout<<"1 : Insert node at first position\n";
        cout<<"2 : Insert node at last position\n";
        cout<<"3 : Insert node at the given position\n";
        cout<<"4 : Delete node from first position\n";
        cout<<"5 : Delete node from last position\n";
        cout<<"6 : Delete node from the given position\n";
        cout<<"7 : Display the elements of linked list\n";
        cout<<"8 : Count the number of nodes from linked list\n";
        cout<<"9 : Terminate the application\n";

        cout<<"-----------------------------------------------------------------\n";

        cin>>iChoice;

        cout<<"-----------------------------------------------------------------\n";

        switch(iChoice)
        {
            case 1:
                cout<<"Enter the value that you want to insert : \n";
                cin>>iValue;
                obj.InsertFirst(iValue);
                break;
            
            case 2:
                cout<<"Enter the value that you want to insert : \n";
                cin>>iValue;
                obj.InsertLast(iValue);
                break;

            case 3:
                cout<<"Enter the value that you want to insert : \n";
                cin>>iValue;

                cout<<"Enter the position : \n";
                cin>>iPosition;

                obj.InsertAtPos(iValue,iPosition);
                break;

            case 4:
                obj.DeleteFirst();
                break;

            case 5:
                obj.DeleteLast();
                break;

            case 6:
                cout<<"Enter the position : \n";
                cin>>iPosition;
                obj.DeleteAtPos(iPosition);
                break;

            case 7:
                obj.Display();
                break;
            
            case 8:
                cout<<"Number of elements are : "<<obj.Count()<<"\n";
                break;

            case 9:
                cout<<"Thank you for using the application\n";
                return 0;

            default:
                cout<<"Invalid choice\n";
                break;
        }
    }

    return 0;
}