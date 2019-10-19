package currency;

public class Main {

    public static void main(String[] args) {
        try {
            NDataProvider nDataProvider = new NDataProvider();
            Repository repository = nDataProvider.requireRemoteData();
            UserInputProvider userInputProvider = new UserInputProvider(repository);
            userInputProvider.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
