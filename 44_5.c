// 5. Write a program which display addition of digits of element from singly 
// linear linked list. 
// Function Prototype :int SumDigit( PNODE Head); 
// Input linked list : |110|->|230|->|20|->|240|->|640| 
// Output : 2 5 2 6 10

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

void SumDigit(PNODE Head)
{
    int iNo=0;

    while(Head!=NULL)
    {
        iNo=Head->data;
        int iDigit=0,iSum=0;

        while(iNo!=0)
        {
          iDigit=iNo%10;
          iSum+=iDigit;
          iNo=iNo/10;
        }
        printf("%d  ",iSum);
        Head=Head->next;
    }
}
int main()
{
    PNODE first=NULL;
    int iRet=0;

    InsertFirst(&first,640);
    InsertFirst(&first,240);
    InsertFirst(&first,20);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    
    SumDigit(first);
    return 0;
}