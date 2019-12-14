import drawing.DynamicFigureGenerator;

import javax.swing.*;
import java.awt.*;

public class Main {

    public static void main(String[] args) {
        JFrame frame = new JFrame();
        DynamicFigureGenerator dynamicFigureGenerator = new DynamicFigureGenerator();
        frame.add(dynamicFigureGenerator);
        dynamicFigureGenerator.initButtons();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setPreferredSize(new Dimension(800, 800));
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
        dynamicFigureGenerator.getTimer().start();
    }
}
