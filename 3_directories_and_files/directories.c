#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Wrong count of parameters. Must be exactly one parameter.");
        exit(EXIT_FAILURE);        
    }

    struct stat *file_stat;
    stat(argv[1], file_stat);

    if (file_stat == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    double file_size = (double) file_stat->st_size;

    if (file_size < 1024.) {
        printf("%f Bytes", file_size);
        exit(EXIT_SUCCESS);
    }
    
    file_size = file_size / 1024.;
    if (file_size < 1024.) {
        printf("%f KiB", file_size);
        exit(EXIT_SUCCESS);
    }

    file_size = file_size / 1024.;
    if (file_size < 1024.) {
        printf("%f MiB", file_size);
        exit(EXIT_SUCCESS);
    } 

    file_size = file_size / 1024.;
    if (file_size < 1024.) {
        printf("%f GiB", file_size);
        exit(EXIT_SUCCESS);
    } 

    file_size = file_size / 1024.;
    if (file_size < 1024.) {
        printf("%f TiB", file_size);
        exit(EXIT_SUCCESS);
    }

    return 0;
}