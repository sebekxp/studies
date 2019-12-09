import request.JpegRequest;
import request.Request;
import request.TextRequest;

import java.io.*;
import java.net.Socket;
import java.util.Random;
import java.util.Scanner;

public class Client {
    private static int port = 7777;
    private static Random rand = new Random();
    private static int ID = rand.nextInt(10000);


    public static void main(String[] args) throws IOException {
        try (var socket = new Socket("localhost", port)) {
            var sc = new Scanner(System.in);
            DataOutputStream out= new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));
            DataInputStream in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));

            Request request = new TextRequest();
            Request request1 = new JpegRequest();
            request.setNext(request1);

                while (sc.hasNextLine()) {
                    var inputLine = sc.nextLine();
                    char type = inputLine.charAt(0);
                    int len = inputLine.length();

                    Request req = request.handleRequest(type, Request.byteSize(len), len, inputLine.getBytes());
                    out.write(req.getData().array());
                    out.flush();

                    Request encodedRequest = Request.encode(in);
                    System.out.println("Received from server");
                    System.out.println("Saving received data to file...");
                    encodedRequest.saveDataToFile(ID);
            }
        }
    }

}