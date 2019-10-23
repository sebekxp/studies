package vector;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class VectorRepository {
    private List<IVector> vectors;

    public VectorRepository() {
        this.vectors = new ArrayList<>();
    }

    public void addVector(IVector vector) {
        vectors.add(vector);
    }

    public boolean removeVector(IVector vector) {
        return vectors.remove(vector);
    }

    public Optional<IVector> getVectorByPoint(double[] shitf) {
        for (IVector vector : vectors) {
            if (vector.getType() == VectorType.Vector2D) {
                if (vector.getX() == shitf[0] && vector.getY() == shitf[1]) {
                    return Optional.of(vector);
                }
            } else if (vector.getType() == VectorType.Vector3D) {
                Vector3D vector3D = (Vector3D) vector;
                if (vector3D.getX() == shitf[0] && vector3D.getY() == shitf[1] && vector3D.getZ() == shitf[2]) {
                    return Optional.of(vector);
                }
            }

        }
        return Optional.empty();
    }

    public List<IVector> getVectors() {
        return vectors;
    }
}
