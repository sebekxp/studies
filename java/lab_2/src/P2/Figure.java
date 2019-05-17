package P2;

import Enums.figureType;

public class Figure {
    private double area;
    protected figureType type;

    public double getArea() {
        return area;
    }

    public Figure(double area) {
        this.area = area;
    }
}
