#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define arrySize 10
#define numTh 2
int array[arrySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int results[numTh] = {0};
int total_product = 1;
void *calculate_product(void *thread_id)
{
    int tid = *((int *)thread_id);
    int start = tid * (arrySize / numTh);
    int end = (tid + 1) * (arrySize / numTh);
    results[tid] = 1;
    for (int i = start; i < end; i++)
    {
        results[tid] *= array[i];
    }
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[numTh];
    int thread_ids[numTh];
    for (int i = 0; i < numTh; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_product, (void *)&thread_ids[i]);
    }
    for (int i = 0; i < numTh; i++)
    {
        pthread_join(threads[i], NULL);
        total_product *= results[i];
    }

    printf("Total Product: %d\n", total_product);
    // return 0;
}