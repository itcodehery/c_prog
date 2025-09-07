#include<stdio.h>

int factorial(int a) {
    if (a==0 || a==1) {
        return 1;
    }
    return a * factorial(a - 1);
}
int main() {
    int num,fact;
    printf("Enter the number :");
   scanf("%d",&num);
    fact = factorial(num);
    printf("\nThe factorial of %d is %d",num,fact);
    return 0;
}
