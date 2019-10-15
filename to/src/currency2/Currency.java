package currency2;

public class Currency {
    private String name;
    private int multiplier;
    private String code;
    private double rate;

    public Currency(String name, int multiplier, String code, double rate) {
        this.name = name;
        this.multiplier = multiplier;
        this.code = code;
        this.rate = rate;
    }

    public Currency() {
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getMultiplier() {
        return multiplier;
    }

    public void setMultiplier(int multiplier) {
        this.multiplier = multiplier;
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }

    public double getRate() {
        return rate;
    }

    public void setRate(double rate) {
        this.rate = rate;
    }
}
