#include <stdio.h>

int main() {
    int sum = 0;
    
    for(int i = 100; i <= 998; i += 2) {
        sum += i;
    }
    
    printf("Sum of all 3-digit even natural numbers: %d\n", sum);
    
    return 0;
}
