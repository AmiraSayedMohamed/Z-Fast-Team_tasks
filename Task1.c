#include <stdio.h>
#include <stdlib.h>

// Function to set a bit
int setBit(int number, int bit_position) {
    return number | (1 << bit_position);
}

// Function to clear a bit
int clearBit(int number, int bit_position) {
    return number & ~(1 << bit_position);
}

// Function to toggle a bit
int toggleBit(int number, int bit_position) {
    return number ^ (1 << bit_position);
}

// Function to read a bit
int readBit(int number, int bit_position) {
    return (number >> bit_position) & 1;
}

// Function to validate the bit position
int isValidBitPosition(int bit_position, int bit_length) {
    return bit_position >= 0 && bit_position < bit_length;
}

int main() {
    int number, bit_position, choice, result;
    int bit_length = sizeof(int) * 8; // Calculate bit size of an integer

    printf("Enter an integer number: ");
    scanf("%d", &number);

    printf("Enter a bit position: ");
    scanf("%d", &bit_position);

    // Validate bit position
    if (!isValidBitPosition(bit_position, bit_length)) {
        printf("Invalid bit position. Please enter a position between 0 and %d.\n", bit_length - 1);
        return 1;
    }

    printf("\nBit Manipulation Menu:\n");
    printf("1. Set a Bit\n");
    printf("2. Clear a Bit\n");
    printf("3. Toggle a Bit\n");
    printf("4. Read a Bit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            result = setBit(number, bit_position);
            printf("Result after setting the bit: %d\n", result);
            break;

        case 2:
            result = clearBit(number, bit_position);
            printf("Result after clearing the bit: %d\n", result);
            break;

        case 3:
            result = toggleBit(number, bit_position);
            printf("Result after toggling the bit: %d\n", result);
            break;

        case 4:
            result = readBit(number, bit_position);
            printf("The bit at position %d is: %d\n", bit_position, result);
            break;

        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }

    return 0;
}
