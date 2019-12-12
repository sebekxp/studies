package figure.state;

import utils.Vector2D;

import java.util.List;

public class RectangleState implements FigureState {
    private Vector2D vertex;
    private double width;
    private double height;

    public RectangleState(Vector2D vertex, double width, double height) {
        this.vertex = vertex;
        this.width = width;
        this.height = height;
    }

    public Vector2D getVertex() {
        return vertex;
    }

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
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
