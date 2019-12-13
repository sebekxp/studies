package figure;

import drawing.DrawCircle;
import figure.state.CircleState;
import figure.state.FigureState;
import utils.RandomColorGenerator;
import utils.Vector2D;

import java.awt.*;

public class Circle implements Figure {
    private Vector2D center;
    private double radius;
    private DrawCircle drawCircle;
    private Color color;

    public Circle(Vector2D center, int radius) {
        this.center = center;
        this.radius = radius;
        this.drawCircle = new DrawCircle(this);
        RandomColorGenerator randomColorGenerator = new RandomColorGenerator();
        this.color = randomColorGenerator.generateColor();
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
    public Color getColor() {
        return color;
    }

    @Override
    public void draw(Graphics g) {
        drawCircle.draw(g);
    }

    @Override
    public FigureState toState() {
        return new CircleState(center, radius);
    }

    @Override
    public Figure loadState(FigureState figureState) {
        return null;
    }
}
