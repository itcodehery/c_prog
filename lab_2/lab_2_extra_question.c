#include <stdio.h>
// 145 is a number that is 1! + 4! + 5!
// Find all the numbers below 1000.
int factorial(int N) {
    int fact = 1, i;
    // Loop from 1 to N to get the factorial
    for (i = 1; i <= N; i++) {
        fact *= i;
    }
    return fact;
}


void main() {
    printf("Finding all numbers below 1000 whose sum of factorial of digits is equal to the number itself:");
    printf("\n------------------------------------------------------------------------");
for(int i = 1; i < 100000 ; i++){
        // Get Digits
        int digit1,digit10,digit100,sum;
    if (i<10) {
        digit1 = i;
        digit10= 0;
        digit100= 0;
    } else if (i < 100) {
        digit1 = i % 10;
        digit10 = i / 10;
        digit100 = 0;
    } else {
        digit1 = i % 10;
        digit10 = (i % 100 - digit1)/10;
        digit100 = i / 100;
    }
    // printf("\nDigits: %d %d %d", digit100, digit10, digit1);
    if (i < 10) {
        sum = factorial(digit1);
    }
    else if (i < 100) {
        sum = factorial(digit1) + factorial(digit10);
    }
    else {
        sum = factorial(digit1) + factorial(digit10) + factorial(digit100);
    }
    // printf("\nSum: %d", sum);
    if (sum == i) {
        printf("\nFound number: %d",i);
        printf("\nSum of Factorials of Digits: %d",sum);
        printf("\nBoth are equal\n");
        }
}
    return;
    
}