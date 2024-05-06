#include <stdio.h>
#include <pthread.h>

void *runner(void *arg)
{
    int thread_id=*(int*)arg;
    printf("Hello from thread %d", thread_id);
    return 0;
}

int main()
{
    pthread_t t1;
    int thread_arg=101;
    pthread_create(&t1, NULL, runner, (void *)&thread_arg );
    pthread_join(t1, NULL);
}