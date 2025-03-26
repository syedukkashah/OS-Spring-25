#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define N 10000000  // 10 million elements
#define NUM_THREADS 10  // 10 worker threads

float *A, *B, *C;

typedef struct {
    size_t start;
    size_t end;
} ThreadData;

void *add_arrays(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (size_t i = data->start; i < data->end; i++) {
        C[i] = A[i] + B[i];
    }
    pthread_exit(NULL);
}

int main() {
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

    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    size_t chunk_size = N / NUM_THREADS;

    clock_t start = clock();

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].start = i * chunk_size;
        thread_data[i].end = (i == NUM_THREADS - 1) ? N : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, add_arrays, &thread_data[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Parallel Execution Time: %f seconds\n", time_taken);

    free(A);
    free(B);
    free(C);
    return 0;
}
