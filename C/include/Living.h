
    #ifndef LIVING_H
    #define LIVING_H
    #include <stdio.h>
    #include <stdlib.h>
        
        struct LIVING {
            char*(*appreance)(); // kalitim verdigim fonksiyon
            void(*deleteLiving) (struct LIVING *);
            int rowLocation;
            int columnLocation;
            int value;
        };
        typedef struct LIVING *Living;
        Living newLiving(int);
        void deleteLiving(const Living);

    #endif 