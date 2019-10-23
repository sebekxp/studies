package vector;

public class Main {

    public static void main(String[] args) {
        VectorRepository vectorRepository = DataLoader.loadData("D:\\Studia\\Semestr 5\\to\\Vector\\src\\data\\data.json");

        vectorRepository.getVectors().add(new Vector(1, 2));
        vectorRepository.getVectors().add(new Vector(3, 5));
        vectorRepository.getVectors().add(new Vector(2, 5));
        vectorRepository.getVectors().add(new Vector(5, 5));
        vectorRepository.getVectors().add(new Vector(7, 5));
        vectorRepository.getVectors().add(new Vector(3, 5));
        vectorRepository.getVectors().add(new Vector(3, 5));
        vectorRepository.getVectors().add(new Vector(3, 3));
        vectorRepository.getVectors().add(new Vector(2, 1));
        vectorRepository.getVectors().add(new Vector(3, 5));
        vectorRepository.getVectors().add(new Vector3D(1, 2, 3));
        vectorRepository.getVectors().add(new Vector3D(1, 2, 3));
        vectorRepository.getVectors().add(new Vector3D(1, 2, 3));
        vectorRepository.getVectors().add(new Vector3D(1, 2, 3));
        vectorRepository.getVectors().add(new Vector3D(1, 2, 3));
        vectorRepository.getVectors().add(new Vector3D(1, 5, 3));
        DataSaver.saveData("D:\\Studia\\Semestr 5\\to\\Vector\\src\\data\\data.json" ,vectorRepository.getVectors());

        UserInputProvider userInputProvider = new UserInputProvider(vectorRepository);
        userInputProvider.start();
    }
}
