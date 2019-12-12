package memento;


import figure.Figure;
import figure.state.FigureState;

import java.util.ArrayList;
import java.util.List;

public class Memento {
    private List<FigureState> state = new ArrayList<>();

    public Memento() {
    }

    public Memento(List<Figure> state) {
        state.forEach(figure -> {
            this.state.add(figure.toState());
        });
    }

    public List<FigureState> getState() {
        return state;
    }

    public void setState(List<FigureState> state) {
        this.state = state;
    }
}
