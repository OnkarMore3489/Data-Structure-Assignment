// 5. Write a program which return smallest element from singly linear linked 
// list. 
// Function Prototype :
// int Minimum( PNODE Head); 
// Input linked list : |110|->|230|->|20|->|240|->|640| 
// Output : 20

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

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->next=(*Head);
        (*Head)=newn;
    }
}

int Minimum(PNODE Head)
{
    int iMin=(Head)->data;
    while(Head!=NULL)
    {
        if((Head)->data < iMin)
        {
            iMin=(Head)->data;
        }
        Head=Head->next;
    }
    return iMin;
}

int main()
{
    PNODE first=NULL;
    int iRet=0;

    InsertFirst(&first,70);
    InsertFirst(&first,30);
    InsertFirst(&first,50);
    InsertFirst(&first,40);
    InsertFirst(&first,30);
    InsertFirst(&first,20);
    InsertFirst(&first,10);

    iRet=Minimum(first);
    printf("Minimum elements is : %d\n",iRet);

    return 0;
}