package ThreeDim;

import Enums.figureType;
import P2.Figure;

public class Cube extends Figure {
    private double d;

    public Cube(double d) {
        super(6*d*d);
        this.d = d;
        this.type = figureType.ThreeD;
    }

    public double getD() {
        return d;
    }
}
