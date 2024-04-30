#include "Habitat.h"
#include <stdio.h>

// Create a new habitat with the specified dimensions
Habitat newHabitat(int rows, int cols) {
    Habitat habitat = (Habitat)malloc(sizeof(struct HABITAT));
    if (!habitat) {
        perror("Error allocating memory for habitat");
        exit(EXIT_FAILURE);
    }

    habitat->rows = rows;
    habitat->cols = cols;
    habitat->livingCount = 0;

    // Allocate memory for the habitat matrix
    habitat->habitatMatrix = (Living **)malloc(rows * sizeof(Living *));
    if (!habitat->habitatMatrix) {
        perror("Error allocating memory for habitat matrix");
        free(habitat);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; ++i) {
        habitat->habitatMatrix[i] = (Living *)malloc(cols * sizeof(Living));
        if (!habitat->habitatMatrix[i]) {
            perror("Error allocating memory for habitat row");
            // Free previously allocated memory
            for (int j = 0; j < i; ++j) {
                free(habitat->habitatMatrix[j]);
            }
            free(habitat->habitatMatrix);
            free(habitat);
            exit(EXIT_FAILURE);
        }
    }
    habitat->addLiving = &addLiving;
    habitat->killLiving = &killLiving;
    habitat->resizeHabitat = &resizeHabitat;
    habitat->printHabitat = &printHabitat;
    habitat->printWinner = &printWinner;
    habitat->deleteHabitat = &deleteHabitat;

    return habitat;
}

void addLiving(const Habitat habitat, Living living, int row, int column) {
    if (row < 0 || column < 0) {
        fprintf(stderr, "Row and column values must be greater than or equal to 0.\n");
        exit(EXIT_FAILURE);
    }

    if (column >= habitat->cols) {
        resizeHabitat(habitat, habitat->rows, column + 1);
    }

    if (row >= habitat->rows) {
        resizeHabitat(habitat, row + 1, habitat->cols);
    }

    habitat->livingCount++;
    habitat->habitatMatrix[row][column] = living;
}

void killLiving(const Habitat habitat, int row, int column) {
    if (row < 0 || column < 0) {
        fprintf(stderr, "Row and column values must be greater than or equal to 0.\n");
        exit(EXIT_FAILURE);
    }

    if (row >= habitat->rows || column >= habitat->cols) {
        fprintf(stderr, "Row and column values cannot exceed the habitat dimensions.\n");
        exit(EXIT_FAILURE);
    }

    if (habitat->habitatMatrix[row][column] == NULL) {
        fprintf(stderr, "There is no living creature at this location.\n");
        exit(EXIT_FAILURE);
    }
    
    habitat->habitatMatrix[row][column] = NULL;
    habitat->livingCount--;
}

void resizeHabitat(const Habitat habitat, int newRow, int newColumn) {
    Living **newHabitatMatrix = (Living**)malloc(newRow * sizeof(Living*));
    if (newHabitatMatrix == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < newRow; i++) {
        newHabitatMatrix[i] = (Living*)malloc(newColumn * sizeof(Living));
        if (newHabitatMatrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            newHabitatMatrix[i][j] = habitat->habitatMatrix[i][j];
        }
    }

    for (int i = 0; i < habitat->rows; i++) {
        free(habitat->habitatMatrix[i]);
    }
    free(habitat->habitatMatrix);

    habitat->habitatMatrix = newHabitatMatrix;
    habitat->rows = newRow;
    habitat->cols = newColumn;
}

void printHabitat(const Habitat habitat) {

    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            if (habitat->habitatMatrix[i][j] == NULL) {
                printf("X ");
            } else {
            printf("%s " , habitat->habitatMatrix[i][j]->appreance(habitat->habitatMatrix[i][j]));
            }
        }
        printf("\n");
    }
}

void printWinner(const Habitat habitat) {
    if (habitat->livingCount == 0) {
        printf("No winner.\n");
        return;
    }

    for (int i = 0; i < habitat->rows; i++) {
        for (int j = 0; j < habitat->cols; j++) {
            if (habitat->habitatMatrix[i][j] != NULL) {
                printf("%s (%d,%d) is the winner.\n ", habitat->habitatMatrix[i][j]->appreance(habitat->habitatMatrix[i][j])
                , habitat->habitatMatrix[i][j]->rowLocation, habitat->habitatMatrix[i][j]->columnLocation);
                return;
            }
        }
    }
}

void deleteHabitat(const Habitat habitat) {
    for (int i = 0; i < habitat->rows; i++) {
        free(habitat->habitatMatrix[i]);
    }
    free(habitat->habitatMatrix);
    free(habitat);
}
