package P8;

import java.util.ArrayList;

public class CarSaloon {
    private String nameSaloon;
    private Type typeCarsInSaloon;
    ArrayList<Car> cars;

    CarSaloon(String nameSaloon, Type typeCarsInSaloon) {
        this.nameSaloon = nameSaloon;
        this.typeCarsInSaloon = typeCarsInSaloon;
        cars = new ArrayList<Car>();
    }

    void addCar(Car car) {
        if (car.getFabricName() == typeCarsInSaloon) {
            cars.add(car);
        } else {
            System.out.println("W salonie trzymane sa samochody innej marki");
        }
    }

    void removeCar(Car car) {
        if (cars.contains(car)) {
            cars.remove(car);
        } else
            System.out.println("Nie ma mozna usunac nieistniejacego samochodu");
    }

    void showCarsInSaloon() {
        for (Car car : cars) {
            car.getInfo();
        }
    }
}
