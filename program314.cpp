#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}NODE,*PNODE;

class DoublyCL
{
    private:
        PNODE First;
        PNODE Last;
        int iCount;

    public:
        DoublyCL();
        ~DoublyCL();

        void InsertFirst(int iNo);
        void InsertLast(int iNo);
        void InsertAtPos(int iNo, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count(); 
};

void DoublyCL :: InsertFirst(int iNo)
{}

void DoublyCL :: InsertLast(int iNo)
{}

void DoublyCL :: InsertAtPos(int iNo, int iPos)
{}

void DoublyCL :: DeleteFirst()
{}

void DoublyCL :: DeleteLast()
{}

void DoublyCL :: DeleteAtPos(int iPos)
{}

int main()
{
    return 0;
}
