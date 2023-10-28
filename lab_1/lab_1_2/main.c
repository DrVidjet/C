
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double a = 5, b;
    int c = 5, d;

    printf("b=");
    scanf("%lf", &b);

    printf("d=");
    scanf("%d", &d);

    a=a+b-2;
    printf("a = a+b-2 : a=%lf b=%f c=%d d=%d\n", a, b, c, d);

    c=c+1,d=c-a+d;
    printf("c=c+1, d=c-a+d : a=%f b=%f c=%d d=%d\n", a, b, c, d);

    a=a*c,c=c-1;
    printf("a=a*c, c=c-1 : a=%f b=%f c=%d d=%d\n", a, b, c, d);

    a=a/10,c=c/2,b=b-1,d=d*(c+b+a);
    printf("a=a/10, c=c/2, b=b-1, d=d*(c+b+a) : a=%f b=%f c=%d d=%d\n", a, b, c, d);

    system("pause");
    return 0;
}
