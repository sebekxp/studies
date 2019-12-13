package utils;


import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;
import figure.Figure;
import figure.FigureAdapter;
import figure.FiguresRepository;

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
                    .registerTypeAdapter(Figure.class, new FigureAdapter())
                    .create();

            try (Reader reader = new FileReader(selectedFile)) {
                Type collectionType = new TypeToken<List<Figure>>() {
                }.getType();

                List<Figure> figures = gson.fromJson(reader, collectionType);
                FiguresRepository figuresRepository = new FiguresRepository();

                for (Figure figure : figures) {
                    figuresRepository.add(figure);
                }

                return figuresRepository;
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return null;
    }
}
