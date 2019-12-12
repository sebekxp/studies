package figure.state;

import utils.Vector2D;

import java.util.List;

public class TriangleState implements FigureState {
    private Vector2D v1;
    private Vector2D v2;
    private Vector2D v3;

    public TriangleState(Vector2D v1, Vector2D v2, Vector2D v3) {
        this.v1 = v1;
        this.v2 = v2;
        this.v3 = v3;
    }

    public Vector2D getV1() {
        return v1;
    }

    public Vector2D getV2() {
        return v2;
    }

    public Vector2D getV3() {
        return v3;
    }

    @Override
    public List<Vector2D> getVectors2D() {
        return null;
    }

    @Override
    public double getSizes() {
        return 0;
    }
}
