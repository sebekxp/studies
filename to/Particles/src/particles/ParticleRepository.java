package particles;

import java.util.ArrayList;
import java.util.List;

public class ParticleRepository {
    private List<Particle> particles;

    public ParticleRepository() {
        particles = new ArrayList<>();
    }

    public List<Particle> getParticles() {
        return particles;
    }

    public void add(Particle particle) {
        particles.add(particle);
    }

    public void remove(Particle particle) {
        particles.remove(particle);
    }
}
