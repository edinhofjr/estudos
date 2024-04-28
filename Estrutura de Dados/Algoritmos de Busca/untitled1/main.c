#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t flag = PTHREAD_MUTEX_INITIALIZER;
int contador = 0;

void *threadPrint(void *vargp) {
    long tid = (long)vargp;

    for(int i = 0; i < 100; i++) {
        pthread_mutex_lock(&flag);

        int meu_contador = contador;
        int novo_contador = meu_contador + 1;
        contador = novo_contador;

        printf("thread #%ld incrementou %d\n", tid, contador);
        //sleep(1);

        pthread_mutex_unlock(&flag);
    }
    return NULL;
}

int main() {
    int numThreads = 5;
    pthread_t threads[numThreads];

    for (long i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, threadPrint, (void *)i);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Valor final: %d\n", contador);

    pthread_mutex_destroy(&flag);
    return EXIT_SUCCESS;
}
