package vector;

public interface IVector {

    double getAbs();

    double getX();

    double getY();

    void setX(double x);

    void setY(double y);

    void setType(VectorType type);

    VectorType getType();

    IVector scalar(IVector v);

    IVector addVectors(IVector v);

    IVector subtractVectors(IVector v);

}
