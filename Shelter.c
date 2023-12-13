#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ANI 200
#define TRAITS 100
/* Code by Daniel Redington:
This program searches a file of animals and places all animals sorted by species then age into a text file 
*/

struct Animal {
    char name[TRAITS];
    char species[TRAITS];
    char gender[TRAITS];
    int age;
    double weight;
};

// This is the comparison function for qsort
int animcomp(const void *a, const void *b) {
    const struct Animal *animalA = (const struct Animal *)a;
    const struct Animal *animalB = (const struct Animal *)b;

    int compare = strcmp(animalA->species, animalB->species);
    if (compare != 0) {
        return compare; 
    } else {
        return animalA->age - animalB->age; 
    }
}

int main() {
    struct Animal animals[MAX_ANI];
    int n = 0;
    char spec_want[TRAITS];
    char gen_want[TRAITS];

    FILE *inputFile = fopen("animals.txt", "r");
    FILE *outputFile = fopen("results.txt", "w");
    // This section reads in the data from the file
    while (fscanf(inputFile, "%s %s %s %d %lf", animals[n].name, animals[n].species, animals[n].gender, &animals[n].age, &animals[n].weight) == 5) {
        n++;
    }

    printf("Enter species: ");
    scanf("%s", spec_want);
    printf("Enter gender: ");
    scanf("%s", gen_want);

    qsort(animals, n, sizeof(struct Animal), animcomp);
    // This section compares to see if an animal matches the specifications and then adds it to the new file
    for (int i = 0; i < n; i++) {
        if (strcmp(animals[i].species, spec_want) == 0 && strcmp(animals[i].gender, gen_want) == 0) {
            fprintf(outputFile, "%s %d %s %.2lf %s\n", animals[i].species, animals[i].age, animals[i].name, animals[i].weight, animals[i].gender);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Output file name: results.txt\n");

    return 0;
}
