import java.net.*;
import java.io.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class BClient {
    BufferedReader reader;
    JTextArea tf;
    JTextField jta;
    PrintWriter writer;
    public static void main(String[] args) {
        new BClient().go();
    }

    void go() {
        JFrame frame = new JFrame("Client");
        JPanel panel = new JPanel();
        JButton sendButton = new JButton("Send");
        sendButton.addActionListener(new SendButtonListener());
        jta = new JTextField(20);
        tf = new JTextArea(20, 20);
        tf.setEditable(false);
        setUpNetworking();
        panel.add(tf);
        panel.add(jta);
        panel.add(jta);
        panel.add(sendButton);
        frame.add(panel);
        frame.setSize(200,200);
        frame.setVisible(true);
    }

    void setUpNetworking() {
        try {
            Socket socket = new Socket("127.0.0.1", 5000);
            System.out.println("ConnectionEstablished");
            reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            writer = new PrintWriter(socket.getOutputStream());
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
                    tf.setText(tf.getText() +  "\n" + msg);
                }
            } catch(Exception e) {
                e.printStackTrace();
            }
        }
    }

    public class SendButtonListener implements ActionListener {
        public void actionPerformed(ActionEvent ae) {
            try {
                writer.println(jta.getText());
                writer.flush();
            } catch(Exception e) {
                e.printStackTrace();
            }
            jta.setText("");
        }
    }
}
