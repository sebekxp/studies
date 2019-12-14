package figure.state;

import utils.Vector2D;

public class RectangleState implements FigureState {
    private Vector2D vertex;
    private double width;
    private double height;
    private double area;
    private double perimeter;
    private Integer color;

    public RectangleState(Vector2D vertex, double width, double height, Integer color) {
        this.vertex = vertex;
        this.width = width;
        this.height = height;
        area = width * height;
        perimeter = 2 * width + 2 * height;
        this.color = color;
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
