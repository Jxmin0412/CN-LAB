#include <stdio.h>
#include <string.h>
char msg[100], g[10], x1[10], rem[10], rcv[100], urcv[100];
int m, n, j = 0, f = -1, k = 0;
char xor (char a, char b) {
    if (a == b)
        return '0';
    else
        return '1';
} void cal(char x2[])
{
    k = 0;
    for (int i = 0; i < n; i++)
    {
        rem[i] = xor(x1[i], g[i]);
    }
    while (rem[k] != '1' && k <= n)
    {
        k++;
    }
    int q = 0, p = k;
    while (rem[p] != '\0')
    {
        x1[q++] = rem[p++];
    }

    for (int r = 0; r < k; r++)
    {
        x1[q++] = x2[j++];
    }
}

void crc(char x2[])
{
    j = 0;
    for (int i = 0; i < n; i++)
    {
        x1[i] = x2[j++];
    }

    while (x2[j] != '\0')
    {
        cal(x2);
    }
    cal(x2);
}
void main()
{
    printf("Enter the message : ");
    scanf("%s", msg);
    printf("\nEnter Divisor : ");
    scanf("%s", g);
    n = strlen(g);
    m = strlen(msg);

    for (int i = 0; i < m; i++)
    {
        rcv[i] = msg[i];
    }

    for (int i = m; i < m + n - 1; i++)
    {
        msg[i] = '0';
    }

    printf("\nAfter appending zeroes the message : %s\n", msg);

    crc(msg);

    printf("\nReminder  is  : %s\n", rem);

    int ind = 1;
    for (int i = m; i < m + n - 1; i++)
    {
        rcv[i] = rem[ind++];
    }

    printf("\nReciever message without errors is : %s\n", rcv);

    printf("\nEnter the Recieved message : ");
    scanf("%s", urcv);

    crc(urcv);

    printf("\nReminder of given msg is : %s\n", rem);

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (rem[i] != '0')
        {
            flag = 0;
        }
    }
    if (flag)
        printf("\nNO ERROR ! \n\n");
    else
        printf("\n ERROR DETECTED!!!!\n\n");
}
