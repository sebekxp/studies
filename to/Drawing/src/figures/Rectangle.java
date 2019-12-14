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
    private Integer color;

    public Rectangle(Vector2D vertex, double width, double height) {
        this.vertex = vertex;
        this.width = width;
        this.height = height;
        this.drawRectangle = new DrawRectangle(this);
        RandomColorGenerator randomColorGenerator = new RandomColorGenerator();
        this.color = randomColorGenerator.generateColor();
    }

    public Rectangle(Vector2D vertex, double width, double height, Integer color) {
        this.vertex = vertex;
        this.width = width;
        this.height = height;
        this.drawRectangle = new DrawRectangle(this);
        this.color = color;
    }

    public Rectangle() {
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
    public Integer getColor() {
        return color;
    }

    @Override
    public void draw(Graphics g) {
        drawRectangle.draw(g);
    }

    @Override
    public FigureState toState() {
        return new RectangleState(vertex, width, height, color);
    }

    public Figure loadState(FigureState figureState) {
        RectangleState rect = (RectangleState) figureState;
        return new Rectangle(rect.getVertex(), rect.getWidth(), rect.getHeight(), rect.getColor());
    }
}
