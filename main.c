// #include <sys/time.h>
// #include <stdio.h>

// int main() {
//   struct timeval current_time;
//   gettimeofday(&current_time, NULL);
//   printf("seconds : %ld\nmicro seconds : %ld\n",
//     current_time.tv_sec, current_time.tv_usec);

//   return 0;
// }


#include <pthread.h>
#include <stdio.h>

void *thread_function(void *arg)
{
    printf("This is a new thread.\n");
    return NULL;
}

int main()
{
    pthread_t my_thread;
    int result;

    result = pthread_create(&my_thread, NULL, thread_function, NULL);
    if (result != 0) {
        perror("pthread_create");
        return 1;
    }

    printf("This is the main thread.\n");
    pthread_join(my_thread, NULL);

    return 0;
}
