#include <stdio.h>
#include <stdlib.h>

int end;

int main(void)
{
    int choice;

    printf("Enter the program number(1-6): ");
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
    }

    system("pause");
}
void first()
{
    end = 1;
    choice();
}
void second()
{
    end = 2;
    choice();
}
void third()
{
    end = 3;
    choice();
}
void fouth()
{
    end = 4;
    choice();
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
           case 4: fouth();
           break;
       }
    }
    else if(choice == 2)
        main();
    else if(choice == 3)
        system("exit");
}
