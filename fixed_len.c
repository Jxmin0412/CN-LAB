#include <stdio.h>
int main()
{
    int i, j, l, s, c = 0;
    char str[25], msg[25];
    printf("enter string: ");
    scanf("%s", str);
    printf("enter frame size: ");
    scanf("%d", &s);
    l = 0, j = 0;
    msg[0] = '\0';
    for (i = 0; str[i] != '\0'; i++)
    {
        if (l == s)
        {
            printf("msg of frame %d is: %s\n", c++, msg);
            l = 0, j = 0;
        }
        l++;
        msg[j] = str[i];
        j++;
        msg[j] = '\0';
    }
    printf("msg of frame %d is: %s", c++, msg);
    return 0;
}
