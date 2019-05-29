package P8;

class MazdaFactory {
    static Car createCar() {
        return new Mazda("Mazda", "Sedan", Type.Mazda);
    }
}
