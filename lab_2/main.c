#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define EPS7 1e-5
#define EPS8 1e-4

int factor;
int end;

int main(void)
{
    int choice;

    printf("Enter the program number(1-9): ");
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
        case 7: seventh();
        break;
        case 8: eighth();
        break;
        case 9: nineth();
        break;
    }

    system("pause");
}

void first()
{
    double k, m, f;

    printf("Please, enter number k: ");
    scanf("%lf", &k);
    printf("Please, enter number m: ");
    scanf("%lf", &m);

    if(k > 0)
    {
        f = m/k;
        printf("f=%lf\n", f);
    } else if(k<=0 || m<0)
    {
        f = m+k;
        printf("f=%lf\n", f);
    } else {
        f = k*m;
        printf("f=%lf\n", f);
    }
    end = 1;
    choice();
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
        end = 2;
        choice();
    } else {
    c = powf(M_E, -1./6)*powf(pow(a, 2)+logf(abs(b)), 1./2)-tanf(a);
    d = 2*powf(cosf(powf(a, 3)), 2);

    D = c/d;

    printf("D = %lf\n", D);

    end = 2;
    choice();
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
        a = abs(ax)+abs(ay);
        b = abs(bx)+abs(by);
        if(a < b)
            printf("Point a is more distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by);
        else if(a > b)
            printf("Point b is more distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by);
        else
            printf("Points equally distant: a(%.1lf; %.1lf), b(%.1lf; %.1lf)\n", ax, ay, bx, by);
    }

    end = 3;
    choice();
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
        c = (a-i*n)*c;
        printf("%lf\n", c);
    }
    c *= a;
    printf("%lf\n", c);

    end = 4;
    choice();
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

    end = 5;
    choice();
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

    end = 6;
    choice();
}
void seventh()
{
    double a,x,s,f;
    int n;

    printf("Enter the number x: ");
    scanf("%lf", &x);

    a = 0.5;
    s = 0;

    for(n = 1; fabs(a) > EPS7; n += 2)
    {
        f = factorial(n);
        a = powf(x, n)/f;
        s += a;
    }
    printf("s = %lf\ne^%.0lf-e^%.0lf/2 = %lf\n", s, x, -x, (powf(M_E, x)-pow(M_E, -x))/2);

    end = 7;
    choice();
}
void eighth()
{
    double a,x,s,f;
    int n = 0;

    printf("Enter the number x(0.1-1): ");
    scanf("%lf", &x);
    fflush(stdin);

        if(x < 0.1 || x > 1)
        {
            printf("You have entered an invalid value.\n");
            end = 8;
            choice();
        }

    a = 0.5;
    s = 0;

    while(fabs(a) > EPS8)
    {
        f = factorial(n);
        a = ((2*n+1)/f)*powf(x, 2*n);
        s += a;
        n++;
    }

    printf("s = %.6lf\n(1+2%.1lf^2)e^%.1lf^2 = %.6lf\n", s, x, x, (1+2*powf(x, 2))*powf(M_E, powf(x, 2)));

    end = 8;
    choice();
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

    end = 9;
    choice();
}
void choice()
{
    int choice;
    int res(int value);
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
           case 7: seventh();
           break;
           case 8: eighth();
           break;
           case 9: nineth();
       }
       }
    else if(choice == 2)
        main();
    else if(choice == 3)
        system("exit");
}
int factorial(factor)
{
    if (factor == 1 || factor == 0)
    {
        return 1;
    }
    return factor * factorial(factor - 1);
}

