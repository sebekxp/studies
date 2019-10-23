package vector;

import java.util.List;

public abstract class VectorDisplayer {
    static void displayInfo(IVector vector) {
        if (vector.getType() == VectorType.Vector3D) {
            Vector3D vector3D = (Vector3D) vector;
            System.out.println(vector3D.getType() + " [" + vector3D.getX() + " " + vector3D.getY() +
                    " " + vector3D.getZ() + "]" + ", length = " + vector3D.getAbs());
        } else if (vector.getType() == VectorType.Vector2D) {
            System.out.println(vector.getType() + " [" + vector.getX() + " " + vector.getY() + "]" + ", length = " + vector.getAbs());
        }
    }

    public static void listRepository(List<IVector> vectors) {
        System.out.println("=============== LIST OF AVAILABLE VECTORS ===============");
        if (!vectors.isEmpty()) {
            int i=0;
            for (IVector vector : vectors) {
                System.out.print("["+i+"] ");
                VectorDisplayer.displayInfo(vector);
                i++;
            }
        } else
            System.out.println("Repository is empty");
    }
}
