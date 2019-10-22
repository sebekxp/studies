package vector;

import com.google.gson.*;
import com.google.gson.reflect.TypeToken;

import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.lang.reflect.Type;
import java.util.Collection;

public class DataLoader {
    public static VectorRepository loadData(String filePath) {
        Gson gson = new GsonBuilder()
                .setLenient()
                .registerTypeAdapter(IVector.class, new IVectorAdapter())
                .create();

        try (Reader reader = new FileReader(filePath)) {
            Type collectionType = new TypeToken<Collection<IVector>>(){}.getType();
            Collection<IVector> vectors = gson.fromJson(reader, collectionType);
//            IVector[] vectors  = gson.fromJson(reader, IVector[].class);
            for (IVector v :
                    vectors) {
                System.out.println(v.getClass());
                System.out.println(v.getX() + ", " + v.getY() + ", " + v.getAbs());
            }

            return new VectorRepository();

        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }
}
