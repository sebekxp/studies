package Currency;

import java.util.List;

public class Repository {
    private List<Currency> currencies;

    public Repository(List<Currency> currencies) {
        this.currencies = currencies;
    }

    public List<Currency> getCurrencies() {
        return currencies;
    }

    private Currency getCurrencyByCoode(String code) {
        for (Currency currency : currencies) {
            if (currencies.equals(currency.getCode()))
                return currency;
        }
        return null;
    }
}
