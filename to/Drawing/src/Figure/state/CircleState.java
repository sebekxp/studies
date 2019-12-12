package figure.state;

import utils.Vector2D;

import java.util.Arrays;
import java.util.List;

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

    @Override
    public List<Vector2D> getVectors2D() {
        return Arrays.asList(getCenter());
    }

    @Override
    public double getSizes() {
        return getRadius();
    }
}
