#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_ARRAY 3
#define ARRAY_SIZE 5
int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
int result[2 * ARRAY_SIZE];
pthread_mutex_t mutex;

void *concatinate(void *arg)
{
    int threads_id = *((int *)arg);
    int chunk_size = ARRAY_SIZE / NUM_ARRAY;
    int start = threads_id * chunk_size;
    int end = start + chunk_size;

    for (int i = start; i < end; i++)
    {
        printf("Thread %d: Start index = %d, End index = %d\n", threads_id, start, end);

        pthread_mutex_lock(&mutex);
        result[i] = array1[i];
        result[i + ARRAY_SIZE] = array2[i];
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    memset(result, 0, sizeof(result));
    pthread_t threads[NUM_ARRAY];
    int thread_arg[NUM_ARRAY];

    for (int i = 0; i < NUM_ARRAY; i++)
    {
        thread_arg[i] = i;
        pthread_create(&threads[i], NULL, concatinate, (void *)&thread_arg[i]);
    }
    for (int i = 0; i < NUM_ARRAY; i++)
    {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 2 * ARRAY_SIZE; i++)
    {
        printf("%d ", result[i]);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}