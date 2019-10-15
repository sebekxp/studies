package currency;

import java.io.*;
import java.net.URL;

public abstract class ResoruceLoader {

    public static byte[] getResources(String url) throws IOException {
        URL URL = new URL(url);
        InputStream in = new BufferedInputStream(URL.openStream());

        ByteArrayOutputStream arrayOutputStream = new ByteArrayOutputStream();
        byte[] buf = new byte[4096];
        int n;
        while ((n = in.read(buf)) > 0) {
            arrayOutputStream.write(buf, 0, n);
        }
        arrayOutputStream.close();
        in.close();

        byte[] response = arrayOutputStream.toByteArray();

        return response;
    }
}
