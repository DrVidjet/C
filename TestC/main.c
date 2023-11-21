#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("text.txt", "r+");

    char buffer[256];

    long d = ftell(fp);

    fseek(fp, 5, SEEK_SET);

    fprintf(fp, "AAA");
}
