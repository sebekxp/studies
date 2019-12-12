package drawing;

import Figure.Circle;

import java.awt.*;
import java.awt.geom.Ellipse2D;

public class DrawCircle implements Drawable {
    private Circle circle;

    public DrawCircle(Circle circle) {
        this.circle = circle;
    }

    @Override
    public void draw(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;
        var x = circle.getCenter().getX();
        var y = circle.getCenter().getY();
        var r = circle.getRadius();

        Ellipse2D.Double circle = new Ellipse2D.Double(x, y, r, r);
        g2d.setColor(Color.RED);
        g2d.fill(circle);
    }
}