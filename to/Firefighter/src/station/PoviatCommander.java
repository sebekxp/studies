package station;

import firefighters.Firefighter;
import strategy.SignalStrategy;

public class PoviatCommander extends Firefighter {

    public PoviatCommander(String name, String surname, String phoneNumber) {
        super(name, surname, phoneNumber);
    }

    public void sendSignal(BaseStation baseStation, SignalStrategy signalStrategy) {
        baseStation.setSignalStrategy(signalStrategy);
        baseStation.notifyObservers();
    }
}