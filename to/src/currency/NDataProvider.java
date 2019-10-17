package currency;

import org.w3c.dom.Document;

import java.io.IOException;

public class NDataProvider implements IDataProvider {

    @Override
    public Repository requireRemoteData() throws IOException {
        byte[] resources = ResoruceLoader.getResources("http://www.nbp.pl/kursy/xml/LastA.xml");
        Document xml = XmlParser.parse(resources);
        return NConverter.remoteRepository(xml);
    }
}
