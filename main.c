#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main(void) {

    FILE *file;

    char measurement[100];
    char *city;
    char *temperature;
    int i = 1;
    float temps = 0;
    float mean_temp;

    // open file
    file = fopen("/Users/artako/CLionProjects/billion_line/measurements.txt", "r");

    // make sure file is not empty
    if (file == NULL) {
        printf("There is nothing here you idiot\n");
        return 1;
    }

    // raed the file line by line
    while (fgets(measurement, 100, file) != NULL) {

        // city selection
        city = strtok(measurement, ";");
        if (strcmp(city, "Rome") == 0) {

            // temperature readings for selected city
            temperature = strtok(NULL, "NULL");
            // printf("%s\n", temperature);

            // summation of temperature readings
            temps += strtof(temperature, NULL);
            // printf("%f\n", temps);
        }

        // loop cancellation
        i++;
    }

    // number of lines in input file
    // printf("%d\n", i-1);

    // mean temperature for selected city
    mean_temp = temps/i;

    printf("Rome\n");
    printf("%f\n", mean_temp);

    // 1.078057

    // close file
    fclose(file);

    return 0;
}