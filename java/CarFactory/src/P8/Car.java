package P8;

public abstract class Car implements Cloneable {

    private String nameMark;
    private String model;
    private int serialNumber;
    private Type fabricName;
    private static int uniqueNumber = 0;

    Car(String nameMark, String model, Type fabricName) {
        this.nameMark = nameMark;
        this.model = model;
        this.serialNumber = uniqueNumber++;
        this.fabricName = fabricName;
    }

    public String getNameMark() {
        return nameMark;
    }

    public String getModel() {
        return model;
    }

    public int getSerialNumber() {
        return serialNumber;
    }

    public Type getFabricName() {
        return fabricName;
    }

    public void setNameMark(String nameMark) {
        this.nameMark = nameMark;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setSerialNumber(int serialNumber) {
        this.serialNumber = serialNumber;
    }

    public void setFabricName(Type fabricName) {
        this.fabricName = fabricName;
    }

    void getInfo() {
        System.out.println(getNameMark() + " " + getModel() + " " + getSerialNumber() + " " + getFabricName());
    }

    public Car clone() throws CloneNotSupportedException {
        Car car = (Car) super.clone();
        car.serialNumber = uniqueNumber++;
        return car;
    }
}
