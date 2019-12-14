package figure.state;

import utils.Vector2D;

public class TriangleState implements FigureState {
    private Vector2D v1;
    private Vector2D v2;
    private Vector2D v3;
    private double area;
    private double perimeter;
    private Integer color;

    public TriangleState(Vector2D v1, Vector2D v2, Vector2D v3, Integer color) {
        this.v1 = v1;
        this.v2 = v2;
        this.v3 = v3;
        area = calcArea();
        perimeter = calcPerimeter();
        this.color = color;
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

    public double getArea() {
        return area;
    }

    public double getPerimeter() {
        return perimeter;
    }

    public double calcArea() {
        var a = v2.getX() - v1.getX();
        var b = v3.getY() - v1.getY();
        var c = v2.getY() - v1.getY();
        var d = v3.getX() - v1.getX();

        return Math.abs(a * b - c * d) / 2;
    }

    public double calcPerimeter() {
        var v1v2 = v1.getDistance(v2);
        var v2v3 = v2.getDistance(v3);
        var v3v1 = v3.getDistance(v1);

        return v1v2 + v2v3 + v3v1;
    }

    public Integer getColor() {
        return color;
    }
}
