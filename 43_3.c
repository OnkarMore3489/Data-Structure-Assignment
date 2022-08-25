// 3. Write a program which returns addition of all element from singly linear 
// linked list. 
// Function Prototype :
// int Addition( PNODE Head); 
// Input linked list : |10|->|20|->|30|->|40| 
// Output : 100

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

int Addition(PNODE Head)
{
    int iSum=0;
    while(Head!=NULL)
    {
        iSum+=Head->data;
        Head=Head->next;
    }
    return iSum;
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


    iRet=Addition(first);
    printf("Addition of all elements is : %d\n",iRet);

    return 0;
}