package P7;

class ShapeFactory{
    Shape createShape(String shapeName) {
        if (shapeName == null) return null;
        else if (shapeName.equalsIgnoreCase("CIRCLE")) return new Circle();
        else if (shapeName.equalsIgnoreCase("SQUARE")) return new Square();
        else if (shapeName.equalsIgnoreCase("RECTANGLE")) return new Rectangle();
        return null;
    }
}
