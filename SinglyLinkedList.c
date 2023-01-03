#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct node
{
    int iData;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int CountNodes(PNODE First)
{
    int iCount = 0;

    while(First != NULL)
    {
        iCount = iCount + 1;
        First = First->next;
    }

    return iCount;
}

void Display(PNODE First)
{
    printf("Elements in linked list are:\n");
    while (First != NULL)
    {
        printf("| %d | -> ",First->iData);
        First = First->next;
    }
    printf("NULL\n");   
}

void InsertFirst(PPNODE First, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First, int iNo)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->iData = iNo;
    newn->next = NULL;

    if(*First == NULL)
    {
        *First = newn;
    }
    else
    {
        PNODE Temp = *First;

        while(Temp->next != NULL)
        {
            Temp = Temp -> next;
        }
        Temp->next = newn;
    }
    
}

void InsertAtPosition(PPNODE First, int iNo, int iPos)
{
    int iCount = CountNodes(*First);
    int iCnt = 0;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid position...\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(First, iNo);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(First, iNo);
    }
    else
    {
        PNODE Temp = *First;
        PNODE newn = (PNODE)malloc(sizeof(NODE));
        newn->iData = iNo;
        newn->next = NULL;

        for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn; 
    }
}

void DeleteFirst(PPNODE First)
{

    if(*First == NULL)
    {
        return;
    }
    else
    {
        PNODE Temp = *First;
        *First = Temp->next;
        free(Temp);
    }
}

void DeleteLast(PPNODE First)
{
    if(*First == NULL)
    {
        return;
    }
    else
    {
        PNODE Temp = *First;

        while(Temp->next->next != NULL)
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
}

void DeleteAtPosition(PPNODE First, int iPos)
{
    int iCount = CountNodes(*First);
    int iCnt = 0;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        printf("Invalid position...\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(First);
    }
    else if(iPos == iCount + 1)
    {
        DeleteLast(First);
    }
    else
    {
        PNODE Temp1 = *First;
        PNODE Temp2 = NULL;

        for(iCnt = 1; iCnt < (iPos-1); iCnt++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next;
        Temp1->next = Temp2->next;
        free(Temp2); 
    }
}

int main()
{
    PNODE Head = NULL;

    int iNo = 0, iPos = 0;
    int iRet = 0, iChoice = -1;

    while(iChoice != 0)
    {
        printf("============================================================\n\n");

        printf("Choose the operation to perfotm on Linked list:\n\n");

        printf("1: Insert element at First\n");
        printf("2: Insert element at Last\n");
        printf("3: Insert element at specific position\n");
        printf("4: Delete element from first\n");
        printf("5: Delete element from last\n");
        printf("6: Delete element from specific postiton\n");
        printf("7: Display linked list\n");
        printf("8: Count number of nodes\n");
        printf("9: Exit\n");

        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            printf("Enter Number:\n");
            scanf("%d", &iNo);

            InsertFirst(&Head, iNo);
            Display(Head);
            break;

        case 2:
            printf("Enter Number:\n");
            scanf("%d", &iNo);

            InsertLast(&Head, iNo);
            Display(Head);
            break;

        case 3:
            printf("Enter Number:\n");
            scanf("%d", &iNo);

            printf("Enter position:\n");
            scanf("%d", &iPos);

            InsertAtPosition(&Head, iNo, iPos);
            Display(Head);
            break;

        case 4:
            DeleteFirst(&Head);
            Display(Head);
            break;
            
        case 5:
            DeleteLast(&Head);
            Display(Head);
            break;

        case 6:
            printf("Enter position:\n");
            scanf("%d", &iPos);

            DeleteAtPosition(&Head, iPos);
            Display(Head);
            break;

        case 7:
            Display(Head);
            break;

        case 8:
            iRet = CountNodes(Head);

            printf("Number of nodes in linked list are: %d\n", iRet);
            break;

        case 9:
            printf("Thank you...\n");
            iChoice = 0;
            break;
        
        default:
        printf("Invalid choice...\n");
            break;
        }

        printf("============================================================\n\n");

    }
  
    return 0;

}