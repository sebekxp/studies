package drawing;

import Figure.Circle;
import Figure.Rectangle;
import vector.Vector2D;

import javax.swing.*;
import java.awt.*;

public class DynamicFigure extends JPanel {
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Circle circle = new Circle(new Vector2D(300,300), 50);
        Rectangle rectangle = new Rectangle(new Vector2D(30,30), 100, 50);
        circle.draw(g);
        rectangle.draw(g);
    }
}
