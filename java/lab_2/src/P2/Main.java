package P2;

import ThreeDim.Cube;
import ThreeDim.Roller;
import TwoDim.Circle;
import TwoDim.Square;

public class Main {
    public static void main(String[] args){
        Circle circle = new Circle(5.5);
        Square square = new Square(9.8);

        System.out.println("Area: " + circle.getArea()+ " r: "+ circle.getR() + " type: " +circle.type);
        System.out.println("Area: " + square.getArea()+ " d: "+ square.getD() + " type: " +square.type);

        Figure cube = new Cube(10);
        Figure roller = new Roller(280.11, 50);

        System.out.println("Area: " + cube.getArea()+ " d: "+ ((Cube) cube).getD() + " type: " +cube.type);
        System.out.println("Area: " + roller.getArea()+ "pr: "+ ((Roller) roller).getR() + " h: "+ ((Roller) roller).getH() +  " type: " +roller.type);


    }
}
