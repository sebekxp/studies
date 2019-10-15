package Currency;

import org.w3c.dom.Document;

public class Main {

    public static void main(String[] args) {
        try {
            byte[] resources = ResoruceLoader.getResources("http://www.nbp.pl/kursy/xml/LastA.xml");
            Document xml = XmlParser.parse(resources);
            Repository repository = NConverter.remoteRepository(resources, xml);
            System.out.println("elo");
            for (Currency currency:
                 repository.getCurrencies()) {
                System.out.println("elo");
                System.out.println(currency.getName());
                System.out.println(currency.getMultiplier());
                System.out.println(currency.getCode());
                System.out.println(currency.getMultiplier());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
