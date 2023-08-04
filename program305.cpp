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

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

// Implementations of all the behaviours

/*
    Return_Value Class_Name :: Function_Name(Parameter_List)
    {
        Function_Body;
    }
*/

void SinglyLL :: InsertFirst(int iNo)
{}

void SinglyLL :: InsertLast(int iNo)
{}

void SinglyLL :: InsertAtPos(int iNo, int iPos)
{}

void SinglyLL :: DeleteFirst()
{}

void SinglyLL :: DeleteLast()
{}

void SinglyLL :: DeleteAtPos(int iPos)
{}

void SinglyLL :: Display()
{}

int SinglyLL :: Count()
{
    return 0;
}

SinglyLL :: SinglyLL()
{}

int main()
{
    SinglyLL obj1;
    
    return 0;
}