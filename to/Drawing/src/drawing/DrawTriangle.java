package drawing;

import Figure.Triangle;

import java.awt.*;

public class DrawTriangle implements Drawable {
    private Triangle triangle;

    public DrawTriangle(Triangle triangle) {
        this.triangle = triangle;
    }

    @Override
    public void draw(Graphics g) {
        int[] x = new int[3];
        int[] y = new int[3];

        x[0] = (int) triangle.getV1().getX();
        x[1] = (int) triangle.getV2().getX();
        x[2] = (int) triangle.getV3().getX();

        y[0] = (int) triangle.getV1().getY();
        y[1] = (int) triangle.getV2().getY();
        y[2] = (int) triangle.getV3().getY();

        Polygon polygon = new Polygon(x, y, 3);
        g.drawPolygon(polygon);
        g.setColor(Color.PINK);
        g.fillPolygon(polygon);
    }
}
