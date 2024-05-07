
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define GUESTS_PER_TEAM 5

// Mutex and condition variables for synchronization
pthread_mutex_t lock;
pthread_cond_t cond_team_e = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_team_g = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_team_f = PTHREAD_COND_INITIALIZER;

// Guest count for each area
int guests_in_auditorium = 0;
int guests_in_lab = 0;
int guests_in_common = 0;

// Function prototypes
void *team_e(void *arg);
void *team_g(void *arg);
void *team_f(void *arg);
void simulate_guest_arrival();

int main()
{
    pthread_t team_e_thread, team_g_thread, team_f_thread;

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    pthread_create(&team_e_thread, NULL, team_e, NULL);
    pthread_create(&team_g_thread, NULL, team_g, NULL);
    pthread_create(&team_f_thread, NULL, team_f, NULL);

    // Simulate guest arrival in each area
    simulate_guest_arrival();

    // Join threads
    pthread_join(team_e_thread, NULL);
    pthread_join(team_g_thread, NULL);
    pthread_join(team_f_thread, NULL);

    // Clean up
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond_team_e);
    pthread_cond_destroy(&cond_team_g);
    pthread_cond_destroy(&cond_team_f);

    return 0;
}

// Simulate random guest arrivals
void simulate_guest_arrival()
{
    for (int i = 0; i < GUESTS_PER_TEAM; i++)
    {
        sleep(1); // Simulate time between guest arrivals
        pthread_mutex_lock(&lock);
        int area = rand() % 3;
        if (area == 0)
        {
            guests_in_auditorium++;
            pthread_cond_signal(&cond_team_g);
        }
        else if (area == 1)
        {
            guests_in_lab++;
            pthread_cond_signal(&cond_team_f);
        }
        else
        {
            guests_in_common++;
            pthread_cond_signal(&cond_team_e);
        }
        pthread_mutex_unlock(&lock);
    }
}

// Define functions for each team thread
void *team_e(void *arg)
{
    pthread_mutex_lock(&lock);
    while (guests_in_common == 0)
    {
        pthread_cond_wait(&cond_team_e, &lock);
    }
    printf("Team E is serving refreshments to %d guests in the common area.\n", guests_in_common);
    guests_in_common = 0;
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *team_g(void *arg)
{
    pthread_mutex_lock(&lock);
    while (guests_in_auditorium == 0)
    {
        pthread_cond_wait(&cond_team_g, &lock);
    }
    printf("Team G is starting the coding challenge for %d guests in the auditor
ium.\n", guests_in_auditorium);
guests_in_auditorium = 0;
pthread_mutex_unlock(&lock);
return NULL;
}

void *team_f(void *arg)
{
    pthread_mutex_lock(&lock);
    while (guests_in_lab == 0)
    {
        pthread_cond_wait(&cond_team_f, &lock);
    }
    printf("Team F is showcasing exhibits to %d guests in the main IT lab.\n", guests_in_lab);
    guests_in_lab = 0;
    pthread_mutex_unlock(&lock);
    return NULL;
}

explanation:
1. *Mutex and Condition Variables:* We use these to synchronize access to shared resources (the number of guests in each area) and to control the flow of execution so that teams act only when guests arrive in their respective areas.

2. *Guest Arrival Simulation:* This function randomly simulates guests arriving in different areas, which triggers the appropriate team to act. Each area is simulated by incrementing a counter and signaling the respective team's condition variable.

3. *Team Functions:* Each function waits for its condition to be signaled before acting. Once signaled, they report the action taken (e.g., serving refreshments, starting a coding challenge) and reset the guest count for their area to zero, simulating that the guests have been served.

4. *Thread Creation and Management:* Threads are created for each team and joined back in the main function. This ensures that the program does not terminate prematurely, allowing each team to process all guest arrivals.

### Additional Considerations:
- *Error Checking:* This code omits error checking for brevity. In a real-world application, you would want to check the return values of functions like pthread_create, pthread_mutex_lock, and pthread_cond_wait for errors.
- *Randomness:* The use of rand() is simplistic. For more realistic simulations, consider seeding the random number generator with srand(time(NULL)) at the beginning of your program, or use more sophisticated random number generation methods.
- *Thread Safety:* Make sure that all access to shared resources is properly protected with mutexes to prevent race conditions.
- *Scalability:* This model can be scaled up with more teams and locations by adding more threads and condition variables, adjusting the logic as necessary to fit the expanded scope.

This comprehensive setup should provide a robust foundation for your exam question, demonstrating an understanding of thread synchronization with Pthreads in a practical scenario.
