package currency2;

public class Main {

    public static void main(String[] args) {
        try {
            NDataProvider nDataProvider = new NDataProvider();
            nDataProvider.requireRemoteData();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
