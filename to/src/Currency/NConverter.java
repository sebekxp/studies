package currency;

import org.w3c.dom.Document;
import org.w3c.dom.NodeList;

import java.util.ArrayList;
import java.util.List;

public abstract class NConverter {
    public static Repository remoteRepository(Document xml) {
        NodeList items = xml.getElementsByTagName("pozycja");
        List<Currency> currencies = new ArrayList<Currency>();

        for (int i = 0; i < items.getLength(); i++) {
            String name = xml.getElementsByTagName("nazwa_waluty").item(i).getTextContent();
            String code = xml.getElementsByTagName("kod_waluty").item(i).getTextContent();
            int multiplier = Integer.parseInt(xml.getElementsByTagName("przelicznik").item(i).getTextContent());
            double rate = Double.parseDouble(xml.getElementsByTagName("kurs_sredni").item(i).getTextContent().replace(",","."));

            Currency currency = new Currency(name, multiplier, code, rate);
            currencies.add(currency);
        }
        return new Repository(currencies);
    }
}