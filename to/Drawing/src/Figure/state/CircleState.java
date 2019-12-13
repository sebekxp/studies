package figure.state;

import utils.Vector2D;

public class CircleState implements FigureState {
    private Vector2D center;
    private double radius;

    public CircleState(Vector2D center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public Vector2D getCenter() {
        return center;
    }

    public double getRadius() {
        return radius;
    }
}
