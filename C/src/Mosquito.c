#include "Mosquito.h"
#include <stdlib.h>

Mosquito newMosquito(int value)
{
    Mosquito this = (Mosquito)malloc(sizeof(struct MOSQUITO));
    this->super = newInsect(value);
    this->super->super->appreance = &mosquitoAppreance;
    this->deleteMosquito = &deleteMosquito;
    return this;
}

char* mosquitoAppreance(const Mosquito mosquito)
{
    return "S";
}

void deleteMosquito(const Mosquito mosquito)
{
    deleteInsect(mosquito->super);
    free(mosquito);
}

