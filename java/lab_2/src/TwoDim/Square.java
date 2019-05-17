package TwoDim;

import Enums.figureType;
import P2.Figure;

public class Square extends Figure {
    private double d;

    public Square(double d) {
        super(d*d);
        this.d = d;
        this.type = figureType.TwoD;
    }

    public double getD() {
        return d;
    }
}
