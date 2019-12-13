package figure;

import drawing.Drawable;
import figure.state.FigureState;

import java.awt.*;

public interface Figure extends Drawable {
    double getArea();

    double getPerimeter();

    Color getColor();

    FigureState toState();

    Figure loadState(FigureState figureState);
}
