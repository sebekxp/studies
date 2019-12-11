package Figure;

import drawing.DrawCircle;
import vector.Vector2D;

import java.awt.*;

public class Circle implements Figure {
    private Vector2D center;
    private double radius;
    private DrawCircle drawCircle;

    public Circle(Vector2D center, int radius) {
        this.center = center;
        this.radius = radius;
        drawCircle = new DrawCircle(this);
    }

    public Vector2D getCenter() {
        return center;
    }

    public double getRadius() {
        return radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public void draw(Graphics g) {
        drawCircle.draw(g);
    }
}
