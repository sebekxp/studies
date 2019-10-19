package currency;

import java.util.Optional;

public abstract class UserCalc {
    public static double uCalc(String src, String dest, double value, Repository repo) {

        Optional<Currency> optionalCurrency1 = repo.getCurrencyByCoode(src);
        Optional<Currency> optionalCurrency2 = repo.getCurrencyByCoode(dest);

        if (optionalCurrency1.isPresent() && optionalCurrency2.isPresent()) {
            Currency c1 = optionalCurrency1.get();
            Currency c2 = optionalCurrency2.get();

            Calculator calculator = new Calculator(c1, c2, value);
            return calculator.calc();
        } else {
            throw new IllegalArgumentException("We dont support entered currency code.");
        }
    }
}