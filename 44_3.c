// 3. Write a program which returns addition of all even element from singly 
// linear linked list. 
// Function Prototype :
// int AdditionEven( PNODE Head); 
// Input linked list : |11|->|20|->|32|->|41| 
// Output : 52

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

int AdditionEven(PNODE Head)
{
    int iSum=0;

    while(Head!=NULL)
    {
        int iNo=Head->data;
    
        if((iNo%2)==0)
        {
          iSum+=iNo;
        }
        Head=Head->next;
    }
    return iSum;
}
int main()
{
    PNODE first=NULL;
    int iRet=0;

    InsertFirst(&first,41);
    InsertFirst(&first,32);
    InsertFirst(&first,20);
    InsertFirst(&first,11);
    
    iRet=AdditionEven(first);
    printf("Addition of Even Numbers is : %d",iRet);
    return 0;
}