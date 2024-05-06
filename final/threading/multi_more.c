#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
#define NUM_THREADS 10
float Array_A[ARRAY_SIZE];
float Array_B[ARRAY_SIZE];
float Array_C[ARRAY_SIZE];
void calculate_serially()
{
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        Array_C[i] = Array_A[i] + Array_B[i];
    }
    printf("Serial Calculation completed\n");
}
void *calculate_concurrently(void *arg)
{
    int thread_index = *((int *)arg);
    int portion_size = ARRAY_SIZE / NUM_THREADS;
    int start = thread_index * portion_size;
    int end = (thread_index == NUM_THREADS - 1) ? ARRAY_SIZE : (start + portion_size);
    for (int i = start; i < end; i++)
    {
        Array_C[i] = Array_A[i] + Array_B[i];
    }
    return NULL;
}
int main()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        Array_A[i] = (float)rand() / RAND_MAX;
        Array_B[i] = (float)rand() / RAND_MAX;
    }

    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++)
    {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, calculate_concurrently, &thread_args[i]);
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("Parallel Calculation completed.\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%.2f + %.2f = %.2f \n", Array_A[i], Array_B[i], Array_C[i]);
    }
    // return 0;
}