#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];
sem_t empty_slots, full_slots;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    int item = *((int *)arg);
    sleep(1); // Produce item - Sleep to simulate production time

    // Wait for empty slot in buffer
    sem_wait(&empty_slots);

    // Acquire mutex lock before accessing buffer
    pthread_mutex_lock(&mutex);

    for (int i = 0; i < BUFFER_SIZE; i++)
    { // Add item to buffer
        if (buffer[i] == -1)
        {
            buffer[i] = item;
            break;
        }
    }

    // Release mutex lock
    pthread_mutex_unlock(&mutex);

    // Signal that buffer has a new item
    sem_post(&full_slots);

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    // Wait for buffer to have data
    sem_wait(&full_slots);

    // Acquire mutex lock before accessing buffer
    pthread_mutex_lock(&mutex);

    int item = -1;
    for (int i = 0; i < BUFFER_SIZE; i++)
    { // Remove item from buffer
        if (buffer[i] != -1)
        {
            item = buffer[i];
            buffer[i] = -1;
            break;
        }
    }

    // Release mutex lock
    pthread_mutex_unlock(&mutex);

    // Signal that an empty slot is available in buffer
    sem_post(&empty_slots);

    // Consume item
    printf("Consumed item: %d\n", item);

    pthread_exit(NULL);
}

int main()
{
    pthread_t producer_threads[NUM_PRODUCERS], consumer_threads[NUM_CONSUMERS];
    int producer_args[NUM_PRODUCERS] = {1, 2}; // Argument for producers

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty_slots, 0, BUFFER_SIZE); // Initialize empty_slots to BUFFER_SIZE
    sem_init(&full_slots, 0, 0);            // Initialize full_slots to 0

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = -1; // Initialize buffer elements to -1 (indicating empty slots)
    }

    for (int i = 0; i < NUM_PRODUCERS; i++)
    { // Create producer threads
        pthread_create(&producer_threads[i], NULL, producer, &producer_args[i]);
    }

    for (int i = 0; i < NUM_CONSUMERS; i++)
    { // Create consumer threads
        pthread_create(&consumer_threads[i], NULL, consumer, NULL);
    }

    // Join threads
    for (int i = 0; i < NUM_PRODUCERS; i++)
        pthread_join(producer_threads[i], NULL);

    for (int i = 0; i < NUM_CONSUMERS; i++)
        pthread_join(consumer_threads[i], NULL);

    // Destroy mutex and semaphores
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    return 0;
}
