package Application;

import Habitat.Habitat;

public class Main {
    public static void main(String[] args) {

        FileReader fileReader = new FileReader();
        fileReader.ReadFile();
        fileReader.getHabitat().printHabitat();
        Simulation simulation = new Simulation(fileReader.getHabitat());
        simulation.simulate();

        System.out.println();
       fileReader.getHabitat().printHabitat();

    }
}
