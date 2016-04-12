import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class SimpleChatClientA {
    JTextArea incoming;
    JTextField outgoing;
    byte[] buffer = new byte[1024];
    DatagramSocket socket;
    DatagramPacket packet;


    public static void main(String[] args) {
        SimpleChatClientA client = new SimpleChatClientA();
        client.go();
    }

    public void go() {
        JFrame frame = new JFrame("Incredibly simple Chat Client");
        JPanel panel = new JPanel();
        outgoing = new JTextField(20);
        incoming = new JTextArea(15, 50);
        JButton send = new JButton("Send");
        send.addActionListener(new SendButtonListener());
        panel.add(incoming);
        panel.add(outgoing);
        panel.add(send);

        frame.getContentPane().add(BorderLayout.CENTER, panel);
        setUpNetworking();

        Thread readerThread = new Thread(new IncomingReader());
        readerThread.start();

        frame.setSize(500, 500);
        frame.setVisible(true);
    }

    public void setUpNetworking() {
        try {
            socket = new DatagramSocket(4000);
            System.out.println("Connection Established");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public class IncomingReader implements Runnable {
        public void run() {
            try {
                while(true) {
                    packet = new DatagramPacket(buffer, buffer.length);
                    socket.receive(packet);
                    String msg = new String(packet.getData(), 0, packet.getLength());
                    incoming.append("\n" + msg);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public class SendButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            String msg;
            try {
                msg = outgoing.getText().toString();
                buffer = msg.getBytes();
                socket.send(new DatagramPacket(buffer, buffer.length, InetAddress.getLocalHost(), 5000));
            } catch (Exception e) {
                e.printStackTrace();
            }
            outgoing.setText("");
            outgoing.requestFocus();

        }
    }
}



