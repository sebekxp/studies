package P7;

public class Rectangle implements Shape, Cloneable {
    private int r = 9999;

    @Override
    public void printInfo() {
        System.out.println("Rectangle " + getR());
    }

    @Override
    public Rectangle clone() throws CloneNotSupportedException {
        return (Rectangle) super.clone();
    }

    public int getR() {
        return r;
    }

    public void setR(int r) {
        this.r = r;
    }
}
