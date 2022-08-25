// 2. Write a program which displays all elements which are prime from singly 
// linear linked list. 
// Function Prototype :
// int DisplayPrime( PNODE Head); 
// Input linked list : |11|->|20|->|17|->|41|->|22|->|89| 
// Output : 11 17 41 89

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE Head,int no)
{
    PNODE newn=NULL;

    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if((*Head)==NULL)
    {
        (*Head)=newn;
    }
    else
    {
        newn->next=(*Head);
        (*Head)=newn;
    }
}

void DisplayPrime(PNODE Head)
{
    while(Head!=NULL)
    {
        int iNo=Head->data,i=0;
    
        for(i=2;i<=iNo/2;i++)
        {
             if((iNo%i)==0)
            {
                break;
            }
            else
            {
                printf("%d  ",iNo);
                break;
            }
        }
        Head=Head->next;
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,89);
    InsertFirst(&first,22);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    
    DisplayPrime(first);
    return 0;
}