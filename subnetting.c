#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void subnetting(char *ip, int n)
{
    // Convert IP address to binary
    unsigned int ipAddress;
    scanf(ip, "%u", &ipAddress);
    unsigned int subnetMask = (1U << 32) - 1;
    subnetMask <<= (32 - n);
    unsigned int hostsPerSubnet = (1U << (32 - n)) - 2;
    unsigned int subnetBase = ipAddress & subnetMask;
    printf("Subnet Mask: %u\n", subnetMask);
    printf("Number of Hosts per Subnet: %u\n", hostsPerSubnet);
    for (int i = 0; i < n; i++)
    {
        unsigned int subnetStart = subnetBase + i * (1U << (32 - n));
        unsigned int subnetEnd = subnetStart + (1U << (32 - n)) - 1;
        printf("\nSubnet %d:\n", i + 1);
        printf("Subnet Address Range: %u - %u\n", subnetStart, subnetEnd);
    }
}
int main()
{
    char ipAddress[16]; // IPv4 address
    int numSubnets;
    printf("Enter IP address: ");
    scanf("%15s", ipAddress);
    printf("Enter the number of subnets: ");
    scanf("%d", &numSubnets);
    if (numSubnets <= 0 || numSubnets > 32)
    {
        printf("Invalid number of subnets. Please enter a value between 1 and 32.\n");
        return 1;
    }
    subnetting(ipAddress, numSubnets);
    return 0;
}
