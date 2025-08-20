#include <stdio.h>

int main() {
    int num = 12345;
    int digit;
    
    printf("Digits (right to left): ");
    while (num > 0) {
        digit = num % 10;  // Get the last digit
        printf("%d ", digit);
        num = num / 10;    // Remove the last digit
    }
    printf("\n");
    
    return 0;
}