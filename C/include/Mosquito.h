#ifndef MOSQUITO_H
#define MOSQUITO_H

#include "Insect.h"

struct MOSQUITO {
    Insect super;
    void (*deleteMosquito)(struct MOSQUITO *);
};

typedef struct MOSQUITO *Mosquito;

Mosquito newMosquito(int);
char* mosquitoAppreance(const Mosquito);
void deleteMosquito(const Mosquito);

#endif