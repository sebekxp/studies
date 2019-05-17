package ThreeDim;

import Enums.figureType;
import P2.Figure;

public class Roller extends Figure {
    private double h;
    private double r;

    public Roller(double h, double r) {
        super(2*Math.PI*r+2*Math.PI);
        this.h = h;
        this.r = r;
        this.type = figureType.ThreeD;
    }

    public double getH() {
        return h;
    }

    public double getR() {
        return r;
    }
}
