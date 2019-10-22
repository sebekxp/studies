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
    };

    public double getAbs() {
        return sqrt(pow(getX(), 2) + pow(getY(), 2 + pow(this.z, 2)));
    }

    public double getSecondAngle() {
        return 0;
    }

}
