#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Sparse {
    int row;
    int col;
    int value;
};

void createSparseMatrix(int matrix[][MAX], int rows, int cols, struct Sparse sparse[], int *size) {
    *size = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[*size].row = i;
                sparse[*size].col = j;
                sparse[*size].value = matrix[i][j];
                (*size)++;
            }
        }
    }
}

void displaySparseMatrix(struct Sparse sparse[], int size, int rows, int cols) {
    int sparseMatrix[MAX][MAX] = {0};

    for (int i = 0; i < size; i++) {
        sparseMatrix[sparse[i].row][sparse[i].col] = sparse[i].value;
    }

    printf("\nSparse Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
}

void displaySparseArray(struct Sparse sparse[], int size) {
    printf("\nSparse Array Representation:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int matrix[MAX][MAX];
    struct Sparse sparse[MAX];
    int rows, cols, size;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    createSparseMatrix(matrix, rows, cols, sparse, &size);

    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    displaySparseArray(sparse, size);
    displaySparseMatrix(sparse, size, rows, cols);

    return 0;
}
