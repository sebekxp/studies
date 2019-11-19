package station;

import observer.Observable;
import observer.Observer;
import strategy.SignalStrategy;
import unit.IUnit;
import unit.ResponseCode;
import unit.state.UnitError;
import unit.state.UnitReady;
import java.util.ArrayList;
import java.util.List;

public class BaseStation implements Observer, Observable {
    private List<Observer> vfdUnits;
    private SignalStrategy signalStrategy;

    void setSignalStrategy(SignalStrategy signalStrategy) {
        this.signalStrategy = signalStrategy;
    }

    public BaseStation() {
        this.vfdUnits = new ArrayList<>();
    }

    @Override
    public void addObserver(Observer observer) {
        vfdUnits.add(observer);
    }

    @Override
    public void removeObserver(Observer observer) {
        vfdUnits.remove(observer);
    }

    @Override
    public void notifyObservers() {
        vfdUnits.forEach(this::notifyObserver);
    }

    public void notifyObserver(Observer observer) {
        IUnit unit = (IUnit) observer;
        ResponseCode responseCode = signalStrategy.sendSignal(unit);

        if (responseCode == ResponseCode.ERROR) {
            unit.setState(new UnitError());
        } else {
            unit.setState(new UnitReady());
        }
    }
}
























