#include "Plant.h"

#include <stdlib.h>

Plant newPlant(int value) {
    Plant this = (Plant)malloc(sizeof(struct PLANT));
    if (this == NULL) {
        exit(EXIT_FAILURE);
    }

    this->super = newLiving(value);
    this->super->appreance = &plantAppreance;
    this->deletePlant = &deletePlant;

    return this;
}


char* plantAppreance(const Plant this) {
    return "B";
}

void deletePlant(const Plant this) {
    this->super->deleteLiving(this->super);
    free(this);
}