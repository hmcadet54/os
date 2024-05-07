
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_CARS 5

// Semaphore to control the race start
sem_t startSignal;

// Function prototype for driver thread
void *driver_thread(void *arg);

int main()
{
    pthread_t drivers[NUM_CARS];
    int i;

    // Initialize the semaphore to 0 (red state)
    sem_init(&startSignal, 0, 0);

    // Create threads for each driver
    for (i = 0; i < NUM_CARS; i++)
    {
        pthread_create(&drivers[i], NULL, driver_thread, (void *)(long)i);
    }

    // Simulate race official preparing the race
    printf("Race official is getting ready...\n");
    sleep(2); // Delay to simulate readiness checks

    printf("All drivers are ready. The race will start in 3 seconds...\n");
    sleep(3); // Final countdown before the race starts

    // Signal all drivers to start by posting the semaphore multiple times
    for (i = 0; i < NUM_CARS; i++)
    {
        sem_post(&startSignal);
    }

    // Wait for all driver threads to finish
    for (i = 0; i < NUM_CARS; i++)
    {
        pthread_join(drivers[i], NULL);
    }

    // Cleanup semaphore
    sem_destroy(&startSignal);

    return 0;
}

// Driver thread function
void *driver_thread(void *arg)
{
    int driver_id = (int)(long)arg;

    // Each driver is ready and waiting for the start signal
    printf("Driver %d is ready at the starting grid.\n", driver_id);
    sem_wait(&startSignal); // Wait for the start signal semaphore to be released

    // Once semaphore is released, start racing
    printf("Driver %d starts racing!\n", driver_id);
    return NULL;
}

Explanation of the Code:
1) Semaphore Initialization: The semaphore startSignal is initialized to 0. This state represents the red light, indicating that the race cannot start yet.
2) Driver Threads: Each driver operates in a separate thread. They initially wait on the startSignal semaphore. This simulates the drivers being ready at the grid but waiting for the official start.
3) Race Start Simulation: After a simulated setup and countdown, the semaphore is posted for each driver. This action represents switching the semaphore to the green state, signaling all drivers to start simultaneously.
4) Concurrency Control: By using semaphores, the program ensures that no driver starts before the official signal and that all drivers start at precisely the same time.
