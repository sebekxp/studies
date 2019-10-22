package vector;

import com.google.gson.*;

import java.io.FileWriter;
import java.io.IOException;

public class DataSaver {
    public static void saveData(String filePath) {
        Gson gson = new GsonBuilder()
                .setPrettyPrinting()
                .registerTypeAdapter(IVector.class, new IVectorAdapter())
                .create();

//        List<IVector> vectors = new ArrayList<>();
        IVector[] vectors = new IVector[]{
                new Vector(1, 2),
                new Vector(1, 2),
                new Vector(1, 2),
                new Vector3D(1, 8, 5),
                new Vector3D(1, 8, 5),
                new Vector3D(1, 8, 5),
                new Vector3D(1, 8, 5),
                new Vector3D(1, 8, 5),
                new Vector3D(1, 8, 5)
        };
//        vectors.add(new Vector(1, 2));
//        vectors.add(new Vector(1, 2));
//        vectors.add(new Vector(1, 2));
//        vectors.add(new Vector(1, 2));
//        vectors.add(new Vector(1, 2));
//        vectors.add(new Vector(1, 2));
//        vectors.add(new Vector3D(1, 2,3));
//        vectors.add(new Vector3D(1, 2,2));
//        vectors.add(new Vector3D(1, 4,5));
//        vectors.add(new Vector3D(1, 1,5));
//        vectors.add(new Vector3D(1, 8,5));
//        vectors.add(new Vector3D(1, 2,7));

        try (FileWriter writer = new FileWriter(filePath)) {
            gson.toJson(vectors, writer);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
