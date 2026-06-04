#include <stdio.h>

void inputMatrix(int rows, int cols, int matrix[10][10]) {
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[10][10]) {
    int i, j;

    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[10][10], B[10][10], C[10][10];
    int rows, cols, choice;
    int i, j, k;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("\nEnter elements of Matrix A:\n");
    inputMatrix(rows, cols, A);

    printf("\nEnter elements of Matrix B:\n");
    inputMatrix(rows, cols, B);

    printf("\n===== Matrix Operations =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Transpose\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            for(i = 0; i < rows; i++) {
                for(j = 0; j < cols; j++) {
                    C[i][j] = A[i][j] + B[i][j];
                }
            }

            printf("\nResult of Addition:\n");
            displayMatrix(rows, cols, C);
            break;

        case 2:
            for(i = 0; i < rows; i++) {
                for(j = 0; j < cols; j++) {
                    C[i][j] = A[i][j] - B[i][j];
                }
            }

            printf("\nResult of Subtraction:\n");
            displayMatrix(rows, cols, C);
            break;

        case 3:
            for(i = 0; i < rows; i++) {
                for(j = 0; j < cols; j++) {
                    C[i][j] = 0;

                    for(k = 0; k < cols; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }

            printf("\nResult of Multiplication:\n");
            displayMatrix(rows, cols, C);
            break;

        case 4:
            printf("\nTranspose of Matrix A:\n");

            for(i = 0; i < cols; i++) {
                for(j = 0; j < rows; j++) {
                    printf("%d\t", A[j][i]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}
