package vector;

import jdk.dynalink.Operation;

import static java.lang.Math.*;


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

    public double getAngle() {
        return 0;
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
    public VectorType getType() {
        return type;
    }

    @Override
    public IVector scalar(IVector v1) {
        Operator mult = (x, y) -> x * y;
        return this.calculationsHelper(v1, mult);
    }

    @Override
    public IVector addVectors(IVector v1) {
        Operator plus = (x, y) -> x + y;

        return this.calculationsHelper(v1, plus);
    }

    @Override
    public IVector subtractVectors(IVector v1) {
        Operator minus = (x, y) -> x - y;
        return this.calculationsHelper(v1, minus);
    }

    private IVector calculationsHelper(IVector v1, Operator op) {
        IVector vector = null;
        if (v1.getType() == this.getType()) {
            vector = new Vector(op.apply(this.getX(), v1.getX()), op.apply(this.getY(), v1.getY()));
        } else if (v1.getType() == VectorType.Vector3D) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(op.apply(this.getX(), v.getX()), op.apply(this.getY(), v.getY()), op.apply(0,v.getZ()));
        } else if (this.getType() == VectorType.Vector3D) {
            Vector3D v = (Vector3D) this;
            vector = new Vector3D(op.apply(v.getX(), v1.getX()), op.apply(v.getY(), v1.getY()), op.apply(v.getZ(), 0));
        }
        return vector;
    }
}
