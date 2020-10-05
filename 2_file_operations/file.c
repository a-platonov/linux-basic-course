#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

void generate_file() {
    FILE *input_file;
    char buffer[100];
    input_file = fopen("a.txt", "w+");
    
    char c;
    for (int i = 0; i < INT_MAX; i++) {
        c = (char) (abs(rand()) % 127);
        buffer[i % sizeof(buffer)] = c;

        if (i % sizeof(buffer) == sizeof(buffer) - 1) {
            fwrite(buffer, 1, sizeof(buffer), input_file);
            printf("\rSize: %d MiB", i * 1 / 1024 / 1024);
        }
    }
    fclose(input_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalit usage of command. Provide 2 arguments (input_file, output_file)");
        exit(EXIT_FAILURE);
    }

    FILE *input_file;
    FILE *output_file;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror(argv[1]);
        exit(EXIT_FAILURE);
    }

    output_file = fopen(argv[2], "w+");
    if (output_file == NULL) {
        perror(argv[2]);
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    int read_count;
    
    fseek(input_file, 0, SEEK_END);
    long input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    long sc = 0;
    printf("Processing file\n\n");
    while ((read_count = fread(buffer, 1, sizeof(buffer), input_file)) != 0) {
        for (int i = 0; i < sizeof(buffer); i++) {
            buffer[i] = tolower(buffer[i]);
        }
        fwrite(buffer, 1, read_count - 1, output_file);
        printf("\rProcessing: %f %%", (float) (sc++ * sizeof(buffer) / input_size * 100));
    }
    
    fclose(input_file);
    fclose(output_file);

    return 0;
}
