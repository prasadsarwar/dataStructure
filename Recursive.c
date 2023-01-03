#include <stdio.h>

int Factorial(int iNo, int iFact)
{
    if(iNo != 0)
    {   
        iFact = iFact * iNo;
        iNo = iNo - 1;
        iFact = Factorial(iNo, iFact);
    } 

    return iFact;
}

void Fibonacci(int iNo, int x, int y)
{
    int iNum1 = x, iNum2 = y;
    int iFibo = 0;

    if(iNo != 0)
    {
        iFibo = iNum1 + iNum2;
        printf("%d\t", iFibo);

        iNum1 = iNum2;
        iNum2 = iFibo;

        iNo = iNo - 1;
        Fibonacci(iNo,iNum1, iNum2);
    }
}


int main()
{
    int iNo = 0, iFact = 1;
    int iChoice = -1;

    printf("Enter number:\n");
    scanf("%d", &iNo);

    while(iChoice != 0)
    {
        printf("Choose task:\n\n");
        printf("1: Find factorial\n");
        printf("2: Print Fibonacci series\n");
        printf("3: Exit\n");

        scanf("%d", &iChoice);

        switch (iChoice)
        {
        case 1:
            
            iFact = Factorial(iNo, iFact);

            printf("Factorial : %d\n", iFact);
            break;

        case 2:

            Fibonacci(iNo, 0 , 1);
            printf("\n");
            break;

        case 3: 
            printf("Thank you....\n");
            iChoice = 0;
            break;
        
        default:

            printf("Invalid choice...\n");
            break;
        }
    }

    return 0;
}