package unit.state;

import unit.IUnit;
import unit.ResponseCode;

public class UnitError implements UnitState {

    @Override
    public ResponseCode notifyUnit(IUnit unit, String CCIR_CODE) {
        return ResponseCode.ERROR;
    }
}
