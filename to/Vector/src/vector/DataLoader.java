package vector;

import com.google.gson.*;
import com.google.gson.reflect.TypeToken;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.lang.reflect.Type;
import java.util.List;

public class DataLoader {
    public static VectorRepository loadData(String filePath) {
        Gson gson = new GsonBuilder()
                .setLenient()
                .registerTypeAdapter(IVector.class, new VectorAdapter())
                .create();

        try (Reader reader = new FileReader(filePath)) {
            Type collectionType = new TypeToken<List<IVector>>() {
            }.getType();

            List<IVector> vectors = gson.fromJson(reader, collectionType);
            VectorRepository vectorRepository = new VectorRepository();

            for (IVector vector : vectors) {
                vectorRepository.addVector(vector);
            }

            return vectorRepository;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
