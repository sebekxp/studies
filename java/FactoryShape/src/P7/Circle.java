package P7;

public class Circle implements Shape, Cloneable {
    private int c = 10;

    @Override
    public void printInfo() {
        System.out.println("Circle " + getC());

    }

    @Override
    public Circle clone() throws CloneNotSupportedException {
        return (Circle) super.clone();
    }

    public int getC() {
        return c;
    }

    public void setC(int c) {
        this.c = c;
    }
}
