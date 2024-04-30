#include "Insect.h"
#include <stdlib.h>

Insect newInsect(int value)
{
    Insect this = (Insect)malloc(sizeof(struct INSECT));
    this->super = newLiving(value);
    this->deleteInsect = &deleteInsect;
    this->super->appreance = &insectAppreance;
    return this;
}

char* insectAppreance(const Insect insect)
{
    return "C";
}

void deleteInsect(const Insect insect)
{
    if(insect)
    {
        if(insect->super)
        {
            insect->super->deleteLiving(insect->super);
        }
        free(insect);
    }
}