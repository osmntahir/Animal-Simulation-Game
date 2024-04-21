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
                currentLiving = habitat.getLiving(row%rowCount,column%columnCount);
            }

            nextLiving = habitat.getLiving(row%rowCount,(column%columnCount-1)+1);
            if (currentLiving != null && nextLiving != null)
            {
                WarLivings(currentLiving, nextLiving);
                column++;
            }
            if(column%columnCount == 0)
            {
                row++;
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
 * Böcek →Pire*/
private void WarLivings(Living firstLiving, Living secondLiving) {

    // Plant  eats --> Flea
    if (firstLiving instanceof Plant && secondLiving instanceof Flea) {
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    else if(firstLiving instanceof Flea && secondLiving instanceof Plant) {
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Insect eats --> Plant
    else if (firstLiving instanceof Insect && secondLiving instanceof Plant) {
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    else if(firstLiving instanceof Plant && secondLiving instanceof Insect) {
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Mosquito eats --> Flea
    else if (firstLiving instanceof Mosquito && secondLiving instanceof Flea) {
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    else if(firstLiving instanceof Flea && secondLiving instanceof Mosquito) {
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Plant eats --> Mosquito
    else if (firstLiving instanceof Plant && secondLiving instanceof Mosquito) {
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    else if(firstLiving instanceof Mosquito && secondLiving instanceof Plant) {
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Mosquito eats --> Insect
    else if (firstLiving instanceof Mosquito && secondLiving instanceof Insect) {
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    else if(firstLiving instanceof Insect && secondLiving instanceof Mosquito) {
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // Insect eats --> Flea
    else if (firstLiving instanceof Insect && secondLiving instanceof Flea) {
        habitat.killLiving(secondLiving.getRowLocation(), secondLiving.getColumnLocation());
    }
    else if(firstLiving instanceof Flea && secondLiving instanceof Insect) {
        habitat.killLiving(firstLiving.getRowLocation(), firstLiving.getColumnLocation());
    }
    // if livings are same type, compare their locations and values
    else if (firstLiving.getClass().equals(secondLiving.getClass())) {
        Living looser = compareSameTypeLivings(firstLiving, secondLiving);
        habitat.killLiving(looser.getRowLocation(), looser.getColumnLocation());
    }


    System.out.println();
    habitat.printHabitat();
}


    private Living compareSameTypeLivings(Living living1, Living living2) {
        // Canlıların konumlarını ve değerlerini karşılaştırarak kazananı belirle
        int valueComparison = Integer.compare(living1.getValue(), living2.getValue());
        if (valueComparison != 0) {
            return valueComparison < 0 ? living1 : living2; // Değerler farklı ise daha küçük olanı kaybeden olarak döndür
        } else {
            // Değerler aynı ise konumlarına göre kazananı belirle
            int rowComparison = Integer.compare(living1.getRowLocation(), living2.getRowLocation());
            if (rowComparison != 0) {
                return rowComparison < 0 ? living1 : living2; // Satır konumları farklı ise daha küçük olanı kaybeden olarak döndür
            } else {
                // Satır konumları da aynı ise sütun konumlarına göre kazananı belirle
                return Integer.compare(living1.getColumnLocation(), living2.getColumnLocation()) < 0 ? living1 : living2;
            }
        }
    }
}
