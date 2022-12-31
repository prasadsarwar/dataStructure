#include <stdio.h>
#include <stdlib.h>

int InsertElement(int Arr[],int iSize, int iNo, int iPos)
{
    int iCnt = 0;
    iPos = iPos - 1;

    if((iPos < 0) || (iPos > iSize))
    {
        printf("Invalid position\n");
        return -1;
    }

    for(iCnt = iSize; iCnt > iPos; iCnt--)
    {
        Arr[iCnt] = Arr[iCnt - 1];
    }
    Arr[iPos] = iNo;
    iSize = iSize + 1;

    return iSize;
}

int DeleteElement(int Arr[], int iSize, int iPos)
{
    int iCnt = 0;
    iPos = iPos + 1;

    if((iPos < 0) || (iPos > iSize))
    {
        printf("Invalid position\n");
        return -1;
    }

    for(iCnt = iPos; iCnt < iSize; iCnt++)
    {
        Arr[iCnt] = Arr[iCnt + 1];
    }

    iSize = iSize - 1;

    return iSize;
}
void Display(int Arr[],int iSize)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        printf("%d\t",Arr[iCnt]);
    }
    printf("\n");
}

int main()
{
    int iSize = 0, iCnt = 0;
    int *ptr = NULL;
    int iChoice = -1;
    int iPos = 0, iNo = 0; 

    printf("Enter size of array:\n");
    scanf("%d",&iSize);

    ptr = (int *)malloc(iSize * sizeof(int));

    if(ptr == NULL)
    {
        printf("Unable to allocate memory\n");
        return -1;
    }

    printf("Enter array elements:\n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    while(iChoice != 0)
    {
        printf("\n==============================================================\n");

        printf("Choose the operation:\n\n");
        printf("1: Insertion\n");
        printf("2: Deletion\n");
        printf("3: Display\n");
        printf("4: Exit\n\n");

        printf("Enter choice:\n");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                printf("Enter the position to insert the element:\n");
                scanf("%d",&iPos);

                printf("Enter number:\n");
                scanf("%d",&iNo);

                iSize = InsertElement(ptr,iSize,iNo,iPos);
                break;
            
            case 2: 
                printf("Enter the position of the element to delete :\n");
                scanf("%d",&iPos);

                iSize = DeleteElement(ptr, iSize, iPos);
                break;

            case 3:
                Display(ptr,iSize);
                break;

            case 4:

                printf("Thank you...\n");
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
