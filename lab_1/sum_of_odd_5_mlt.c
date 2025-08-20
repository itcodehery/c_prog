#include <stdio.h>

int main() {
    int sum = 0;
    
    for(int i = 100; i <= 999; i++) {
        if(i % 2 != 0 && i % 5 == 0) {
            sum += i;
        }
    }
    
    printf("Sum of 3-digit odd numbers divisible by 5: %d\n", sum);
    
    return 0;
}
