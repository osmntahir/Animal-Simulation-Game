#ifndef INSECT_H
#define INSECT_H

#include "Living.h"
#include <stdlib.h>

struct INSECT {
    Living super;
    void (*deleteInsect)(struct INSECT *);
};
typedef struct INSECT *Insect;

Insect newInsect(int);
char* insectAppreance(const Insect);
void deleteInsect(const Insect);

#endif




