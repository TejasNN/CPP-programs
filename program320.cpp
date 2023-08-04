#include<iostream>
using namespace std;

typedef class Node
{
    public:
        int data;
        struct Node *next;
        struct Node *prev;

        Node()
        {
            data = 0;
            next = NULL;
            prev = NULL;
        }

        Node(int iValue)
        {
            data = iValue;
            next = NULL;
            prev = NULL;
        }

}NODE,*PNODE;

class LinkedList
{
    public:
        PNODE First;
        int iCount;

        LinkedList()
        {
            First = NULL;
            iCount = 0;
        }
        
        virtual void InsertFirst(int iNo) = 0;
        virtual void InsertLast(int iNo) = 0;
        virtual void InsertAtPos(int iNo, int iPos) = 0;

        virtual void DeleteFirst() = 0;
        virtual void DeleteLast() = 0;
        virtual void DeleteAtPos(int iPos) = 0;

        void Display()
        {
            PNODE temp = First;

            cout<<"Elements of the linked List are : "<<"\n";

            for(int iCnt = 1; iCnt <= iCount; iCnt++)
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }
            cout<<"NULL"<<"\n";
        }
        
        int Count()
        {
            return iCount;
        }    
};

class DoublyCL : public LinkedList
{
    private:
        PNODE Last;

    public:
        DoublyCL();
        ~DoublyCL();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos); 
};

DoublyCL::DoublyCL()
{
    Last = NULL;
}

DoublyCL :: ~DoublyCL()
{}

void DoublyCL :: InsertFirst(int iNo)
{
    PNODE newn = new NODE(iNo);

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;    
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

void DoublyCL :: InsertLast(int iNo)
{
    PNODE newn = new NODE(iNo);

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;    
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = Last->next;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

void DoublyCL :: DeleteFirst()
{
    if(iCount == 0)             // LL is empty
    {
        return;    
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                        // LL contains more than one node
    {
        First = First->next;
        delete First->prev;     // delete Last->next;

        Last->next = First;
        First->prev = Last;
    }

    iCount--;
}

void DoublyCL :: DeleteLast()
{
    if(iCount == 0)             // LL is empty
    {
        return;    
    }
    else if(iCount == 1)        // LL contains one node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else                        // LL contains more than one node
    {
        Last = Last->prev;
        delete Last->next;

        Last->next = First;
        First->prev = Last;
    }
    
    iCount--;
}

void DoublyCL :: InsertAtPos(int iNo, int iPos)
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

        PNODE newn = new NODE(iNo);

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

void DoublyCL :: DeleteAtPos(int iPos)
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
    
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

int main()
{
    DoublyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    cout<<"Length of Linked List is : "<<obj.Count()<<"\n";

    obj.InsertAtPos(55,4);

    obj.Display();
    cout<<"Length of Linked List is : "<<obj.Count()<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();
    cout<<"Length of Linked List is : "<<obj.Count()<<"\n";

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    cout<<"Length of Linked List is : "<<obj.Count()<<"\n";

    return 0;
}