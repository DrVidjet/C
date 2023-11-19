#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define EPS7 1e-7
#define EPS8 1e-4



int factor;
void first();
void second();
void third();
void fouth();
void fifth();
void sixth();
void seventh();
void eighth();
void nineth();

int main()
{
    int ch;

    void (*funcs[9])();

    funcs[0] = first;
    funcs[1] = second;
    funcs[2] = third;
    funcs[3] = fouth;
    funcs[4] = fifth;
    funcs[5] = sixth;
    funcs[6] = seventh;
    funcs[7] = eighth;
    funcs[8] = nineth;

        printf("Enter the program number(1-9) or 0 for exit: ");
        scanf("%d", &ch);

        if(ch != 0)
            funcs[ch-1]();
        else
            return 0;
}

void first()
{
    double k, m, f;

    printf("Please, enter number k and m: ");
    scanf("%lf %lf", &k, &m);

    if(k > 0)
    {
        f = m/k;
        printf("f=%lf\n", f);
    }
    else if(k<=0 || m<0)
    {
        f = m+k;
        printf("f=%lf\n", f);
    }
    else
    {
        f = k*m;
        printf("f=%lf\n", f);
    }

    main();
}
void second()
{
    double a,b;
    double c,d;
    double D;

    printf("function definition scope: (-oo;0), (0;+oo)\n");
    printf("Enter numbers a and b: ");
    scanf("%lf %lf", &a, &b);
    fflush(stdin);

    if(a == 0 || b == 0)
    {
        printf("The values do not belong to the scope of the function definition!\n");
        main();
    }
    else
    {
    c = powf(M_E, -1./6)*powf(pow(a, 2)+logf(abs(b)), 1./2)-tanf(a);
    d = 2*powf(cosf(powf(a, 3)), 2);

    D = c/d;

    printf("D = %lf\n", D);

    main();
    }
}
void third()
{
    double ax, ay, bx, by;
    double x, y;
    double a, b;
    double c, d;

    printf("Enter coordinates of the point a: ");
    scanf("%lf %lf", &ax, &ay);
    printf("Enter coordinates of the point b: ");
    scanf("%lf %lf", &bx, &by);

    if(ax == 0 || ay == 0 || bx == 0 || by == 0)
    {
        if(ax == 0 || ay == 0)
        printf("Point a lies on the coordinate line\n");
        else if(bx == 0 || by == 0)
        printf("Point b lies on the coordinate line\n");
        else if(ax == 0 || ay == 0 && bx == 0 || by == 0)
        printf("Both points a lies on the coordinate line\n");
    } else if(ax > 0 && ay > 0 && bx > 0 && by > 0 ||
              ax < 0 && ay > 0 && bx < 0 && by > 0 ||
              ax < 0 && ay < 0 && bx < 0 && by < 0 ||
              ax < 0 && ay > 0 && bx < 0 && by > 0)
    {
    if(ax > bx)
        x = ax-bx;
    else if(ax < bx)
        x = bx-ax;
    if(ay > by)
        y = ay-by;
    else if(ay < by)
        y = by-ay;

    d = hypot(x, y);

    printf("The distance between a and b: %lf\n", d);

    } else
    {
        a = hypot(ax, ay);
        b = hypot(bx, by);

        printf("a = %lf, b = %lf\n", a, b);
        if(a > b)
            printf("Point a is more distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by);
        else if(a < b)
            printf("Point b is more distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by);
        else
            printf("Points equally distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by);
    }

    main();
}
void fouth()
{
    double a;
    int n;
    double c = 1;

    printf("Enter a real number: ");
    scanf("%lf", &a);
    printf("Enter a natural number: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        c *= a-i*n;
        printf("%lf\n", c);
    }
    c *= a;
    printf("%lf\n", c);

    main();
}
void fifth()
{
    double W;
    double Pr;
    double Sum;
    double asum;
    double a;
    bool cap;

    printf("Enter the initial contribution: ");
    scanf("%lf", &W);
    printf("Enter the interest rate: ");
    scanf("%lf", &Pr);
    printf("Enter the amount of interest: ");
    scanf("%lf", &Sum);
    printf("With capitalization by deposit?(yes - 1, no - 0): ");
    scanf("%d", &cap);


    a = W;
    int i = 0;
    while(a)
    {
        if(cap)
            a += a*Pr/100;
        else
            a += W*Pr/100;
        if(a>Sum)
        {
         break;
        }
        i++;
    }
    printf("%d\n", i);

    main();
}
void sixth()
{
    long int num;
    int v;
    bool a = false;
    long int b;
    int c = 0;

    printf("Enter the number being checked: ");
    scanf("%d", &num);
    printf("Enter the verification digit: ");
    scanf("%d", &v);

    b = num;

    while(b)
    {
        c = b % 10;

        if(v == c)
        {
            a = true;
            break;
        }
        b /= 10;
    }

    if(a)
        printf("The verification digit %d is in the number %d\n", v, num);
    else
        printf("The verification digit %d is not in the number %d\n", v, num);

    main();
}
void seventh()
{
    double x,s,r;
    int n;

    printf("Enter the number x: ");
    scanf("%lf", &x);

    r = x;
    s = x;

    for(n = 3; fabs(r) > EPS7; n += 2)
        s += r *= x*x/n/(n-1);

    printf("s = %lf\ne^%.0lf-e^%.0lf/2 = %lf\n", s, x, -x, sinh(x));//powf(M_E, x)-pow(M_E, -x)/2);

    main();
}
void eighth()
{
    double a,c,b,x,s,d,t;
    int n = 1;

    printf("Enter the number x(0.1-1): ");
    scanf("%lf", &x);
    fflush(stdin);

        if(x < 0.1 || x > 1)
        {
            printf("You have entered an invalid value.\n");
            main();
        }

    a = 1;
    s = 1;
    d = 1;
    b = 1;
    c = 1;

    while(fabs(d) > EPS8)
    {
        c = n-1;
        b = factorial(c)*n;
        //a = ((2*n+1)/f)*powf(x, 2*n);
        t = (2*n-1);
        a = ((2*n+1)/t)*x*x;
        d *= a/b;
        s += d;
        n++;
        printf("a = %lf, b = %lf, d = %lf, s = %lf\n", a, b, d, s);
    }

    printf("s = %.6lf\n(1+2%.1lf^2)e^%.1lf^2 = %.6lf\n", s, x, x, (1+2*x*x)*pow(M_E, powf(x, 2)));

    main();
}
void nineth()
{
    int i, c, a, b, d, tic, e, l;

    printf("Enter count of numbers: ");
    scanf("%d", &c);

    int n[c];

    printf("Enter the natural numbers: \n");

    for(i = 0; i<c; i++)
    {
        printf("number %d: ", i+1);
        scanf("%d", &n[i]);
    }

    l = 0;
    d = 0;

    for(i = 0; i<c; i++)
    {
        e = n[i];
        for(tic = 0; e>0; tic++)
        {
            a = e % 10;
            e /= 10;
            if(tic == 0)b = a;
            if(e == 0)d = a;
        }
        if(b == d)l += n[i];
    }

    printf("Result = %d\n", l);

    main();
}
int factorial(factor)
{
    if(factor == 1 || factor == 0)
        return 1;
    return factor * factorial(factor - 1);
}

