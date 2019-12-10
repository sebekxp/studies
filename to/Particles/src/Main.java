import ui.Board;

import javax.swing.*;
import java.awt.*;

public class Main {
    public static void main(String[] args) {
        JFrame frame = new JFrame("Board");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Board board = new Board();

        frame.add(board);
        board.initButtons();
        board.initParticles(12);

        board.setPreferredSize(new Dimension(500, 500));
        frame.pack();
        frame.setVisible(true);
        board.getTimer().start();
    }
}
