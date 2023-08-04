#include<iostream>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////

// Structure for singly linear and singly circular

//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

//////////////////////////////////////////////////////////////////////////////////////////////

// Structure for doubly linear and doubly circular

//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

//////////////////////////////////////////////////////////////////////////////////////////////

// Class of singly linear linked list

//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLL
{
    public:
        struct NodeS<T> * first;
        int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
SinglyLL <T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL <T>::Display()
{
    cout<<"Elements of Singly Linear linked list are: "<<"\n";

    NodeS<T> * temp = first;

    while(temp!= NULL)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL <T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL <T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;
        NodeS<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyLL <T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        first = first->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL <T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL <T>::DeleteAtPos(int iPos)
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
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        
        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////

// Class of singly circular linked list

//////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCL
{
    public:
        struct NodeS<T> * first;
        struct NodeS<T> * last;
        int iCount;

    SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL <T>::Display()
{
    cout<<"Elements of Singly circular linked list are: "<<"\n";

    NodeS<T> * temp = first;

    for(int iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int SinglyCL <T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL <T>::InsertFirst(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL <T>::InsertLast(T no)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->data = no;
    newn->next = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        last = last->next;
    }
    last->next = first;
    iCount++;
}

template <class T>
void SinglyCL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> * newn = new NodeS<T>;
        NodeS<T> *temp = first;

        newn->data = no;
        newn->next = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL <T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
        iCount--;
    }
}

template <class T>
void SinglyCL <T>::DeleteLast()
{
    NodeS<T> * temp = first;

    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        do
        {
            temp = temp->next;
        }while(temp->next != last);

        delete temp->next;
        last = temp;
        last->next = first;
        iCount--;
    }
}

template <class T>
void SinglyCL <T>::DeleteAtPos(int iPos)
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
        NodeS<T> * temp1 = first;
        NodeS<T> * temp2 = NULL;
        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        
        temp2 = temp1->next->next;
        delete temp1->next;
        temp1->next = temp2;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly linear linked list

//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
    public:
        struct NodeD<T> * first;
        int iCount;

    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
DoublyLL <T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL <T>::Display()
{
    cout<<"Elements of Doubly linear linked list are: "<<"\n";

    NodeD<T> * temp = first;

    cout<<"NULL <=> ";
    while(temp!= NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<" NULL"<<"\n";
}

template <class T>
int DoublyLL <T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL <T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL <T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;
    NodeD<T> * temp = first;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL <T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL <T>::DeleteLast()
{
    NodeD<T> * temp = first;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    { 
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL <T>::DeleteAtPos(int iPos)
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
        NodeD<T> * temp = first;

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

//////////////////////////////////////////////////////////////////////////////////////////////

// Class of doubly circular linked list

//////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
    public:
        struct NodeD<T> * first;
        struct NodeD<T> * last;
        int iCount;

    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);        
};

template <class T>
DoublyCL <T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL <T>::Display()
{
    cout<<"Elements of Doubly circular linked list are: "<<"\n";

    NodeD<T> * temp = first;

    if((first != NULL) && (last != NULL))
    {
        do
        {
            cout<<"| "<<temp->data<<" | <=> ";
            temp = temp->next;
        }while(temp != last->next);
        cout<<"\n";
    }
}

template <class T>
int DoublyCL <T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL <T>::InsertFirst(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL <T>::InsertLast(T no)
{
    NodeD<T> * newn = new NodeD<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCL <T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> * newn = new NodeD<T>;
        NodeD<T> * temp = first;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++; 
    }  
}

template <class T>
void DoublyCL <T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }
    
    iCount--;
}

template <class T>
void DoublyCL <T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    
    iCount--;
}

template <class T>
void DoublyCL <T>::DeleteAtPos(int iPos)
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
        NodeD<T> * temp = first;

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

//////////////////////////////////////////////////////////////////////////////////////////////
// Entry point function
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL <int>obj1;
    SinglyCL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCL <int>obj4;

    return 0;
}