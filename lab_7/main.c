#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

void first();
void second();
void third();
void fouth();

int l = 0, ch;

int main()
{
    int end;

    void (*funcs[4])();

    funcs[0] = first;
    funcs[1] = second;
    funcs[2] = third;
    funcs[3] = fouth;

    if(l == 0)
    {
        printf("Enter the program number(1-4): ");
        scanf("%d", &ch);
        l++;
        funcs[ch-1]();
    }
    else
    {
        printf("1 - repeat the program, 2 - go back to the menu, 3 - exit the program\n");
        scanf("%d", &end);

        switch(end)
        {
            case 1:
                funcs[ch-1]();
                break;
            case 2:
                printf("Enter the program number(1-4): ");
                scanf("%d", &ch);
                funcs[ch-1]();
                break;
            case 3:
                return 0;
        }
    }
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

    char buffer[256];
    char postbuffer[256];

    if(fp)
    {
        while((fgets(buffer, 256, fp)) != NULL)
        {
            for(i = 0; i < strlen(buffer); i++)
            {
                if(buffer[i] == 'o' || buffer[i] == 'O')
                    c++;
                else if(buffer[i] == ' ')
                {
                    if(c > 1)
                        prov = 0;
                    else
                        prov = 1;
                    c = 0;
                }
                else if(buffer[i] == '.')
                {
                    if(prov)
                    {
                        for(j = d; j < i+2; j++)
                        {
                            postbuffer[b] = buffer[j];
                            b++;
                        }
                    }
                    prov = 0;
                    d = i+2;
                }
            }
            //Hollow knight. Hello knight.
        }
        fclose(fp);
        remove(fp);
        FILE *fl = fopen(filename, "w+");
        fprintf_s(fl, postbuffer);
        fclose(fl);
        printf("Task well done!\n");
    }
    main();
}
void second()
{
    main();
}
void third()
{
    main();
}
void fouth()
{
    main();
}
