import java.net.*;
import java.io.*;

class UServer {

    DatagramPacket packet;
    DatagramSocket socket;
    byte[] buffer = new byte[1024];

    public static void main(String[] args) {
        new UServer().go();
    }

    void go() {
        try {
            socket = new DatagramSocket(6000);
            while (true) {
                System.out.println("Listening on 6000");
                packet = new DatagramPacket(buffer, buffer.length);
                socket.receive(packet);
                String msg = new String(packet.getData(), 0, packet.getLength());
                int port = packet.getPort();
                System.out.println("Received:" + msg + " " + port);
                buffer = "This is a message from the server".getBytes();
                socket.send(new DatagramPacket(buffer, buffer.length, InetAddress.getLocalHost(), port));
                System.out.println("Sent Message");
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}


