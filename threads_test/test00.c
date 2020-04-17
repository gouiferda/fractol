#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    struct args *Allen = (struct args *)malloc(sizeof(struct args));
    char allen[] = "Allen";
    Allen->name = allen;
    Allen->age = 20;

    pthread_t tid;
    pthread_create(&tid, NULL, hello, (void *)Allen);
    pthread_join(tid, NULL);
    return 0;
}