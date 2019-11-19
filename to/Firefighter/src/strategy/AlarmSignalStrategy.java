package strategy;

import unit.IUnit;
import unit.ResponseCode;

public class AlarmSignalStrategy implements SignalStrategy {
    @Override
    public ResponseCode sendSignal(IUnit unit) {
        System.out.println("Sending alarm signal.");
        String code = unit.getAlarmCode();
        return unit.notify(code);
    }
}