package vector;

public interface IVector {

    double getAbs();

    double getX();

    double getY();

    void setX(double x);

    void setY(double y);

    void setType(VectorType type);

    double skalar(IVector v1, IVector v2);
}
