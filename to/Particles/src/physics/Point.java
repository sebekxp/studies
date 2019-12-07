package physics;

public class Point {
    private double x;
    private double y;


    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setPosition(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getDistance(Point pt) {
        var px = pt.getX() - this.getX();
        var py = pt.getY() - this.getY();
        return Math.sqrt(px * px + py * py);
    }

    @Override
    public String toString() {
        return "Point(" + this.x + ", " + this.y + ")";
    }

    public void print() {
        System.out.println(toString());
    }
}
