package utils;


import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;
import figure.*;
import figure.state.CircleState;
import figure.state.FigureState;
import figure.state.RectangleState;
import figure.state.TriangleState;

import javax.swing.*;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.lang.reflect.Type;
import java.util.List;

public class DataLoader {
    public static FiguresRepository loadData() {
        JFileChooser jfc = new JFileChooser("D:\\Studia\\Semestr 5\\to\\Drawing\\src\\snapshots");

        int returnValue = jfc.showOpenDialog(null);

        if (returnValue == JFileChooser.APPROVE_OPTION) {
            File selectedFile = jfc.getSelectedFile();

            Gson gson = new GsonBuilder()
                    .setLenient()
                    .registerTypeAdapter(FigureState.class, new FigureAdapter())
                    .create();

            try (Reader reader = new FileReader(selectedFile)) {
                Type collectionType = new TypeToken<List<FigureState>>() {
                }.getType();

                List<FigureState> figureStateList = gson.fromJson(reader, collectionType);
                FiguresRepository figuresRepository = new FiguresRepository();


                for (FigureState figureState : figureStateList) {
                    Figure f = null;
                    if (figureState instanceof CircleState) {
                        Circle circle = new Circle();
                        f = circle.loadState(figureState);
                    }
                    else if (figureState instanceof TriangleState) {
                        Triangle triangle = new Triangle();
                        f = triangle.loadState(figureState);
                    }
                    else if (figureState instanceof RectangleState) {
                        Rectangle rectangle = new Rectangle();
                        f = rectangle.loadState(figureState);
                    }

                    figuresRepository.add(f);
                }

                return figuresRepository;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return null;
    }
}
