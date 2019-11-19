package unit;

import firefighters.IFirefighter;
import observer.Observable;
import observer.Observer;
import unit.state.UnitReady;
import unit.state.UnitState;

import java.util.ArrayList;
import java.util.List;

public class Unit implements IUnit, Observer, Observable {
    private List<Observer> fireFighters;
    private String unitName;
    private String testCode;
    private String alarmCode;

    public void setState(UnitState unitState) {
        this.unitState = unitState;
    }

    private UnitState unitState;

    public Unit(String unitName, String testCode, String alarmCode) {
        fireFighters = new ArrayList<>();
        this.unitName = unitName;
        this.testCode = testCode;
        this.alarmCode = alarmCode;
        this.unitState = new UnitReady();
    }

    @Override
    public String getTestCode() {
        return testCode;
    }

    @Override
    public String getAlarmCode() {
        return alarmCode;
    }

    @Override
    public void addObserver(Observer observer) {
        fireFighters.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        fireFighters.remove(observer);
    }

    @Override
    public ResponseCode notify(String CCIR_CODE) {
        return unitState.notifyUnit(this, CCIR_CODE);
    }

    @Override
    public void notifyObservers() {
        fireFighters.forEach(this::notifyObserver);
    }

    @Override
    public void notifyObserver(Observer observer) {
        IFirefighter firefighter = (IFirefighter) observer;
        firefighter.sendSms();
    }
}
