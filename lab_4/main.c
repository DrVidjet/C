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
            A[i] = rand()%100;
    }

    printf("\nBefore sort: \n\n");

    for(i = 0; i < a; i++)
        printf("A[%d] = %d\n", i, A[i]);



    for(i = 0; i < a; i++)
        {
            for(tic = 0; tic < a-i; tic++)
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
    int a, tic, i, temp, *A, n;
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
            A[i] = -100+rand()%200;
    }

    n = 0;
    for(i = 0; i < a; i++)
    {
        if(A[i] > 0)
            n++;
        if(n == 2)
        {
            i++;
            break;
        }
    }
    if(n < 2)
        printf("The array is incorrect!\n\n");
    else
    {
        printf("\nBefore sort: \n\n");
        for(int r = 0; r < a; r++)
            printf("A[%d] = %d\n", r, A[r]);

        a++;
        A = realloc(A, a*sizeof(int));
        temp = A[i];
        A[i] = 100;
        tic = A[i+1];
        A[i+1] = temp;

        for(n=a; n>i+2; n--)
            A[n] = A[n-1];
        A[i+2] = tic;

        printf("\n\nAfter sort: \n\n");

        for(i = 0; i < a; i++)
            printf("A[%d] = %d\n", i, A[i]);

        printf("\n");
    }
    free(A);
    end = 2;
    choice();
}
void third()
{
    int **A;
    int n, m, Sp, So;
    double F;
    int i, j;
    bool h;

    srand(time(NULL));

    printf("Would you want to enter the numbers?(1 - yes, 0 - no) ");
    scanf("%d", &h);

    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &n, &m);

    A = (int**)malloc(n * sizeof(int*)); // Освобождение памяти под строки

    if(h) // Если вводим значения вручную
    {
        for (i = 0; i<n; i++) // Цикл по строкам
        {
            A[i] = (int*)malloc(m * sizeof(int)); // Освобождение памяти под столбцы
            for (j = 0; j<m; j++) // Цикл по столбцам
            {
                printf("a[%d][%d] = ", i+1, j+1);
                scanf("%d", &A[i][j]);
            }
        }
    }
    else if(!h) // Если даем программе сгенерировать значения
    {
        for (i = 0; i < n; i++) // Цикл по строкам
        {
            A[i] = (int*)malloc(m * sizeof(int)); // Освобождение памяти под столбцы
            for (j = 0; j < m; j++) // Цикл по столбцам
                A[i][j] = -100+rand()%200;
        }
    }

    printf("\n");

    for (i = 0; i < n; i++) // Вывод матрицы
    {
        for (j = 0; j < m; j++)
            printf(" %4d ", A[i][j]);

        printf("\n");
    }

    printf("\n");
    Sp = 0;
    for(i = 1; i <= n; i++)
    {
        if(i%2 != 0)
        {
            for(j = 1; j <= m; j++)
            {
                    if(A[i-1][j-1]>0)
                        Sp += A[i-1][j-1];
            }
        }
    }
    So = 0;
    for(i = 1; i <= n; i++)
    {
        if(i%2 == 0)
        {
            for(j = 1; j <= m; j++)
            {
                if(A[i-1][j-1]<0)
                    So += A[i-1][j-1];
            }
        }
    }

    printf("\nSp = %d, So = %d\n\n", Sp, So);

    F = ((double)Sp+(double)So)/(Sp-So);

    printf("\nF = %lf\n\n", F);

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
