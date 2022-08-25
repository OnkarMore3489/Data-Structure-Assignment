// 1. Write a program which displays all elements which are perfect from singly 
// linear linked list. 
// Function Prototype :
// int DisplayPerfect( PNODE Head); 
// Input linked list : |11|->|28|->|17|->|41|->|6|->|89| 
// Output : 6 28

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

void DisplayPerfect(PNODE Head)
{
    int iNo=0,i=0,iSum=0;
    while(Head!=NULL)
    {
        iNo=Head->data;
        for(i=1;i<=iNo/2;i++)
        {
            if(iNo%i==0)
            {
              iSum+=i;
            }
        }

        if(iNo==iSum)
        {
          printf("%d  ",iNo);
        }

        Head=Head->next;
        iSum=0;
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,41);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    
    DisplayPerfect(first);
    return 0;
}