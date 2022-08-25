// 2. Write a program which search last occurrence of particular element from 
// singly linear linked list. 
// Function should return position at which element is found. 
// Function Prototype :
// int SearchLastOcc( PNODE Head, int no ); 
// Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70| 
// Input element : 30 
// Output : 6

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

int SearchLastOcc(PNODE Head,int no)
{
    int i=1,iCnt=0;
    while(Head!=NULL)
    {
        if(Head->data==no)
        {
            iCnt=i;
        }
        Head=Head->next;
        i++;
    }
    return iCnt;
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


    iRet=SearchLastOcc(first,30);
    printf("Last Occurence is : %d\n",iRet);

    return 0;
}