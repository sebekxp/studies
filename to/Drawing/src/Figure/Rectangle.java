package Figure;

import drawing.DrawRectangle;
import vector.Vector2D;

import java.awt.*;

public class Rectangle implements Figure {
    private Vector2D vertex;
    private double width;
    private double height;
    private DrawRectangle drawRectangle;

    public Rectangle(Vector2D vertex, double width, double height) {
        this.vertex = vertex;
        this.width = width;
        this.height = height;
        drawRectangle = new DrawRectangle(this);
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
    public double getArea() {
        return width * height;
    }

    @Override
    public double getPerimeter() {
        return 2 * width + 2 * height;
    }

    @Override
    public void draw(Graphics g) {
        drawRectangle.draw(g);
    }
}
