#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

int numbers_count;
int *numbers;
float average;
int maximum;
int minimum;

pthread_mutex_t mutex_avg;
pthread_mutex_t mutex_max;
pthread_mutex_t mutex_min;

// Function to calculate average of numbers
void *calculate_average(void *arg)
{
    float sum = 0;
    for (int i = 0; i < numbers_count; i++)
    {
        sum += numbers[i];
    }
    average = sum / numbers_count;
    pthread_exit(NULL);
}

// Function to calculate maximum of numbers
void *calculate_maximum(void *arg)
{
    maximum = numbers[0];
    for (int i = 1; i < numbers_count; i++)
    {
        if (numbers[i] > maximum)
        {
            maximum = numbers[i];
        }
    }
    pthread_exit(NULL);
}

// Function to calculate minimum of numbers
void *calculate_minimum(void *arg)
{
    minimum = numbers[0];
    for (int i = 1; i < numbers_count; i++)
    {
        if (numbers[i] < minimum)
        {
            minimum = numbers[i];
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <num1> <num2> ... <numN>\n", argv[0]);
        return 1;
    }

    numbers_count = argc - 1;
    numbers = (int *)malloc(numbers_count * sizeof(int));

    for (int i = 1; i < argc; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    pthread_t threads[NUM_THREADS];

    // Create threads for calculating average, maximum, and minimum
    pthread_create(&threads[0], NULL, calculate_average, NULL);
    pthread_create(&threads[1], NULL, calculate_maximum, NULL);
    pthread_create(&threads[2], NULL, calculate_minimum, NULL);

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    // Print results
    printf("The average value is %.2f.\n", average);
    printf("The minimum value is %d.\n", minimum);
    printf("The maximum value is %d.\n", maximum);

    free(numbers);

    return 0;
}
