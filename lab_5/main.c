#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

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

    free(A);
    end = 1;
    choice();
}
void second()
{
    int **A, **B, n, m, i, j, l, f, c, d;

    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &n, &m);
    printf("Enter the number of rows and the number of columns: ");
    scanf("%d %d", &l, &f);

    B = (int**)malloc(l * sizeof(int*));
    A = (int**)malloc(n * sizeof(int*));

    for(i = 0; i<n; i++)
        A[i] = (int*)malloc(m * sizeof(int));
    for(i = 0; i<l; i++)
        B[i] = (int*)malloc(f * sizeof(int));

    Enter2(A, n, m);
    Enter2(B, l, f);

    printf("\n");

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
    c = 0;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(A[j][i] < 0)
                c ++;
        }
        if(c >= 2)
            A[0][i] = 0;
        c = 0;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            printf(" %4d ", A[i][j]);

        printf("\n");
    }
    printf("\n");

    end = 2;
    choice();
}
void third()
{
    end = 3;
    choice();
}
void Enter2(int **A, int n, int m)
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
void Enter1(int *a, int d)
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
void delete(int **A, int n, int m, int d)
{
    int i, j, **B;

    B = (int**)malloc(n * sizeof(int*))

    for(i = 0; i < n; i++)
        B = (int*)malloc((m-1) * sizeof(int))

    for(i = 0; i < m; i++)
    {
        if(i != d)
        for(j = 0; j < n; j++)
            B[i][j] = A[i][j];
    }

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
