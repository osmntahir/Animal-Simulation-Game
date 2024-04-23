#include "Simulation.h"

Simulation newSimulation(Habitat habitat)
{
    Simulation this = (Simulation)malloc(sizeof(struct SIMULATION));
    this->habitat = habitat;
    this->runSimulation = &runSimulation;
    this->deleteSimulation = &deleteSimulation;
    return this;
}
void CompareSameTypeLivings(const Simulation this,Living currentLiving, Living nextLiving)
{
    if(currentLiving->value > nextLiving->value)
    {
        printf("The current living is stronger than the next living");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    else if(currentLiving->value < nextLiving->value)
    {
        printf("The next living is stronger than the current living");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    else
    {
        if(currentLiving->rowLocation > nextLiving->rowLocation)
        {
            this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
        }
        else if(currentLiving->rowLocation < nextLiving->rowLocation)
        {
            this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
        }
        else
        {
            if(currentLiving->columnLocation > nextLiving->columnLocation)
            {
                this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
            }
            else if(currentLiving->columnLocation < nextLiving->columnLocation)
            {
                this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
            }
        }
    
    }
}
    /***
 *
 * Bitki → Pire
 * Böcek → Bitki
 * Sinek → Pire
 * Bitki → Sinek
 * Sinek → Böcek
 * Böcek →Pire
     *
     * Bitki >> B
     * Sinek >> S
     * Pire  >> P
     * Bocek >> C
     *
     * */
void WarLivings(const Simulation this, Living currentLiving, Living nextLiving) {
    printf("--------------------------------- \n ");
    // Plant eats --> Flea
    if (strcmp(currentLiving->appreance(), "B") == 0 && strcmp(nextLiving->appreance(), "P") == 0) {
        printf("Plant eats Flea");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    if (strcmp(currentLiving->appreance(), "P") == 0 && strcmp(nextLiving->appreance(), "B") == 0) {
        printf("Plant eats Flea");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    // Insect eats --> Plant
    if (strcmp(currentLiving->appreance(), "C") == 0 && strcmp(nextLiving->appreance(), "B") == 0) {
        printf("Insect eats Plant");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    if (strcmp(currentLiving->appreance(), "B") == 0 && strcmp(nextLiving->appreance(), "C") == 0) {
        printf("Insect eats Plant");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    // Mosquito eats --> Flea
    if (strcmp(currentLiving->appreance(), "S") == 0 && strcmp(nextLiving->appreance(), "P") == 0) {
        printf("Mosquito eats Flea");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    if (strcmp(currentLiving->appreance(), "P") == 0 && strcmp(nextLiving->appreance(), "S") == 0) {
        printf("Mosquito eats Flea");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    // Plant eats --> Mosquito
    if (strcmp(currentLiving->appreance(), "B") == 0 && strcmp(nextLiving->appreance(), "S") == 0) {
        printf("Plant eats Mosquito");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    if (strcmp(currentLiving->appreance(), "S") == 0 && strcmp(nextLiving->appreance(), "B") == 0) {
        printf("Plant eats Mosquito");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    // Mosquito eats --> Insect
    if (strcmp(currentLiving->appreance(), "S") == 0 && strcmp(nextLiving->appreance(), "C") == 0) {
        printf("Mosquito eats Insect");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    if (strcmp(currentLiving->appreance(), "C") == 0 && strcmp(nextLiving->appreance(), "S") == 0) {
        printf("Mosquito eats Insect");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    // Insect eats --> Flea
    if (strcmp(currentLiving->appreance(), "C") == 0 && strcmp(nextLiving->appreance(), "P") == 0) {
        printf("Insect eats Flea");
        this->habitat->killLiving(this->habitat, nextLiving->rowLocation, nextLiving->columnLocation);
    }
    if (strcmp(currentLiving->appreance(), "P") == 0 && strcmp(nextLiving->appreance(), "C") == 0) {
        printf("Insect eats Flea");
        this->habitat->killLiving(this->habitat, currentLiving->rowLocation, currentLiving->columnLocation);
    }
    // Current living and next living are the same type
    if (strcmp(currentLiving->appreance(), nextLiving->appreance()) == 0) {
        CompareSameTypeLivings(this, currentLiving, nextLiving);
    }
    printf("\n");
   this->habitat->printHabitat(this->habitat);
}
void runSimulation(const Simulation this)
{
    int rowCount = this->habitat->rows;
    int columnCount = this->habitat->cols;
    Living currentLiving= NULL;
    Living nextLiving=NULL;
    int row = 0;
    int column = 0;
        while(this->habitat->livingCount > 1)
        {
            if(row > rowCount || column > columnCount)
            {
                printf("Row and column must be less than the size of the habitat");
            }
            if(currentLiving == NULL)
            {
                currentLiving = this->habitat->habitatMatrix[row][column];

            }
            nextLiving = this->habitat->habitatMatrix[row][column+1];

            if (currentLiving != NULL && nextLiving != NULL)
            {
                WarLivings(this,currentLiving, nextLiving);

                if(this->habitat->habitatMatrix[currentLiving->rowLocation][currentLiving->columnLocation] == NULL)
                {
                    currentLiving = nextLiving;
                }
                column++;
            }
            if(column >=columnCount-1)
            {
                column = -1;
                row++;
            }
            if(row > rowCount)
            {
               printf("Row and column must be less than the size of the habitat");
            }
        }
}
void deleteSimulation(const Simulation this)
{
    free(this);
}
