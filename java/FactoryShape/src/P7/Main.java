package P7;

public class Main {

    public static void main(String[] args) throws CloneNotSupportedException {
        ShapeFactory shapeFactory = new ShapeFactory();
        Shape circle = shapeFactory.createShape("circle");
        Shape rectangle = shapeFactory.createShape("RECTANGLE");
        Shape square = shapeFactory.createShape("Square");

        Shape circleCopy = circle.clone();
        Shape squareCopy = square.clone();
        Shape rectangleCopy = rectangle.clone();

        circle.printInfo();
        square.printInfo();
        rectangle.printInfo();

        circleCopy.printInfo();
        squareCopy.printInfo();
        rectangleCopy.printInfo();
    }
}
