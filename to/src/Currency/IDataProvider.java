package Currency;

import java.io.IOException;

public interface IDataProvider {
    void requireRemoteData() throws IOException;
}
