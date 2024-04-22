package Habitat;

public abstract class Living {
    protected int value;
    private int rowLocation;
    private int columnLocation;

    public abstract String Appearance();

    public Living(int value){

        this.value = value;
        rowLocation = -1;
        columnLocation = -1;
    }
    public int getValue(){
        return value;
    }

    public int getRowLocation() {
        return rowLocation;
    }

    public int getColumnLocation() {
        return columnLocation;
    }
    public void setRowLocation(int rowLocation) {
        this.rowLocation = rowLocation;
    }
    public void setColumnLocation(int columnLocation) {
        this.columnLocation = columnLocation;
    }

}
