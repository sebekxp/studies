package utils;

import figure.state.FigureState;

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class DataSaver {
    public static void save(List<FigureState> figureStates) throws FileNotFoundException {

        PrintWriter out = new PrintWriter("D:\\Studia\\Semestr 5\\to\\Drawing\\src\\snapshots\\Snapshot_" +
                new SimpleDateFormat("yyyy.MM.dd.HH.mm.ss").format(new Date()) + ".txt");
        figureStates.forEach(figureState -> {
            out.println(figureState.getVectors2D() + " " + figureState.getSizes());
        });

        out.close();
    }
}
