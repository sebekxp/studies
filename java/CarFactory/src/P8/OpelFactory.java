package P8;

class OpelFactory {
    static Car createCar() {
        return new Opel("Opel", "Sedan", Type.Opel);
    }
}
