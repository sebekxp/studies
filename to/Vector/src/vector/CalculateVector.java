package vector;


public class CalculateVector {
    IVector addVectors(IVector v1, IVector v2) {
        return v1.addVectors(v2);
    }

    IVector subtractVectors(IVector v1, IVector v2) {
        return v1.subtractVectors(v2);
    }

    IVector scalarVectors(IVector v1, IVector v2) {
        return v1.scalar(v2);
    }

}
