#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

#define N 5
typedef struct thread
{
    pthread_t thread_id;
    int thread_num;
    // int       thread_sum;
} ThreadData;
void *thread_start(void *thread)
{
    ThreadData *my_data = (ThreadData *)thread;
    //there is no guarantee that prints will be in order
    //  we will use its initial thread->num ,cause it differs for each thread
    //plus you will see how threads will behave
    int order = my_data->thread_num;
    printf("%i) before num T: %i\n", order, my_data->thread_num);
    my_data->thread_num = 4;
    printf("%i) after assignment num T: %i\n", order, my_data->thread_num);

    return NULL;
}

int main(int argc, char *argv[])
{
    int i;
    ThreadData thread[N];
    for (i = 0; i < N; i++)
    {
        thread[i].thread_num = i;
        pthread_create(&(thread[i].thread_id), NULL, thread_start, (void *)(thread + i));
    }
    //wait for all threads
    for (i = 0; i < N; i++)
        pthread_join(thread[i].thread_id, NULL);
    //print results of each thread
    for (i = 0; i < N; i++)
        printf(" %i)thread: number %i\n", i, thread[i].thread_num);
    return 0;
}