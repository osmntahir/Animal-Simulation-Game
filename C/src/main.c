#include <stdio.h>
#include "FileReader.h"
#include "Simulation.h"

int main() {
    FileReader fileReader = newFileReader();
    fileReader->readFile(fileReader);
    fileReader->habitat->printHabitat(fileReader->habitat);
    Simulation simulation = newSimulation(fileReader->habitat);
    simulation->runSimulation(simulation);
    fileReader->habitat->printWinner(fileReader->habitat);

    fileReader->deleteFileReader(fileReader);
    simulation->deleteSimulation(simulation);
    

    return 0;
}
