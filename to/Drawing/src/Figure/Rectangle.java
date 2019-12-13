package figure;

import drawing.DrawRectangle;
import figure.state.FigureState;
import figure.state.RectangleState;
import utils.RandomColorGenerator;
import utils.Vector2D;

import java.awt.*;

public class Rectangle implements Figure {
    private Vector2D vertex;
    private double width;
    private double height;
    private DrawRectangle drawRectangle;
    private Color color;

    public Rectangle(Vector2D vertex, double width, double height) {
        this.vertex = vertex;
        this.width = width;
        this.height = height;
        this.drawRectangle = new DrawRectangle(this);
        RandomColorGenerator randomColorGenerator = new RandomColorGenerator();
        this.color = randomColorGenerator.generateColor();
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
    public Color getColor() {
        return color;
    }

    @Override
    public void draw(Graphics g) {
        drawRectangle.draw(g);
    }

    @Override
    public FigureState toState() {
        return new RectangleState(vertex, width, height);
    }

    @Override
    public Figure loadState(FigureState figureState) {
        return null;
    }
}
