#include<stdio.h>

int main() {
    int row_num, col_num;

    void display_matrix(int matrix[row_num][col_num]) {
        for(int i = 0 ; i < row_num ; i++){
            for(int j = 0 ; j < col_num ; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    printf("Enter the number of rows:");
    scanf("%d", &row_num);
    printf("\nEnter the number of columns:");
    scanf("%d", &col_num);
    int matrix1[row_num][col_num];
    int matrix2[row_num][col_num];
    int matrix3[row_num][col_num];
    printf("\nEnter the elements in the matrix 1.");
    for(int i = 0 ; i < row_num ; i++){
        for(int j = 0 ; j < col_num ; j++){
            printf("\nEnter the element at row %d and column %d: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nEnter the elements in the matrix 2.");
    for(int i = 0 ; i < row_num ; i++){
        for(int j = 0 ; j < col_num ; j++){
            printf("\nEnter the element at row %d and column %d: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    for(int i = 0 ; i < row_num ; i++){
        for(int j = 0 ; j < col_num ; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("\nSum of both matrix:\n");
    for (int i = 0 ; i < row_num ; i++) {
        for (int j = 0; j < col_num ; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\t");
        for (int j = 0; j < row_num ; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\t");
        for (int j = 0; j < col_num ; j++) {
            printf("%d ", matrix3[i][j]);
        }
        printf("\n");
    }
    return 0;
}

