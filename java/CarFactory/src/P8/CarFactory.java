package P8;

class CarFactory {
    CarFactory(){
    }
    Car createCar(Type nameFactory) {
        switch (nameFactory) {
            case Fiat:
                return FiatFactory.createCar();
            case Opel:
                return OpelFactory.createCar();
            case Mazda:
                return  MazdaFactory.createCar();
            default:
                return null;
        }
    }
}
