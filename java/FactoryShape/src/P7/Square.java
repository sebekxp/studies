package P7;

public class Square implements Shape, Cloneable {
    private int s = 12;

    @Override
    public void printInfo() {
        System.out.println("Square " + getS());
    }

    @Override
    public Square clone() throws CloneNotSupportedException {
        return (Square) super.clone();
    }

    public int getS() {
        return s;
    }

    public void setS(int s) {
        this.s = s;
    }
}
