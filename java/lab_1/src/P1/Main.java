package P1;

import java.util.Arrays;
import java.util.Collections;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {

        Miasto[] miasto = new Miasto[4];
        miasto[0] = new Miasto("Polska", "Europa", "30-155", 40000000);
        miasto[1] = new Miasto("Niemcy", "Europa", "30-145", 80000000);
        miasto[2] = new Miasto("Holandia", "Europa", "30-165", 30000000);
        miasto[3] = new Miasto("Hiszpania", "Europa", "30-105", 50000000);
        miasto[3].setKraj("Japonia");

        for (Miasto miasto1 : miasto) {
            System.out.println(miasto1.getKraj());
            System.out.println(miasto1.getRegion());
            System.out.println(miasto1.getKodPocztowy());
            System.out.println(miasto1.getLiczbaMieszkancow());
            System.out.println();
        }
    }
}
