#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct{
    int* arr;
    int size;
}thread_data;
void* avg(void* arg){
    thread_data data= *((thread_data*)arg);
    int sum = 0;
    for(int i=0; i<data.size; i++)
    {
        sum+=data.arr[i];
    }
    printf("avg: %d\n", sum/data.size);
    return NULL;
}
 
void* min(void* arg){
    thread_data data= *((thread_data*)arg);
    int min = data.arr[0];
    for(int i=0; i<data.size; i++)
    {
        if(data.arr[i]<min) min = data.arr[i];
    }
    printf("min = %d\n", min);
    return NULL;
}

void* max(void* arg){
    thread_data data= *((thread_data*)arg);
    int max = data.arr[0];
    for(int i=0; i<data.size; i++)
    {
        if(data.arr[i]>max) max = data.arr[i];
    }
    printf("max = %d\n", max);
    return NULL;
}


int main(int argc, char* argv[])
{

    if(argc<2)
    {
        printf("pass arguments through the command line\n");
        return 1;
    }
    int size = argc-1;
    int arr[size];
    for(int i=0; i<size; i++)
    {
        arr[i] = atoi(argv[i+1]);
    }
    for(int i =0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    thread_data td = {arr, size};
    pthread_t t1;
    pthread_create(&t1, NULL, avg, (void*)&td);
    pthread_t t2;
    pthread_create(&t2, NULL, max, (void*)&td);
    pthread_t t3;
    pthread_create(&t3, NULL, min, (void*)&td);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}
