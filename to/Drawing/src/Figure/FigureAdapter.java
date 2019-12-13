package figure;

import com.google.gson.*;

import java.lang.reflect.Type;

public class FigureAdapter implements JsonSerializer, JsonDeserializer {

    private static final String CLASSNAME = "className";
    private static final String DATA = "data";

    public Figure deserialize(JsonElement jsonElement, Type type,
                              JsonDeserializationContext jsonDeserializationContext) throws JsonParseException {

        JsonObject jsonObject = jsonElement.getAsJsonObject();
        JsonPrimitive prim = (JsonPrimitive) jsonObject.get(CLASSNAME);
        String className = prim.getAsString();
        Class clazz = getObjectClass(className);

        return jsonDeserializationContext.deserialize(jsonObject.get(DATA), clazz);
    }

    public JsonElement serialize(Object jsonElement, Type type, JsonSerializationContext jsonSerializationContext) {
        JsonObject jsonObject = new JsonObject();
        jsonObject.addProperty(CLASSNAME, jsonElement.getClass().getName());
        jsonObject.add(DATA, jsonSerializationContext.serialize(jsonElement));

        return jsonObject;
    }

    public Class getObjectClass(String className) {
        try {
            return Class.forName(className);
        } catch (ClassNotFoundException e) {
            throw new JsonParseException(e.getMessage());
        }
    }
}
