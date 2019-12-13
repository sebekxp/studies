package utils;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;
import figure.Figure;
import figure.FigureAdapter;
import figure.state.FigureState;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Type;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class DataSaver {
    public static void save(List<FigureState> figureStates) throws FileNotFoundException {

        String filePath = "D:\\Studia\\Semestr 5\\to\\Drawing\\src\\snapshots\\Snapshot_" +
                new SimpleDateFormat("yyyy.MM.dd.HH.mm.ss").format(new Date()) + ".json";
        Gson gson = new GsonBuilder()
                .setPrettyPrinting()
                .registerTypeAdapter(Figure.class, new FigureAdapter())
                .create();

        try (FileWriter writer = new FileWriter(filePath)) {
            Type type = new TypeToken<List<Figure>>(){}.getType();
            gson.toJson(figureStates,type, writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
