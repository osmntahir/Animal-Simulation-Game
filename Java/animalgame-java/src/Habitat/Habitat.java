package Habitat;

public class Habitat {
    private  Living[][] habitatMatris;
    private int LivingCounter;



    public Habitat(int row, int column) {
        habitatMatris = new Living[row][column];
  //      LivingCountInRow = column;
        LivingCounter = 0;

    }



    public  void addLiving(int row, int column, Living living) {
        if(row < 0 ||column<0 ){
           throw new IllegalArgumentException("Row and column must be greater than 0");
        }
       if(column>=habitatMatris[0].length )
       {
              resize(habitatMatris.length,column+1);
       }
       if (row>=habitatMatris.length) {
           resize(row + 1, habitatMatris[0].length);
       }
        LivingCounter++;
        habitatMatris[row][column] = living;

    }

    public int getLivingCounter() {
        return LivingCounter;
    }

    public void killLiving(int row, int column) {
        if(row < 0 ||column<0 ){
            throw new IllegalArgumentException("Row and column must be greater than 0");
        }
        if (row >= habitatMatris.length || column >= habitatMatris[0].length) {
            throw new IllegalArgumentException("Row and column must be less than the size of the habitat");
        }
        if(habitatMatris[row][column] == null){
            throw new IllegalArgumentException("There is no living in this location");
        }
        habitatMatris[row][column] = null;
        LivingCounter--;
    }

    public Living getLiving(int row, int column) {
        return habitatMatris[row][column];
    }

    public int getRowCount() {
        return habitatMatris.length;
    }

    public int getColumnCount() {
        return habitatMatris[0].length;
    }

    public void resize(int newRow, int newColumn) {

        Living[][] newHabitatMatris = new Living[newRow][newColumn];
        for (int i = 0; i < habitatMatris.length; i++) {
            for (int j = 0; j < habitatMatris[i].length; j++) {
                newHabitatMatris[i][j] = habitatMatris[i][j];
            }
        }
       // livingCounter= newColumn;
        habitatMatris = newHabitatMatris;
    //    LivingCountInRow = newColumn;
    }
    public void printHabitat() {
        for (int i = 0; i < habitatMatris.length; i++) {
            for (int j = 0; j < habitatMatris[i].length; j++) {
                if (habitatMatris[i][j] != null) {
                    System.out.print(habitatMatris[i][j].Appearance() + " ");
                } else {
                    System.out.print("X "); // Boş hücre için placeholder yazdır
                }
            }
            System.out.println();
        }
    }



/*
    public int getLivingCounter() {
        return livingCounter;
    }

    public void setLivingCounter(int i) {
        livingCounter = i;
    }
    */
}
