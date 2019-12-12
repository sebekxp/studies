package figure;

import drawing.DrawTriangle;
import figure.state.FigureState;
import figure.state.TriangleState;
import utils.RandomColorGenerator;
import utils.Vector2D;

import java.awt.*;

public class Triangle implements Figure {
    private Vector2D v1;
    private Vector2D v2;
    private Vector2D v3;
    private DrawTriangle drawTriangle;
    private Color color;

    public Triangle(Vector2D v1, Vector2D v2, Vector2D v3) {
        this.v1 = v1;
        this.v2 = v2;
        this.v3 = v3;
        drawTriangle = new DrawTriangle(this);
        RandomColorGenerator randomColorGenerator = new RandomColorGenerator();
        this.color = randomColorGenerator.generateColor();
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
    public double getArea() {
        var a = v2.getX() - v1.getX();
        var b = v3.getY() - v1.getY();
        var c = v2.getY() - v1.getY();
        var d = v3.getX() - v1.getX();

        return Math.abs(a * b - c * d) / 2;
    }

    @Override
    public double getPerimeter() {
        var v1v2 = v1.getDistance(v2);
        var v2v3 = v2.getDistance(v3);
        var v3v1 = v3.getDistance(v1);

        return v1v2 + v2v3 + v3v1;
    }

    @Override
    public Color getColor() {
        return color;
    }

    @Override
    public void draw(Graphics g) {
        drawTriangle.draw(g);
    }

    @Override
    public FigureState toState() {
        return new TriangleState(v1, v2, v3);
    }
}
