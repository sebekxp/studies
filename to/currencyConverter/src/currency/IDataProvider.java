package currency;

import java.io.IOException;

public interface IDataProvider {
    Repository requireRemoteData() throws IOException;
}
