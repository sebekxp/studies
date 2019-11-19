package strategy;

import unit.IUnit;
import unit.ResponseCode;

public interface SignalStrategy {
     ResponseCode sendSignal(IUnit unit);
}
