#include <stdio.h>
int main()
{
    int windowsize, sent = 0, ack, i;
    printf("Enter window size:\n");
    scanf("%d", &windowsize);
    while (1)
    {
        for (i = 0; i < windowsize; i++)
        {
            printf("frame %d has been transmitted \n", sent);
            sent++;
            if (sent == windowsize)
                break;
        }
        printf("\n Please enter last acknowledgement recieved");
        scanf("%d", &ack);
        if (ack == windowsize)
            break;
        else
            sent = ack;
    }
    return 0;
}