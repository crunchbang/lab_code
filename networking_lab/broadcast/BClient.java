import java.net.*;
import java.io.*;
import javax.swing.*;

public class BClient {
    BufferedReader reader;
    JTextArea tf;
    public static void main(String[] args) {
        new BClient().go();
    }

    void go() {
        JFrame frame = new JFrame("Client");
        JPanel panel = new JPanel();
        tf = new JTextArea(20, 20);
        tf.setEditable(false);
        setUpNetworking();
        panel.add(tf);
        frame.add(panel);
        frame.setSize(200,200);
        frame.setVisible(true);
    }

    void setUpNetworking() {
        try {
            Socket socket = new Socket("127.0.0.1", 5000);
            System.out.println("ConnectionEstablished");
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            Thread t = new Thread(new ServerRead());
            t.start();
        } catch(Exception e) {
            e.printStackTrace();
        }
    }

    class ServerRead implements Runnable {
        String msg;
        public void run() {
            try {
                while ((msg = reader.readLine()) != null) {
                    System.out.println("Message");
                    tf.setText(msg);
                }
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }
}
