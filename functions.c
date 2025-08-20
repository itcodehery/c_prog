#include<stdio.h>

int main() {
    int i,n;
    char c;
    
    printf("Enter the number of stars: ");
    scanf("%d", &n);

    fflush(stdin); // Clearing the input buffer
    
    printf("\nEnter a character: ");
    scanf("%c", &c);
    
    printf("\nThe stars are:\n");
    
    void format(int n, char c);      // Prototype declaration
    
    for(i=0; i<10; i++) {
        format(n,c);       // Calling of the functions
    }
}

void format(int n, char c) {         // Function definition
    int i;
    for(i=0; i<n; i++) {
        printf("%c",c);
    }
    printf("\n");
}