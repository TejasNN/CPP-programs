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

void SinglyLL :: InsertAtPos(int iNo, int iPos)
{}

void SinglyLL :: DeleteFirst()
{}

void SinglyLL :: DeleteLast()
{}

void SinglyLL :: DeleteAtPos(int iPos)
{}

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

int main()
{
    int iRet = 0;

    SinglyLL obj1;
    SinglyLL obj2;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.Display();

    iRet = obj1.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    obj2.InsertFirst(20);
    obj2.InsertFirst(10);
    obj2.InsertLast(30);

    obj2.Display();

    iRet = obj2.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    return 0;
}