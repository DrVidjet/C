#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    int A[20], i, temp;

    for(i = 0; i < 20; i++)
    {
        A[i] = -100+rand()%200;
        printf("%d ", A[i]);
    }
    printf("\n");
    for(i = 0; i < 20/2; i++)
    {
        temp = A[i];
        A[i] = A[20-i-1];
        A[20-i-1] = temp;
    }
    for(i = 0; i < 20; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}
