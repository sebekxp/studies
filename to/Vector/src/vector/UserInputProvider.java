package vector;

import java.util.Optional;
import java.util.Random;
import java.util.Scanner;

public class UserInputProvider {
    private VectorRepository vectorRepository;
    private Scanner sc;
    private boolean run;

    public UserInputProvider(VectorRepository vectorRepository) {
        this.vectorRepository = vectorRepository;
        this.sc = new Scanner(System.in);
        this.run = true;
    }

    public void start() {
        while (run) {
            Menu.printMenu();

            System.out.println("Chose option");
            int option = sc.nextInt();
            switch (option) {
                case 1:
                    VectorDisplayer.listRepository(vectorRepository.getVectors());
                    break;
                case 2:
                    addToRepo();
                    break;
                case 3:
                    removeFromRepo();
                    break;
                case 4:
                    searchInRepo();
                    break;
                case 5:
                    addVectors();
                    break;
                case 6:
                    subtractVectors();
                    break;
                case 7:
                    scalarVectors();
                    break;
                case 0:
                    exit();
                    break;
            }
        }
        System.out.println("GOOD BYE");
    }


    public void exit() {
        run = false;
    }

    private void addToRepo() {
        int options = chooseVector();
        IVector vector = null;
        if (options == 2) {
            double[] array = handle2DVector();
            vector = new Vector(array[0], array[1]);
        } else if (options == 3) {
            double[] array = handle3DVector();
            vector = new Vector3D(array[0], array[1], array[2]);
        }

        vectorRepository.addVector(vector);
    }

    private double[] handle2DVector() {
        System.out.println("Enter two pint [x, y]");
        System.out.println("Enter x: ");
        double x = sc.nextDouble();
        System.out.println("Enter y: ");
        double y = sc.nextDouble();

        return new double[]{x, y};
    }

    private double[] handle3DVector() {
        System.out.println("Enter three pint [x, y, z]");
        System.out.println("Enter x: ");
        double x = sc.nextDouble();
        System.out.println("Enter y: ");
        double y = sc.nextDouble();
        System.out.println("Enter z: ");
        double z = sc.nextDouble();

        return new double[]{x, y, z};
    }

    private int chooseVector() {
        System.out.println("Choose type of vector");
        System.out.println("[2] 2D");
        System.out.println("[3] 3D");

        return sc.nextInt();
    }

    private void removeFromRepo() {
        System.out.println("Enter number of index you want to delete from repository");
        int index = sc.nextInt();
        IVector vectorToDelete = vectorRepository.getVectors().get(index);
        vectorRepository.removeVector(vectorToDelete);

        System.out.print("You removed from repository vector: ");
        VectorDisplayer.displayInfo(vectorRepository.getVectors().get(index));
    }

    private void searchInRepo() {
        System.out.println("Search vector in repository by point");
        System.out.println("Enter [x, y] to 2D vector or [x, y, z] to 3D vector");
        int options = chooseVector();
        double[] arr = null;
        if (options == 2) {
            arr = handle2DVector();
        } else if (options == 3) {
            arr = handle3DVector();
        }
        Optional<IVector> searchedVector = vectorRepository.getVectorByPoint(arr);
        if (searchedVector.isPresent()) {
            System.out.println("We found vector");
            VectorDisplayer.displayInfo(searchedVector.get());
        } else {
            System.out.println("We dont found that vector in repositor");
        }
    }

    private IVector[] calculationHelper() {
        System.out.println("Select two index from list of vectors that you want to calculate");
        System.out.println("[1] Select random two");
        System.out.println("[2] Select index");
        int options = sc.nextInt();
        IVector v1;
        IVector v2;
        if (options == 1) {
            Random rnd = new Random();
            int index1 = rnd.nextInt(vectorRepository.getVectors().size());
            int index2 = rnd.nextInt(vectorRepository.getVectors().size());
            v1 = vectorRepository.getVectors().get(index1);
            v2 = vectorRepository.getVectors().get(index2);
            return new IVector[]{v1, v2};
        } else if (options == 2) {
            System.out.println("Select first index");
            int index1 = sc.nextInt();
            System.out.println("Select second index");
            int index2 = sc.nextInt();
            v1 = vectorRepository.getVectors().get(index1);
            v2 = vectorRepository.getVectors().get(index2);
            return new IVector[]{v1, v2};
        }
        return null;
    }

    private void addVectors() {
        CalculateVector calculateVector = new CalculateVector();
        IVector[] vectors = calculationHelper();
        IVector v = calculateVector.addVectors(vectors[0], vectors[1]);

        System.out.println("You add two vectors");
        VectorDisplayer.displayInfo(vectors[0]);
        VectorDisplayer.displayInfo(vectors[1]);
        System.out.println("Result of your calculations:");
        VectorDisplayer.displayInfo(v);
    }

    private void subtractVectors() {
        CalculateVector calculateVector = new CalculateVector();
        IVector[] vectors = calculationHelper();
        IVector v = calculateVector.subtractVectors(vectors[0], vectors[1]);

        System.out.println("You subtract two vectors");
        VectorDisplayer.displayInfo(vectors[0]);
        VectorDisplayer.displayInfo(vectors[1]);
        System.out.println("Result of your calculations:");
        VectorDisplayer.displayInfo(v);
    }

    private void scalarVectors() {
        CalculateVector calculateVector = new CalculateVector();
        IVector[] vectors = calculationHelper();
        IVector v = calculateVector.scalarVectors(vectors[0], vectors[1]);

        System.out.println("You scalar two vectors");
        VectorDisplayer.displayInfo(vectors[0]);
        VectorDisplayer.displayInfo(vectors[1]);
        System.out.println("Result of your calculations:");
        VectorDisplayer.displayInfo(v);
    }
}
