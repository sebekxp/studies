package unit.state;

import unit.IUnit;
import unit.ResponseCode;

public interface UnitState {
     ResponseCode notifyUnit(IUnit unit, String CCIR_CODE);
}
