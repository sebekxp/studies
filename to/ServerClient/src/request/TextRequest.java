package request;


import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class TextRequest extends Request {
    private Request next;
    private static int reqCount = 0;

    public TextRequest() {
    }

    public TextRequest(byte[] array) {
        setType('t');
        setLen(array.length);
        setData(array);
    }

    @Override
    public void handle() {
        String str = new String(getData().array());
        str = str.substring(3, getLen() + 3).toUpperCase();
        getData().clear();
        setData(str.getBytes());
    }

    @Override
    public Request handleRequest(char type, int numBytesLen, int len, byte[] array) {
        Request request = null;
        if (type != 'j') {
            request = new TextRequest(array);
        } else if (this.next != null) {
            request = next.handleRequest(type, Request.byteSize(len), len, array);
        }
        return request;
    }

    @Override
    public void setNext(Request next) {
        this.next = next;
    }

    @Override
    public void saveDataToFile(int id) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter("data\\textrequest_"
                + reqCount++
                + "_clientID_"
                + id++
                + ".txt"));

        String str = new String(getData().array());
        int startPositionOfData = 3;
        str = str.substring(startPositionOfData, getLen() + startPositionOfData);
        writer.write(str);
        writer.close();
    }
}