// 4. Write a program which return second maximum element from singly linear 
// linked list. 
// Function Prototype :
// int SecMaximum( PNODE Head); 
// Input linked list : |110|->|230|->|320|->|240| 
// Output : 240


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

void SortList(PNODE Head)
{
    PNODE temp1=Head;
    int temp=0;
    while(temp1!=NULL)
    {
        PNODE temp2=temp1->next;

            while(temp2!=NULL)
            {
                if((temp1->data) > (temp2->data))
                {
                 temp=temp1->data;
                 temp1->data=temp2->data;
                 temp2->data=temp;
                }
                temp2=temp2->next;
            }
        temp1=temp1->next;
    }
}

int SecMaximum(PNODE Head)
{
    SortList(Head);

    while(Head->next->next!=NULL)
    {
        Head=Head->next;
    }
    return (Head->data);
}

int main()
{
    PNODE first=NULL;
    int iRet=0;

    InsertFirst(&first,240);
    InsertFirst(&first,320);
    InsertFirst(&first,230);
    InsertFirst(&first,110);
    
    SortList(first);
    
    iRet=SecMaximum(first);
    printf("Second Maximum Numbers is : %d",iRet);
    return 0;
}