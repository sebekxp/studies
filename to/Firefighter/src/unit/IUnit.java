package unit;

import unit.state.UnitState;

public interface IUnit {
    ResponseCode notify(String CCIR_CODE);
    void setState(UnitState state);
    String getTestCode();
    String getAlarmCode();
    void notifyObservers();
}
