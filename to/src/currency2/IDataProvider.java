package currency2;

import java.io.IOException;

public interface IDataProvider {
    void requireRemoteData() throws IOException;
}
