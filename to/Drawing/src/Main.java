import Figure.Triangle;
import drawing.DynamicFigure;
import vector.Vector2D;

import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {
        Triangle triangle = new Triangle(new Vector2D(1, 3),
                new Vector2D(4, 0),
                new Vector2D(-2, 1));
        JFrame frame = new JFrame();
        frame.add(new DynamicFigure());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setPreferredSize(new Dimension(500,500));
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
