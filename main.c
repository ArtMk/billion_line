#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    FILE *file;

    char measurement[100];
    char *city;
    char *temperature;
    int i = 0;
    int j = 0;
    char selected[100] = "Hamburg";
    float mean;

    // open file
    file = fopen("/Users/artako/CLionProjects/billion_line/measurements.txt", "r");

    // make sure file is not empty
    if (file == NULL) {
        printf("There is nothing here you idiot\n");
        return 1;
    }

    // raed the file line by line
    while (fgets(measurement, 100, file) != NULL) {
    // while (i <= 10000) {

        // fgets(measurement, 100, file);

        // city selection
        city = strtok(measurement, ";");
        if (strcmp(city, selected) == 0) {

            // temperature readings for selected city
            temperature = strtok(NULL, "NULL");
            // printf("%s\n", temperature);

            // summation of temperature readings
            mean += strtof(temperature, NULL);
            // printf("%f\n", temps);

            // count city occurrences
            j++;
        }

        // count number of rows
        i++;
    }

    printf("Total number of rows: %d\n", i);
    printf("Number of city occurrences: %d\n", j);
    printf("Selected city: %s\n", selected);

    // mean temperature of selected city
    mean = mean / j;
    printf("Mean temperature: %f\n", mean);

    // close file
    fclose(file);

    return 0;
}