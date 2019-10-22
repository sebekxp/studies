package vector;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;


public class Vector implements IVector {
    private double x;
    private double y;
    VectorType type;

    Vector(double x, double y) {
        setType(VectorType.Vector2D);
        this.x = x;
        this.y = y;
    }

    @Override
    public double getAbs() {
        return sqrt(pow(this.x, 2) + pow(this.x, 2));
    }

    @Override
    public double getX() {
        return x;
    }

    @Override
    public double getY() {
        return y;
    }

    @Override
    public void setX(double x) {
        this.x = x;
    }

    @Override
    public void setY(double y) {
        this.y = y;
    }

    @Override
    public void setType(VectorType type) {
        this.type = type;
    }

    @Override
    public double skalar(IVector v1, IVector v2) {
        return 0;
    }

    public double getAngle() {
        return 0;
    }
}
