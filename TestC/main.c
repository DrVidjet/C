#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[] = "ab. ab";
    char new_word[ strlen(word) ];

    int j=0;
    for(int i=0; i<strlen(word); i++)
    {
        if (word[i] != ' ')
        {
            new_word[j] = word[i];
            j++;
        }
    }
    new_word[j] = '\0';

    printf("%d\n", strlen(new_word));

    char result[ strlen(new_word) ];

    int i = 0;
    for(; i<strlen(new_word) - 2; i++)
    {
        "bbfd      -       hf"
        char* buffer = new_word[i-2];
        strncat(result, buffer, 1);
    }
    result[i+1] = '\0';

    printf("%s", result);


    return 0;
}
