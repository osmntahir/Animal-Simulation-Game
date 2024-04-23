#include "Living.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


 Living newLiving(int value)
 {
        Living this = (Living)malloc(sizeof(struct LIVING));
        this->columnLocation = 0;
        this->rowLocation = 0;
        this->value = value;
        this->deleteLiving = &deleteLiving;
        return this;
 }

    void deleteLiving(const Living this)
    {
        free(this);
    }