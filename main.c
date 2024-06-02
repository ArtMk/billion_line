#include <stdio.h>

int main(void) {

    FILE *file;

    char vector[100];
    int i = 1;

    file = fopen("/Users/artako/CLionProjects/billion_line/measurements.txt", "r");

    if (file == NULL) {
        printf("There is nothing here you idiot\n");
        return 1;
    }

    while (1) {
        fgets(vector, 100, file);
        // printf("%s", vector);
        i++;
    }

    printf("%d\n", i-1);

    fclose(file);

    return 0;
}