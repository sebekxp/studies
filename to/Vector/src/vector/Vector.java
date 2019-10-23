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
    public VectorType getType() {
        return type;
    }

    @Override
    public IVector scalar(IVector v1) {
        IVector vector = null;
        if (v1.getType().compareTo(this.getType()) > 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() * v.getX(), this.getY() * v.getY(), v.getZ());
        } else if (v1.getType().compareTo(this.getType()) == 0) {
            vector = new Vector(this.getX() * v1.getX(), this.getY() * v1.getY());
        } else if (v1.getType().compareTo(this.getType()) < 0) {
            Vector3D v = (Vector3D) this;
            vector = new Vector3D(v.getX() * v1.getX(), v.getY() * v1.getY(), v.getZ());
        }
        return vector;
    }

    @Override
    public IVector addVectors(IVector v1) {
        IVector vector = null;
        if (v1.getType().compareTo(this.getType()) > 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() + v.getX(), this.getY() + v.getY(), v.getZ());
        } else if (v1.getType().compareTo(this.getType()) == 0) {
            vector = new Vector(this.getX() + v1.getX(), this.getY() + v1.getY());
        } else if (v1.getType().compareTo(this.getType()) < 0) {
            Vector3D v = (Vector3D) this;
            vector = new Vector3D(v.getX() + v1.getX(), v.getY() + v1.getY(), v.getZ());
        }
        return vector;
    }

    @Override
    public IVector subtractVectors(IVector v1) {
        IVector vector = null;
        if (v1.getType().compareTo(this.getType()) > 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() - v.getX(), this.getY() - v.getY(), v.getZ());
        } else if (v1.getType().compareTo(this.getType()) == 0) {
            vector = new Vector(this.getX() - v1.getX(), this.getY() - v1.getY());
        } else if (v1.getType().compareTo(this.getType()) < 0) {
            Vector3D v = (Vector3D) this;
            vector = new Vector3D(v.getX() - v1.getX(), v.getY() - v1.getY(), v.getZ());
        }
        return vector;
    }

    public double getAngle() {
        return 0;
    }
}
