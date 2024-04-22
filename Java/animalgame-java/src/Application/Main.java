package Application;

public class Main {
    public static void main(String[] args) {

        FileREADER fileReader = new FileREADER();
        fileReader.ReadFile();
        fileReader.getHabitat().printHabitat();
        Simulation simulation = new Simulation(fileReader.getHabitat());
        simulation.simulate();

        System.out.println();

       fileReader.getHabitat().printWinner();

    }
}
