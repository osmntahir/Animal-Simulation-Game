#include "FileReader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FileReader newFileReader() {
    FileReader fileReader = (FileReader)malloc(sizeof(struct FILE_READER));
    fileReader->row = 0;
    fileReader->column = 0;
    fileReader->habitat = newHabitat(4, 5);
    fileReader->readFile = &readFile;
    fileReader->deleteFileReader = &deleteFileReader;
    return fileReader;
}

void readFile(FileReader fileReader) {

    printf("Dosya okunuyor...\n");
    FILE *file = fopen("doc/data.txt", "r");
    if (file == NULL) {
        printf("Dosya açılamadı.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        int column = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            int value = atoi(token);
            Living living = createNewLiving(value);
            living->rowLocation = fileReader->row;
            living->columnLocation = column;
            fileReader->habitat->addLiving(fileReader->habitat, living, fileReader->row, column);
            column++;
            token = strtok(NULL, " ");
        }
        fileReader->row++;
    }
    fclose(file);
}

void deleteFileReader(FileReader fileReader) {
    fileReader->habitat->deleteHabitat(fileReader->habitat);
    free(fileReader);
}


Living createNewLiving(int value) {
    Living living = NULL;
    if (value >= 1 && value <= 9) {
        living = (Living)newPlant(value)->super;
    } else if (value >= 10 && value <= 20) {
        living = (Living)newInsect(value)->super;
    } else if (value >= 21 && value <= 50) {
        living = (Living)newMosquito(value)->super->super;
    } else if (value >= 51 && value <= 99) {
        living = (Living)newFlea(value)->super->super;
    } else {
        fprintf(stderr, "Geçersiz değer: %d\n", value);
        exit(EXIT_FAILURE);
    }
    return living;
}
