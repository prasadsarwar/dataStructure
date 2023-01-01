 #include <stdio.h>
 #include <stdlib.h>


 void Display(int Arr[], int iSize)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        printf("%d\t",Arr[iCnt]);
    }
    printf("\n");
}

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

 int LinearSearch(int Arr[], int iSize, int iKey)
 {
    int iCnt = 0, iFlag = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iKey)
        {
            iFlag = 1;
            break;
        }
    }
    if(iFlag == -1)
    {
        return iFlag;
    }
    else
    {
        return iCnt + 1;
    }
 }

 int BinarySearch(int Arr[], int iSize, int iKey)
 {
    int iLow = 0, iMid = 0, iHigh = 0;
    int iCnt = 0, iFlag = 0;

    iLow = 0;
    iHigh = iSize;

    while (iLow <= iHigh)
    {
        iMid = (iLow + iHigh) / 2;

        if(Arr[iMid] == iKey)
        {
            iFlag = 1;
            break;
        }
        else if (iKey > Arr[iMid])
        {
            iLow = iMid + 1;
        }
        else
        {
            iHigh = iMid - 1;
        }     
    }

    if(iFlag == 0)
    {
        return iFlag;
    }
    else
    {
        return iMid + 1;
    }
     
 }


 int main()
 {
    int iSize = 0, iCnt = 0, iKey = 0;
    int iRet = 0, iChoice = -1;
    int *ptr = NULL;

    printf("Enter Size of array:\n");
    scanf("%d",&iSize);

    ptr = (int *)malloc(iSize * sizeof(int));

    if(ptr == NULL)
    {
        printf("Unable to allocate memory...");
        return -1;
    }

    printf("Enter array elements:\n");

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        scanf("%d", &ptr[iCnt]);
    }
    while (iChoice != 0)
    {
        printf("Enter element you want to search:\n");
        scanf("%d", &iKey);

        printf("Cnoose search method:\n\n");
        printf("1: Linear search\n");
        printf("2: Binary Search (array will be sorted)\n");
        printf("3: Display\n");
        printf("4: Exit\n");

        scanf("%d",&iChoice);

        switch (iChoice)
        {
        case 1:
            iRet = LinearSearch(ptr, iSize, iKey);

            if(iRet == 0)
            {
                printf("Element not found...\n");
            }
            else
            {
                printf("Element %d found at position %d\n", iKey, iRet);
            }

            break;
        
        case 2:
            BubbleSort(ptr,iSize);

            iRet = BinarySearch(ptr,iSize,iKey);

            if(iRet == 0)
            {
                printf("Element not found...\n");
            }
            else
            {
                printf("Element %d found at position %d\n", iKey, iRet);
            }
            break;

        case 3:
            Display(ptr, iSize);
            break;

        default:
            printf("Invalid choice...\n");
            break;
        }
    }
  
    
    return 0;
 }
