#include <stdio.h>

int main() {
    int sum = 0;
    int count = 0;
    int num = 1;
 
    while (count < 10) {
        sum += num;
        num += 2;  
        count++;
    }
    
    printf("Sum of first 10 odd natural numbers is: %d\n", sum);
    
    return 0;
}
