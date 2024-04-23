#ifndef PLANT_H
#define PLANT_H

    #include "Living.h"

    struct PLANT {
        Living super;
        void (*deletePlant)(struct PLANT *);
    };
    typedef struct PLANT *Plant;

    Plant newPlant(int);
    char* plantAppreance(const Plant);
    void deletePlant(const Plant);


   
    #endif