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

int main()
{
    SinglyLL obj1();
    
    return 0;
}