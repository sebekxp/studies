package P8;

public class Main {

    public static void main(String[] args) {
        CarFactory carFactory = new CarFactory();
        try {
            Car opel = carFactory.createCar(Type.Opel);
            Car fiat = carFactory.createCar(Type.Fiat);
            Car mazda = carFactory.createCar(Type.Mazda);

            opel.getInfo();
            mazda.getInfo();
            fiat.getInfo();

            Car opelClone = opel.clone();
            opelClone.getInfo();

            System.out.println();
            System.out.println();

            CarSaloon opelSaloon = new CarSaloon("Opel Saloon", Type.Opel);

            opelSaloon.addCar(opel);
            opelSaloon.addCar(opelClone);
            opelSaloon.addCar(fiat);
            opelSaloon.showCarsInSaloon();

            opelSaloon.removeCar(opelClone);
            opelSaloon.removeCar(fiat);

            System.out.println("Po usinieciu");
            opelSaloon.showCarsInSaloon();

        } catch (NullPointerException ex) {
            System.out.println(ex.getMessage());
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }

    }
}
