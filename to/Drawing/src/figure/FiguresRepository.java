package figure;

import java.util.ArrayList;
import java.util.List;

public class FiguresRepository {
    private List<Figure> figures;

    public FiguresRepository() {
        this.figures = new ArrayList<>();
    }

    public List<Figure> getFigures() {
        return figures;
    }

    public void setFigures(List<Figure> figures) {
        this.figures = figures;
    }

    public void add(Figure figure) {
        figures.add(figure);
    }

    public void remove(Figure figure) {
        figures.remove(figure);
    }
}
