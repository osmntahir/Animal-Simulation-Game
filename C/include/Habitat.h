#ifndef HABITAT_H
#define HABITAT_H

#include "Living.h"
#include "Insect.h"
#include "Flea.h"
#include "Plant.h"
#include "Mosquito.h"
#include <stdlib.h>

 struct HABITAT {
    Living ** habitatMatrix;
    int rows;
    int cols;
    int livingCount;
   void (*addLiving)(struct HABITAT *, Living , int, int);
    void (*killLiving)(struct HABITAT *, int, int);
    void (*resizeHabitat)(struct HABITAT *, int, int);
    void (*printHabitat)(struct HABITAT *);
    void (*printWinner)(struct HABITAT *);
    void (*deleteHabitat)(struct HABITAT *);
};typedef struct HABITAT *Habitat;

Habitat newHabitat(int, int);
void addLiving(const Habitat, Living, int, int);
void killLiving(const Habitat, int, int);
void resizeHabitat(const Habitat, int, int);
void printHabitat(const Habitat);
void printWinner(const Habitat);
void deleteHabitat(const Habitat);


#endif
