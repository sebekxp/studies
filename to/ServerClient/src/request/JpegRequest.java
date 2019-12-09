package request;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.nio.ByteBuffer;

public class JpegRequest extends Request {
    private Request next;
    private static int reqCount = 0;

    public JpegRequest() {
    }

    public JpegRequest(byte[] array) {
        System.out.println("Jpeg Constructor");
        setType('j');
        setLen(array.length);
        setData(array);
    }

    @Override
    public void handle() throws AWTException, IOException {
        BufferedImage image = new Robot().createScreenCapture(new Rectangle(Toolkit.getDefaultToolkit().getScreenSize()));
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ImageIO.write(image, "png", baos);
        setLen(baos.size());
        setData(baos.toByteArray());
    }

    @Override
    public Request handleRequest(char type, int numBytesLen, int len, byte[] array) {
        Request request = null;
        if (type == 'j') {
            request = new JpegRequest(array);
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
        ByteBuffer buff = getData();
        int backToStartFromPosition = 2 + buff.get(1);
        buff.position(backToStartFromPosition);
        buff.compact();
        BufferedImage img = ImageIO.read(new ByteArrayInputStream(buff.array()));
        File outputfile = new File("data\\jpegequest_"
                + reqCount++
                + "_clientID_"
                + id++
                + ".png");
        ImageIO.write(img, "png", outputfile);
    }
}