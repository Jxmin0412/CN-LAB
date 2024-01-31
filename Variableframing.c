#include<stdio.h>
void main()
{
    char msg[100];
    int i = 0 , j , size , count = 0;
    printf("\nEnter the Message : ");
    scanf("%s",msg);
    while(msg[i] != '\0')
    {
        printf("\nEnter the Frame Size : ");
        scanf("%d",&size);
        printf("Message = ");
        for(j = i ; j < i + size ; j++)
        {
            printf("%c",msg[j]);
        }
        i += size;
    }
    printf("\n\n");
}
