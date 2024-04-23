#ifndef FLEA_H
#define FLEA_H

#include "Insect.h"


struct FLEA {
    Insect super;
    void (*deleteFlea)(struct FLEA *);
};
typedef struct FLEA *Flea;

Flea newFlea(int);
char* fleaAppreance(const Flea);
void deleteFlea(const Flea);

#endif
