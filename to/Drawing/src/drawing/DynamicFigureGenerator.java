package drawing;

import figure.Rectangle;
import figure.*;
import memento.CareTaker;
import memento.Memento;
import utils.DataLoader;
import utils.DataSaver;
import utils.Vector2D;

import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.util.Random;


public class DynamicFigureGenerator extends JPanel {
    private Timer timer;
    private FiguresRepository figuresRepository;
    private Random random = new Random();
    private boolean clear = false;
    private CareTaker careTaker = new CareTaker();

    public DynamicFigureGenerator() {
        figuresRepository = new FiguresRepository();
        timer = new Timer(0, e -> repaint());
    }

    public Timer getTimer() {
        return timer;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (!clear)
            figuresRepository.getFigures().forEach(figure -> figure.draw(g));
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
        JButton clear = new JButton("Clear");
        JButton load = new JButton("Load");
        JButton save = new JButton("Save");

        circle.addActionListener(e -> {
            this.clear = false;
            Figure figureToDraw = new Circle(generateRandomVector2D(), generateRandomValue());
            figuresRepository.getFigures().add(figureToDraw);
            timer.start();
        });

        triangle.addActionListener(e -> {
            this.clear = false;
            Figure figureToDraw = new Triangle(generateRandomVector2D(),
                    generateRandomVector2D(),
                    generateRandomVector2D());
            figuresRepository.getFigures().add(figureToDraw);
            timer.start();
        });

        rectangle.addActionListener(e -> {
            this.clear = false;
            Figure figureToDraw = new Rectangle(generateRandomVector2D(),
                    generateRandomValue(),
                    generateRandomValue());
            figuresRepository.getFigures().add(figureToDraw);
            timer.start();
        });

        clear.addActionListener(e -> {
            this.clear = true;
            this.figuresRepository.getFigures().clear();
            timer.start();
        });

        save.addActionListener(e -> {
            careTaker.add(new Memento(figuresRepository.getFigures()));
            var currentState = careTaker.getMementos().size() - 1;
            try {
                DataSaver.save(careTaker.getMementos().get(currentState).getState());
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        });

        load.addActionListener(e -> {
            figuresRepository.getFigures().clear();
            figuresRepository = DataLoader.loadData();
            if (!timer.isRunning()) {
                timer.start();
            }
        });
        this.add(circle);
        this.add(rectangle);
        this.add(triangle);
        this.add(clear);
        this.add(save);
        this.add(load);
    }

}
