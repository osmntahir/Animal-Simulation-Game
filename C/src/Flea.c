#include "Flea.h"

Flea newFlea(int value) {
    Flea flea = (Flea)malloc(sizeof(struct FLEA));
    flea->super = newInsect(value);
    flea->super->super->appreance = &fleaAppreance;
    flea->deleteFlea = &deleteFlea;
    return flea;
}

char* fleaAppreance(const Flea flea) {
    return "P";
}

void deleteFlea(const Flea this) {
    if(this) {
      if(this->super)
      {
        this->super->deleteInsect(this->super);
      }
        free(this);
    }
}