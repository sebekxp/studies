package vector;

import java.util.List;
import java.util.Optional;

public class VectorRepository {
    private List<IVector> vectors;

    public void addVector(IVector vector) {
        vectors.add(vector);
    }

    public boolean removeVector(IVector vector) {
        return vectors.remove(vector);
    }

    public Optional<IVector> getVectorByShift(double[] shitf) {
        for (IVector vector :
                vectors) {
            if (vector.getX() == shitf[0] && vector.getY() == shitf[1]) {
                return Optional.of(vector);
            }
        }
        return Optional.empty();
    }
}
