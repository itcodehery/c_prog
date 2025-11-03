#include <stdio.h>
#define size 2

void multiplyMatrices(int a[size][size], int b[size][size], int result[size][size]) {
    // Initialize empty result matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
        }
    }
    // Multiply matrices
    for (int i = 0; i < size ; i++){
        for (int j = 0 ; j < size ; j++){
            for (int k = 0 ; k < size ; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }            
        }
    }
    // Display result
    printf("\n\nResult of matrix multiplication: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[size][size];
    int b[size][size];
    printf("Enter the values of Matrix A: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the values of Matrix B: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    printf("Matrix A: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }


    int result[size][size];
    multiplyMatrices(a, b, result);
    return 0;
}

