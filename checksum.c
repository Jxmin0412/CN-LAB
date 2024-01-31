#include <stdio.h>
#include <string.h>

// Function to calculate the checksum for a given data string
int calculateChecksum(const char *data)
{
    int checksum = 0;
    int dataLen = strlen(data);

    for (int i = 0; i < dataLen; i++)
    {
        checksum += data[i];
    }

    return checksum;
}

// Function to verify the checksum for a given data string and received checksum
int verifyChecksum(const char *data, int receivedChecksum)
{
    int calculatedChecksum = calculateChecksum(data);
    return (calculatedChecksum == receivedChecksum);
}

int main()
{
    char data[100];
    int sentChecksum, receivedChecksum;

    // Input data
    printf("Enter data: ");
    scanf("%s", data);

    // Calculate and print the checksum for the sent data
    sentChecksum = calculateChecksum(data);
    printf("Checksum for sent data: %d\n", sentChecksum);

    // Simulate transmission by copying the sent data and checksum
    char receivedData[100];
    strcpy(receivedData, data);
    receivedChecksum = sentChecksum;

    // Verify the checksum for the received data
    if (verifyChecksum(receivedData, receivedChecksum))
    {
        printf("Received data is correct. No errors detected.\n");
    }
    else
    {
        printf("Error detected in received data.\n");
    }

    return 0;
}
