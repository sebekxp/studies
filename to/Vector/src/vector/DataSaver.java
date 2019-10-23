package vector;

import com.google.gson.*;
import com.google.gson.reflect.TypeToken;

import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Type;
import java.util.List;

public class DataSaver {
    public static void saveData(String filePath, List<IVector> data) {
        Gson gson = new GsonBuilder()
                .setPrettyPrinting()
                .registerTypeAdapter(IVector.class, new IVectorAdapter())
                .create();

        try (FileWriter writer = new FileWriter(filePath)) {
            Type type = new TypeToken<List<IVector>>(){}.getType();
            gson.toJson(data, type, writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
