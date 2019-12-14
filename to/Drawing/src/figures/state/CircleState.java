package figure.state;

import utils.Vector2D;

public class CircleState implements FigureState {
    private Vector2D center;
    private double radius;
    private double area;
    private double perimeter;
    private Integer color;

    public CircleState(Vector2D center, double radius, Integer color) {
        this.center = center;
        this.radius = radius;
        this.color = color;
        area = Math.PI * radius * radius;
        perimeter = 2 * Math.PI * radius;
    }

    public Vector2D getCenter() {
        return center;
    }

    public double getRadius() {
        return radius;
    }

    public Integer getColor() {
        return color;
    }

    public double getArea() {
        return area;
    }

    public double getPerimeter() {
        return perimeter;
    }
}
