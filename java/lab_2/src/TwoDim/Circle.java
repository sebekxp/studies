package TwoDim;

import Enums.figureType;
import P2.Figure;

public class Circle extends Figure {
    private double r;

    public Circle(double r) {
        super(r*r*Math.PI);
        this.r = r;
        this.type = figureType.TwoD;
    }

    public double getR() {
        return r;
    }
}
