#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to hold array and its size
typedef struct {
    int *arr;
    int size;
} Data;

// Thread result storage
int average_result;
int min_result;
int max_result;

// Average thread function
void* calculate_average(void* arg) {
    Data* data = (Data*)arg;
    int sum = 0;
    for (int i = 0; i < data->size; i++) {
        sum += data->arr[i];
    }
    average_result = sum / data->size;
    return NULL;
}

// Minimum thread function
void* calculate_min(void* arg) {
    Data* data = (Data*)arg;
    min_result = data->arr[0];
    for (int i = 1; i < data->size; i++) {
        if (data->arr[i] < min_result)
            min_result = data->arr[i];
    }
    return NULL;
}

// Maximum thread function
void* calculate_max(void* arg) {
    Data* data = (Data*)arg;
    max_result = data->arr[0];
    for (int i = 1; i < data->size; i++) {
        if (data->arr[i] > max_result)
            max_result = data->arr[i];
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <list of integers>\n", argv[0]);
        return 1;
    }

    int size = argc - 1;
    int* numbers = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    Data data = { numbers, size };

    pthread_t avg_thread, min_thread, max_thread;

    // Create threads
    pthread_create(&avg_thread, NULL, calculate_average, &data);
    pthread_create(&min_thread, NULL, calculate_min, &data);
    pthread_create(&max_thread, NULL, calculate_max, &data);

    // Wait for threads to finish
    pthread_join(avg_thread, NULL);
    pthread_join(min_thread, NULL);
    pthread_join(max_thread, NULL);

    // Print results
    printf("The average value is %d.\n", average_result);
    printf("The minimum value is %d.\n", min_result);
    printf("The maximum value is %d.\n", max_result);

    free(numbers);
    return 0;
}
