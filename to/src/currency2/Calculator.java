package currency2;

public class Calculator {
    private Currency src;
    private Currency dest;
    private double value;

    public Calculator(Currency src, Currency dest, double value) {
        this.src = src;
        this.dest = dest;
        this.value = value;
    }

    public double calc() {
        return (value * (this.src.getRate() * this.src.getMultiplier())) / (this.dest.getRate() * this.dest.getMultiplier());
    }

    public void setValue(double value) {
        this.value = value;
    }
}
