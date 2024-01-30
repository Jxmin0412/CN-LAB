#include <stdio.h>
void main()
{
    char in[100], out[100], destuff[100];//in:input array,out:array after bitstuffing,destuff:array after destuffing
    int count = 0, i = 0, j = 0;
    printf("Enter the Input String : ");
    scanf("%s", in);
    
    //Bit Stuffing
    while (in[i] != '\0')
    {
        if (in[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }

        out[j++] = in[i++];

        if (count == 5)
        {
            out[j++] = '0';
            count = 0;
        }
    }
    out[j++] = '\0';


    //Bit destuffing
    //Reset count,i,j variables to 0 for destuffing
    i = 0;
    j = 0;
    count = 0;
    while (out[i] != '\0')
    {
        if (out[i] == '1')
        {
            count++;
        }
        else
        {
            count = 0;
        }
        destuff[j++] = out[i++];

        if (count == 5)
        {
            i++;
            count = 0;
        }
    }
    destuff[i] = '\0';

    printf("After Bit Stuffing : %s\n", out);
    printf("After destuffing: %s\n", destuff);
}
