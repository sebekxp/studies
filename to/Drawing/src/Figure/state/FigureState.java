package figure.state;

import utils.Vector2D;

import java.util.List;

public interface FigureState {
    List<Vector2D> getVectors2D();
    double getSizes();
}
