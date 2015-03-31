#include  <stdio.h>	/* printf */
#include  <sys/types.h>	/* pid_t */
#include <unistd.h>	/* get_pid */
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <sys/wait.h> 	/* wait */
#include <pthread.h>

void *counterFunction();
pthread_mutex_t mutex_stdout = PTHREAD_MUTEX_INITIALIZER;

long globalNumber;

int main(void) {
    globalNumber = 0;
    pthread_t counterThread[5];
    int iret[5];
    int i;


    for (i = 0; i < 5; i++) {
        iret[i] = pthread_create(&counterThread[i], NULL, counterFunction, NULL);
    }
    for (i = 0; i < 5; i++) {
        pthread_join(counterThread[i], NULL);

    }



    printf("The value of counter at the end is: %ld \n", globalNumber);
    return (0);
}

void *counterFunction() {

    long loopCounter = 0;
    //C
    /* Initialize pid and thread_id
     * to the correct values.
     */
    pid_t pid = getpid();
    int thread_id = pthread_self();

    printf("pid: %d, thread id: %d\n", pid, thread_id);
    while (loopCounter < 2000L) {

      pthread_mutex_lock(&mutex_stdout);
        long tmpNumber = globalNumber;
        tmpNumber++;
        globalNumber = tmpNumber;
      pthread_mutex_unlock(&mutex_stdout);
        loopCounter++;
        usleep(1000); //Creates a delay 
    }
}
