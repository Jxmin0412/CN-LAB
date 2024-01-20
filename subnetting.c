#include<stdio.h>
int main(){
    char data[100];
    printf("Enter Ip address:");
    scanf("%s",data);
    printf("enter number of subnets:");
    int n;
    scanf("%d",&n);
    unsigned long long int num=(pow(2, 32) - 1)-(pow(2,32-n)-1);
    printf("subnet mask:%llu",num);
    num=pow(2,32-n);
    printf("\nNumber of hosts for subnet:%llu",num-2);
    unsigned long long int sum=0;
    for(int i=0;i<n;i++){
        printf("\nsubnet %d\n",i+1);
        printf("\n Subnet range:%llu to %llu",sum,sum+num-1);
        sum=num+sum;
        
        
    }
    
}
