#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

void first();
void second();
void third();
void fouth();

int main()
{
    int ch;

    void (*funcs[4])();

    funcs[0] = first;
    funcs[1] = second;
    funcs[2] = third;
    funcs[3] = fouth;

        printf("Enter the program number(1-4) or 0 for exit: ");
        scanf("%d", &ch);
        fflush(stdin);

        if(ch != 0)
            funcs[ch-1]();
        else
            return 0;
}

void first()
{
    char *filename;
    filename = (char*)malloc(15);
    int i, c, r, w;
    bool prov;

    printf("Enter the file name: ");
    fflush(stdin);
    fgets(filename, 15, stdin);

    for(i = -1; filename[++i] > 31;);
    filename[i] = '\0';

    FILE *fp = fopen(filename, "r+");

    if(!fp)main();
    else
    {
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        printf("size = %d\n", size);

        char *buffer;

        buffer = (char*)malloc(size+1);

        for(i = 0; i<size;)buffer[i++] = fgetc(fp);
        buffer[size] = '\0';

        for(i = -1; buffer[++i];)buffer[i] += 22*!(buffer[i] - '\n');

        printf("%s\n", buffer);

        for(prov = c = i = r = w = 0; i < size; i++)
        {
            if(buffer[i] != '.')
            {
                c += !((buffer[i]|0x20)-'o');
                if(buffer[i] == ' ' && c == 2)prov = 1;
                if(c > 2)prov = 0;
                c *= !!(buffer[i] - ' ');
                printf("c = %d, buffer[%d] = %c\n", c, i, buffer[i]);
                printf("prov = %d\n", prov);
            }
            else
            {
                if(c == 2)prov = 1;
                if(prov && r == 0)r = i+2;
                else if(prov && r != 0)r = i;
                else
                    for(;r < i;)
                    {
                        buffer[w++] = buffer[r++];
                        printf("w = %d, r = %d\n", w, r);
                    }
                prov = 0;
            }
        }
        buffer[w+2] = '\0';
        printf("c = %d\n", c);
        for(i = 0; i < w;)printf("%c", buffer[i++]);

        remove(fp);
        FILE *fl = fopen(filename, "w+");

        for(i = 0; i < w;)fputc(buffer[i++], fl);

        fclose(fl);
        fclose(fp);
        free(filename);
        free(buffer);

        printf("\n\nTask well done!\n\n");
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
