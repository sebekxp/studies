package main;

import strategy.AlarmSignalStrategy;
import station.BaseStation;
import strategy.TestSignalStrategy;
import unit.Unit;
import firefighters.Firefighter;
import station.PoviatCommander;

public class Main {

    public static void main(String[] args) {
        PoviatCommander poviatCommander = new PoviatCommander("Janek", "Komendant", "111111111");

        Firefighter firefighter = new Firefighter("Kazek", "Strazak", "222222222");
        Firefighter firefighter1 = new Firefighter("Zbyszek", "Strazak", "333333333");
        Firefighter firefighter2 = new Firefighter("Janek", "Strazak", "333333113");
        Firefighter firefighter3 = new Firefighter("Patryk", "Strazak", "333554333");
        Firefighter firefighter4 = new Firefighter("Szymon", "Strazak", "111333333");
        Firefighter firefighter5 = new Firefighter("Alek", "Strazak", "111333543");

        Unit unit1 = new Unit("unit1", "unit1Test", "unit1Alarm");
        Unit unit2 = new Unit("unit2", "unit1Test", "unit1Alarm");

        unit1.addObserver(firefighter);
        unit1.addObserver(firefighter1);
        unit1.addObserver(firefighter2);

        unit2.addObserver(firefighter3);
        unit2.addObserver(firefighter4);
        unit2.addObserver(firefighter5);

        BaseStation baseStation =  new BaseStation();

        baseStation.addObserver(unit1);
        baseStation.addObserver(unit2);

        poviatCommander.sendSignal(baseStation, new AlarmSignalStrategy());
        poviatCommander.sendSignal(baseStation, new TestSignalStrategy());
    }

}