#include<stdio.h>

int sumOfOddDigits(int digits[]) {
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (digits[i] % 2 != 0) {
            sum += digits[i];
        }
    }
    return sum;
}

int isPalindrome(int num) {
    int backnum = 0;
    int dupli_num = num;
    while (dupli_num != 0) {
        backnum = backnum * 10 + dupli_num % 10;
        dupli_num /= 10;
    }
    if (num == backnum) {
        return 1;
    }
    else {
        return 0;
    }
}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    if (num == 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

int sumOfFactorialsOfEvenDigits(int num) {
    int sum = 0;
    while (num!= 0) {
        int digit = num % 10;
        if (digit % 2 == 0) {
            sum += factorial(digit);
        }
        num /= 10;
    }
    return sum;
}

int main() {
    int choice, num, dupli_num, digits[10];  
    do {
        printf("\n=== Number Menu ===\n");
        printf("1. Sum of Odd Digits\n");
        printf("2. Check Palindrome\n"); 
        printf("3. Sum of Factorials of the Even Digits\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        printf("\n\nEnter the number: ");
        scanf("%d", &num);
        if (num == 4) {
            break;
        }
     
        
        switch(choice) {
            case 1:
            dupli_num = num;
    for (int i = 0; i < 10; i++) {
        digits[i] = dupli_num % 10;
        dupli_num /= 10;
    }
            printf("%d", num);
                printf("\nSum of Odd Digits: %d\n", sumOfOddDigits(digits));
                break;
            case 2:
            dupli_num = num;
    for (int i = 0; i < 10; i++) {
        digits[i] = dupli_num % 10;
        dupli_num /= 10;
    }
     
                if (isPalindrome(num) == 1) {
                    printf("\n%d is a palindrome.\n", num);
                }
                else {
                    printf("\n%d is not a palindrome.\n", num);
                }
                break;
            case 3:
            dupli_num = num;
    for (int i = 0; i < 10; i++) {
        digits[i] = dupli_num % 10;
        dupli_num /= 10;
    }
                printf("\nSum of Factorials of Even Digits of %d is %d\n", num, sumOfFactorialsOfEvenDigits(num));
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);
}

