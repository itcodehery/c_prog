#include<stdio.h>

int is_prime(int num) {
    if (num < 1) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    for (int i = 2; i < num ; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int is_palindrome(int num) {
    int reversed = 0;
    int original = num;
    
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    
    return original == reversed;
}

int main() {
    printf("Checking for Prime Palindromes from 100 to 1000\n\n\n\n\n\n");
 for (int i = 100; i <= 1000 ; i++) {
    if (is_prime(i)) {
        if (is_palindrome(i)) {
            printf("%d is a prime palindrome number.\n", i);
        }
    }
}
}

