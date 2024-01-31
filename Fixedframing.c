#include<stdio.h>
void main()
{
    char msg[100];
    int i , j , size , count = 0;
    printf("Enter the Message : ");
    scanf("%s",msg);
    printf("Enter the Frame Size : ");
    scanf("%d",&size);
    printf("\nMessage =");
    for(i = 0 ; msg[i] != '\0' ; i++ , count++)
    {
        if(count == size)
        {
            printf("\nMessage =");
            count = 0;
        }
        printf("%c",msg[i]);
    }
    printf("\n\n");
}
