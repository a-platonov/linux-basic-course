#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>


int sum(int *elements) {
    int sum = 0;
    for (int i = 0; i < sizeof(elements); i++) {
        sum = sum + elements[i];
        printf("%d ", elements[i]);
    }

    return sum;
}


int main(int argc, char* argv[]) {
    int process_count = 2;
    int elements_count = 5;
    int arrays[process_count][elements_count];

    // Fill array
    int rand_max = 10;
    int rand_min = 0;
    unsigned t = time(NULL);
    srand(t);
    for (int i = 0; i < process_count; i++){
        for (int j = 0; j < elements_count; j++) {
            arrays[i][j] = rand() % ((rand_max - rand_min) + 1) + rand_min;
        }
    }

    // Print generated data
    for (int i = 0; i < process_count; i++) {
        for (int j = 0; j < elements_count; j++) {
            printf("%d ", arrays[i][j]);
        }
        printf("\n");
    }

    //Process arrays
    pid_t child_processes[process_count];
    int results[process_count];

    for (int i = 0; i < process_count; i++) {
        if (!(child_processes[i] = fork())) {
            // Child process
            printf("Child(i: %d) ", i);
            int s = sum(arrays[i]);
            printf("| sum = %d\n", s);
            exit(EXIT_SUCCESS);
        }
    }

    wait(&child_processes[1]);
    wait(&child_processes[0]);

    return 0;
}

