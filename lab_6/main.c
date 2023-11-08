#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int end;

int main(void)
{
    int choice;

    printf("Enter the program number(1-2): ");
    scanf("%d", &choice);
    fflush(stdin);

    switch(choice)
    {
        case 1: first();
        break;
        case 2: second();
        break;
    }

    system("pause");
}

void first()
{
    char str[15];

    printf("Enter the number: ");
    fgets(str, 15, stdin);
    long num = strtol(str, NULL, 10);

    if(num > 0 && num < 65535)
        printf("\nThe entered number %d can be represented in the form 'unsigned short int'.\n\n", num);
    else if(num < 0 || num > 65535)
        printf("\nThe entered number %d cannot be represented in the form 'unsigned short int'.\n\n", num);
    else
        printf("\nThe entered sequence of characters is not a number!\n\n");

    end = 1;
    choice();
}
void second()
{
    char pstr[50];
    char *str;
    str = (char*)malloc(50);
    char sep[1] = ".";
    int i, c = 0;
    char temp;

    printf("Enter some text: ");
    fgets(str, 50, stdin);
    fflush(stdin);

    for(i = 0; i < 50; i++)
    {
        if(str[i] != '.')
        {
            pstr[i] = str[i];
            c++;
        }
        else
        {
            pstr[i] = str[i];
            break;
        }
    }

    free(str);

    c = 0;
    for(i = 0; i < 50; i++)
    {
        if(pstr[i] == ' ' || pstr[i] == '.')
        {
            temp = pstr[i-1];
            pstr[i-1] = pstr[c];
            pstr[c] = temp;
            c = i+1;
        }
    }

    puts(pstr);

    end = 2;
    choice();
}
int choice()
{
    int choice;
    printf("1 - repeat the program, 2 - go back to the menu, 3 - exit the program\n");
    scanf("%d", &choice);
    fflush(stdin);
    if(choice == 1)
    {
       switch(end)
       {
           case 1: first();
           break;
           case 2: second();
           break;
       }
    }
    else if(choice == 2)
        main();
    else if(choice == 3)
        system("exit");
}
