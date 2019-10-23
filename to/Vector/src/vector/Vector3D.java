package vector;

import static java.lang.Math.pow;
import static java.lang.Math.sqrt;

public class Vector3D extends Vector {
    private double z;

    Vector3D(double x, double y, double z) {
        super(x, y);
        setType(VectorType.Vector3D);
        this.z = z;
    }

    public double getZ() {
        return z;
    }

    public void setZ(double z) {
        this.z = z;
    }

    public double getAbs() {
        return sqrt(pow(getX(), 2) + pow(getY(), 2) + pow(this.z, 2));
    }

    public double getSecondAngle() {
        return 0;
    }

    @Override
    public IVector addVectors(IVector v1) {
        IVector vector = null;
        if (v1.getType().compareTo(this.getType()) > 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() + v.getX(), this.getY() + v.getY(), v.getZ());
        } else if (v1.getType().compareTo(this.getType()) == 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() + v.getX(), this.getY() + v.getY(), this.getZ() + v.getZ());
        } else if (v1.getType().compareTo(this.getType()) < 0) {
            Vector3D v = this;
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
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() - v.getX(), this.getY() - v.getY(), this.getZ() - v.getZ());
        } else if (v1.getType().compareTo(this.getType()) < 0) {
            Vector3D v = this;
            vector = new Vector3D(v.getX() - v1.getX(), v.getY() - v1.getY(), v.getZ());
        }
        return vector;
    }

    @Override
    public IVector scalar(IVector v1) {
        IVector vector = null;
        if (v1.getType().compareTo(this.getType()) > 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() * v.getX(), this.getY() * v.getY(), v.getZ());
        } else if (v1.getType().compareTo(this.getType()) == 0) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(this.getX() * v.getX(), this.getY() * v.getY(), this.getZ() * v.getZ());
        } else if (v1.getType().compareTo(this.getType()) < 0) {
            Vector3D v = this;
            vector = new Vector3D(v.getX() * v1.getX(), v.getY() * v1.getY(), v.getZ());
        }
        return vector;
    }
}
