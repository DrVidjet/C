#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

int end;

int main(void)
{
    int choice;

    printf("Enter the program number(1-4): ");
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
    char *filename;
    filename = (char*)malloc(15);
    int i, j, c = 0, d = 0, g = 0;

    fflush(stdin);
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");
    char buffer[256];

    if(fp)
    {
        fgets(buffer, 256, fp);
            printf("%s\n\n", buffer);
            for(i = 0; i < strlen(buffer); i++)
            {
                if(buffer[i] == ' ' || buffer[i] == ',')
                {
                    c = 0;
                    g++;
                }
                else if(buffer[i] == 'o')
                    c++;
                else if(buffer[i] == '.')
                {
                    if(g > 0)
                    {
                        for(j = d; j < d+i; j++)
                        {
                            buffer[j] = " ";
                        }

                        d = i;
                        g = 0;
                    }
                }
            }
            fclose(fp);
    }
    free(filename);
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
