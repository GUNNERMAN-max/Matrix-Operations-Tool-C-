#include <stdio.h>

#define MAX 10

// Function declarations
void input_matrix(int matrix[MAX][MAX], int rows, int cols, const char *name);
void print_matrix(int matrix[MAX][MAX], int rows, int cols);
void add_matrices(int A[MAX][MAX], int B[MAX][MAX], int Result[MAX][MAX], int rows, int cols);
void transpose_matrix(int A[MAX][MAX], int Result[MAX][MAX], int rows, int cols);
void multiply_matrices(int A[MAX][MAX], int B[MAX][MAX], int Result[MAX][MAX], int r1, int c1, int c2);

int main() {
    int A[MAX][MAX], B[MAX][MAX], Result[MAX][MAX];
    int r1, c1, r2, c2;

    printf("=== Matrix Operations Program ===\n\n");

    // Input dimensions for Matrix A
    printf("Enter rows and columns for Matrix A (max %d): ", MAX);
    scanf("%d %d", &r1, &c1);

    // Input dimensions for Matrix B
    printf("Enter rows and columns for Matrix B (max %d): ", MAX);
    scanf("%d %d", &r2, &c2);

    // Input matrix values
    input_matrix(A, r1, c1, "A");
    input_matrix(B, r2, c2, "B");

    // Display input matrices
    printf("\n--- Input Matrices ---\n");
    printf("Matrix A (%dx%d):\n", r1, c1);
    print_matrix(A, r1, c1);

    printf("Matrix B (%dx%d):\n", r2, c2);
    print_matrix(B, r2, c2);

    // 1. Matrix Addition
    printf("\n--- 1. Matrix Addition (A + B) ---\n");
    if (r1 == r2 && c1 == c2) {
        add_matrices(A, B, Result, r1, c1);
        print_matrix(Result, r1, c1);
    } else {
        printf("Addition not possible! Matrices must have the exact same dimensions.\n");
    }

    // 2. Matrix Transpose
    printf("\n--- 2. Matrix Transpose ---\n");
    printf("Transpose of Matrix A (%dx%d):\n", c1, r1);
    transpose_matrix(A, Result, r1, c1);
    print_matrix(Result, c1, r1);

    printf("Transpose of Matrix B (%dx%d):\n", c2, r2);
    transpose_matrix(B, Result, r2, c2);
    print_matrix(Result, c2, r2);

    // 3. Matrix Multiplication
    printf("\n--- 3. Matrix Multiplication (A * B) ---\n");
    if (c1 == r2) {
        multiply_matrices(A, B, Result, r1, c1, c2);
        printf("Result Matrix A * B (%dx%d):\n", r1, c2);
        print_matrix(Result, r1, c2);
    } else {
        printf("Multiplication not possible! Columns of A (%d) must match rows of B (%d).\n", c1, r2);
    }

    return 0;
}

/**
 * Reads matrix elements from standard input.
 */
void input_matrix(int matrix[MAX][MAX], int rows, int cols, const char *name) {
    printf("\nEnter elements for Matrix %s (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s[%d][%d]: ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

/**
 * Prints a 2D matrix in formatted grid output.
 */
void print_matrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

/**
 * Adds two matrices element by element: Result[i][j] = A[i][j] + B[i][j]
 */
void add_matrices(int A[MAX][MAX], int B[MAX][MAX], int Result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

/**
 * Transposes a matrix by swapping rows and columns: Result[j][i] = A[i][j]
 */
void transpose_matrix(int A[MAX][MAX], int Result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Result[j][i] = A[i][j];
        }
    }
}

/**
 * Multiplies Matrix A (r1 x c1) by Matrix B (c1 x c2) using three nested loops.
 */
void multiply_matrices(int A[MAX][MAX], int B[MAX][MAX], int Result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            Result[i][j] = 0; // Initialize cell accumulator
            for (int k = 0; k < c1; k++) {
                Result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
