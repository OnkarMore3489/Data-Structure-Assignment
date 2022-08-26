// 2. Write a program which display all palindrome elements of singly linked 
// list. 
// Function Prototype :
// void DisplayPallindrome( PNODE Head); 
// Input linked list : |11|->|28|->|17|->|414|->|6|->|89| 
// Output : 11 6 414

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

void DisplayPalindrome(PNODE Head)
{
    int iNo=0,iValue=0;

    while(Head!=NULL)
    {
        iNo=Head->data;
        iValue=Head->data;

        int iRev=0,iDigit=0;

        while(iNo!=0)
        {
           iDigit=iNo%10;
           iRev=(iRev*10)+iDigit;
           iNo=iNo/10;
        }
        if(iValue==iRev)
        {
         printf("|%d| ->",iValue);
        }
        Head=Head->next;
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,89);
    InsertFirst(&first,6);
    InsertFirst(&first,414);
    InsertFirst(&first,17);
    InsertFirst(&first,28);
    InsertFirst(&first,11);
    
    DisplayPalindrome(first);

    return 0;
}