#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>

int sum(int *array, size_t length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = sum + array[i];
    }
    printf(" (%d) ", sum);
    return sum;
}

void print_array(int *array, size_t length) {
    printf("[");
    for (int i = 0; i < length - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]", array[length -1]);
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
        print_array(arrays[i], sizeof(arrays[i]) / sizeof(arrays[i][0]));
        printf("\n");
    }

    //Process arrays
    pid_t child_processes[process_count];

    int p[2];
    if (pipe(p) == -1) {
        exit(1);
    }

    for (int i = 0; i < process_count; i++) {
        if (!(child_processes[i] = fork())) {
            // Child process
            printf("Child(i: %d) ", i);
            int result = sum(arrays[i], sizeof(arrays[i]) / sizeof(arrays[i][0]));
            write(p[1], &result, sizeof(int));
            printf("| sum = %d\n", result);
            close(p[1]);
            exit(EXIT_SUCCESS);
        }
    }

    int total_sum = 0;
    for (int i = 0; i < sizeof(child_processes) / sizeof(child_processes[0]); i++) {
        wait(&child_processes[i]);
    }

    close(p[1]);
    int ps, nbytest;
    while ((nbytest = read(p[0], &ps, sizeof(int))) > 0) {
        printf("%d\n", ps);
        total_sum = total_sum + ps;
    }

    printf("Total sum: %d\n", total_sum);

    return 0;
}
