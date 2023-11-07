#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>

int end;

int main(void)
{
    int choice;

    printf("Enter the program number(1-3): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: first();
        break;
        case 2: second();
        break;
        case 3: third();
        break;
    }

    system("pause");
}

void first()
{
    int **A, *a, n, m, d, i, j, l;
    double S, s;

    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &n, &m);
    printf("Enter the size of the array: ");
    scanf("%d", &d);

    a = (int*)malloc(d * sizeof(int));
    A = (int**)malloc(n * sizeof(int*));

    for(i = 0; i<n; i++)
        A[i] = (int*)malloc(m * sizeof(int));

    Enter2(A, n, m);
    Enter1(a, d);

    printf("\n");

    for(i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf(" %4d ", A[i][j]);

        printf("\n");
    }

    printf("\n");

    for(i = 0; i < d; i++)
    {
        s += a[i];
    }

    s /= d;
    l = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            S += A[i][j];
        }
        S /= m;
        printf("arithmetic mean[%d]: %lf\n", i+1, S);
        if(S > s)
            l++;
    }

    printf("\n");

    for(i = 0; i < d; i++)
        printf("% 4d", a[i]);
    printf(" (arithmetic mean: %lf)\n", s);

    printf("\n%d rows\n\n", l);

    free(a);
    for(i = 0; i < n; i++)
        free(A[i]);
    free(A);
    end = 1;
    choice();
}
void second()
{
    int **A, **B, n, m, i, j, l, f, c, d, s;

    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &n, &m);
    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &l, &f);

    A = (int**)malloc(n * sizeof(int*));
    B = (int**)malloc(l * sizeof(int*));
    for(i = 0; i < n; i++)
        A[i] = (int*)malloc(m * sizeof(int));
    for(i = 0; i < l; i++)
        B[i] = (int*)malloc(f * sizeof(int));

    Enter2(A, n, m);
    Enter2(B, l, f);

    printf("\nBefore sort: \n\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf(" %4d ", A[i][j]);

        printf("\n");
    }
    printf("\n");
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < f; j++)
            printf(" %4d ", B[i][j]);

        printf("\n");
    }
    printf("\n");

    s = 0;
    for(i = 0; i < m; i++)
    {
        c = 0;
        for(j = 0; j < n; j++)
        {
            if(A[j][i] < 0)
                c++;
        }
        if(c > 1)
        {
            A[0][i] = -1555;
            s++;
        }
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(A[0][i] == -1555)
            {
                d = i;
                delete(A, n, m, d);
            }
        }
    }
    m -= s;

    s = 0;
    for(i = 0; i < f; i++)
    {
        c = 0;
        for(j = 0; j < l; j++)
        {
            if(B[j][i] < 0)
                c++;
        }
        if(c > 2)
        {
            B[0][i] = -1555;
            s++;
        }
    }
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(B[0][i] == -1555)
            {
                d = i;
                delete(B, l, f, d);
            }
        }
    }
    f -= s;

    printf("\nAfter sort: \n\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf(" %4d ", A[i][j]);

        printf("\n");
    }
    printf("\n");

    for(i = 0; i < l; i++)
    {
        for(j = 0; j < f; j++)
            printf(" %4d ", B[i][j]);

        printf("\n");
    }
    printf("\n");

    for(i = 0; i < n-1; i++)
        free(A[i]);
    free(A);
    for(i = 0; i < l-1; i++)
        free(B[i]);
    free(B);
    end = 2;
    choice();
}
void third()
{
    end = 3;
    choice();
}
int Enter2(int **A, int n, int m)
{
    int i, j;
    bool h;

    srand(time(NULL));

    printf("Would you want to enter the numbers?(1 - yes, 0 - no) ");
    scanf("%d", &h);

    if(h)
    {
        for (i = 0; i<n; i++)
        {
            for (j = 0; j<m; j++)
            {
                printf("a[%d][%d] = ", i+1, j+1);
                scanf("%d", &A[i][j]);
            }
        }
    }
    else if(!h)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                A[i][j] = -100+rand()%200;
        }
    }
    return A;
}
int Enter1(int *a, int d)
{
    int i;
    bool h;

    printf("Would you want to enter the numbers?(1 - yes, 0 - no) ");
    scanf("%d", &h);

    if(h)
    {
        for (i = 0; i<d; i++)
        {
            printf("a[%d][%d] = ", i+1);
            scanf("%d", &a[i]);
        }
    }
    else if(!h)
    {
        for (i = 0; i < d; i++)
            a[i] = -100+rand()%200;
    }

    return a;
}
int delete(int **A, int n, int m, int d)
{
    int i, j;

    for(i = d; i < m; i++)
        for(j = 0; j < n; j++)
            A[j][i] = A[j][i+1];

    return A;
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
       }
    }
    else if(choice == 2)
        main();
    else if(choice == 3)
        system("exit");
}
