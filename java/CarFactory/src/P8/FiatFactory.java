package P8;

class FiatFactory {
    static Car createCar() {
        return new Fiat("Fiat", "Kombi", Type.Fiat);
    }
}
