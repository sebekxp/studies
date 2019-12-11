package vector;

public class Vector2D {
    private double x;
    private double y;

    public Vector2D(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public double getDistance(Vector2D v) {
        var x = v.getX() - this.getX();
        var y = v.getY() - this.getY();

        return Math.sqrt(x * x + y * y);
    }
}
