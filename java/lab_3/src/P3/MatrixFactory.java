package P3;

public class MatrixFactory extends MathFactory {
    public IMath createMath(Object size) {
        return new Matrix(size);
    }
}
