package currency;

import java.util.List;
import java.util.Optional;

public class Repository {
    private List<Currency> currencies;

    public Repository(List<Currency> currencies) {
        this.currencies = currencies;
        this.currencies.add(new Currency("polski zloty", 1, "PLN", 1));
    }

    public List<Currency> getCurrencies() {
        return currencies;
    }

    public Optional<Currency> getCurrencyByCoode(String code) {
        for (Currency currency : currencies) {
            if (code.equals(currency.getCode()))
                return Optional.of(currency);
        }
        return Optional.empty();
    }
}
