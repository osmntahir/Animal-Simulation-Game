package Application;

import Habitat.*;

public class Simulation {
    private final Habitat habitat;

    public Simulation(Habitat habitat) {
        this.habitat = habitat;
    }

    public void simulate() {
        int rowCount = habitat.getRowCount();
        int columnCount = habitat.getColumnCount();
        Living currentLiving= null;
        Living nextLiving=null;
int row = 0;
int column = 0;
        while(habitat.getLivingCounter()>1)
        {
            if(row > rowCount || column > columnCount)
            {
                throw new IllegalArgumentException("Row and column must be less than the size of the habitat");
            }
            if(currentLiving == null)
            {
                currentLiving = habitat.getLiving(row,column);

            }
            nextLiving = habitat.getLiving(row,column+1);

            if (currentLiving != null && nextLiving != null)
            {
                WarLivings(currentLiving, nextLiving);
                if(habitat.getLiving(currentLiving.getRowLocation(),currentLiving.getColumnLocation()) == null)
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
                throw new IllegalArgumentException("Row and column must be less than the size of the habitat");
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
private void WarLivings(Living firstLiving, Living secondLiving) {
    System.out.println("-----------------------");

    System.out.println(firstLiving.Appearance() + " vs " + secondLiving.Appearance());
    // Plant  eats --> Flea
    if (firstLiving.Appearance().equals("B") && secondLiving.Appearance().equals("P")) {
        System.out.println("Plant eats Flea");
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    if(firstLiving.Appearance().equals("P") && secondLiving.Appearance().equals("B"))
    {
        System.out.println("Plant eats Flea");
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Insect  eats --> Plant
    if (firstLiving.Appearance().equals("C") && secondLiving.Appearance().equals("B")) {
        System.out.println("Insect eats Plant");
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    if(firstLiving.Appearance().equals("B") && secondLiving.Appearance().equals("C"))
    {
        System.out.println("Insect eats Plant");
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Mosquito  eats --> Flea
    if (firstLiving.Appearance().equals("S") && secondLiving.Appearance().equals("P")) {
        System.out.println("Mosquito eats Flea");
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    if(firstLiving.Appearance().equals("P") && secondLiving.Appearance().equals("S"))
    {
        System.out.println("Mosquito eats Flea");
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Plant  eats --> Mosquito
    if (firstLiving.Appearance().equals("B") && secondLiving.Appearance().equals("S")) {
        System.out.println("Plant eats Mosquito");
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    if(firstLiving.Appearance().equals("S") && secondLiving.Appearance().equals("B"))
    {
        System.out.println("Plant eats Mosquito");
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Mosquito  eats --> Insect
    if (firstLiving.Appearance().equals("S") && secondLiving.Appearance().equals("C")) {
        System.out.println("Mosquito eats Insect");
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    if(firstLiving.Appearance().equals("C") && secondLiving.Appearance().equals("S"))
    {
        System.out.println("Mosquito eats Insect");
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Insect  eats --> Flea
    if (firstLiving.Appearance().equals("C") && secondLiving.Appearance().equals("P")) {
        System.out.println("Insect eats Flea");
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    if(firstLiving.Appearance().equals("P") && secondLiving.Appearance().equals("C"))
    {
        System.out.println("Insect eats Flea");
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    if (firstLiving.Appearance().equals(secondLiving.Appearance())) {
        Living loser = compareSameTypeLivings(firstLiving, secondLiving);
        System.out.println("Same type livings are fighting. Loser is: " + loser.Appearance() + " at " + loser.getRowLocation() + "," + loser.getColumnLocation());
        habitat.killLiving(loser.getRowLocation(), loser.getColumnLocation());
    }
    habitat.printHabitat();
    System.out.println("-----------------------");
}
    private Living compareSameTypeLivings(Living living1, Living living2) {
       if(living1.getValue() > living2.getValue())
       {
           return living2;
       }
       else if(living1.getValue() < living2.getValue())
       {
           return living1;
       }
       else
       {
           if(living1.getRowLocation() > living2.getRowLocation())
           {
               return living1;
           }
           else if(living1.getRowLocation() < living2.getRowLocation())
           {
               return living2;
           }
           else
           {
               if(living1.getColumnLocation() > living2.getColumnLocation())
               {
                   return living1;
               }
               else
               {
                   return living2;
               }
           }
       }
    }
}
