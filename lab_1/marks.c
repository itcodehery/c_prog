#include <stdio.h>

int main() {
    float marks;
    
    printf("Enter marks obtained in Computer Science: ");
    scanf("%f", &marks);
    
    if (marks > 90) {
        printf("Grade: A\n");
    }
    else if (marks >= 70 && marks <= 90) {
        printf("Grade: B\n");
    }
    else if (marks >= 50 && marks <= 69) {
        printf("Grade: C\n");
    }
    else {
        printf("Grade: D\n");
    }
    
    return 0;
}
