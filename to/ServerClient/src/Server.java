import request.JpegRequest;
import request.Request;
import request.TextRequest;

import java.awt.*;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.Executors;

public class Server {
    private static int port = 7777;

    public static void main(String[] args) throws IOException {
        try (var server = new ServerSocket(port)) {
            System.out.println("Server is running at " + port + "...");
            var clientPool = Executors.newFixedThreadPool(10);
            while (true) {
                clientPool.execute(new ClientThread(server.accept()));
            }
        }
    }

    private static class ClientThread implements Runnable {
        private Socket socket;

        ClientThread(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            System.out.println("Connected: " + socket);
            try {
                DataInputStream in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
                DataOutputStream out = new DataOutputStream(new BufferedOutputStream(socket.getOutputStream()));
                Request request = new TextRequest();
                Request request1 = new JpegRequest();
                request.setNext(request1);
                while (true) {
                    Request encodedRequest = Request.encode(in);
                    encodedRequest.handle();
                    System.out.println("Received data from client");
                    System.out.println("Sending response to client");
                    out.write(encodedRequest.getData().array());
                    out.flush();
                }
            } catch (IOException | AWTException e) {
                e.printStackTrace();
            } finally {
                try {
                    socket.close();
                } catch (IOException ignored) {
                }
                System.out.println("Closed: " + socket);
            }
        }
    }
}