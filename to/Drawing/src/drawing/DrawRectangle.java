package drawing;


import figure.Rectangle;

import java.awt.*;

public class DrawRectangle implements Drawable {
    private Rectangle rectangle;

    public DrawRectangle(Rectangle rectangle) {
        this.rectangle = rectangle;
    }

    @Override
    public void draw(Graphics g) {
        int x = (int) rectangle.getVertex().getX();
        int y = (int) rectangle.getVertex().getY();
        int w = (int) rectangle.getWidth();
        int h = (int) rectangle.getHeight();

        g.setColor(new Color(rectangle.getColor()));
        g.fillRect(x, y, w, h);
    }
}
