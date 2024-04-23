#include "Habitat.h"
#include <string.h>
struct  SIMULATION {
    Habitat habitat;
    void (*runSimulation)(struct SIMULATION *);
    void (*deleteSimulation)(struct SIMULATION *);
};
typedef struct SIMULATION *Simulation;

Simulation newSimulation(Habitat );
void runSimulation(const Simulation);
void deleteSimulation(const Simulation);