#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}NODE,*PNODE,**PPNODE;

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
{}

int main()
{
    int iRet = 0;

    SinglyLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.Display();

    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj1.InsertAtPos(55,4);

    obj1.Display();

    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();

    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    return 0;
}