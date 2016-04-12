import java.net.*;
import java.io.*;

class UClient {

    DatagramPacket packet;
    DatagramSocket socket;
    byte[] buffer = new byte[1024];

    public static void main(String[] args) {
        new UClient().go();
    }

    void go() {
        try {
            socket = new DatagramSocket(5000);
            buffer = "This is a message from the client".getBytes();
            socket.send(new DatagramPacket(buffer, buffer.length, InetAddress.getLocalHost(), 6000));
            System.out.println("Sent Message");
            packet = new DatagramPacket(buffer, buffer.length);
            socket.receive(packet);
            String msg = new String(packet.getData(), 0, packet.getLength());
            int port = packet.getPort();
            System.out.println("Received:" + msg + " " + port);
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
}


