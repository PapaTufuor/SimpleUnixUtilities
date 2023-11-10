#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc <= 1) {
       exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        FILE *file = fopen(argv[i], "r");
        if (file == NULL) {
            
            fprintf(stderr,"wcat: cannot open file '%s' \n", argv[i]);
           
            exit(EXIT_FAILURE);
        }

        char line[MAX_LINE_LENGTH];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%s", line);
        }

        fclose(file);
    }

    exit(EXIT_FAILURE);
}
