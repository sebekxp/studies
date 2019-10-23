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
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(op.apply(this.getX(), v.getX()), op.apply(this.getY(), v.getY()), op.apply(this.getZ(), v.getZ()));
        } else if (v1.getType() == VectorType.Vector3D) {
            Vector3D v = (Vector3D) v1;
            vector = new Vector3D(op.apply(this.getX(), v.getX()), op.apply(this.getY(), v.getY()), op.apply(0, v.getZ()));
        } else if (this.getType() == VectorType.Vector3D) {
            Vector3D v = this;
            vector = new Vector3D(op.apply(v.getX(), v1.getX()), op.apply(v.getY(), v1.getY()), op.apply(v.getZ(), 0));
        }

        return vector;
    }
}
