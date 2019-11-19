package unit.state;

import unit.IUnit;
import unit.ResponseCode;

public class UnitReady implements UnitState {

    @Override
    public ResponseCode notifyUnit(IUnit unit, String CCIR_CODE) {
        if (unit.getTestCode().equals(CCIR_CODE)) {
            return ResponseCode.TEST_OK;
        } else if (unit.getAlarmCode().equals(CCIR_CODE)) {
            unit.notifyObservers();
            return ResponseCode.ALARM_OK;
        } else {
            return ResponseCode.ERROR;
        }
    }
}
