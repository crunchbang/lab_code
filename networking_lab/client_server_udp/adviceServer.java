import java.net.*;
import java.io.*;

class AdviceServer {
    public String[] adviceList = { "Advice A", "Advice B", "Advice C" };
    DatagramSocket socket;
    DatagramPacket packet;
    int port;
    byte[] buffer = new byte[1024];


    void go() {
        try {
            socket = new DatagramSocket(5000);
            while(true) {
                packet = new DatagramPacket(buffer, buffer.length);
                System.out.println("Listening on port 5000");
                socket.receive(packet);
                String msg = new String(packet.getData(), 0, packet.getLength());
                port = packet.getPort();
                System.out.println("Accepted Connection on port 5000");
                buffer = getAdvice().getBytes();
                socket.send(new DatagramPacket(buffer, buffer.length, InetAddress.getLocalHost(), port));
                System.out.println("Connection closed on port 5000");
            }
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    String getAdvice() {
        int random = (int) (Math.random() * adviceList.length);
        return adviceList[random];
    }

    public static void main(String[] args) {
        AdviceServer adServ = new AdviceServer();
        adServ.go();
    }
}

