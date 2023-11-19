#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void first();
void second();

int main()
{
    int ch;

    void (*funcs[2])();

    funcs[0] = first;
    funcs[1] = second;

        printf("Enter the program number(1-2) or 0 for exit: ");
        scanf("%d", &ch);
        fflush(stdin);

        if(ch != 0)
            funcs[ch-1]();
        else
            return 0;
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

    main();
}
void second()
{
    char pstr[50];
    char *str;
    str = (char*)malloc(50);
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

    printf_s("%s\n", pstr);

    main();
}
