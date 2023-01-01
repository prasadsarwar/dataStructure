#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool CheckEmpty(int iTop)
{
    if(iTop == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CheckFull(int iTop, int iSize)
{
    if(iTop == (iSize -1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Push(int Stack[], int iSize, int iTop, int iNo)
{
    if(CheckFull(iTop, iSize) == true)
    {
        return -1;
    }
    else
    {
        iTop = iTop + 1;

        Stack[iTop] = iNo;

        return iTop;
    }
}

int Pop(int Stack[], int iTop)
{
    if(CheckEmpty(iTop) == true)
    {
        return -2;
    }
    else
    {
        iTop = iTop - 1;

        return iTop;
    }

}

void Display(int Stack[], int iTop)
{
    int iCnt = 0;

    if(CheckEmpty(iTop) == true)
    {
        return;
    }

    printf("Elements in stack are:\n");
    
    for(iCnt = 0; iCnt <= iTop; iCnt++)
    {
        printf("%d\t", Stack[iCnt]);
    }
}

int main()
{
    int iSize = 0, iChoice = -1, iCnt = 0;
    int *Stack = NULL;
    int Top = -1, iRet = 0, iNo = 0;
    bool bCheck = false;

    printf("Enter size of stack:\n");
    scanf("%d",&iSize);

    Stack = (int *)malloc(sizeof(int) * iSize);

    if(Stack == NULL)
    {
        printf("Unable to allocate memory...");
        return -1;
    }

    while(iChoice != 0)
    {
        printf("\n==============================================================\n");

        printf("Choose the operation:\n\n");
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Check full\n");
        printf("4: Check empty\n");
        printf("5: Display\n");
        printf("6: Exit\n\n");

        printf("Enter choice:\n");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:

                printf("Enter element:\n");
                scanf("%d", &iNo);

                iRet = Push(Stack, iSize, Top, iNo);

                if(iRet == -1)
                {
                    printf("Stack is full...\n");
                }
                else
                {
                    printf("Element inserted successfully...");
                    Top = iRet;
                }
                break;
            
            case 2:

                iRet = Pop(Stack, Top);

                if(iRet == -2)
                {
                    printf("Stack is empty");
                } 
                else
                {
                    printf("Elemnt %d deleted Successully",Stack[Top]);
                    Top = iRet;
                }
                
                break;

            case 3:
                
                bCheck = CheckFull(Top, iSize);

                if(bCheck == true)
                {
                    printf("Stack is full...\n");
                }
                else
                {
                    printf("Stack is not full...\n");
                }

                break;

            case 4:

                bCheck = CheckEmpty(Top);

                if(bCheck == true)
                {
                    printf("Stack is empty...\n");
                }
                else
                {
                    printf("Stack is not empty...\n");
                }

                break;

            case 5:

                Display(Stack, Top);
                break;

            case 6:

                iChoice = 0;
                break;

            default:
                printf("Invalid choice...\n");
                break;
                
        }

        printf("\n==============================================================\n");
    }

    return 0;


}