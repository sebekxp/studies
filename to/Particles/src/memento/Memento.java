package memento;

import particles.Particle;
import particles.ParticleState;

import java.util.ArrayList;
import java.util.List;

public class Memento {
    private List<ParticleState> state = new ArrayList<>();

    public Memento() {
    }

    public Memento(List<Particle> state) {
        state.forEach(p -> {
            this.state.add(p.toState());
        });
    }

    public List<ParticleState> getState() {
        return state;
    }

    public void setState(List<ParticleState> state) {
        this.state = state;
    }
}
