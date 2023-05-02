// #include <sys/time.h>
// #include <stdio.h>

// int main() {
//   struct timeval current_time;
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\nmicro seconds : %ld\n",
//     current_time.tv_sec, current_time.tv_usec);

//   return 0;
// }


// #include <pthread.h>
// #include <stdio.h>

// void *thread_function(void *arg)
// {
//     printf("This is a new thread.\n");
//     return NULL;
// }

// int main()
// {
//     pthread_t my_thread;
//     int result;

//     result = pthread_create(&my_thread, NULL, thread_function, NULL);
//     if (result != 0) {
//         perror("pthread_create");
//         return 1;
//     }

//     printf("This is the main thread.\n");
//     pthread_join(my_thread, NULL);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>
    
// void *worker(void *data)
// {
//     char *name = (char*)data;
    
//     for (int i = 0; i < 120; i++)
//     {
//     usleep(50000);
//     printf("Hi from thread name = %s\n", name);
//     }
    
//     printf("Thread %s done!\n", name);
//     return NULL;
// }
    
// int main(void)
// {
//     pthread_t th1, th2;
//     pthread_create(&th1, NULL, worker, "X");
//     pthread_create(&th2, NULL, worker, "Y");
//     sleep(5);
//     printf("Exiting from main program\n");
//     return 0;
// }


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

int shared_variable = 0;
pthread_mutex_t mutex;

void *thread_function(void *arg) {
    int thread_id = *(int*)arg;
    printf("Thread %d starting...\n", thread_id);
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);
        shared_variable++;
        printf("Thread %d: shared_variable = %d\n", thread_id, shared_variable);
        pthread_mutex_unlock(&mutex);
    }
    printf("Thread %d exiting...\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int result = pthread_mutex_init(&mutex, NULL);
    if (result != 0) {
        fprintf(stderr, "Failed to initialize mutex\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result != 0) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        result = pthread_join(threads[i], NULL);
        if (result != 0) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
    pthread_mutex_destroy(&mutex);
    printf("All threads completed. shared_variable = %d\n", shared_variable);
    return 0;
}
