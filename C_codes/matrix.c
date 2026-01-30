#include <stdio.h>
#include <stdlib.h>

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns of first matrix: ");
    if (scanf("%d %d", &r1, &c1) != 2 || r1 <= 0 || c1 <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }
    printf("Enter rows and columns of second matrix: ");
    if (scanf("%d %d", &r2, &c2) != 2 || r2 <= 0 || c2 <= 0) {
        printf("Invalid dimensions.\n");
        return 1;
    }

    // allocate matrices
    int **A = malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; ++i) A[i] = malloc(c1 * sizeof(int));
    int **B = malloc(r2 * sizeof(int*));
    for (int i = 0; i < r2; ++i) B[i] = malloc(c2 * sizeof(int));

    printf("Enter elements of first matrix (%dx%d):\n", r1, c1);
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix (%dx%d):\n", r2, c2);
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            scanf("%d", &B[i][j]);

    // Addition / Subtraction
    if (r1 == r2 && c1 == c2) {
        int **S = malloc(r1 * sizeof(int*));
        int **D = malloc(r1 * sizeof(int*));
        for (int i = 0; i < r1; ++i) {
            S[i] = malloc(c1 * sizeof(int));
            D[i] = malloc(c1 * sizeof(int));
        }
        for (int i = 0; i < r1; ++i)
            for (int j = 0; j < c1; ++j) {
                S[i][j] = A[i][j] + B[i][j];
                D[i][j] = A[i][j] - B[i][j];
            }

        printf("Sum of matrices:\n");
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) printf("%d ", S[i][j]);
            printf("\n");
        }
        printf("Difference of matrices:\n");
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c1; ++j) printf("%d ", D[i][j]);
            printf("\n");
        }

        for (int i = 0; i < r1; ++i) { free(S[i]); free(D[i]); }
        free(S); free(D);
    } else {
        printf("Addition/Subtraction not possible: dimensions do not match.\n");
    }

    // Multiplication
    if (c1 == r2) {
        int **P = malloc(r1 * sizeof(int*));
        for (int i = 0; i < r1; ++i) {
            P[i] = malloc(c2 * sizeof(int));
            for (int j = 0; j < c2; ++j) {
                P[i][j] = 0;
                for (int k = 0; k < c1; ++k) P[i][j] += A[i][k] * B[k][j];
            }
        }
        printf("Product of matrices (%dx%d):\n", r1, c2);
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) printf("%d ", P[i][j]);
            printf("\n");
        }
        for (int i = 0; i < r1; ++i) free(P[i]);
        free(P);
    } else {
        printf("Multiplication not possible: columns of first != rows of second.\n");
    }

    // Transposes
    int **T1 = malloc(c1 * sizeof(int*));
    for (int i = 0; i < c1; ++i) { T1[i] = malloc(r1 * sizeof(int)); }
    for (int i = 0; i < r1; ++i) for (int j = 0; j < c1; ++j) T1[j][i] = A[i][j];
    printf("Transpose of first matrix (%dx%d):\n", c1, r1);
    for (int i = 0; i < c1; ++i) {
        for (int j = 0; j < r1; ++j) printf("%d ", T1[i][j]);
        printf("\n");
    }

    int **T2 = malloc(c2 * sizeof(int*));
    for (int i = 0; i < c2; ++i) { T2[i] = malloc(r2 * sizeof(int)); }
    for (int i = 0; i < r2; ++i) for (int j = 0; j < c2; ++j) T2[j][i] = B[i][j];
    printf("Transpose of second matrix (%dx%d):\n", c2, r2);
    for (int i = 0; i < c2; ++i) {
        for (int j = 0; j < r2; ++j) printf("%d ", T2[i][j]);
        printf("\n");
    }

    // Traces
    if (r1 == c1) {
        int trace1 = 0;
        for (int i = 0; i < r1; ++i) trace1 += A[i][i];
        printf("Trace of first matrix: %d\n", trace1);
    } else {
        printf("Trace of first matrix: N/A (not square)\n");
    }
    if (r2 == c2) {
        int trace2 = 0;
        for (int i = 0; i < r2; ++i) trace2 += B[i][i];
        printf("Trace of second matrix: %d\n", trace2);
    } else {
        printf("Trace of second matrix: N/A (not square)\n");
    }

    // free everything
    for (int i = 0; i < r1; ++i) free(A[i]);
    for (int i = 0; i < r2; ++i) free(B[i]);
    for (int i = 0; i < c1; ++i) free(T1[i]);
    for (int i = 0; i < c2; ++i) free(T2[i]);
    free(A); free(B); free(T1); free(T2);

    return 0;
}