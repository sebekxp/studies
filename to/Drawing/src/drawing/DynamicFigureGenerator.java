package drawing;

import Figure.Circle;
import Figure.Figure;
import Figure.Rectangle;
import Figure.Triangle;
import vector.Vector2D;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class DynamicFigureGenerator extends JPanel {
    private Timer timer;
    private Figure figureToDraw;
    private Random random = new Random();

    public DynamicFigureGenerator() {
        timer = new Timer(0, e -> repaint());
    }
    
    public Timer getTimer() {
        return timer;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (figureToDraw != null)
            figureToDraw.draw(g);
        timer.stop();
    }

    public Vector2D generateRandomVector2D() {
        double minPos = 20;
        double maxPos = 480;

        double randX = minPos + (maxPos - minPos) * random.nextDouble();
        double randY = minPos + (maxPos - minPos) * random.nextDouble();

        return new Vector2D(randX, randY);
    }

    public int generateRandomValue() {
        double minPos = 20;
        double maxPos = 480;

        return (int) (minPos + (maxPos - minPos) * random.nextDouble());
    }


    public void initButtons() {
        JButton circle = new JButton("Circle");
        JButton rectangle = new JButton("Rectangle");
        JButton triangle = new JButton("Triangle");

        circle.addActionListener(e -> {
            figureToDraw = new Circle(generateRandomVector2D(), generateRandomValue());
            timer.start();
        });

        triangle.addActionListener(e -> {
            figureToDraw = new Triangle(generateRandomVector2D(),
                    generateRandomVector2D(),
                    generateRandomVector2D());
            timer.start();
        });

        rectangle.addActionListener(e -> {
            figureToDraw = new Rectangle(generateRandomVector2D(),
                    generateRandomValue(),
                    generateRandomValue());
            timer.start();
        });

        this.add(circle);
        this.add(rectangle);
        this.add(triangle);
    }

}
