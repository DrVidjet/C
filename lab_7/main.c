#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

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
    int i, j, c = 0, d = 0, b = 0;
    bool prov;

    printf("Enter the file name: ");
    fflush(stdin);
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");
    char *buffer;
    char *postbuffer;
    postbuffer = (char*)malloc(256);
    buffer = (char*)malloc(256);

    if(fp)
    {
        while((fgets(buffer, 256, fp)) != NULL)
        {
            buffer = realloc(buffer, strlen(buffer));
            postbuffer = realloc(postbuffer, strlen(buffer));
            for(i = 0; i < strlen(buffer); i++)
            {
                if(buffer[i] == 'o' || buffer[i] == 'O')
                {
                    c++;
                }
                else if(buffer[i] == ' ')
                {
                    if(c > 1)
                        prov = 1;
                    c = 0;
                }
                else if(buffer[i] == '.')
                {
                    if(prov == 0)
                    {
                        for(j = d; j < i; j++)
                        {
                            postbuffer[b] = buffer[j+2];
                            //printf("buffer[%d] = %c, postbuffer[%d] = %c\n", j, buffer[j], b, postbuffer[b]);
                            b++;
                        }
                    }
                    prov = 0;
                    d = i;
                }
            }


            postbuffer = realloc(postbuffer, b);
            //Hollow knight. Hello knight.
            fclose(fp);
            remove(filename);
            FILE *fp = fopen(filename, "w+");
            fprintf(fp, buffer);
            printf("Before:\n\n%s\n\n", buffer);

            printf("After:\n\n");
            for(i = 0; i < b; i++)
                printf("%c", postbuffer[i]);
            printf("\n\n");
        }
    }

    free(postbuffer);
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
