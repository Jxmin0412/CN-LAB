#include <stdio.h>
#define FLAG '$'
#define ESC '@'

void stuff(char in[], char out[])
{
    int i = 0, j = 0;
    out[j++] = FLAG; // starting of string

    while (in[i] != '\0')
    {
        if (in[i] == FLAG || in[i] == ESC)
        {
            out[j++] = ESC;
        }
        out[j++] = in[i++];
    }

    out[j++] = FLAG; // for end of the string
}

void destuff(char in[], char out[])
{
    int i = 0, j = 0;
    while (in[i] != '\0')
    {
        if (in[i] == ESC)
        {
            i++; // skip the ESC
        }
        out[j++] = in[i++];
    }
    out[j] = '\0'; // null-terminate the destination string
}

int main()
{
    char input[100], stuffed[200], destuffed[100];

    printf("Enter the Input String : ");
    scanf("%s", input);

    // Character Stuffing
    stuff(input, stuffed);
    printf("After Character Stuffing : %s\n", stuffed);

    // Character Destuffing
    destuff(stuffed, destuffed);
    printf("After Character Destuffing : %s\n", destuffed);

    return 0;
}
