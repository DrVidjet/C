#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

int end;

int main(void)
{
    int choice;

    printf("Enter the program number(1-6): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: first();
        break;
        case 2: second();
        break;
        case 3: third();
        break;
        case 4: fouth();
        break;
        case 5: fifth();
        break;
        case 6: sixth();
        break;
    }

    system("pause");
}


void first()
{
    int a, tic, i, temp, *A, ni, n;
    bool h;

    srand(time(NULL));

    printf("Would you want to enter the numbers?(1 - yes, 0 - no) ");
    scanf("%d", &h);

    printf("Enter the size of the array: ");
    scanf("%d", &a);

    A = (int*)malloc(a * sizeof(int));

    if(h)
    {
        for(i = 0; i < a; i++)
        {
            printf("A[%d] = ", i);
            scanf("%d", &A[i]);
        }
    }

    else if(!h)
    {
        for(i = 0; i < a; i++)
            A[i] = rand()%500;
    }

    printf("\nBefore sort: \n\n");

    for(i = 0; i < a; i++)
        printf("A[%d] = %d\n", i, A[i]);



    for(i = 0; i < a-1; i++)
        {
            for(tic = 0; tic < a-i-1; tic++)
            {
                if (A[tic] > A[tic+1])
                {
                    temp = A[tic];
                    A[tic] = A[tic+1];
                    A[tic+1] = temp;
                }
            }
        }

    printf("\n\nIn ascending order: \n\n");

    for(i = 0; i < a; i++)
        printf("A[%d] = %d\n", i, A[i]);
    printf("\n");

    n = a-1;
    ni = 0;

    for(i = 0; i < a/2; i++)
    {
        temp = A[i];
        if(i%2 == 0)
        {
            A[ni] = temp;
            ni ++;
        }
        else if(i%2 != 0)
        {
            A[n] = temp;
            n--;
        }
    }

    printf("\n\nAfter sort: \n\n");

    for(i = 0; i < a; i++)
        printf("A[%d] = %d\n", i, A[i]);

    printf("\n\n");

    free(A);
    end = 1;
    choice();
}
void second()
{
    end = 2;
    choice();
}
void third()
{
    end = 3;
    choice();
}
void fouth()
{
    end = 4;
    choice();
}
void fifth()
{
    end = 5;
    choice();
}
void sixth()
{
    end = 6;
    choice();
}
int choice()
{
    int choice;
    printf("1 - repeat the program, 2 - go back to the menu, 3 - exit the program\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
       switch(end)
       {
           case 1: first();
           break;
           case 2: second();
           break;
           case 3: third();
           break;
           case 4: fouth();
           break;
           case 5: fifth();
           break;
           case 6: sixth();
           break;
       }
    }
    else if(choice == 2)
        main();
    else if(choice == 3)
        system("exit");
}
