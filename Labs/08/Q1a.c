#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000  // 10 million elements

int main() {
    float *A, *B, *C;
    A = (float *)malloc(N * sizeof(float));
    B = (float *)malloc(N * sizeof(float));
    C = (float *)malloc(N * sizeof(float));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize arrays
    for (size_t i = 0; i < N; i++) {
        A[i] = 1.0f;
        B[i] = 2.0f;
    }

    clock_t start = clock();

    // Perform element-wise addition
    for (size_t i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Serial Execution Time: %f seconds\n", time_taken);

    free(A);
    free(B);
    free(C);
    return 0;
}
