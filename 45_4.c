// 4. Write a program which display smallest digits of all element from singly 
// linear linked list.
// Function Prototype :
// void DisplaySmall( PNODE Head); 
// Input linked list : |11|->|250|->|532|->|415| 
// Output : 1 0 2 1

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node** PPNODE;

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

void DisplaySmall(PNODE Head)
{
    int iNo=0;

    while(Head!=NULL)
    {
        iNo=Head->data;

        int iDigit=0,iMin=0;
        
        iMin=iNo%10;
        while(iNo!=0)
        {
           iDigit=iNo%10;
           if(iMin > iDigit)
           {
               iMin=iDigit;
           }
           iNo=iNo/10;
        }
        printf("%d ",iMin);
        Head=Head->next;
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,415);
    InsertFirst(&first,532);
    InsertFirst(&first,250);
    InsertFirst(&first,11);
    
    DisplaySmall(first);

    return 0;
}