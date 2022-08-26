// 5. Write a program which display largest digits of all element from singly 
// linear linked list.
// Function Prototype :
// void DisplayLarge( PNODE Head); 
// Input linked list : |11|->|250|->|532|->|419| 
// Output : 1 5 5 9

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

void DisplayLarge(PNODE Head)
{
    int iNo=0;

    while(Head!=NULL)
    {
        iNo=Head->data;

        int iDigit=0,iMax=0;
        
        iMax=iNo%10;
        while(iNo!=0)
        {
           iDigit=iNo%10;
           if(iMax < iDigit)
           {
               iMax=iDigit;
           }
           iNo=iNo/10;
        }
        printf("%d ",iMax);
        Head=Head->next;
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,419);
    InsertFirst(&first,532);
    InsertFirst(&first,250);
    InsertFirst(&first,11);
    
    DisplayLarge(first);

    return 0;
}