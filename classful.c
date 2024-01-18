#include <stdio.h>
#include <string.h>

char findClass(char str[]) {
    int ip;
    sscanf(str, "%d", &ip);

    if (ip >= 1 && ip <= 126) return 'A';
    else if (ip >= 128 && ip <= 191) return 'B';
    else if (ip >= 192 && ip <= 223) return 'C';
    else if (ip >= 224 && ip <= 239) return 'D';
    else return 'E';
}

void separate(char str[], char ipClass) {
    char network[16], host[16];
    int i = 0, j = 0, dotCount = 0;

    while ((dotCount < 3 && ipClass == 'C') || (dotCount < 1 && ipClass != 'D' && ipClass != 'E')||(dotCount < 2 &&ipClass == 'B')) {
        network[i++] = str[j];
        if (str[j] == '.') 
            dotCount++;
            j++;
    }
    network[i] = '\0';

    i = 0;
    while (str[j] != '\0') {
        host[i++] = str[j++];
    }
    host[i] = '\0';

    printf("Network ID is %s\n", network);
    printf("Host ID is %s\n", host);
}

int main() {
    char str[20];
    printf("Enter IP address:");
    scanf("%s",str);
    char ipClass = findClass(str);

    printf("Given IP address belongs to Class %c\n", ipClass);
    separate(str, ipClass);

    return 0;
}
