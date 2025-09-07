#include <malloc.h>
#include<stdio.h>
#include<stdio.h>

void inputMarks(int *marks, int n) {
    for (int i = 0; i < n ; i++) {
        printf("\nEnter marks for student %d: ", i + 1);
        scanf("%d", (marks + i));
    }
}

void displayMarks(int *marks, int n) {
    for (int i = 0; i < n; i++) {
        printf("Marks of student %d: %d\n", i + 1, *(marks + i));
    }
}

int findMax(int *marks, int n) {
    int max = *(marks + 0);
    for (int i = 1; i < n; i++) {
        if (*(marks + i) > max) {
            max = *(marks + i);
        }
    }
    return max;
}

float findAverage(int *marks, int n) {
    float average = 0.0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=  *(marks + i);
    }
    average = (float) sum / n;
    return average;
}

int main() {
    int studentNum, *arr;
    printf("\nEnter the number of students: ");
    scanf("%d", &studentNum);
    arr = (int *)malloc(studentNum * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    inputMarks(arr, studentNum);
    displayMarks(arr, studentNum);
    int max = findMax(arr, studentNum);
    float average = findAverage(arr, studentNum);
    printf("Highest marks: %d\n", max);
    printf("Average marks: %.2f\n", average);

    // Memory deallocation
    free(arr);
    printf("Memory successfully deallocated!");
    return 0;
}
