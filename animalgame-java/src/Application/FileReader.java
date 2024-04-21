package Application;

import Habitat.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class FileReader {
private int row;
private int column;
private Habitat habitat;

    public FileReader() {
        row = 0;
        column = 0;
        habitat = new Habitat(4,5);

    }

    public void ReadFile() {
        try {
            // Dosyayı okumak için Scanner oluştur
            File file = new File("animalgame-java/src/Habitat/data/data.txt");
            Scanner scanner = new Scanner(file);

            // Dosya sonuna kadar döngüyü başlat
            while (scanner.hasNextLine()) {
                // Satırı oku
                String line = scanner.nextLine();

                // Satırdaki sayıları boşluklardan ayırarak diziye ekle
                String[] numbers = line.split(" ");

                // Her sayıyı kontrol et ve uygun canlıları oluştur
                for (String number : numbers) {
                    int value = Integer.parseInt(number);
                    Living living = createNewLiving(value);
                 //   System.out.print(living.Appearance () + " ");
                    living.setRowLocation(row);
                    living.setColumnLocation(column);
                    habitat.addLiving(row,column,living);

                       column++;
                }
     //           System.out.println("row: " + row + " column: " + column);
                column =0;
                row++;
       //         System.out.println(); // Her satırın sonunda bir alt satıra geç

            }

            // Dosyayı kapat
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println("Dosya bulunamadı: " + e.getMessage());
        }
    }


    public static Living createNewLiving(int value) {
        if (value >= 1 && value <= 9) {
            return new Plant(value);
        } else if (value >= 10 && value <= 20) {
            return new Insect(value);
        } else if (value >= 21 && value <= 50) {
            return new Mosquito(value);
        } else if (value >= 51 && value <= 99) {
            return new Flea(value);
        } else {
            throw new IllegalArgumentException("Geçersiz değer: " + value);
        }
    }

    public int getColumn() {
        return column;
    }

    public int getRow() {
        return row;
    }

    public Habitat getHabitat() {
        return habitat;
    }
}