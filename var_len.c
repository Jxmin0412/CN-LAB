#include <stdio.h>
int main()
{
    int i = 0, j, s, c = 0;
    char msg[100];
    printf("Enter string: ");
    scanf("%s", msg);
    while (msg[i] != '\0')
    {
        printf("enter frame size of %d: ", c);
        scanf("%d", &s);
        printf("message of %d frame is: ", c++);
        for (j = i; j < i + s; j++)
        {
            printf("%c", msg[j]);
        }
        i += s;
        printf("\n");
    }
    return 0;
}
