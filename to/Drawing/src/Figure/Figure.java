package figure;

import drawing.Drawable;
import figure.state.FigureState;

public interface Figure extends Drawable {
    double getArea();

    double getPerimeter();

    Integer getColor();

    FigureState toState();

    Figure loadState(FigureState figureState);
}
