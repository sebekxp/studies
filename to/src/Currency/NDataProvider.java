package Currency;

import org.w3c.dom.Document;

import java.io.IOException;
import java.util.Scanner;

public class NDataProvider implements IDataProvider {
    private Scanner sc = new Scanner(System.in);
    private boolean run = true;

    @Override
    public void requireRemoteData() throws IOException {
        while (run) {
            Menu.printMenu();

            System.out.println("Chose option");
            int option = sc.nextInt();
            switch (option) {
                case 1:
                    convertCurrency();
                    break;
                case 2:
                    exit();
                    break;
            }
        }
        System.out.println("GOOOD BYE");
    }

    public void convertCurrency() throws IOException {
        byte[] resources = ResoruceLoader.getResources("http://www.nbp.pl/kursy/xml/LastA.xml");
        Document xml = XmlParser.parse(resources);
        Repository repository = NConverter.remoteRepository(xml);
        sc.nextLine();
        System.out.println("Currency code (source)");
        String src = sc.nextLine();
        System.out.println("Currency code (destination)");
        String dest = sc.nextLine();
        System.out.println("Amount of money");
        double value = sc.nextDouble();

        Currency c1 = repository.getCurrencyByCoode(src);
        Currency c2 = repository.getCurrencyByCoode(dest);

        Calculator calculate = new Calculator(c1, c2, value);
        System.out.println("Amount of money after convert");
        System.out.println(value + " " + src + " == " + calculate.calc() + " " + dest);
        System.out.println(value + " " + src + " == " + UserCalc.uCalc(src, dest, value, repository) + " " + dest);
    }

    public void exit() {
        run = false;
    }
}
