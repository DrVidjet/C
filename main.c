#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    printf("3! = %d\n", factorial(3));
    printf("5! = %d\n", factorial(5));
    printf("7! = %d\n", factorial(7));

    return 0;
}
int factorial(factor)
{
    if (factor == 1)
    {
        return 1;
    }
    return factor * factorial(factor - 1);
}
