package P3;

public class VectorFactory extends MathFactory {
    public IMath createMath(Object size) {
        return new Vector(size);
    }
}
