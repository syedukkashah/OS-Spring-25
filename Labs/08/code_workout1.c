#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass data to the thread
typedef struct {
    int n;
    long long result;
} summation_data;

// Thread function to calculate summation
void* summation_thread(void* arg) {
    summation_data* data = (summation_data*)arg;
    long long sum = 0;
    
    for (int i = 0; i <= data->n; i++) {
        sum += i;
    }
    
    data->result = sum;
    return NULL;
}

int main() {
    int N;
    pthread_t thread;
    summation_data data;
    
    // Get user input
    printf("Enter a non-negative integer N: ");
    scanf("%d", &N);
    
    if (N < 0) {
        printf("Error: N must be non-negative.\n");
        return 1;
    }
    
    // Set up thread data
    data.n = N;
    data.result = 0;
    
    // Create thread to calculate summation
    if (pthread_create(&thread, NULL, summation_thread, &data) {
        printf("Error creating thread.\n");
        return 1;
    }
    
    // Wait for the thread to complete
    if (pthread_join(thread, NULL)) {
        printf("Error joining thread.\n");
        return 1;
    }
    
    // Print the result
    printf("The summation from 0 to %d is %lld\n", N, data.result);
    
    return 0;
}
