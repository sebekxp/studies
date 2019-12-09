package request;

import java.awt.*;
import java.io.DataInputStream;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.ByteBuffer;

public abstract class Request {
    private ByteBuffer data;
    private char type;
    private int len;

    public abstract void handle() throws AWTException, IOException;

    public static Request encode(DataInputStream in) throws IOException {
        char type = (char) in.read();
        int neededBytesToSaveLength = in.read();
        byte[] dataLength = new byte[neededBytesToSaveLength];

        in.read(dataLength);
        int length = new BigInteger(1, dataLength).intValue();
        byte[] dataByte = new byte[length];
        in.read(dataByte);

        Request request = new TextRequest();
        Request request1 = new JpegRequest();
        request.setNext(request1);

        return request.handleRequest(type, neededBytesToSaveLength, dataByte.length, dataByte);
    }

    public ByteBuffer getData() {
        return data;
    }

    public static int byteSize(long x) {
        if (x < 0) throw new IllegalArgumentException();
        int s = 1;
        while (s < 8 && x >= (1L << (s * 8))) s++;
        return s;
    }

    public void setData(byte[] array) {
        int neededBytesToSaveType = 1;
        int numberOfBytesNeededToWriteLengthBytes = 1;
        int neededBytesToSaveData = getLen();
        int neededBytesToSaveLength = byteSize(neededBytesToSaveData);

        this.data = ByteBuffer.allocate(
                neededBytesToSaveType +
                        numberOfBytesNeededToWriteLengthBytes +
                        neededBytesToSaveLength +
                        neededBytesToSaveData);

        this.data.clear();
        this.data.put((byte) getType());
        this.data.put((byte) neededBytesToSaveLength);
        this.data.put(BigInteger.valueOf(neededBytesToSaveData).toByteArray());
        this.data.put(array);
    }

    public char getType() {
        return type;
    }

    public void setType(char type) {
        this.type = type;
    }

    public int getLen() {
        return len;
    }

    public void setLen(int len) {
        this.len = len;
    }

    public abstract Request handleRequest(char type, int numBytesLen, int len, byte[] array);

    public abstract void setNext(Request next);

    public abstract void saveDataToFile(int id) throws IOException;
}