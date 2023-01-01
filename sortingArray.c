#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int Arr[], int iSize)
{
    int i = 0, j = 0;
    int iTemp = 0; 

    for(i = 1; i < iSize; i++)
    {
        for(j = 0; j < iSize - i; j++)
        {
            if(Arr[j] > Arr[j + 1])
            {
                iTemp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = iTemp;
            }
        }
    }
}

void SelectionSort(int Arr[], int iSize)
{
    int i = 0, j = 0;
    int iTemp = 0;

    for(i = 0; i < iSize; i++)
    {
        for(j = (i + 1); j < iSize; j++)
        {
            if(Arr[i] > Arr[j])
            {
                iTemp = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = iTemp;
            }
        }
    } 
}

void InsertionSort(int Arr[], int iSize)
{
    int i = 0, j = 0;
    int iKey = 0;

    for(i = 1; i < iSize; i++)
    {
        iKey = Arr[i];
        j = i - 1;

        while((Arr[j] > iKey) && (j >= 0))
        {
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = iKey;
    }
}

void Display(int Arr[], int iSize)
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
    int iSize = 0, iChoice = -1, iCnt = 0;
    int *ptr = NULL;

    printf("Enter size of array:\n");
    scanf("%d",&iSize);

    ptr = (int *)malloc(sizeof(int) * iSize);

    if(ptr == NULL)
    {
        printf("Unable to allocate memory...");
        return -1;
    }

    printf("Enter arrey elements:\n");
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }


    while(iChoice != 0)
    {
        printf("\n==============================================================\n");

        printf("Choose the operation:\n\n");
        printf("1: Bubble Sort\n");
        printf("2: Selection Sort\n");
        printf("3: Insertion Sort\n");
        printf("4: Display\n");
        printf("5: Exit\n\n");

        printf("Enter choice:\n");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 1:
                BubbleSort(ptr,iSize);
                break;
            
            case 2: 
                SelectionSort(ptr,iSize);
                break;

            case 3:
                InsertionSort(ptr, iSize);
                break;

            case 4:
                Display(ptr,iSize);
                break;

            case 5:

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
