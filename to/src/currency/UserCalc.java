package currency;

public abstract class UserCalc {
    public static double uCalc(String src, String dest, double value, Repository repo) {

        Currency c1 = repo.getCurrencyByCoode(src);
        Currency c2 = repo.getCurrencyByCoode(dest);
        if (c1 != null && c2 != null) {
            Calculator calculator = new Calculator(c1, c2, value);
            return calculator.calc();
        } else {
            throw new IllegalArgumentException("We dont support entered currency code.");
        }
    }
}