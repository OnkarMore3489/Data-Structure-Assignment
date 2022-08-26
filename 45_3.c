// 3. Write a program which display product of all digits of all element from 
// singly linear linked list. (Don’t consider 0) 
// Function Prototype :
// void DisplayProduct( PNODE Head); 
// Input linked list : |11|->|20|->|32|->|41| 
// Output : 1 2 6 4

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

void DisplayProduct(PNODE Head)
{
    int iNo=0;

    while(Head!=NULL)
    {
        iNo=Head->data;

        int iDigit=0,iMult=1;

        while(iNo!=0)
        {
           iDigit=iNo%10;
           if(iDigit==0)
           {
               iDigit=1;
           }
           iMult*=iDigit;
           iNo=iNo/10;
        }
        printf("%d  ",iMult);
        Head=Head->next;
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,41);
    InsertFirst(&first,32);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    
    DisplayProduct(first);

    return 0;
}