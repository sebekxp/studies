package strategy;

import unit.IUnit;
import unit.ResponseCode;

public class TestSignalStrategy implements SignalStrategy {
    @Override
    public ResponseCode sendSignal(IUnit unit) {
        System.out.println("Sending test signal.");
        String code = unit.getTestCode();
        return unit.notify(code);
    }
}
