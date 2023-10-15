#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x1,x2,y1,y2,x,y,A,B,C,rez;

    printf("Enter x1 and y1: ");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter x2 and y2: ");
    scanf("%lf %lf", &x2, &y2);


    A = hypotf(x1, y1);
    B = hypotf(x2, y2);

    x = fabs(x1)-fabs(x2);
    y = fabs(y1)-fabs(y2);

    C = hypotf(x, y);
    rez = A+B+C;

    printf("A = %lf, B = %lf, C = %lf\n", A, B, C);
    printf("Result = %lf\n", rez);

    return 0;
}
