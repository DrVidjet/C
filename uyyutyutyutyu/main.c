#include <stdio.h>
#include <stdlib.h>
#define EPS 1e-5

int main()
{
    double x, a=1, S=0, n=1;

    printf("Enter x= ", x);
    scanf("%lf", &x);

    while (a > EPS)
    {
      a = powf((x-1),n)/(n*powf(x,n));
      S+=a;
      n++;
    }
    printf("Sum=%lf, f=%lf\n", S, log(x));

    return 0;
}
