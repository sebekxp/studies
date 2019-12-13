package figure.state;

import figure.FigureType;
import utils.Vector2D;

import java.util.List;

public interface FigureState {
    FigureType getFigureType();
    List<Vector2D> getVectors2D();
    List<Double> getSizes();
}
