package Application;

import Habitat.*;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FileREADER {
private int row;
private int column;

private Habitat habitat;

    public FileREADER() {
        row = 0;
        column = 0;
        habitat = new Habitat(4,5);

    }

    public void ReadFile() {
        try {
            // Dosyayı okumak için BufferedReader kullan
            File file = new File("src\\Habitat\\data\\data.txt");
            BufferedReader reader = new BufferedReader(new FileReader(file));

            // Dosya sonuna kadar döngüyü başlat
            String line;
            while ((line = reader.readLine()) != null) {
                // Her satırı kontrol et ve uygun canlıları oluştur
                Matcher matcher = Pattern.compile("\\d+").matcher(line);
                int column = 0;
                while (matcher.find()) {
                    int value = Integer.parseInt(matcher.group());
                    Living living = createNewLiving(value);
                    living.setRowLocation(row);
                    living.setColumnLocation(column);
                    habitat.addLiving(row, column, living);
                    column++;
                }
                row++;
            }
            // Dosyayı kapat
            reader.close();
        } catch (IOException e) {
            System.out.println("Dosya okunurken bir hata oluştu: " + e.getMessage());
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

    public Habitat getHabitat() {
        return habitat;
    }
}