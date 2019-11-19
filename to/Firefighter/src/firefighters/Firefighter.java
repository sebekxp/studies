package firefighters;

import observer.Observer;

public class Firefighter implements IFirefighter, Observer {
    private String name;
    private String surname;
    private String phoneNumber;

    public Firefighter(String name, String surname, String phoneNumber) {
        this.name = name;
        this.surname = surname;
        this.phoneNumber = phoneNumber;
    }

    @Override
    public void sendSms() {
        System.out.println("    Send SMS to " + this.name + " " + this.surname);
    }

    @Override
    public void notifyObserver(Observer observer) {
        sendSms();
    }
}
