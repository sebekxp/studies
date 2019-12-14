package drawing;

import figure.Circle;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class DrawCircle implements Drawable {
    private Circle circle;

    public DrawCircle(Circle circle) {
        this.circle = circle;
    }

    @Override
    public void draw(Graphics g) {
        Graphics2D graphics2D = (Graphics2D) g;
        var x = circle.getCenter().getX();
        var y = circle.getCenter().getY();
        var r = circle.getRadius();

        graphics2D.setColor(new Color(this.circle.getColor()));
        graphics2D.fill(new Ellipse2D.Double(x, y, r, r));
    }
}