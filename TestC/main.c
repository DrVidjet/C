#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    double a = 2, b = 1;
    double n; // количество итераций
    double c, d = 1;

    printf("n = ");
    scanf("%lf", &n);

    for(int i = 1; i<=n; i++)
    {
        if(i > 1)
        {
            if(i%2 != 0)
                a *= 2;
        if(i%2 == 0)
            b = i+1;
        }

        c = a/b;
        d *= c;
    }
    printf("d = %lf", d);

    return 0;
}
