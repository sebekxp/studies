package figure.state;

import utils.Vector2D;

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
}
